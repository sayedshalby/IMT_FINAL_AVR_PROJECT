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

/*****************************************************
*           Header Inclusions					     *
*****************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"



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
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value)
{

    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)
        {
            case DIO_u8_PORTA:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO->PORTA,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO->PORTA,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO->PORTB,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO->PORTB,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO->PORTC,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO->PORTC,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Value)
                                {
                                    case  DIO_u8_LOW:   CLR_BIT(DIO->PORTD,Copy_u8PinId);     break;
                                    case  DIO_u8_HIGH:  SET_BIT(DIO->PORTD,Copy_u8PinId);     break;
                                }
                                break;

        }
    }
    else
    {

    }
}

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

void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction)
{

    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)
        {
            case DIO_u8_PORTA:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO->DDRA,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO->DDRA,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTB:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO->DDRB,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO->DDRB,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTC:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO->DDRC,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO->DDRC,Copy_u8PinId);     break;
                                }
                                break;
            case DIO_u8_PORTD:  switch(Copy_u8Direction)
                                {
                                    case  DIO_u8_INPUT:   CLR_BIT(DIO->DDRD,Copy_u8PinId);     break;
                                    case  DIO_u8_OUTPUT:  SET_BIT(DIO->DDRD,Copy_u8PinId);     break;
                                }
                                break;

        }
    }
    else
    {

    }
}


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
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{

    u8 Local_u8PinValue = 5;

    if( (Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7))
    {
        switch(Copy_u8PortId)
        {
            case DIO_u8_PORTA:  Local_u8PinValue = GET_BIT(DIO->PINA,Copy_u8PinId);  break;
            case DIO_u8_PORTB:  Local_u8PinValue = GET_BIT(DIO->PINB,Copy_u8PinId);  break;
            case DIO_u8_PORTC:  Local_u8PinValue = GET_BIT(DIO->PINC,Copy_u8PinId);  break;
            case DIO_u8_PORTD:  Local_u8PinValue = GET_BIT(DIO->PIND,Copy_u8PinId);  break;
        }
    }
    else
    {

    }
    return Local_u8PinValue;
}

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
void DIO_voidSetPortValue(u8 Copy_u8PortId, u8 Copy_u8Value)
{
	if( (Copy_u8PortId <= DIO_u8_PORTD) )
	    {
	        switch(Copy_u8PortId)
	        {
	            case DIO_u8_PORTA:  switch(Copy_u8Value)
	                                {
	                                    case  DIO_u8_LOW:   DIO->PORTA=0x00;     break;
	                                    case  DIO_u8_HIGH:  DIO->PORTA=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTB:  switch(Copy_u8Value)
	                                {
	                                    case  DIO_u8_LOW:   DIO->PORTB=0x00;     break;
	                                    case  DIO_u8_HIGH:  DIO->PORTB=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTC:  switch(Copy_u8Value)
	                                {
	                                    case  DIO_u8_LOW:   DIO->PORTC=0x00;     break;
	                                    case  DIO_u8_HIGH:  DIO->PORTC=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTD:  switch(Copy_u8Value)
	                                {
	                                    case  DIO_u8_LOW:   DIO->PORTD=0x00;     break;
	                                    case  DIO_u8_HIGH:  DIO->PORTD=0xff;     break;
	                                }
	                                break;

	        }
	    }
	    else
	    {

	    }

}

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
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction)
{
	if( (Copy_u8PortId <= DIO_u8_PORTD) )
	    {
	        switch(Copy_u8PortId)
	        {
	            case DIO_u8_PORTA:  switch(Copy_u8Direction)
	                                {
	                                    case  DIO_u8_INPUT:   DIO->DDRA=0x00;     break;
	                                    case  DIO_u8_OUTPUT:  DIO->DDRA=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTB:  switch(Copy_u8Direction)
	                                {
	                                    case  DIO_u8_INPUT:   DIO->DDRB=0x00;     break;
	                                    case  DIO_u8_OUTPUT:  DIO->DDRB=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTC:  switch(Copy_u8Direction)
	                                {
	                                    case  DIO_u8_INPUT:   DIO->DDRC=0x00;     break;
	                                    case  DIO_u8_OUTPUT:  DIO->DDRC=0xff;     break;
	                                }
	                                break;
	            case DIO_u8_PORTD:  switch(Copy_u8Direction)
	                                {
	                                    case  DIO_u8_INPUT:   DIO->DDRD=0x00;     break;
	                                    case  DIO_u8_OUTPUT:  DIO->DDRD=0xff;     break;
	                                }
	                                break;

	        }
	    }
	    else
	    {

	    }

}

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

u8 DIO_voidGetPortValue(u8 Copy_u8PortId)
{
    u8 Local_u8PinValue = 5;

    if( (Copy_u8PortId <= DIO_u8_PORTD) )
    {
        switch(Copy_u8PortId)
        {
            case DIO_u8_PORTA:  Local_u8PinValue = DIO->PINA;  break;
            case DIO_u8_PORTB:  Local_u8PinValue = DIO->PINB;  break;
            case DIO_u8_PORTC:  Local_u8PinValue = DIO->PINC;  break;
            case DIO_u8_PORTD:  Local_u8PinValue = DIO->PIND;  break;
        }
    }
    else
    {

    }
    return Local_u8PinValue;
}


void DIO_voidWritePort(u8 u8PortCpy ,u8 u8ValueCpy )
{
	switch(u8PortCpy)
	{
		case DIO_u8_PORTA :
		DIO->PORTA = u8ValueCpy;
		break;
		case DIO_u8_PORTB :
		DIO->PORTB =u8ValueCpy;
		break;
		case DIO_u8_PORTC :
		DIO->PORTC = u8ValueCpy;
		break;
		case DIO_u8_PORTD :
		DIO->PORTD = u8ValueCpy;
		break;
	}
}