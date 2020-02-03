/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s.h"

int main(void) {

	/* initialization */
	PIO_PER = YELLOW | GREEN | PUSH1 | PUSH2 ;
	PIO_OER = YELLOW | GREEN ;
	PIO_ODR = PUSH1 | PUSH2 ;
	PIO_SODR = YELLOW | GREEN ;

	int GreenState = 0 ;
	/* main loop */
	while(1) {
		if ((PIO_PDSR & PUSH1) == 0){
			PIO_CODR = YELLOW ;
		}
		if ((PIO_PDSR & PUSH2) == 0){
				GreenState = 1 ;
		}

		if ((PIO_PDSR & PUSH1) != 0){
			PIO_SODR = YELLOW ;
		}
		if (((PIO_PDSR & PUSH2) != 0) && GreenState==1){
			if ((PIO_PDSR & GREEN)==0) {
				PIO_SODR = GREEN ;
			}
			else {
				PIO_CODR = GREEN ;
			}
			GreenState = 0 ;
		}
	}

	return 0;
}
