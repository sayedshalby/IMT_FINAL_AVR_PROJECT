 /******************************************************************************
 *
 * Module: I2C(TWI)
 *
 * File Name: i2c.h
 *
 * Description: Header file for the I2C(TWI) AVR driver
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/ 


#ifndef I2C_H_
#define I2C_H_



/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

//TWCR Register 
#define  TWIE_BIT     0
#define  TWEN_BIT     2
#define  TWWC_BIT     3
#define  TWSTO_BIT    4
#define  TWSTA_BIT    5
#define  TWEA_BIT     6
#define  TWINT_BIT    7


#define STATUS_MASK 0xF8

/* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)
General Call Recognition: Off */
#define MY_ADDRESS 0x02       //0b00000010
//100KZ
#define BIT_RATE  0x08

/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start 
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*********************************************************************************/
/* Function: TWI_init
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to intialized TWI.
 */
/*********************************************************************************/
void TWI_init(void);

/*********************************************************************************/
/* Function: TWI_start
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to start TWI
 */
/*********************************************************************************/
void TWI_start(void);


/*********************************************************************************/
/* Function: TWI_stop
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to stop TWI.
 */
/*********************************************************************************/
void TWI_stop(void);

/*********************************************************************************/
/* Function: TWI_write
 * Input/outPut Parameters:
 * 			 INPUT : data
 *
 * Returns:  void
 * Description:	This Function used to write data on TWI Register.
 */
/*********************************************************************************/
void TWI_write(u8 data);

/*********************************************************************************/
/* Function: TWI_readWithACK
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to Read data from TWI with ACK.
 */
/*********************************************************************************/
u8 TWI_readWithACK(void); //read with send Ack



/*********************************************************************************/
/* Function: TWI_readWithNACK
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to Read data from TWI with NACK
 */
/*********************************************************************************/
u8 TWI_readWithNACK(void); //read without send Ack


/*********************************************************************************/
/* Function: TWI_getStatus
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to return status of TWI.
 */
/*********************************************************************************/
u8 TWI_getStatus(void);


#endif /* I2C_H_ */
