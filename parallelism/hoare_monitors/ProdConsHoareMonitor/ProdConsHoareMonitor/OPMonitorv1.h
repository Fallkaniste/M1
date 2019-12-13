#ifndef PC_H
#define PC_H
#define NB_STEP 8
#define NB_COUNTERS 4

#include "MONITEURS_HOARE/HoareMonitor.h"
#include "MONITEURS_HOARE/HoareCondition.h"

#define BUFFER_MAX_SIZE  20

class OPMonitorV1 : public HoareMonitor {

  public :

    typedef struct {
      int current_step;
      char str[100];
      int isProcessed = 0;
    } Order;

    OPMonitorV1(unsigned newNBStep);

  protected :

    HoareCondition *CounterFree, ** Step, **orderBeingProcessed;

    void order(void);
    Order orders[NB_COUNTERS];
    void startStep(int stepNumber, Order * anOrder, int * aCounter);
    void finishStep(Order * anOrder, int * aCounter);

};

#endif
