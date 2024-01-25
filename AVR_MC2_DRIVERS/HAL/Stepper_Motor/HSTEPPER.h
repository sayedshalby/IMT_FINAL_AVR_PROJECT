/******************************************************************************
 *
 * Module: STEEPER MOTOR
 *
 * File Name: HSTEPPER.h
 *
 * Description: header file for the ATmega32 STEEPER MOTOR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef HSTEPPER_H_
#define HSTEPPER_H_

/*Select stepper steps*/
#define HALF_WAVE_STEPS 8

#define FULL_WAVE_STEPS 4

/*Select stepper steps*/
#define STEP_CONFIG FULL_WAVE_STEPS

/*common macros to select Port and pins Connected to stepper*/
#define FIRST_4_PINS 0
#define SECOND_4_PINS 1
#define MICRO_PINS  SECOND_4_PINS
#define STEPPER_PORT PORTB

#define INT_PORT    DIO_u8_PORTB
#define IN1_PIN     DIO_u8_PIN4
#define IN2_PIN     DIO_u8_PIN5
#define IN3_PIN     DIO_u8_PIN6
#define IN4_PIN      DIO_u8_PIN7


/*********************************************************************************/
/* Function: HStepper_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized stepper motor.
 */
/*********************************************************************************/

void HStepper_voidInit(void);


/*********************************************************************************/
/* Function: HStepper_voidStart
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Stepper motor in Clock Wise Direction.
 */
/*********************************************************************************/
void HStepper_voidStart(void);


/*********************************************************************************/
/* Function: HStepper_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop Stepper motor.
 */
/*********************************************************************************/
void HStepper_voidStop(void);


#endif /* HSTEPPER_H_ */