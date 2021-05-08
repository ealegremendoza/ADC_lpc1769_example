/*
 * ADC_lpc1769.c
 *
 *  Created on: 7 may. 2021
 *      Author: eze
 */
#include "ADC_lpc1769.h"

void ADC_Init(void)
{
	PCONP |= (1<<12);//ENCIENDO EL ADC
	PCLKSEL0 &= ~(3<<24);	//cclk/4
	PCLKSEL0 = (0<<24);

	GPIO_Func(ADC_PIN,ADC_FUNC);	//configuro el pin como ADC

	ISER0 |= (1<<22); //HAbilito interrupciones

	/*configuro el adc */
	AD0CR = (1<<ADC_CH0) |	/* SEL=0, select channel 0 on ADC0 */
			(0<<8) |	/* CLKDIV = LA MINIMA */
			(0<<16) |	/* BURST=0, no burst, software controlled */
			(0<<17) |	/* CLKS=0, 11 clocks/10bits */
			(0<<21) |	/* PDN=1, normal operation */
			(0<<24) |	/* START=0, A/D convertion stops */
			(0<<27) ;	/* EDGE=0, (CAP/MAT Signal falling, trigger, A/D Conversion) */
	/* If polling, no need to do the following */
	AD0INTEN=0X1FF; /* Enable all interrupts */
}

void ADC_Disparo(uint32_t canal) //al systick
{
	/*configuro el adc */
	AD0CR = (1<<canal) |	/* SEL=0, select channel x on ADC0 */
			(0<<8) |	/* CLKDIV = LA MINIMA */
			(0<<16) |	/* BURST=0, no burst, software controlled */
			(0<<17) |	/* CLKS=0, 11 clocks/10bits */
			(1<<21) |	/* PDN=1, normal operation */
			(1<<24) |	/* START=1, A/D convertion starts */
			(0<<27) ;	/* EDGE=0, (CAP/MAT Signal falling, trigger, A/D Conversion) */
}

void ADC_IRQHandler(void)
{
	uint32_t lectura;
	uint32_t voltaje;
	uint32_t canal=AD0GDR;// GLOBAL DATA REGISTER
	canal=(canal>>24)&0x07;
	switch(canal)
	{
	case 0:
		lectura=(AD0DR0>>4)&0xfff; //DATA REGISTER CH0
		break;
	case 1:
		lectura=(AD0DR1>>4)&0xfff; //DATA REGISTER CH1
		break;
	case 2:
		lectura=(AD0DR2>>4)&0xfff; //DATA REGISTER CH2
		break;
	case 3:
		lectura=(AD0DR3>>4)&0xfff; //DATA REGISTER CH3
		break;
	case 4:
		lectura=(AD0DR4>>4)&0xfff; //DATA REGISTER CH4
		break;
	case 5:
		lectura=(AD0DR5>>4)&0xfff; //DATA REGISTER CH5
		break;
	case 6:
		lectura=(AD0DR6>>4)&0xfff; //DATA REGISTER CH6
		break;
	case 7:
		lectura=(AD0DR7>>4)&0xfff; //DATA REGISTER CH7
		break;
	default:
		break;
	}

	/* operar a partir de acá con la lectura.*/
	//V=lectura*Vref/(2^n-1)
	if(canal==0)
	{
		/*	CIRCUITO:
		 * 3.3V - POTENCIOMETRO_PIN3
		 * AD0 	- POTENCIOMETRO_PIN2
		 * GND	- POTENCIOMETRO_PIN1 */
		voltaje=lectura;
		voltaje*=330; //vref=3.3v //330 porque opero con punto fijo
		voltaje/=4095; //n=12 -> 2^n-1
		printf("lectura:%d tension: %d.%d V\n",lectura,voltaje/100,voltaje%100);
	}
}
