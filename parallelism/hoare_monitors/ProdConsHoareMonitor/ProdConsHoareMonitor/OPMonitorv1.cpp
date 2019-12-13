/* CB/UPS/IRIT
 * Producteur-consommateur - Moniteur - Corps
 * */

#include "OPMonitorv1.h"
#include <string.h>
#include <stdlib.h>

/*--------------------------------------------------*/
OPMonitorV1 :: OPMonitorV1 (unsigned newNBStep) {
  Step = new HoareCondition*(newNBStep);
  orderBeingProcessed = new HoareCondition*()
}


/*--------------------------------------------------*/
void OPMonitorV1::order (void) {
  //TODO
}

void OPMonitorV1::startStep(int stepNumber, Order * anOrder, int * aCounter) {
  //TODO
}

void OPMonitorV1::finishStep(Order * anOrder, int * aCounter) {
  //TODO
}
