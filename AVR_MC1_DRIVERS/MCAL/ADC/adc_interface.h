/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc_interface.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

extern volatile u16 res;

/******************Analog Channel and Gain Selection Bits************/
typedef enum{
ADC_CHANNEL_ADC0,
ADC_CHANNEL_ADC1,
ADC_CHANNEL_ADC2,
ADC_CHANNEL_ADC3,
ADC_CHANNEL_ADC4,
ADC_CHANNEL_ADC5,
ADC_CHANNEL_ADC6,
ADC_CHANNEL_ADC7,
ADC_CHANNEL_ADC0_ADC0_10X,
ADC_CHANNEL_ADC1_ADC0_10X,
ADC_CHANNEL_ADC0_ADC0_200X ,
ADC_CHANNEL_ADC1_ADC0_200X ,
ADC_CHANNEL_ADC2_ADC2_10X ,
ADC_CHANNEL_ADC3_ADC2_10X ,
ADC_CHANNEL_ADC2_ADC2_200X ,
ADC_CHANNEL_ADC3_ADC2_200X,
ADC_CHANNEL_ADC0_ADC1_1X ,
ADC_CHANNEL_ADC1_ADC1_1X,
ADC_CHANNEL_ADC2_ADC1_1X,
ADC_CHANNEL_ADC3_ADC1_1X,
ADC_CHANNEL_ADC4_ADC1_1X,
ADC_CHANNEL_ADC5_ADC1_1X,
ADC_CHANNEL_ADC6_ADC1_1X,
ADC_CHANNEL_ADC7_ADC1_1X,
ADC_CHANNEL_ADC0_ADC2_1X,
ADC_CHANNEL_ADC1_ADC2_1X,
ADC_CHANNEL_ADC2_ADC2_1X,
ADC_CHANNEL_ADC3_ADC2_1X,
ADC_CHANNEL_ADC4_ADC2_1X,
}Adc_ChannelType;

/*********************ADC Prescaler Selections*****************/
#define ADC_PRESCALER_2 1
#define ADC_PRESCALER_4 2
#define ADC_PRESCALER_8 3
#define ADC_PRESCALER_16 4
#define ADC_PRESCALER_32 5
#define ADC_PRESCALER_64 6
#define ADC_PRESCALER_128 7

/******************ADC Auto Trigger Source Selections****************/
#define Free_Running_mode 0
#define Analog_Comparator 1
#define External_Interrupt_Request_0 2
#define Timer_Counter0_Compare_Match 3
#define Timer_Counter0_Overflow 4
#define Timer_Counter1_Compare_Match 5
#define Timer_Counter1_Overflow 6
#define Timer_Counter1_Capture_Event 7



/*************Voltage Reference Selections for ADC**************/
#define AREF_Internal_Vref_turned_off 0
#define AVCC_with_external_capacitor_at_AREF_pin 1
#define Reserved 2
#define Internal_2_56V_Voltage_Reference_with_external_capacitor_at_AREF_pin 3


#define  ADC_Enable 1
#define  ADC_Disable 0

//Put '1' to read data from LOW register first
#define READ_LOW_DATA 1
//Put '1' to read data from HIGH register first
#define READ_HIGH_DATA 0



/*********************************************************************************/
/* Function: ADC_u16ReadingSync
 * Input/outPut Parameters:
 * 			 INPUT : channel_num
 *
 * Returns:  u16
 * Description:	This Function used to Read ADC Value.
 */
/*********************************************************************************/

u16 ADC_u16ReadingSync(u8 channel_num);


/*********************************************************************************/
/* Function: ADC_voidinit
 * Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 *
 * Returns:  VOID
 * Description:	This Function initialize ADC by selecting AREF , enable ADC ,
 * selcet prescaler and select ADC CLK value
 */
/*********************************************************************************/
void ADC_voidInit(void);


/*********************************************************************************/
/* Function: MADC_u16ADC_StartConversion_interrupt
 * Input/outPut Parameters:
 * 			 INPUT : Adc_ChannelType Copy_u8Channel
 *
 * Returns:  VOID
 * Description:	This Function used to Start ADC conversion in Interrupt Mode
 */
/*********************************************************************************/
void MADC_u16ADC_StartConversion_interrupt(Adc_ChannelType Copy_u8Channel);


/*********************************************************************************/
/* Function: Adc_EnableNotification
 * Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 *
 * Returns:  VOID
 * Description:	This Function used to Enable ADC Interrupt
 */
/*********************************************************************************/
void Adc_EnableNotification(void);
void set_callBack(void(*ptr)(void));
//Adc_StateType Adc_GetResultAsync(u16* result_ref);
//void Adc_EnableNotification(void);
//void Adc_DisableNotification(void);
//void Adc_SetCallback(void (*funcPtr) (u16 data));


#endif /* ADC_INTERFACE_H_ */