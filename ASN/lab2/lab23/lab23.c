/* M1 CSA, ASN, lab 1.2 */
#include "../at91sam7s-term.h"

void putc(char c) {
	while(!(US0_CSR && US_TXRDY));
	US0_THR = c;
}

void puts(char *s) {
	while(*s)
		putc(*s++);
}

void __attribute__ ((interrupt("IRQ"))) handle_tc0(void) {
}

int main(void) {

	/* initialization */
	US0_CR = US_TXEN;
	US0_MR = US_USCLKS_MCK
		   | US_CHRL_8
		   | US_PAR_NONE
		   | US_NBSTOP_1
		   | US_CHMODE_NORMAL;
	US0_BRGR = MCK / 57600 / 16;
	US0_TTGR = 10;
	puts("READY!\n");

	/* main loop */
	while(1) {

	}

	return 0;
}
