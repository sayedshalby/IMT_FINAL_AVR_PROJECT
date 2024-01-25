 /******************************************************************************
 *
 * Module: Interrupts
 *
 * File Name: ExtInt.h
 *
 * Description: header file for the ATmega32 INT driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef INC_EXTINT_H_
#define INC_EXTINT_H_

#include "DIO_Interface.h"

#define EXTINT_PIN_INT0      DIO_u8_PORTD,DIO_u8_PIN2
#define EXTINT_PIN_INT1      DIO_u8_PORTD,DIO_u8_PIN3
#define EXTINT_PIN_INT2      DIO_u8_PORTB,DIO_u8_PIN2


typedef enum {
    EXTINT_TRIGGER_LOW_LEVEL,
    EXTINT_TRIGGER_ON_CHANGE,
    EXTINT_TRIGGER_FALLING_EDGE,
    EXTINT_TRIGGER_RISING_EDGE
} ExtInt_TriggerEdgeType;

typedef enum {
    EXTINT_CHANNEL_INT0,
    EXTINT_CHANNEL_INT1,
    EXTINT_CHANNEL_INT2
} ExtInt_ChannelType;


void EXTI_voidEXTIEnable(ExtInt_ChannelType Copy_u8EXTINo, ExtInt_TriggerEdgeType Copy_u8EXTISense);
void EXTI_voidEXTIDisable(ExtInt_ChannelType channel);
void EXTI_voidSetCallBack(ExtInt_ChannelType channel, void (*funcPtr) (void));
#endif /* INC_EXTINT_H_ */
