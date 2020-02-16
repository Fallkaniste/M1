/* M1 CSA, ASN, lab 3.1 */
#include "../at91sam7s.h"
#include <stdio.h>


#define THM	0

char* itoa(int val, int base){

    static char buf[32] = {0};

    int i = 30;

    for(; val && i ; --i, val /= base)

        buf[i] = "0123456789abcdef"[val % base];

    return &buf[i+1];

}
/**
 * Synchronously write a character to US0.
 * @param c	Written character.
 */
void us0_putc(char c) {
	while(!(US0_CSR && US_TXRDY));
	US0_THR = c;
}

/**
 * Synchronously write a string to US0.
 * @param s		Written string.
 */
void us0_puts(char *s) {
	while(*s)
		us0_putc(*s++);
}

/**
 * Initialize US0 (57,500 bauds, no parity, 8-bit character, 1 stop bit).
 */
void us0_init(void) {
	US0_CR = US_TXEN;
	US0_MR = US_USCLKS_MCK
		   | US_CHRL_8
		   | US_PAR_NONE
		   | US_NBSTOP_1
		   | US_CHMODE_NORMAL;
	US0_BRGR = MCK / 57600 / 16;
	US0_TTGR = 10;
}



int main(void) {
	int v = 0;
	/* initialization */
	ADC_MR = ADC_PRESCAL(0x3f);
	ADC_CHER = 1 << THM;
	TC0_CCR = TC_CLKDIS ;
  TC0_CMR = TC_TCCLKS_CLOCK3 | TC_CPCTRG ;
  TC0_RC = 62500 ;
  TC0_CCR = TC_SWTRG | TC_CLKEN ;
	us0_init();
	char str[16];
	/* main loop */
	while(1) {
		if (TC_CPCS & TC0_SR){
			ADC_CR = ADC_START;
			while(!(ADC_SR & ADC_EOC(THM)));
			v = ADC_CDR0 * 100 / 1023;
			sprintf(str, "%d", v);
			us0_puts(str);
			us0_puts("\n\r");
		}

		//us0_puts(itoa(v,10));
		//us0_putc(v);
	}

	return 0;
}
