 /******************************************************************************
 *
 * Module: BUSH_BUTTON
 *
 * File Name: hpp.h
 *
 * Description: header file for the ATmega32 Bush_button driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

/*****************************************************
*           Header Inclusions					     *
*****************************************************/
#include <util/delay.h>
#include "DIO_Interface.h"
#include "HPP_Interface.h"




/*********************************************************************************/
/* Function: PB_void_Init      	                        				     */
/* Input/outPut Parameters:
 * 			One INPUT, NO Return Function
 * 			Input Arguments
 * 					1- PB_t *ptr_PB		
 * Returns:  VOID
 * Description:	This Function Take const Pointer to structure (PB_t)
 * 			
 */
/*********************************************************************************/
void PB_void_Init(const PB_t *ptr_PB){
	DIO_voidSetPinDirection(ptr_PB->PB_port, ptr_PB->PB_pin ,INPUT);
}


/*********************************************************************************/
/* Function: PB_void_readState      	                        				     */
/* Input/outPut Parameters:
 * 			Two INPUT, NO Return Function
 * 			Two Arguments
 * 					1- const PB_t *ptr_PB	
 *                  2- Button_StateType* state
 * Returns:  VOID
 * Description:	This Function Take const Pointer to structure (PB_t) and Take pointer to button_sate
 * 			
 */
/*********************************************************************************/
void PB_void_readState(const PB_t *ptr_PB,Button_StateType* state ){
         // u8 counter = 0;
	     u8 flag = BUTTON_NOT_PRESSED;
		 static Button_StateType copy_u8state = BUTTON_NOT_PRESSED;
	 #if (BUTTON_CONNECTION == BUTTON_PULLUP)

	  if (DIO_voidGetPinValue(ptr_PB->PB_port, ptr_PB->PB_pin) ==  0 ){
            _delay_ms(20);
		  if (DIO_voidGetPinValue(ptr_PB->PB_port, ptr_PB->PB_pin) ==  0 ){
			  if(flag == BUTTON_NOT_PRESSED){
				  flag = BUTTON_PRESSED;
				  *state = BUTTON_PRESSED;
			  }
			  else if (flag == BUTTON_PRESSED)
			  {
				  *state = BUTTON_NOT_PRESSED;
			  }
			  else{
			  }
			  
		  }
		   else{
			   *state = BUTTON_NOT_PRESSED;
			   flag = BUTTON_NOT_PRESSED;
		   }
		  
	  
	  }
	   else{
		   *state = BUTTON_NOT_PRESSED;
		   flag = BUTTON_NOT_PRESSED;
	   }
	   
	  
	#elif (BUTTON_CONNECTION == BUTTON_PULLDOWN)
	  
	  if (DIO_voidGetPinValue(ptr_PB->PB_port, ptr_PB->PB_pin) ==  0 ){
		  _delay_ms(20);
		  if (DIO_voidGetPinValue(ptr_PB->PB_port, ptr_PB->PB_pin) ==  0 ){
			  if(flag == BUTTON_NOT_PRESSED){
				  flag = BUTTON_PRESSED;
				  *state = BUTTON_PRESSED;
			  }
			  else if (flag == BUTTON_PRESSED)
			  {
				  *state = BUTTON_NOT_PRESSED;
			  }
			  else{
			  }
			  
		  }
		  else{
			  *state = BUTTON_NOT_PRESSED;
			  flag = BUTTON_NOT_PRESSED;
		  }
		  
		  
	  }
	  else{
		  *state = BUTTON_NOT_PRESSED;
		  flag = BUTTON_NOT_PRESSED;
	  }
	  #endif
	  
}


