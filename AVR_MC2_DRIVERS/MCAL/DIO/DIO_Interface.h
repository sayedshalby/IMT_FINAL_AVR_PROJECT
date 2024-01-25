 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: dio_interface.h
 *
 * Description: header file for the ATmega32 DIO driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1

#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1


/*********************************************************************************/
/* Function: DIO_voidSetPinValue	                        				     */
/* Input/outPut Parameters:
 * 			Three INPUT, NO Return Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- PIN 	(0,1-->7)		Note Use DIO_u8_PIN0   for Pin 0
 * 					3- Value(HIGH or LOW)	Note use DIO_u8_LOW    for LOW
 * Returns:  VOID
 * Description:	This Function Writes 1 or zero on PORT register to SET DIO Pin as
 * 				HIGH or LOW
 */
/*********************************************************************************/
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value) ;

/*********************************************************************************/
 /* Function: DIO_voidSetPinDirection
 * Input/outPut Parameters:
 * 			Three INPUT, NO Return Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- PIN 	(0,1-->7)		Note Use DIO_u8_PIN0   for Pin 0
 * 					3- Value(HIGH or LOW)	Note use DIO_u8_LOW    for LOW
 * Returns:  VOID
 * Description:	This Function Writes 1 or zero on DDR register to SET DIO Pin as
 * 				INPUT or OUTPUT
 */
/*********************************************************************************/
void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);

/*********************************************************************************/
/* Function: DIO_voidGetPinValue
 * Input/outPut Parameters:
 * 			Two INPUT, One OUTPUT Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- PIN 	(0,1-->7)		Note Use DIO_u8_PIN0   for Pin 0
 * Returns:  u8, which is the value of the bit
 * Description:	This Function Returns 1 or zero from PIN register to read an input
 * 				Value of DIO pin
 */
/*********************************************************************************/
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

/*********************************************************************************/
/* Function: DIO_voidSetPortValue	                        				     
 * Input/outPut Parameters:
 * 			Two INPUT, NO Return Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- Value(HIGH or LOW)	Note use DIO_u8_LOW    for LOW
 * Returns:  VOID
 * Description:	This Function Writes 1 or zero on PORT register to SET DIO Port as
 * 				HIGH or LOW
 */
/*********************************************************************************/
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value);

/*********************************************************************************/
/* Function: DIO_voidSetPortDirection
 * Input/outPut Parameters:
 * 			Two INPUT, NO Return Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- Value(HIGH or LOW)	Note use DIO_u8_LOW    for LOW
 * Returns:  VOID
 * Description:	This Function Writes 1 or zero on DDR register to SET DIO Port as
 * 				INPUT or OUTPUT
 */
/*********************************************************************************/
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);

/*********************************************************************************/
/* Function: DIO_voidGetPortValue
 * Input/outPut Parameters:
 * 			Three INPUT, One OUTPUT Function
 * 			Input Arguments
 * 					1- PORT (A,B,C,D) 		Note Use DIO_u8_PORTA  for A
 * 					2- PIN 	(0,1-->7)		Note Use DIO_u8_PIN0   for Pin 0
 * Returns:  u8, which is the value of the register and equal to values of input PINS
 * Description:	This Function Returns Num between 0->255 from PIN register
 * 				which is the decimal value of input pins status of DIO pin
 */
/*********************************************************************************/
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);


void DIO_voidWritePort(u8 u8PortCpy ,u8 u8ValueCpy );


#endif /* DIO_INTERFACE_H_ */
