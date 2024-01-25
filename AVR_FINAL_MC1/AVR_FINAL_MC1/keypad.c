 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.c
 *
 * Description: Source file for the Keypad driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Registers.h"
#include "keypad.h"

/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

#if (N_col == 3)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x3 keypad
 */
static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number);
#elif (N_col == 4)
/*
 * Function responsible for mapping the switch number in the keypad to
 * its corresponding functional number in the proteus for 4x4 keypad
 */
static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number);
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
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
u8 KeyPad_getPressedKey(void)
{
	u8 col,row;
	while(1)
	{
		for(col=0;col<N_col;col++) /* loop for columns */
		{
			/* 
			 * each time only one of the column pins will be output and 
			 * the rest will be input pins include the row pins 
			 */ 
			KEYPAD_PORT_DIR = (0b00010000<<col); 
			
			/* 
			 * clear the output pin column in this trace and enable the internal 
			 * pull up resistors for the rows pins
			 */ 
			KEYPAD_PORT_OUT = (~(0b00010000<<col));

			for(row=0;row<N_row;row++) /* loop for rows */
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row)) /* if the switch is press in this row */ 
				{
					#if (N_col == 3)
						return KeyPad_4x3_adjustKeyNumber((row*N_col)+col+1);
					#elif (N_col == 4)
						return KeyPad_4x4_adjustKeyNumber((row*N_col)+col+1);
					#endif
				}
			}
		}
	}	
}

#if (N_col == 3) 

/*********************************************************************************/
/* Function: KeyPad_4x3_adjustKeyNumber
 * Input/outPut Parameters:
 * 			INPUT : button_number
 *
 * Returns:  u8
 * Description:	This Function used to get_pressed key on keypad 4*3.
 */
/*********************************************************************************/

static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
		case 10: return '*'; // ASCII Code of *
				 break;
		case 11: return 0;
				 break;		
		case 12: return '#'; // ASCII Code of #
				 break;
		default: return button_number;								 						
	}
} 

#elif (N_col == 4)
 
 
 /*********************************************************************************/
/* Function: KeyPad_4x3_adjustKeyNumber
 * Input/outPut Parameters:
 * 			INPUT : button_number
 *
 * Returns:  u8
 * Description:	This Function used to get_pressed key on keypad 4*4.
 */
/*********************************************************************************/
static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
		case 1: return 65; 
				break;
		case 2: return 1; 
				break;
		case 3: return 4; 
				break;
		case 4: return 7; // ASCII Code of %
				break;
		case 5: return 0; 
				break;
		case 6: return 2;
				break;
		case 7: return 5; 
				break;
		case 8: return 8; /* ASCII Code of '*' */
				break;		
		case 9: return 66; 
				break;
		case 10: return 3; 
				break;
		case 11: return 6; 
				break;
		case 12: return 9; /* ASCII Code of '-' */
				break;
		case 13: return 67;  /* ASCII of Enter */
				break;			
		case 14: return 68; 
				break;
		case 15: return 69; /* ASCII Code of '=' */
				break;
		case 16: return 70; /* ASCII Code of '+' */
				break;
		default: return button_number;								 						
	}
} 

#endif
