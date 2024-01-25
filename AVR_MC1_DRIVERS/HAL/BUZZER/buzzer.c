/******************************************************************************
 *
 * Module: buzzer
 *
 * File Name: buzzer.c
 *
 * Description: header file for the ATmega32 buzzer driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

/************************Libraries and inclusions*******************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "buzzer.h"

/*******************************************************************************/

/*******************************************************************************/

/**********************************Functions************************************/


/*********************************************************************************/
/* Function: Buzzer_init
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized buzzer.
 */
/*********************************************************************************/
void Buzzer_init(void)
{
	/*Make the buzzer pin output pin*/
	DIO_voidSetPinDirection(BUZZER_PORT,BUZZER_PIN,DIO_u8_OUTPUT);

	/*Turn off the buzzer*/
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_u8_LOW);
}



/*********************************************************************************/
/* Function: Buzzer_on
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to start buzzer.
 */
/*********************************************************************************/
void Buzzer_on(void)
{
	/*Turn on the buzzer*/
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_u8_HIGH);
}

/*********************************************************************************/
/* Function: Buzzer_off
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to stop buzzer.
 */
/*********************************************************************************/
void Buzzer_off(void)
{
	/*Turn off the buzzer*/
	DIO_voidSetPinValue(BUZZER_PORT,BUZZER_PIN,DIO_u8_LOW);
}
