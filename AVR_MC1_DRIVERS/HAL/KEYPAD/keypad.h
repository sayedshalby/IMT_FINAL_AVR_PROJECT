 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the Keypad driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 4
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTB
#define KEYPAD_PORT_IN  PINB
#define KEYPAD_PORT_DIR DDRB 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*********************************************************************************/
/* Function: KeyPad_getPressedKey
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to get_pressed key.
 */
/*********************************************************************************/
u8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
