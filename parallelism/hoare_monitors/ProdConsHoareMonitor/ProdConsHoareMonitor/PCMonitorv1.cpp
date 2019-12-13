/* CB/UPS/IRIT
 * Producteur-consommateur - Moniteur - Corps
 * */

#include "PCMonitorv1.h"
#include <string.h>
#include <stdlib.h>

/*--------------------------------------------------*/
PCMonitorV1 :: PCMonitorV1 (unsigned newBufferSize) {
  unsigned i;

  bufferSize = newBufferSize;
  iInsert = 0;
  iExtract = 0;
  for (i = 0; i < bufferSize; i++) {
    strcpy(buffer[i].info, "Empty");
    buffer[i].type = 0;
    buffer[i].prod = -1;
  }
  nbFilledPositions = 0;

  Empty = newCondition();
  Full = newCondition();
}

/*--------------------------------------------------*/
void PCMonitorV1 :: showBuffer (int a) {
  unsigned i;
  printf("%d [ ", a);
  for (i = 0; i < bufferSize; i++) {
    printf("[T%d] %s (of %d), ", buffer[i].type,
           buffer[i].info, buffer[i].prod);
  }
  printf("]\n");
}

/*--------------------------------------------------*/
unsigned PCMonitorV1 :: opposite (unsigned type) {
  return (type + 1)%2;
}

/*--------------------------------------------------*/
/*--------------------------------------------------*/
void PCMonitorV1 :: private_insert (TypeMessage aMessage) {
  strcpy(buffer[iInsert].info, aMessage.info);
  buffer[iInsert].type = aMessage.type;
  buffer[iInsert].prod = aMessage.prod;
  iInsert = (iInsert + 1) % bufferSize;
#ifdef TRACE_BUF
  showBuffer();
#endif
}

/*--------------------------------------------------*/
void PCMonitorV1 :: private_extract (TypeMessage *aMessage) {
  strcpy(aMessage->info, buffer[iExtract].info);
  aMessage->type = buffer[iExtract].type;
  aMessage->prod = buffer[iExtract].prod;
  iExtract = (iExtract + 1) % bufferSize;
#ifdef TRACE_BUF
  showBuffer();
#endif
}

/*--------------------------------------------------
 * V1 - Operation insert
 * */
void PCMonitorV1 :: insert (TypeMessage aMessage, unsigned prod) {
  // Start Mutual Exclusion
  enter();

  // Block if buffer full, wait for an empty space
  if (nbFilledPositions == bufferSize) {
    Empty->wait();
  }

  private_insert(aMessage);

  nbFilledPositions++;

  printf("\tProd %d : Message inserted = [T%d] %s (of %d)\n",
         prod, aMessage.type, aMessage.info, aMessage.prod);

  // A new filled position, wake up a potential consumer
  Full->signal();

  // Fin E.M.
  leave();
}

/*--------------------------------------------------
 * V1 - Operation extract
 * */
void PCMonitorV1 :: extract (TypeMessage *aMessage, unsigned cons) {
  enter();

  // Block if buffer empty, wait for a filled position
  if (nbFilledPositions == 0) {
    Full->wait();
  }

  private_extract(aMessage);

  // A space is secured
  nbFilledPositions--;

  printf("\t\tCons %d : Message read = [T%d] %s (of %d)\n",
         cons, aMessage->type, aMessage->info, aMessage->prod);

  // An empty space is created, wake up a producer
  Empty->signal();

  leave();
}
