 /******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: TimerCon.h
 *
 * Description: header file for the ATmega32 TIMER0 driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_



// CPU Clock
#define F_OSC                      1




//Mode [MODE_TIMER0_OVF , MODE_TIMER0_CTC , MODE_TIMER0_FAST_PWM]
#define TIMER_MODE MODE_TIMER0_FAST_PWM


//Choose Comapre Mode (Disconnected , Toggel , Clear , Set )
#define COMPARE_OUTPUT_MODE COMP_OUT_MODE_CLEAR


//Set Prescaller
#define PRESCALLER TIMER_PRESCALER_8


//Timer Modes
#define TIMER_INT_SOURCE_TIM0_OVF 1
#define TIMER_INT_SOURCE_TIM0_COMP 2



#endif /* TIMER_CONFIG_H_ */