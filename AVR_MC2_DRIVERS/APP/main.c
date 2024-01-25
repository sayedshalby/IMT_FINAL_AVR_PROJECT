 /******************************************************************************
 *
 * Module: APP
 *
 * File Name: main.c
 *
 * Description: Application file for ATMEGA32
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Registers.h"
#include "Interrupts.h"
#include "Timer_Interface.h"
#include "SEV_SEG_interface.h"
#include "HFAN.h"
#include "UART_interface.h"
#include "UlTRASONIC_interface.h"
#include "MTIMER1_interface.h"
#include "ExtInt.h"
#include "HDC_MOTOR.h"
#include "HSTEPPER.h"

#define TIME_DELAY 2000
#define DIST_MIN 15
#define TEMP_MAX 35
/*global variable to recieve uart data*/
volatile u8 Rx_data ; 


/*********************************************************************************/
/* Function: receive_char
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function passed to function UARTRX_vidSetISR()
 * and used to get received data from UART.
 */
/*********************************************************************************/
void receive_char(void)
{
/*get the received data*/
Rx_data=UART_u8ReceiveData();
/*Display received data on seven segment*/
SevSeg_voidDisplay(Rx_data);
/*disable transmitter*/
disable_tx();
}



/*********************************************************************************/
/* Function: handler_ON
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function passed to function EXTI_voidSetCallBack()
 * and used to start motors in the factory.
 */
/*********************************************************************************/
void handler_ON(void)
{
	/*start dc motor*/
 HDCMOTOR_voidStartClockWise();
 /*start steeper motor*/
 HStepper_voidStart();
}


/*********************************************************************************/
/* Function: handler_OFF
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function passed to function EXTI_voidSetCallBack()
 * and used to stop motors in the factory.
 */
/*********************************************************************************/
void handler_OFF(void)
{
	/*stop dc motor*/
HDCMOTOR_voidStop();
/*stop stepper motor*/
HStepper_voidStop();
}

int main(void)
{
/*local variable to get distance*/
u32 distance = 0;
/*initialized FAN*/
HFAN_voidInit();
/*initialized dc motor*/
HDCMOTOR_voidInit();
/*initialized stepper motor*/
HStepper_voidInit();
/*initialized Ultrasonic */
HULTRASONIC_voidInit();
/*initialized UART*/
UART_voidInit();
/*Enable external interrupt number 0*/
EXTI_voidEXTIEnable(EXTINT_CHANNEL_INT0,EXTINT_TRIGGER_FALLING_EDGE);
/*Enable external interrupt number 1*/
EXTI_voidEXTIEnable(EXTINT_CHANNEL_INT1,EXTINT_TRIGGER_FALLING_EDGE);


/*function called by external interrupt 0*/
EXTI_voidSetCallBack(EXTINT_CHANNEL_INT0,handler_ON);
/*function called by external interrupt 1*/
EXTI_voidSetCallBack(EXTINT_CHANNEL_INT1,handler_OFF);
	 

UARTRX_vidSetISR(receive_char);

/*Enable Global interrupt enable*/
 SET_BIT(SREG,SREG_I);
/*configure PORTA as OUPUT for seven segment 1*/
DIO_voidSetPortDirection(DIO_u8_PORTA, DIO_u8_OUTPUT);
/*configure PORTC as OUPUT for seven segment 2*/
DIO_voidSetPortDirection(DIO_u8_PORTC , DIO_u8_OUTPUT);
/*configure pin4 in PORTD As input for pushbutton*/
DIO_voidSetPinDirection(DIO_u8_PORTD , DIO_u8_PIN4 , DIO_u8_INPUT); 

    while (1) 
    {	
	/*check if temp larger than or equal TEMP_MAX if it is Start FAN otherwise STOP FAN*/
		if (Rx_data >= TEMP_MAX)
		{
			/*start fan*/
			HFAN_voidStart();
		}
		else{
			/*stop fan*/
			HFAN_voidStop();
		}
		
		
/*Enable Global interrupt enable*/
CLR_BIT(SREG,SREG_I);


/*get distance from HULTRASONIC_u32Distance() function*/
 distance = HULTRASONIC_u32Distance();
 /*check if distance smaller than DIST_MIN if it is stop all motors otherwise start all motors again*/
 if (distance < DIST_MIN)
 {
	 	/*stop dc motor*/
	 HDCMOTOR_voidStop();
	 /*stop stepper motor*/
	 HStepper_voidStop();
 }
 /*Non Blocking delay based on timer 0*/
Timer_setDelayTimeMilliSec(TIME_DELAY);

/*Enable Global interrupt enable*/
 SET_BIT(SREG,SREG_I);
 /*Non Blocking delay based on timer 0*/
Timer_setDelayTimeMilliSec(TIME_DELAY);

	}		
}

