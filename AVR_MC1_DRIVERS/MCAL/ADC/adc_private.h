/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc_private.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define NULL_PTR ((void*)0)

/************* ADC Registers *************/
#define ADMUX		*((volatile u8*) 0x27)
#define ADCSRA		*((volatile u8*) 0x26)
#define ADCDATA		*((volatile u16*) 0x24)
#define ADCL		*((volatile u8*) 0x24)
#define ADCH		*((volatile u8*) 0x25)
#define SFIOR		*((volatile u8*) 0x50)
/************* ADMUX  PINS *************/
#define ADMUX_REFS1      7
#define ADMUX_REFS0      6
#define ADMUX_ADLAR      5
#define ADMUX_MUX4       4
#define ADMUX_MUX3       3
#define ADMUX_MUX2       2
#define ADMUX_MUX1       1
#define ADMUX_MUX0       0
/************* ADMUX  PINS *************/
#define ADCSRA_ADEN     7
#define ADCSRA_ADSC     6
#define ADCSRA_ADATE    5
#define ADCSRA_ADIF     4
#define ADCSRA_ADIE     3
#define ADCSRA_ADPS2    2
#define ADCSRA_ADPS1    1
#define ADCSRA_ADPS0    0
/************* SFIOR  PINS *************/
#define SFIOR_ADTS2     2
#define SFIOR_ADTS1      1
#define SFIOR_ADTS0      0



#define SREG		*((volatile u8*) 0x5F)
#define SREG_I      7

#endif /* ADC_PRIVATE_H_ */