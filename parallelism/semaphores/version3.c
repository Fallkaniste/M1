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
#include <semaphore.h> //NEW

#define TRACE

#define NB_TIMES_PROD  1
#define NB_TIMES_CONS  1

#define NB_TYPES 5

#define NB_PROD_MAX   20
#define NB_CONS_MAX  20

#define NB_POSITIONS  20 // Maximum size of the buffer

pthread_mutex_t criticalMutex = PTHREAD_MUTEX_INITIALIZER;
sem_t producerSem ;
sem_t consumerSem[NB_TYPES] ;


typedef struct {
  char info[80];
  int  typeOfMessage;
  int  producerNumber;
} TypeMessage;

typedef struct {
  TypeMessage buffer[NB_POSITIONS];  // Buffer
  int posW;              // Index next put
  int posR;			     // Index next get
} CriticalResource;

// Shared Variables
CriticalResource resCritiques;  // Modifications so possible conflicts
int nbPositions;                // Size of the buffer

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
  int *retour = malloc(sizeof(int));
  *retour = valeurErr;
  fprintf(stderr, "%s: %d (%s) \n", msgErr, codeErr, strerror(codeErr));
  pthread_exit(retour);
}

/*--------------------------------------------------*/
void initializeSharedVariables(void) {
  int i;
  /* The buffer, its indices and the number of full positions */
  resCritiques.posW = 0;
  resCritiques.posR = 0;
  for (i = 0; i < nbPositions; i++) {
    strcpy(resCritiques.buffer[i].info, "Empty");
    resCritiques.buffer[i].typeOfMessage = -1;
    resCritiques.buffer[i].producerNumber = -1;
  }
}

/*--------------------------------------------------*/
void showBuffer (void) {
  int i;

  printf("[ ");
  for (i = 0; i < nbPositions; i++) {
	  if (resCritiques.buffer[i].producerNumber == -1) printf("(Empty)");
	  else printf("(%d, %s, %d)",
		   resCritiques.buffer[i].typeOfMessage, resCritiques.buffer[i].info, resCritiques.buffer[i].producerNumber);
  }
  printf("]\n");
}

/*--------------------------------------------------*/
void makePut (TypeMessage theMessage) {
  strcpy(resCritiques.buffer[resCritiques.posW].info, theMessage.info);
  resCritiques.buffer[resCritiques.posW].typeOfMessage = theMessage.typeOfMessage;
  resCritiques.buffer[resCritiques.posW].producerNumber = theMessage.producerNumber;
  resCritiques.posW = (resCritiques.posW + 1) % nbPositions;
}

/*--------------------------------------------------*/
void makeGet (TypeMessage *theMessage) {
  strcpy(theMessage->info, resCritiques.buffer[resCritiques.posR].info);
  theMessage->typeOfMessage = resCritiques.buffer[resCritiques.posR].typeOfMessage;
  theMessage->producerNumber = resCritiques.buffer[resCritiques.posR].producerNumber;

	resCritiques.buffer[resCritiques.posR].producerNumber = -1;
	resCritiques.buffer[resCritiques.posR].typeOfMessage = -1;
	strcpy(resCritiques.buffer[resCritiques.posR].info, "Empty");

  resCritiques.posR = (resCritiques.posR + 1) % nbPositions;
}

/*--------------------------------------------------*/
void * producer (void *arg) {
  int i;
  TypeMessage theMessage;
  Parameters *param = (Parameters *)arg;
	sleep(1);
    sprintf (theMessage.info, "%s n°%d", "Hello", i);
    theMessage.typeOfMessage = param->typeOfMessage;
    theMessage.producerNumber = param->threadNumber;
	  sem_wait(&producerSem);
	  pthread_mutex_lock(&criticalMutex);
	  makePut(theMessage);
	  pthread_mutex_unlock(&criticalMutex);
    sem_post(&consumerEntrySem]);
  }
  return NULL;
}

/*--------------------------------------------------*/
void * consumer (void *arg) {
  int i;
  TypeMessage theMessage;
  Parameters *param = (Parameters *)arg;
	sleep(1);
  for (i = 0; i < NB_TIMES_CONS; i++) {
    sem_wait(&consumerEntrySem);
    for (int i = 0 ; i < NB_TYPE ; i++){
      if(theMessage.typeOfMessage == i) {
        sem_post(&consSem[i]) ;
      }
    }
	  pthread_mutex_lock(&criticalMutex);
	  makeGet(&theMessage);
	  sem_post(&producerSem);
	  pthread_mutex_unlock(&criticalMutex);
  }
  return NULL;
}

/*--------------------------------------------------*/
int main(int argc, char *argv[]) {
  int i, etat;
  int nbThds, nbProd, nbCons;
  Parameters paramThds[NB_PROD_MAX + NB_CONS_MAX];
  pthread_t idThdProd[NB_PROD_MAX], idThdConso[NB_CONS_MAX];


  if (argc < 3) {
    printf ("Usage: %s <Nb Producers <= %d> <Nb Consumers <= %d> <Nb Positions <= %d> \n",
             argv[0], NB_PROD_MAX, NB_CONS_MAX, NB_POSITIONS);
    exit(2);
  }
	pthread_mutex_init(&criticalMutex, NULL);
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

  initializeSharedVariables();
  sem_init(&producerSem, 0, nbPositions);
  for (int i = 0 ; i < NB_TYPES ; i++){
    sem_init(&consumerSem[i], 0, 0);
  }

  for (i = 0; i <  nbThds; i++) {
    if (i < nbProd) {
      paramThds[i].typeOfMessage = i%NB_TYPES;
      paramThds[i].threadNumber = i;
      if ((etat = pthread_create(&idThdProd[i], NULL, producer, &paramThds[i])) != 0)
        thdErreur(etat, "Creation producer", etat);
    }
    else {
      paramThds[i].typeOfMessage = i%NB_TYPES;
      paramThds[i].threadNumber = i - nbProd;
      if ((etat = pthread_create(&idThdConso[i-nbProd], NULL, consumer, &paramThds[i])) != 0)
        thdErreur(etat, "Creation consumer", etat);
    }
  }

  /* Wait the end of threads */
  for (i = 0; i < nbProd; i++) {
    if ((etat = pthread_join(idThdProd[i], NULL)) != 0)
      thdErreur(etat, "Join threads producers", etat);
#ifdef TRACE
	  pthread_mutex_lock(&criticalMutex);
    printf("End thread producer n°%d\n", i);
	  pthread_mutex_unlock(&criticalMutex);

#endif
  }

  for (i = 0; i < nbCons; i++) {
    if ((etat = pthread_join(idThdConso[i], NULL)) != 0)
      thdErreur(etat, "Join threads consumers", etat);
#ifdef TRACE
	  pthread_mutex_lock(&criticalMutex);
    printf("End thread consumer n°%d\n", i);
	  pthread_mutex_unlock(&criticalMutex);
#endif
  }

#ifdef TRACE
  printf ("\nEnd of main \n");
  showBuffer();
#endif

  return 0;
}
