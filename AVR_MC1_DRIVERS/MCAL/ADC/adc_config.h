/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc_config.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*************select_ADC_Voltage**********************

AREF_Internal_Vref_turned_off
AVCC_with_external_capacitor_at_AREF_pin
Reserved
Internal_2_56V_Voltage_Reference_with_external_capacitor_at_AREF_pin
*****************************************************/
#define ADC_VOLTAGE     AVCC_with_external_capacitor_at_AREF_pin


/**************Select ADC Prescaler***************
ADC_PRESCALER_2
ADC_PRESCALER_4
ADC_PRESCALER_8
ADC_PRESCALER_16
ADC_PRESCALER_32
ADC_PRESCALER_64
ADC_PRESCALER_128
*******************************************************/
#define ADC_RESCALER ADC_PRESCALER_8




/******************ADC Auto Trigger Source Selections****************
Free_Running_mode
Analog_Comparator
External_Interrupt_Request_0
Timer_Counter0_Compare_Match
Timer_Counter0_Overflow
Timer_Counter1_Compare_Match
Timer_Counter1_Overflow
Timer_Counter1_Capture_Event
***********************************************************************/
#define TRIGGER_MODE Free_Running_mode


/**************ADC_State******************************
ADC_Enable
ADC_Disable
******************************************************/
#define ADC_STATE ADC_Enable

/******************Select ADC Channel************
ADC_CHANNEL_ADC0
ADC_CHANNEL_ADC1
ADC_CHANNEL_ADC2
ADC_CHANNEL_ADC3
ADC_CHANNEL_ADC4
ADC_CHANNEL_ADC5
ADC_CHANNEL_ADC6
ADC_CHANNEL_ADC7
ADC_CHANNEL_ADC0_ADC0_10X
ADC_CHANNEL_ADC1_ADC0_10X
ADC_CHANNEL_ADC0_ADC0_200X
ADC_CHANNEL_ADC1_ADC0_200X
ADC_CHANNEL_ADC2_ADC2_10X
ADC_CHANNEL_ADC3_ADC2_10X
ADC_CHANNEL_ADC2_ADC2_200X
ADC_CHANNEL_ADC3_ADC2_200X
ADC_CHANNEL_ADC0_ADC1_1X
ADC_CHANNEL_ADC1_ADC1_1X
ADC_CHANNEL_ADC2_ADC1_1X
ADC_CHANNEL_ADC3_ADC1_1X
ADC_CHANNEL_ADC4_ADC1_1X
ADC_CHANNEL_ADC5_ADC1_1X
ADC_CHANNEL_ADC6_ADC1_1X
ADC_CHANNEL_ADC7_ADC1_1X
ADC_CHANNEL_ADC0_ADC2_1X
ADC_CHANNEL_ADC1_ADC2_1X
ADC_CHANNEL_ADC2_ADC2_1X
ADC_CHANNEL_ADC3_ADC2_1X
ADC_CHANNEL_ADC4_ADC2_1X
******************************************************************/
#define CHANNEL_NUM ADC_CHANNEL_ADC0


//Put '1' to read data from LOW register first
#define READ_LOW_DATA 1
//Put '1' to read data from HIGH register first
#define READ_HIGH_DATA 0






#endif /* ADC_CONFIG_H_ */