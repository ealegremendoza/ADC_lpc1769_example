/*
===============================================================================
 Name        : ADC_lpc1769_example.c
 Author      : ealegremendoza
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "headers.h"

void SystemInit(void)
{
	InitPLL();
	SysTick_Init(1000);
	ADC_Init();

}
int main(void) {
	SystemInit();
    while(1) {
    	/* See systick.c and ADC_lpc1769.c	*/
		/*	CIRCUITO:
		 * 3.3V - POTENCIOMETRO_PIN3
		 * AD0 	- POTENCIOMETRO_PIN2
		 * GND	- POTENCIOMETRO_PIN1 */
    }
    return 0 ;
}
