 /******************************************************************************
 *
 * Module: seven_segment
 *
 * File Name: sev_seg_interface.h
 *
 * Description: header file for the ATmega32 SSD driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef SEV_SEG_INTERFACE_H_
#define SEV_SEG_INTERFACE_H_


#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3

#define COMMON_CATHODE 	 1
#define COMMON_ANODE   	 2


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
void SevSeg_voidDisplay(u8 num_cpy);


#endif