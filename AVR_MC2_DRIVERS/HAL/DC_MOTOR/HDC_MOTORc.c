/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: HDC_MOTOR.c
 *
 * Description: header file for the ATmega32 DC_MOTOR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "HDC_MOTOR.h"

/*********************************************************************************/
/* Function: HDCMOTOR_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized DC_Motor.
 */
/*********************************************************************************/
void HDCMOTOR_voidInit(void){
	DIO_voidSetPinDirection(MOTOR_ONE_PORT,MOTOR_ONE_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(MOTOR_TWO_PORT,MOTOR_TWO_PIN,DIO_u8_OUTPUT);
}



/*********************************************************************************/
/* Function: HDCMOTOR_voidStartClockWise
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Motor in Clock Wise Direction.
 */
/*********************************************************************************/
void HDCMOTOR_voidStartClockWise(void){
	DIO_voidSetPinValue(MOTOR_ONE_PORT,MOTOR_ONE_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(MOTOR_TWO_PORT,MOTOR_TWO_PIN,DIO_u8_HIGH);
}



/*********************************************************************************/
/* Function: HDCMOTOR_voidStartAntiClockWise
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Motor in Anti Clock Wise Direction.
 */
/*********************************************************************************/
void HDCMOTOR_voidStartAntiClockWise(void){
	DIO_voidSetPinValue(MOTOR_ONE_PORT,MOTOR_ONE_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(MOTOR_TWO_PORT,MOTOR_TWO_PIN,DIO_u8_LOW);
}


/*********************************************************************************/
/* Function: HDCMOTOR_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop DC_Motor.
 */
/*********************************************************************************/
void HDCMOTOR_voidStop(void){
	DIO_voidSetPinValue(MOTOR_ONE_PORT,MOTOR_ONE_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(MOTOR_TWO_PORT,MOTOR_TWO_PIN,DIO_u8_LOW);
}