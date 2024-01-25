/******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ULTRASONIC_program.c
 *
 * Description: Header file for the  ULTRASONIC 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "MTIMER1_interface.h"
#include "UlTRASONIC_config.h"
#include "UlTRASONIC_interface.h"




//#define F_CPU 16000000UL

static u16 u16_global_RissingValue = 0;
static u16 u16_global_FallingValue = 0;

/* Initialize the Ultrasonic sensor */
void HULTRASONIC_voidInit(void)
{
    // Set the trigger pin as an output and the echo pin as an input
    DIO_voidSetPinDirection(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_OUTPUT);
    DIO_voidSetPinDirection(ECHO_PORT, ECHO_PIN, DIO_u8_INPUT);

    // Clear the Input Capture Flag
    ICU_u8ClearInputCaptureFlag();
}

/* Trigger the Ultrasonic sensor to send a pulse */
void HULTRASONIC_voidTrigger(void)
{
    // Generate a pulse on the trigger pin
    DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_HIGH);
    _delay_ms(50); // Delay for 50ms
    DIO_voidSetPinValue(TRIGGER_PORT, TRIGGER_PIN, DIO_u8_LOW);
}

/* Handle the rising edge of the echo signal */
void HULTRASONIC_voidRisingEdge(void)
{
    // Configure for rising edge, no prescaler, and noise canceler
    ICU_u8SetTriggerEdge(ICU_RISING_EDGE);
    ICU_voidNoiseCanceler();
    MTIMER1_voidNoPrescaler();

    // Wait until the Input Capture Flag is set
    while (ICU_u8GetInputCaptureFlag() == 0);
    u16_global_RissingValue = ICU_u16ReadInputCapture(); // Read the capture register
    ICU_u8ClearInputCaptureFlag();                       // Clear the Input Capture Flag
}

/* Handle the falling edge of the echo signal */
void HULTRASONIC_voidFallingEdge(void)
{
    // Configure for falling edge, no prescaler, and noise canceler
    ICU_u8SetTriggerEdge(ICU_FALLING_EDGE);
    ICU_voidNoiseCanceler();
    MTIMER1_voidNoPrescaler();

    // Wait until the Input Capture Flag is set
    while (ICU_u8GetInputCaptureFlag() == 0);
    u16_global_FallingValue = ICU_u16ReadInputCapture(); // Read the capture register
    ICU_u8ClearInputCaptureFlag();                       // Clear the Input Capture Flag

    // Stop the timer
    MTIMER1_voidSetTimerValue(0);
    MTIMER1_enumStop();
}

/* Calculate and return the distance measured by the Ultrasonic sensor in centimeters */
u32 HULTRASONIC_u32Distance(void)
{
	HULTRASONIC_voidTrigger();
    HULTRASONIC_voidRisingEdge();
    HULTRASONIC_voidFallingEdge();

    // Calculate the time the echo signal was on
    u32 u32_local_TimeOn = u16_global_FallingValue - u16_global_RissingValue;
    u32 u32_local_Distance = 0;

    // Calculate the distance based on the time and the speed of sound
    u32_local_Distance = ((u32_local_TimeOn * 34600) / (F_CPU_U * 2)); // Speed of sound is approximately 346 m/s

    return u32_local_Distance;
}

/* Stop the Ultrasonic sensor (if needed) */
void HULTRASONIC_voidStop(void)
{
    // Implement the stop functionality if required
}
