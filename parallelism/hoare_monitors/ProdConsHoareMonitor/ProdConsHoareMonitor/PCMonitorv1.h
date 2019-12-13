/* CB/UPS/IRIT
 * Producteur-consommateur - Moniteur - Specification (V1)
 * */

#ifndef PC_H
#define PC_H

#include "MONITEURS_HOARE/HoareMonitor.h"
#include "MONITEURS_HOARE/HoareCondition.h"

#define BUFFER_MAX_SIZE  20 

class PCMonitorV1 : public HoareMonitor {

  public :
    typedef struct {
      char      info[80];
      unsigned  type;          // Message of 2 types (0/1 for instance)
      unsigned  prod;      // Who produced the message ?
    } TypeMessage;

  protected :
    TypeMessage buffer[BUFFER_MAX_SIZE];  	// Buffer
    unsigned iInsert;                    // Indice next insertion
    unsigned iExtract;			// Indice next extraction
    unsigned bufferSize;             // Actual size of the buffer

    // Version 1 : Basic version, no constraints
    // Producer is blocked if buffer is full
    // Consummer is blocked if buffer is empty
    HoareCondition *Empty, *Full;
    unsigned nbFilledPositions;

    unsigned opposite (unsigned type);
    void private_insert (TypeMessage aMessage);
    void private_extract (TypeMessage *aMessage);

  public :
    PCMonitorV1(unsigned newbufferSize);
	void showBuffer (int);

    // Insert and Extract messages
    void insert (TypeMessage aMessage, unsigned prod);
    void extract (TypeMessage *aMessage, unsigned prod);

};

#endif
