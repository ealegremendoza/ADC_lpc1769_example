/*
 * ADC_lpc1769.h
 *
 *  Created on: 7 may. 2021
 *      Author: eze
 */

#ifndef ADC_LPC1769_H_
#define ADC_LPC1769_H_
#include "headers.h"

#define ADC_PIN		PORT_ADC_PIN
#define ADC_FUNC	PORT_ADC_FUNC
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7
void ADC_Init(void);
void ADC_Disparo(uint32_t canal);

#endif /* ADC_LPC1769_H_ */
