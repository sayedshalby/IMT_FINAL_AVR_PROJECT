 /******************************************************************************
 *
 * Module: External EEPROM
 *
 * File Name: external_eeprom.h
 *
 * Description: Header file for the External EEPROM Memory
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
*******************************************************************************/

/*********************************************************************************/
/* Function: EEPROM_init
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized EEPROM.
 */
/*********************************************************************************/
void EEPROM_init(void);


/*********************************************************************************/
/* Function: EEPROM_writeByte
 * Input/outPut Parameters:
 * 			 INPUT : u16addr , u8data
 *
 * Returns:  u8  (to return status)
 * Description:	This Function used to write byte on EEPROM.
 */
/*********************************************************************************/
u8 EEPROM_writeByte(u16 u16addr,u8 u8data);


/*********************************************************************************/
/* Function: EEPROM_readByte
 * Input/outPut Parameters:
 * 			NO INPUT : u16addr , *u8data
 *
 * Returns:  u8 (return status)
 * Description:	This Function used to read byte on EEPROM.
 */
/*********************************************************************************/
u8 EEPROM_readByte(u16 u16addr,u8 *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */
