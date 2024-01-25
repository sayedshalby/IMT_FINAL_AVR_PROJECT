 /******************************************************************************
 *
 * Module: Seven_segment
 *
 * File Name: sev_seg_config.h
 *
 * Description: header file for the ATmega32 SSD driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

#ifndef SEV_SEG_CONFIG_H_
#define SEV_SEG_CONFIG_H_

/*
Choose the connection of seven segment()
1- COMMON_CATHODE
2- COMMON_ANODE
*/ 
#define  COMMON_TYPE      COMMON_CATHODE



#define ONE_SSD 1
#define TWO_SSD 2
/*
Choose the number of seven segment(SSD_DISPLAY)
1- ONE_SSD
2- TWO_SSD
*/
#define  SSD_DISPLAY   TWO_SSD




#define  First_SEVEN_PORT_NAME         DIO_u8_PORTC
#define  Second_SEVEN_PORT_NAME        DIO_u8_PORTA


#endif
