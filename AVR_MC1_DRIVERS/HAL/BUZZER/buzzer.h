/******************************************************************************
 *
 * Module: buzzer
 *
 * File Name: buzzer.h
 *
 * Description: header file for the ATmega32 buzzer driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define BUZZER_PIN  DIO_u8_PIN2
#define BUZZER_PORT DIO_u8_PORTC

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*********************************************************************************/
/* Function: Buzzer_init
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized buzzer.
 */
/*********************************************************************************/
void Buzzer_init(void);


/*********************************************************************************/
/* Function: Buzzer_on
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to start buzzer.
 */
/*********************************************************************************/
void Buzzer_on(void);



/*********************************************************************************/
/* Function: Buzzer_off
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to stop buzzer.
 */
/*********************************************************************************/
void Buzzer_off(void);

#endif /* BUZZER_H_ */
