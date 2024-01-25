/******************************************************************************
 *
 * Module: DC_MOTOR
 *
 * File Name: HDC_MOTOR.h
 *
 * Description: header file for the ATmega32 DC_MOTOR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/


#ifndef HDC_MOTOR_H_
#define HDC_MOTOR_H_
/*common macros to select Port and pins Connected to motor*/
#define MOTOR_ONE_PORT DIO_u8_PORTD
#define MOTOR_ONE_PIN DIO_u8_PIN3

#define MOTOR_TWO_PORT DIO_u8_PORTD
#define MOTOR_TWO_PIN DIO_u8_PIN4




/*********************************************************************************/
/* Function: HDCMOTOR_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized DC_Motor.
 */
/*********************************************************************************/
void HDCMOTOR_voidInit(void);




/*********************************************************************************/
/* Function: HDCMOTOR_voidStartAntiClockWise
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Motor in Anti Clock Wise Direction.
 */
/*********************************************************************************/
void HDCMOTOR_voidStartAntiClockWise(void);




/*********************************************************************************/
/* Function: HDCMOTOR_voidStartClockWise
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start Motor in Clock Wise Direction.
 */
/*********************************************************************************/
void HDCMOTOR_voidStartClockWise(void);






/*********************************************************************************/
/* Function: HDCMOTOR_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop DC_Motor.
 */
/*********************************************************************************/
void HDCMOTOR_voidStop(void);



#endif /* HDC_MOTOR_H_ */