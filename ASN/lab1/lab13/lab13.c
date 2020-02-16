/* M1 CSA, ASN, lab 1.3 */
#include "../at91sam7s.h"

int GreenState = 0 ;

void __attribute__ ((interrupt("IRQ"))) handle_pio(void) {

int v;

/* interrupt processing */

if ((PIO_PDSR & PUSH1) == 0){
	PIO_CODR = YELLOW ;
}
if ((PIO_PDSR & PUSH1) != 0){
		PIO_SODR = YELLOW ;
	}

	if ((PIO_PDSR & PUSH2) == 0){
			GreenState = 1 ;
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

v = PIO_ISR;
v = AIC_EOICR;

}


int main(void) {

	/* initialization */

	AIC_IDCR = 1 << ID_PIO;
  void handle_pio(void);
  AIC_SVR[ID_PIO] = (uint32_t)handle_pio;
  AIC_SMR[ID_PIO] = 0;

	PIO_PER = YELLOW | GREEN | PUSH1 | PUSH2 ;
	PIO_OER = YELLOW | GREEN ;
	PIO_ODR = PUSH1 | PUSH2 ;
	PIO_SODR = YELLOW | GREEN ;
	PIO_IER = PUSH1 | PUSH2;

  int x = AIC_EOICR;
  AIC_ICCR = 1 << ID_PIO;
  AIC_IECR = 1 << ID_PIO;
  UNMASK_IRQ;

	/* main loop */
	while(1) {}

	return 0;
}
