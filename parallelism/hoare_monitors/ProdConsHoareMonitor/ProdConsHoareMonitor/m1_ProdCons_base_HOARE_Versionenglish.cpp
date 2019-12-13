/*
 * Producer-consommer, base without synchronisation
 * */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#include "PCMonitorv1.h"

#define TRACE

PCMonitorV1 *moniteurPC;

#define NB_TIMES_PROD   2 
#define NB_TIMES_CONS  2 

#define NB_PROD_MAX   20
#define NB_CONS_MAX  20

#define NB_POSITIONS  20 // Maximum size of the buffer 

pthread_mutex_t mutex_display = PTHREAD_MUTEX_INITIALIZER;

typedef struct {                // Parameters of the threads
  int threadNumber;
  int typeOfMessage;
} Parameters;

/*---------------------------------------------------------------------*/
/* codeErr : code returned by a primitive 
 * msgErr  : error message, personalised
 * valErr  : returned value by the thread
 */
void thdErreur(int codeErr, char *msgErr, int valeurErr) {
  int *retour = (int *)malloc(sizeof(int));
  *retour = valeurErr;
  fprintf(stderr, "%s: %d (%s) \n", msgErr, codeErr, strerror(codeErr));
  pthread_exit(retour);
}
  
/*--------------------------------------------------*/
void * producer (void *arg) {
  int i;
  PCMonitorV1::TypeMessage theMessage;
  Parameters *param = (Parameters *)arg;

	sleep(1); // to make sure that all consumers and producers have been created before starting --> only for display reasons, so that there is no interleaving...
	
  for (i = 0; i < NB_TIMES_PROD; i++) {
    sprintf (theMessage.info, "%s n°%d", "Hello", i);
    theMessage.type = param->typeOfMessage;
    theMessage.prod = param->threadNumber;

	  moniteurPC->insert(theMessage, param->threadNumber);
	  
	  printf("\tProducer %d : Message = (%d, %s, %d)\n",
			 param->threadNumber, theMessage.type, theMessage.info, theMessage.prod);
#ifdef TRACE
	  moniteurPC->showBuffer(param->threadNumber);
#endif

    //usleep(rand()%(100 * param->rang + 100));
  }
  return NULL;
}

/*--------------------------------------------------*/
void * consumer (void *arg) {
  int i;
  PCMonitorV1::TypeMessage  theMessage;
  Parameters *param = (Parameters *)arg;
	sleep(1); // to make sure that all consumers and producers have been created before starting --> only for display reasons, so that there is no interleaving...

  for (i = 0; i < NB_TIMES_CONS; i++) {
	  
	  moniteurPC->extract(&theMessage, param->threadNumber);
	printf("\t\tConso %d : Message = (%d, %s, %d)\n",
           param->threadNumber, theMessage.type, theMessage.info, theMessage.prod);
#ifdef TRACE
	  moniteurPC->showBuffer(param->threadNumber);
#endif
	  
    //usleep(rand()%(100 * param->rang + 100));
  }
  return NULL;
}

/*--------------------------------------------------*/
int main(int argc, char *argv[]) {
  int i, etat;
  int nbThds, nbProd, nbCons, nbPositions;
  Parameters paramThds[NB_PROD_MAX + NB_CONS_MAX];
  pthread_t idThdProd[NB_PROD_MAX], idThdConso[NB_CONS_MAX];

  if (argc < 3) {
    printf ("Usage: %s <Nb Producers <= %d> <Nb Consumers <= %d> <Nb Positions <= %d> \n", 
             argv[0], NB_PROD_MAX, NB_CONS_MAX, NB_POSITIONS);
    exit(2);
  }
	pthread_mutex_init(&mutex_display, NULL);
//	srand((int)pthread_self());
	
  nbProd  = atoi(argv[1]);
  if (nbProd > NB_PROD_MAX)
    nbProd = NB_PROD_MAX;
  nbCons = atoi(argv[2]);
  if (nbCons > NB_CONS_MAX)
    nbCons = NB_CONS_MAX;
  nbThds = nbProd + nbCons;
  nbPositions = atoi(argv[3]);
  if (nbPositions > NB_POSITIONS)
    nbPositions = NB_POSITIONS;

	moniteurPC = new PCMonitorV1(nbPositions);

  /* Creation of nbProd producers and nbConso consumers */
  for (i = 0; i <  nbThds; i++) {
    if (i < nbProd) {
      paramThds[i].typeOfMessage = 0;
      paramThds[i].threadNumber = i;
      if ((etat = pthread_create(&idThdProd[i], NULL, producer, &paramThds[i])) != 0)
        thdErreur(etat, "Creation producer", etat);
#ifdef TRACE
      printf("Creation thread producer n°%d -> %d/%d\n", i, paramThds[i].threadNumber, nbProd-1);
#endif
    }
    else {
      paramThds[i].typeOfMessage = 0;
      paramThds[i].threadNumber = i - nbProd;
      if ((etat = pthread_create(&idThdConso[i-nbProd], NULL, consumer, &paramThds[i])) != 0)
        thdErreur(etat, "Creation consumer", etat);
#ifdef TRACE
      printf("Creation thread consumer n°%d -> %d/%d\n", i-nbProd, paramThds[i].threadNumber, nbCons-1);
#endif
    }
  }

  /* Wait the end of threads */
  for (i = 0; i < nbProd; i++) {
    if ((etat = pthread_join(idThdProd[i], NULL)) != 0)
      thdErreur(etat, "Join threads producers", etat);
#ifdef TRACE
	  pthread_mutex_lock(&mutex_display);
    printf("End thread producer n°%d\n", i);
	  pthread_mutex_unlock(&mutex_display);

#endif
  }

  for (i = 0; i < nbCons; i++) {
    if ((etat = pthread_join(idThdConso[i], NULL)) != 0) 
      thdErreur(etat, "Join threads consumers", etat);
#ifdef TRACE
	  pthread_mutex_lock(&mutex_display);
    printf("End thread consumer n°%d\n", i);
	  pthread_mutex_unlock(&mutex_display);
#endif
  }
    
#ifdef TRACE
  printf ("\nEnd of main \n");
  moniteurPC->showBuffer(-1);
#endif

  return 0;
}
  
