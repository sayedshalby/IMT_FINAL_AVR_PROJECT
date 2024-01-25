/******************************************************************************
 *
 * Module: FAN
 *
 * File Name: HDCFAN.h
 *
 * Description: header file for the ATmega32 FAN driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef HFAN_H_
#define HFAN_H_

/*common macros to select Port and pins Connected to FAN*/

#define FAN_ONE_PORT DIO_u8_PORTB
#define FAN_ONE_PIN DIO_u8_PIN0

#define FAN_TWO_PORT DIO_u8_PORTB
#define FAN_TWO_PIN DIO_u8_PIN1

/*********************************************************************************/
/* Function: HFAN_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized FAN.
 */
/*********************************************************************************/
void HFAN_voidInit(void);



/*********************************************************************************/
/* Function: HFAN_voidStart
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Start FAN in Clock Wise Direction.
 */
/*********************************************************************************/
void HFAN_voidStart(void);


/*********************************************************************************/
/* Function: HFAN_voidStop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to Stop FAN.
 */
/*********************************************************************************/
void HFAN_voidStop(void);
#endif /* HFAN_H_ */