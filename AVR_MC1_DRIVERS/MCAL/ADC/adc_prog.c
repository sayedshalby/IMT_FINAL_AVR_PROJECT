/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc_prog.c
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "adc_private.h"
#include "adc_config.h"
#include "adc_interface.h"
#include "Interrupts.h"
volatile u16 res ; /*Global variable to get adc value*/
void (*adc_ptr)(void) = NULL_PTR; /*Initialized adc_ptr by NULL*/

void set_callBack(void(*ptr)(void)){
	adc_ptr = ptr;
}

ISR(VECTOR_ADC){
	res = ADCL;
	res = res | (ADCH<<8);
	if (NULL_PTR != adc_ptr) {
		adc_ptr();
	}
	
}

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
void ADC_voidInit(void){
	ADMUX  = 0;
	#if (ADC_VOLTAGE == AREF_Internal_Vref_turned_off)
		CLR_BIT(ADMUX ,ADMUX_REFS0);
		CLR_BIT(ADMUX ,ADMUX_REFS1);
	
	#elif (ADC_VOLTAGE == AVCC_with_external_capacitor_at_AREF_pin)
		SET_BIT(ADMUX ,ADMUX_REFS0);
		CLR_BIT(ADMUX ,ADMUX_REFS1);
	
	#elif (ADC_VOLTAGE == Internal_2_56V_Voltage_Reference_with_external_capacitor_at_AREF_pin)
		SET_BIT(ADMUX ,ADMUX_REFS0);
		SET_BIT(ADMUX ,ADMUX_REFS1);
	
	#endif
	
	
	
	
	#if (ADC_RESCALER == ADC_PRESCALER_2)
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_4)
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_8)
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		CLR_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_16)
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_32)
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		CLR_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_64)
		CLR_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#elif (ADC_RESCALER == ADC_PRESCALER_128)
		SET_BIT(ADCSRA,ADCSRA_ADPS0);
		SET_BIT(ADCSRA,ADCSRA_ADPS1);
		SET_BIT(ADCSRA,ADCSRA_ADPS2);
	
	#endif
	
	
	#if (ADC_STATE == ADC_Enable)
		SET_BIT(ADCSRA,ADCSRA_ADEN);
	
	#elif (ADC_STATE == ADC_Disable)
		CLR_BIT(ADCSRA,ADCSRA_ADEN);
	
	#endif
	
	#if (TRIGGER_MODE == Free_Running_mode)
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Analog_Comparator)
		SET_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == External_Interrupt_Request_0)
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Timer_Counter0_Compare_Match)
		SET_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		CLR_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Timer_Counter0_Overflow)
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Timer_Counter1_Compare_Match)
		SET_BIT(SFIOR,SFIOR_ADTS0);
		CLR_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Timer_Counter1_Overflow)
		CLR_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
	
	#elif (TRIGGER_MODE == Timer_Counter1_Capture_Event)
		SET_BIT(SFIOR,SFIOR_ADTS0);
		SET_BIT(SFIOR,SFIOR_ADTS1);
		SET_BIT(SFIOR,SFIOR_ADTS2);
	
	#endif
	
	
}

/*********************************************************************************/
/* Function: ADC_u16ReadingSync
 * Input/outPut Parameters:
 * 			 INPUT : channel_num
 *
 * Returns:  u16
 * Description:	This Function used to Read ADC Value.
 */
/*********************************************************************************/

u16 ADC_u16ReadingSync(u8 channel_num){
channel_num &=0x07;
ADMUX &= 0xE0;    
ADMUX = ADMUX | channel_num;   
SET_BIT(ADCSRA,ADCSRA_ADSC);   /*ADC Start Conversion-->Polling , Return ADC Value*/

while(BIT_IS_CLEAR(ADCSRA,ADCSRA_ADIF));   
SET_BIT(ADCSRA,ADCSRA_ADIF);   

#if READ_LOW_DATA == 1
u16 data = ADCL;
data = data | (ADCH<<8);


#elif READ_HIGH_DATA == 1
u16 data = ADCL;
data = data | (3<<ADCH);

#endif
return data; /*return ADC Value*/
}

/*********************************************************************************/
/* Function: Adc_EnableNotification
 * Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 *
 * Returns:  VOID
 * Description:	This Function used to Enable ADC Interrupt
 */
/*********************************************************************************/
void Adc_EnableNotification(void){
	SET_BIT(ADCSRA,ADCSRA_ADIE); 
}



/*********************************************************************************/
/* Function: MADC_u16ADC_StartConversion_interrupt
 * Input/outPut Parameters:
 * 			 INPUT : Adc_ChannelType Copy_u8Channel
 *
 * Returns:  VOID
 * Description:	This Function used to Start ADC conversion in Interrupt Mode
 */
/*********************************************************************************/
void MADC_u16ADC_StartConversion_interrupt(Adc_ChannelType Copy_u8Channel){
     Copy_u8Channel &= 0x07; 
	ADMUX &= 0xE0; 
	ADMUX |= Copy_u8Channel;

	SET_BIT(ADCSRA,ADCSRA_ADSC);
}
