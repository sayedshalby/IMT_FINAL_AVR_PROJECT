/******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ULTRASONIC_config.c
 *
 * Description: Header file for the  ULTRASONIC 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef ULTRASONIC_CONFIG_H_
#define ULTRASONIC_CONFIG_H_
/*commom macros to select trigger , echo port and pins*/
#define TRIGGER_PORT    DIO_u8_PORTD
#define TRIGGER_PIN     DIO_u8_PIN7

#define ECHO_PORT       DIO_u8_PORTD
#define ECHO_PIN        DIO_u8_PIN6

#define F_CPU_U 1000000

#endif /* ULTRASONIC_CONFIG_H_ */
