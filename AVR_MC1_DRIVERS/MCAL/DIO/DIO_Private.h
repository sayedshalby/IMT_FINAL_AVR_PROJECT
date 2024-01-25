 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: dio_private.h
 *
 * Description: header file for the ATmega16 DIO driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_



#define DIO_u8_DDRA_REG 	*((volatile u8 *)(0x3A))			//Base Address Of DDRA REGISTER
#define DIO_u8_PORTA_REG	*((volatile u8 *)(0x3B))            //Base Address Of PORTA REGISTER
#define DIO_u8_PINA_REG		*((volatile u8 *)(0x39))            //Base Address Of PINA REGISTER

#define DIO_u8_DDRB_REG     *((volatile u8 *)(0x38))            //Base Address Of DDRB REGISTER
#define DIO_u8_PORTB_REG    *((volatile u8 *)(0x37))            //Base Address Of PORTB REGISTER
#define DIO_u8_PINB_REG     *((volatile u8 *)(0x36))            //Base Address Of PINB REGISTER

#define DIO_u8_DDRC_REG     *((volatile u8 *)(0x35))            //Base Address Of DDRC REGISTER
#define DIO_u8_PORTC_REG    *((volatile u8 *)(0x34))            //Base Address Of PORTC REGISTER
#define DIO_u8_PINC_REG     *((volatile u8 *)(0x33))            //Base Address Of PINC REGISTER

#define DIO_u8_DDRD_REG     *((volatile u8 *)(0x32))            //Base Address Of DDRD REGISTER
#define DIO_u8_PORTD_REG    *((volatile u8 *)(0x31))            //Base Address Of PORTD REGISTER
#define DIO_u8_PIND_REG     *((volatile u8 *)(0x30))            //Base Address Of PIND REGISTER



#define PORTS_BaseAddress	0x30		// START ADDRESS OF ALL USED REGISTERS

typedef struct
{
	u8 PIND	 ;		// INPUT/port D
	u8 DDRD  ;		// Direction/port D
	u8 PORTD ;		// Output/Port D
	u8 PINC  ;		// INPUT/port C
	u8 DDRC  ;		// Direction/port C
	u8 PORTC ;		// Output/Port C
	u8 PINB  ;		// INPUT/port B
	u8 DDRB  ;		// Direction/port B
	u8 PORTB ;		// Output/Port B
	u8 PINA  ;		// Input/port A
	u8 DDRA  ;		// Direction/port A
	u8 PORTA ; 		// Output/Port A
}PORTS_Reg;

#define 	DIO	 ((volatile PORTS_Reg*)(PORTS_BaseAddress))
/* use
 * DIO->PORTA
 *
 */


#define DIO_u8_INITIAL_OUTPUT   1
#define DIO_u8_INITIAL_INPUT	0

#define DIO_u8_OUTPUT_LOW       0
#define DIO_u8_OUTPUT_HIGH      1

#define DIO_u8_INPUT_FLOATING   0
#define DIO_u8_INPUT_PULLUP     1



#endif /* DIO_PRIVATE_H_ */
