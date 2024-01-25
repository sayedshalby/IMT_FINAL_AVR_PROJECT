 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: Private.h
 *
 * Description: header file for the ATmega32 TIMER0 driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef TIMER_PRIVATEH_H_
#define TIMER_PRIVATEH_H_





#define TIMSK_REG		*((volatile u8*) 0x59)
#define TOIE0_BIT 0
#define  OCIE0_BIT 1



#define TIFR		*((volatile u8*) 0x58)
#define TOV0_BIT 0
#define OCF0 1


/************* Timer/Counter 0 *************/
#define TCCR0_REG		*((volatile u8*) 0x53)
#define CS00_BIT 0
#define CS01_BIT 1
#define CS02_BIT 2
#define WGM01_BIT 3
#define COM00_BIT 4
#define COM01_BIT 5
#define WGM00_BIT 6
#define FOC0_BIT 7

#define TCNT0_REG		*((volatile u8*) 0x52)
#define OCR0_REG		*((volatile u8*) 0x5C)




#define  PRE_MASK 0xF8

#define TIMER_PRESCALER_NO_CLOCK_SOURCE 0
#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3 
#define TIMER_PRESCALER_256 4 
#define TIMER_PRESCALER_1024 5
#define TIMER_PRESCALER_EXT_FALLING 6 
#define TIMER_PRESCALER_EXT_RISING 7






#define PRE_MASK_MODE 0xCF

#define COMP_OUT_MODE_DISCONNECTED 0
#define COMP_OUT_MODE_TOGGLE 1
#define COMP_OUT_MODE_CLEAR 2
#define COMP_OUT_MODE_SET 3



#define TIMER0_OVF 1
#define TIMER0_CTC 2
#define TIMER0_PHASE_CORRECT 3
#define TIMER0_FAST_PWM 4



#define PREMASK_STOP_TIMER_MASK 0xF8
#define SHIFT_OCR 4


#define MODE_TIMER0_OVF 1
#define MODE_TIMER0_CTC 2
#define MODE_TIMER0_FAST_PWM 3

#define  TIMER0_8_BITS 256
#endif /* TIMER_PRIVATEH_H_ */