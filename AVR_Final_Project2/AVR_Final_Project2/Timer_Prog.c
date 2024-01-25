 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: TimerProg.c
 *
 * Description: header file for the ATmega32 TIMER0 driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
 
 
 
 /*****************************************************
 *           Header Inclusions					     *
 *****************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Timer_Config.h"
#include "Timer_Privateh.h"
#include "Timer_Interface.h"
#include "Interrupts.h"
#include "DIO_Interface.h"
#include "Registers.h"

#define NULL_PTR ((void*)0)
static u32 Timer_U32_NumOfOV = 0;
u32 Timer_U32_NumOfCM = 0;
u8 Timer_U8_RemTicks = 0;
static u32 counter_OV = 0;

	

void (*Callback_TIM0_COMP ) (void) = NULL_PTR;
void (*Callback_TIM0_OVF  ) (void) = NULL_PTR;

ISR(VECTOR_TIM0_COMP) {
		 counter_OV ++;
static u32 Local_U32_Counter = 0;
Local_U32_Counter++;
	if (NULL_PTR != Callback_TIM0_COMP) {
		if(Local_U32_Counter == Timer_U32_NumOfCM)
		{
		Callback_TIM0_COMP();
			Local_U32_Counter = 0;
		}
		
	}
}

ISR(VECTOR_TIM0_OVF) {

	 counter_OV ++;
	 static u32 Local_U32_Counter = 0;
	 Local_U32_Counter++;
	if (NULL_PTR != Callback_TIM0_OVF) {
		if(Local_U32_Counter == Timer_U32_NumOfOV){
		Callback_TIM0_OVF();
		Local_U32_Counter = 0;
		TCNT0_REG = 256 - Timer_U8_RemTicks;
		}
	}
}


void SetCallback_TIMER_OVF(void (*funcPtr) (void)) {
	Callback_TIM0_OVF = funcPtr;

}

void SetCallback_TIMER_COMP(void (*funcPtr) (void)) {
	Callback_TIM0_COMP = funcPtr;

}


/*********************************************************************************/
/* Function: Timer_Init	                        				                */
/* Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 * 			
 * Returns:  VOID
 * Description:	This Function Used to initialized Timer
 * 				
 */
/*********************************************************************************/

void Timer_Init(void){
	#if TIMER_MODE == MODE_TIMER0_OVF 
	CLR_BIT(TCCR0_REG , WGM01_BIT);
	CLR_BIT(TCCR0_REG , WGM00_BIT);
	
	
	#elif TIMER_MODE ==  MODE_TIMER0_CTC
		SET_BIT(TCCR0_REG , WGM01_BIT);
		CLR_BIT(TCCR0_REG , WGM00_BIT);
		  TCCR0_REG &= PRE_MASK_MODE;
		  TCCR0_REG |= (COMPARE_OUTPUT_MODE<<SHIFT_OCR);
	#elif TIMER_MODE == MODE_TIMER0_FAST_PWM
	      TCCR0_REG = 0;
	      TCCR0_REG |= PRESCALLER;
		  SET_BIT(TCCR0_REG , WGM00_BIT);
		  SET_BIT(TCCR0_REG , WGM00_BIT);
          TCCR0_REG |= PRESCALLER;
		  CLR_BIT(TCCR0_REG , FOC0_BIT);
		  TCCR0_REG |= (COMPARE_OUTPUT_MODE<<SHIFT_OCR);
	
	#endif
}

/*********************************************************************************/
/* Function: setFastPWM	                        				                */
/* Input/outPut Parameters:
 * 			NO INPUT : duty
 * 			
 * Returns:  VOID
 * Description:	This Function Used to setFastPWM value
 * 				
 */
/*********************************************************************************/
void setFastPWM(u8 duty)
{
	#if COMPARE_OUTPUT_MODE == COMP_OUT_MODE_CLEAR
	if (duty == 0 )
	{
		OCR0 =(((u16)duty*255) / 100)   ;
	}
	else
	{
		OCR0 = (((u16)duty*255) / 100) - 1 ;
	}
	#elif COMPARE_OUTPUT_MODE == COMP_OUT_MODE_SET
	if (duty == 100 )
	{
		OCR0 = (255 - ((duty * 256 )/100 )) + 1 ;
	}
	else
	{
		OCR0 = 255 - ((duty * 256 )/100 ) ;
	}

	#else
	#warning ("Mode Not Selected")
	#endif
}

/*********************************************************************************/
/* Function: Timer_start	                        				     */
/* Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 * 			
 * Returns:  VOID
 * Description:	This Function used to start timer
 * 				
 */
