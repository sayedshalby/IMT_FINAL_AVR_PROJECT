/******************************************************************************
 *
 * Module: FAN
 *
 * File Name: HDCFAN.h
 *
 * Description: header file for the ATmega32 FAN driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "HFAN.h"



/*********************************************************************************/
/* Function: HFAN_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized FAN.
 */
/*********************************************************************************/
void HFAN_voidInit(void){
	DIO_voidSetPinDirection(FAN_ONE_PORT,FAN_ONE_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(FAN_TWO_PORT,FAN_TWO_PIN,DIO_u8_OUTPUT);
}


/*********************************************************************************/
/* Function: HFAN_voidStart
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start FAN in Clock Wise Direction.
 */
/*********************************************************************************/
void HFAN_voidStart(void){
	DIO_voidSetPinValue(FAN_ONE_PORT,FAN_ONE_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(FAN_TWO_PORT,FAN_TWO_PIN,DIO_u8_HIGH);
}



/*********************************************************************************/
/* Function: HFAN_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop FAN.
 */
/*********************************************************************************/
void HFAN_voidStop(void){
		DIO_voidSetPinValue(FAN_ONE_PORT,FAN_ONE_PIN,DIO_u8_LOW);
		DIO_voidSetPinValue(FAN_TWO_PORT,FAN_TWO_PIN,DIO_u8_LOW);
}