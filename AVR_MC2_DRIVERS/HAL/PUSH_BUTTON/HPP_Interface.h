 /******************************************************************************
 *
 * Module: BUSH_BUTTON
 *
 * File Name: hpp_interface.h
 *
 * Description: header file for the ATmega32 Bush_button driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/


#ifndef HPP_INTERFACE_H_
#define HPP_INTERFACE_H_

/*****************************************************
*           Header Inclusions					     *
*****************************************************/
#include "DIO_Interface.h"

#define  INPUT 0
#define  OUTPUT 1
//button state
typedef enum {
	BUTTON_NOT_PRESSED,
	BUTTON_PRESSED
} Button_StateType;

/*
typedef enum{
	ACTIVE_HIGH = 0,
	ACTIVE_LOW
	}PB_Active_t;
*/


typedef struct{
	u8 PB_port;
	u8 PB_pin;
   // PB_Active_t PB_mode;
	}PB_t;



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
void PB_void_Init(const PB_t *ptr_PB);


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
void PB_void_readState(const PB_t *ptr_PB,Button_StateType* state );
#endif /* HPP_INTERFACE_H_ */