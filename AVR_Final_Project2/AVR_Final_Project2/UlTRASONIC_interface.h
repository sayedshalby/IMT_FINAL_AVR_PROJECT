/******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ULTRASONIC_interface.c
 *
 * Description: Header file for the  ULTRASONIC 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_



/**
 * @brief Initialize the Ultrasonic sensor.
 */
void HULTRASONIC_voidInit(void);

/**
 * @brief Trigger the Ultrasonic sensor to send a pulse.
 */
void HULTRASONIC_voidTrigger(void);

/**
 * @brief Handle the rising edge of the echo signal.
 */
void HULTRASONIC_voidRisingEdge(void);

/**
 * @brief Handle the falling edge of the echo signal.
 */
void HULTRASONIC_voidFallingEdge(void);

/**
 * @brief Calculate and return the distance measured by the Ultrasonic sensor in centimeters.
 *
 * @return The distance in centimeters.
 */
u32 HULTRASONIC_u32Distance(void);

/**
 * @brief Stop the Ultrasonic sensor (if needed).
 */
void HULTRASONIC_voidStop(void);

#endif /* ULTRASONIC_INTERFACE_H_ */
