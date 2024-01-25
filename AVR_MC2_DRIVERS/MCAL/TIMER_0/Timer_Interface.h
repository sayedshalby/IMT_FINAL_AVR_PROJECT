 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: Timer_interface.c
 *
 * Description: header file for the ATmega32 TIMER0 driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/*********************************************************************************/
/* Function: Timer_Init	                        				     */
/* Input/outPut Parameters:
 * 			NO INPUT, NO Return Function
 * 			
 * Returns:  VOID
 * Description:	This Function Used to initialized Timer
 * 				
 */
/*********************************************************************************/
void Timer_Init(void);

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
void Timer_start(void);

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
void Timer_stop(void);

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
void Timer_GetCounts(u32 *Timer_Counts);

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
void EnableInt(u8 Copy_u8_Source);

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
void DisableInt(u8 Copy_u8_Source);

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
void TIMER0_OVERFLOW_VALUE(u8 Copy_u8_Value);

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
void TIMER0_COMPARE_MATCH_VALUE(u8 Copy_u8_Value);


void SetCallback_TIMER_OVF(void (*funcPtr) (void));
void SetCallback_TIMER_COMP(void (*funcPtr) (void));

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
void Timer_setDelayTimeMilliSec(u32 delay_ms);





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
void setFastPWM(u8 duty);

#endif /* TIMER_INTERFACE_H_ */