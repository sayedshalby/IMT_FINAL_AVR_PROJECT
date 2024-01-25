/******************************************************************************
 *
 * Module: STEEPER MOTOR
 *
 * File Name: HSTEPPER.c
 *
 * Description: header file for the ATmega32 STEEPER MOTOR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Registers.h"
#include "HSTEPPER.h"

#define STEP_CONFIG FULL_WAVE_STEPS
#if STEP_CONFIG == FULL_WAVE_STEPS
u8 stepper_steps[FULL_WAVE_STEPS] = {12 , 6 , 3 , 9};
#elif STEP_CONFIG == HALF_WAVE_STEPS
u8 stepper_steps[HALF_WAVE_STEPS] = {8,12,4,6,2,3,1,9};
#endif
volatile u8 count = 0;



/*********************************************************************************/
/* Function: HStepper_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized stepper motor.
 */
/*********************************************************************************/
void HStepper_voidInit(void){
	DIO_voidSetPinDirection(INT_PORT,IN1_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(INT_PORT,IN2_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(INT_PORT,IN3_PIN,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(INT_PORT,IN4_PIN,DIO_u8_OUTPUT);
}




/*********************************************************************************/
/* Function: HStepper_voidStart
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Stepper motor in Clock Wise Direction.
 */
/*********************************************************************************/
void HStepper_voidStart(void){
#if MICRO_PINS ==  FIRST_4_PINS
       STEPPER_PORT = (stepper_steps[count] & 0x0F) | (STEPPER_PORT & 0xF0);
	   count++;
	   if (count == STEP_CONFIG)
	   {
		   count = 0;
	   }
#elif MICRO_PINS ==  SECOND_4_PINS
STEPPER_PORT = (stepper_steps[count]<<4) | (STEPPER_PORT&0x0F);
count++;
if (count == STEP_CONFIG)
{
	count = 0;
}
#endif
}



/*********************************************************************************/
/* Function: HStepper_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop Stepper motor.
 */
/*********************************************************************************/
void HStepper_voidStop(void){
	DIO_voidSetPinValue(INT_PORT,IN1_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(INT_PORT,IN2_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(INT_PORT,IN3_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(INT_PORT,IN4_PIN,DIO_u8_LOW);
}


