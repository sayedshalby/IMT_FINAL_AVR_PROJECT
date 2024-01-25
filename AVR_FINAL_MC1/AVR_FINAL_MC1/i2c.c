 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.c
 *
 * Description: Source file for the I2C(TWI) AVR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Registers.h"
#include "Interrupts.h"
#include "i2c.h"

/*********************************************************************************/
/* Function: TWI_init
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to intialized TWI.
 */
/*********************************************************************************/
void TWI_init(void)
{
    /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
    TWBR = BIT_RATE;
	TWSR = 0x00;
	
    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
       General Call Recognition: Off */
    TWAR = MY_ADDRESS; // my address = 0x01 :) 
	
    TWCR = (1<<TWEN_BIT); /* enable TWI */
}

/*********************************************************************************/
/* Function: TWI_start
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to start TWI
 */
/*********************************************************************************/
void TWI_start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT_BIT) | (1 << TWSTA_BIT) | (1 << TWEN_BIT);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT_BIT));
}
/*********************************************************************************/
/* Function: TWI_stop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to stop TWI.
 */
/*********************************************************************************/
void TWI_stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT_BIT) | (1 << TWSTO_BIT) | (1 << TWEN_BIT);
}


/*********************************************************************************/
/* Function: TWI_write
 * Input/outPut Parameters:
 * 			 INPUT : data
 *
 * Returns:  void
 * Description:	This Function used to write data on TWI Register.
 */
/*********************************************************************************/
void TWI_write(u8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT_BIT) | (1 << TWEN_BIT);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT_BIT));
}


/*********************************************************************************/
/* Function: TWI_readWithACK
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to Read data from TWI with ACK.
 */
/*********************************************************************************/
u8 TWI_readWithACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT_BIT) | (1 << TWEN_BIT) | (1 << TWEA_BIT);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT_BIT));
    /* Read Data */
    return TWDR;
}

/*********************************************************************************/
/* Function: TWI_readWithNACK
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to Read data from TWI with NACK
 */
/*********************************************************************************/

u8 TWI_readWithNACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT_BIT) | (1 << TWEN_BIT);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT_BIT));
    /* Read Data */
    return TWDR;
}


/*********************************************************************************/
/* Function: TWI_getStatus
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to return status of TWI.
 */
/*********************************************************************************/
u8 TWI_getStatus(void)
{
    u8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & STATUS_MASK;
    return status;
}