/*********************************************************************************/
void Timer_start(void){
TCCR0_REG &= PRE_MASK;
TCCR0_REG |= PRESCALLER;

}
/*********************************************************************************/
/* Function: Timer_stop	                        				     */
/* Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 * 			
 * Returns:  VOID
 * Description:	This Function used to stop timer
 * 				
 */
/*********************************************************************************/

void Timer_stop(void){
	TCCR0_REG &= PREMASK_STOP_TIMER_MASK;
}


/*********************************************************************************/
/* Function: EnableInt	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- Copy_u8_Source
 * Returns:  VOID
 * Description:	This Function used to Enable interrupt for timer
 * 				
 */
/*********************************************************************************/
void EnableInt(u8 Copy_u8_Source){
	if (Copy_u8_Source == TIMER_INT_SOURCE_TIM0_OVF){
		SET_BIT(TIMSK_REG , TOIE0_BIT);
	}
	else if (Copy_u8_Source == TIMER_INT_SOURCE_TIM0_COMP){
		SET_BIT(TIMSK_REG , OCIE0_BIT);
	}
	
	
}


/*********************************************************************************/
/* Function: DisableInt	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- Copy_u8_Source
 * Returns:  VOID
 * Description:	This Function used to Disable interrupt for timer
 * 				
 */
/*********************************************************************************/
void DisableInt(u8 Copy_u8_Source){
     if (Copy_u8_Source == TIMER_INT_SOURCE_TIM0_OVF){
		SET_BIT(TIMSK_REG , TOIE0_BIT);
	 }
	else if (Copy_u8_Source == TIMER_INT_SOURCE_TIM0_COMP){
		SET_BIT(TIMSK_REG , OCIE0_BIT);
	}
	
}
/*********************************************************************************/
/* Function: TIMER0_COMPARE_MATCH_VALUE	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- Copy_u8_Value
 * Returns:  VOID
 * Description:	This Function used to update OCR for timer
 * 				
 */
/*********************************************************************************/
void TIMER0_COMPARE_MATCH_VALUE(u8 Copy_u8_Value){
	OCR0_REG = Copy_u8_Value;
}

/*********************************************************************************/
/* Function: TIMER0_OVERFLOW_VALUE	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- Copy_u8_Value
 * Returns:  VOID
 * Description:	This Function used to update TCNT for timer
 * 				
 */
/*********************************************************************************/
void TIMER0_OVERFLOW_VALUE(u8 Copy_u8_Value){
	TCNT0_REG = Copy_u8_Value;
}


/*********************************************************************************/
/* Function: Timer_GetCounts	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- u32 *Timer_Counts
 * Returns:  VOID
 * Description:	This Function used get counts of Timer
 * 				
 */
/*********************************************************************************/
void Timer_GetCounts(u32 *Timer_Counts){
	 *Timer_Counts = (counter_OV * TIMER0_8_BITS) + TCNT0_REG;
}

/*********************************************************************************/
/* Function: Timer_setDelayTimeMilliSec	                        				     */
/* Input/outPut Parameters:
 * 			ONE INPUT, NO Return Function
 * 			INPUT PARAMETER:
                  1- delay_ms
 * Returns:  VOID
 * Description:	This Function used to set delay 
 * 				
 */
/*********************************************************************************/
void Timer_setDelayTimeMilliSec(u32 delay_ms){
	
	u32 TIMER0_PRESCALLER_ARR[] = {1,8,64,256,1024};
		/*
		f32 tickTime = (TIMER0_PRESCALLER_ARR[PRESCALLER-1]);
		tickTime = (tickTime/F_OSC)*256;
		f32 NO_over = (f32)delay_ms/(tickTime*1000000);
		Timer_U32_NumOfOV = NO_over;
		float REM = NO_over - (unsigned int)(NO_over);
	Timer_U8_RemTicks = REM;
	u32 what_l = REM * 256;
		if(Timer_U8_RemTicks != 0){
			Timer_U32_NumOfOV++;
			TCNT0_REG =256 - what_l;
			}
		*/
		
	f32 tickTime = (f32)(TIMER0_PRESCALLER_ARR[PRESCALLER-1])/F_OSC;
  
	u32 NumOfTicks = ((delay_ms*1000)/(tickTime));
	Timer_U32_NumOfOV = NumOfTicks / 256 ;
	Timer_U8_RemTicks = NumOfTicks % 256;
	if(Timer_U8_RemTicks != 0){
		Timer_U32_NumOfOV++;
		TCNT0_REG =256 - Timer_U8_RemTicks;
	}
	
}
