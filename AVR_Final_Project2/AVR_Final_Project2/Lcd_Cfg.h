 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd_cfg.h
 *
 * Description: header file for the ATmega32 LCD driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef INC_LCD_CFG_H_
#define INC_LCD_CFG_H_



#define LCD_MODE_8_BIT  1
#define LCD_MODE_4_BIT  2

#define LCD_MODE        LCD_MODE_8_BIT

#define LCD_PIN_RS      DIO_u8_PORTC,DIO_u8_PIN5
#define LCD_PIN_RW      DIO_u8_PORTC,DIO_u8_PIN6
#define LCD_PIN_EN      DIO_u8_PORTC,DIO_u8_PIN7

#if LCD_MODE == LCD_MODE_8_BIT
#define LCD_PIN_D0       DIO_u8_PORTB,DIO_u8_PIN0
#define LCD_PIN_D1       DIO_u8_PORTA,DIO_u8_PIN1
#define LCD_PIN_D2       DIO_u8_PORTA,DIO_u8_PIN2
#define LCD_PIN_D3       DIO_u8_PORTA,DIO_u8_PIN3
#endif					 
#define LCD_PIN_D4       DIO_u8_PORTA,DIO_u8_PIN4
#define LCD_PIN_D5       DIO_u8_PORTA,DIO_u8_PIN5
#define LCD_PIN_D6       DIO_u8_PORTA,DIO_u8_PIN6
#define LCD_PIN_D7       DIO_u8_PORTA,DIO_u8_PIN7

#endif /* INC_LCD_CFG_H_ */
