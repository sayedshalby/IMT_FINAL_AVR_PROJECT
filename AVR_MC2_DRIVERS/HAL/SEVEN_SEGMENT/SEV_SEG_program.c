 /******************************************************************************
 *
 * Module: seven_segment
 *
 * File Name: sev_seg_program.c
 *
 * Description: header file for the ATmega32 SSD driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"
#include "SEV_SEG_config.h"

				   /* 0    1    2   3     4    5    6    7     8     9  */
u8 SevenSeg_arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


/*******************************************************************************
 *                      Functions Prototypes                                   *
*******************************************************************************/

/*********************************************************************************/
/* Function: SevSeg_voidDisplay
 * Input/outPut Parameters:
 * 			 INPUT : num_cpy
 *
 * Returns:  void
 * Description:	This Function used to Display number on SSD.
 */
/*********************************************************************************/
void SevSeg_voidDisplay(u8 num_cpy)
{
	#if SSD_DISPLAY == TWO_SSD
	#if COMMON_TYPE == COMMON_CATHODE
	u8 x = num_cpy;
	num_cpy = num_cpy / 10;
	x = x % 10;
		DIO_voidWritePort(First_SEVEN_PORT_NAME,SevenSeg_arr[num_cpy]);
		
	    DIO_voidWritePort(Second_SEVEN_PORT_NAME,SevenSeg_arr[x]);
	#elif COMMON_TYPE == COMMON_ANODE
		DIO_voidWritePort(First_SEVEN_PORT_NAME,~SevenSeg_arr[num_cpy/10]);
		DIO_voidWritePort(Second_SEVEN_PORT_NAME,~SevenSeg_arr[num_cpy%10]);
	#endif
	#elif SSD_DISPLAY == ONE_SSD
	#if COMMON_TYPE == COMMON_CATHODE
	DIO_voidWritePort(First_SEVEN_PORT_NAME,SevenSeg_arr[num_cpy]);
	#elif COMMON_TYPE == COMMON_ANODE
	DIO_voidWritePort(First_SEVEN_PORT_NAME,~SevenSeg_arr[num_cpy]);
	#endif
	#endif
}



