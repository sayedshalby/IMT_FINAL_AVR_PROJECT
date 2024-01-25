/******************************************************************************
 *
 * Module: TIMER_1
 *
 * File Name: MTIMER1_config.h
 *
 * Description: Header file for the  TIMER_1 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_

/************** CRYSTAL_FREQ *************************/
#define CRYSTAL_FREQ         1       // in MHZ

/*********** TIMER 1 ************/
/* TIMER1_MODES:
 * 1) TIMER1_NORMAL_MODE
 * 2) TIMER1_CTC_MODE
 * 3) TIMER1_FAST_PWM_MODE
 * 4) TIMER1_PHASE_CORRECT_PWM_MODE
 */
#define TIMER1_MODE         TIMER1_NORMAL_MODE

/* OC1A_COMP_MATCH_PIN_MODES:
 * 1) OC1A_DISCONNECTED
 * 2) OC1A_TOGGLE
 * 3) OC1A_CLEAR
 * 4) OC1A_SET
 */
#define OC1A_MODE           OC1A_DISCONNECTED

/* OC1B_COMP_MATCH_PIN_MODES:
 * 1) OC1B_DISCONNECTED
 * 2) OC1B_TOGGLE
 * 3) OC1B_CLEAR
 * 4) OC1B_SET
 */
#define OC1B_MODE           OC1B_DISCONNECTED

/* FAST_PWM_MODE:
 * 1) FAST_PWM_INVERTED_MODE
 * 2) FAST_PWM_NON_INVERTED_MODE
 */
#define FAST_PWM_MODE       FAST_PWM_NON_INVERTED_MODE

/* PHASE_CORRECT_PWM_MODE:
 * 1) PHASE_CORRECT_PWM_INVERTED_MODE
 * 2) PHASE_CORRECT_PWM_NON_INVERTED_MODE
 */
#define PHASE_CORRECT_PWM_MODE   PHASE_CORRECT_PWM_NON_INVERTED_MODE

/*
 * TIMER1_PRESCALER_SELECT:
 * 1) TIMER1_NO_PRESCALER
 * 2) TIMER1_DIVIDE_BY_8
 * 3) TIMER1_DIVIDE_BY_64
 * 4) TIMER1_DIVIDE_BY_256
 * 5) TIMER1_DIVIDE_BY_1024
 */
#define TIMER1_PRESCALLER_SELEC  TIMER1_DIVIDE_BY_64

/*
 * COUNTER_EDGE_MODE:
 * 1) COUNTER1_RISING_EDGE_MODE
 * 2) COUNTER1_FALLING_EDGE_MODE
 */
#define COUNTER_EDGE_MODE COUNTER1_RISING_EDGE_MODE

#endif /* TIMER1_CONFIG_H_ */
