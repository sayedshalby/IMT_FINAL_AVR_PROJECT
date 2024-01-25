 /******************************************************************************
 *
 * Module: APP
 *
 * File Name: main.c
 *
 * Description: Application file for ATMEGA32
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/

//#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Registers.h"
#include "Interrupts.h"
#include "keypad.h"
#include "DIO_Interface.h"
#include "i2c.h"
#include "external_eeprom.h"
#include "Lcd.h"
#include "buzzer.h"
#include "adc_interface.h"
#include "UART_interface.h"
#include "HDC_MOTOR.h"


/*********************************************************************************/
/* Function: check_pass
 * Input/outPut Parameters:
 * 	 INPUT : u8 *ptr_1 , u8 *ptr_2
 *
 * Returns: u8 (return status)
 * Description:	This Function used to check two array are the same or not.
 */
/*********************************************************************************/
u8 check_pass(u8 *ptr_1 , u8 *ptr_2){
	u8 state = 1;
	for(u8 i = 0 ; i < 4 ; i++){
		if(ptr_1[i] != ptr_2[i]){
			state = 0;
			break;
		}
	}
	return state;
}


/*********************************************************************************/
/* Function: EEPROM_u8CheckPass
 * Input/outPut Parameters:
 * 	 NO INPUT : 
 *
 * Returns: u8 (return status)
 * Description:	This Function used to Handle the password entered from user.
 */
/*********************************************************************************/
u8 EEPROM_u8CheckPass(void){
	u8 state = 0;
	u8 k = 0;
	u8 arr[4] = {0};
    u8 EEPROM_ARR[4] = {0};
	u8 key;
	u8 i;
	while(k != 3){
		k++;
		Lcd_ClearDisplay();
		Lcd_DisplayString("Enter your Pass : ");
		Lcd_SetCursorPosition(1 , 4);
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		while(key != 66){
			key = KeyPad_getPressedKey(); /* get the pressed key number */
			_delay_ms(300);
			if((key <= 9) && (key >= 0)){
				Lcd_DisplayNumber(key); /* display the pressed keypad switch */
				arr[i] = key;
				i++;
			}
		}
		
		if((i < 4) || (i > 4)){
			i = 0;
			Lcd_ClearDisplay();
			Lcd_DisplayString("enter 4 digit");
			_delay_ms(2000);
		}
		else{
			u8 x = 0;
			for (u8 j = 0 ; j < 4 ; j++)
			{
				EEPROM_readByte(0x0311+j , &x);
				EEPROM_ARR[j] = x;
				
			}
			state = check_pass(arr,EEPROM_ARR);
			if (state == 1)
			{
				return state;
				Lcd_ClearDisplay();
				Lcd_DisplayString("1-Open Door");
				Lcd_SetCursorPosition(1,0);
				Lcd_DisplayString("2-Change Pass");
			}
		     else if(state == 0){
					i = 0;
					Lcd_ClearDisplay();
					Lcd_DisplayString("Wrong Pass");
					state = 0;
					_delay_ms(1000);
				}		    
			
			}
			/*reset loop to start again*/
			k = 0;
			/*start buzzer*/
			Buzzer_on();
			_delay_ms(3000);
			/*stop buzzer*/
			Buzzer_off();
		}
	return state;
}

/*********************************************************************************/
/* Function: Enter_new_Pass
 * Input/outPut Parameters:
 * 	 NO INPUT : 
 *
 * Returns: u8 (return status)
 * Description:	This Function used to Creat new password.
 */
/*********************************************************************************/
u8 Enter_new_Pass(void){
	u8 key;
	u8 i = 0;
	u8 k = 0;
	u8 z = 0;
	u8 j = 0;
	u8 arr[4] = {0};
	u8 arr_2[4] = {0};
	u8 state = 0;
	while(k != 3){
		k++;
		Lcd_ClearDisplay();
		Lcd_DisplayString("Enter new Pass : ");
		Lcd_SetCursorPosition(1 , 4);
		key = KeyPad_getPressedKey(); /* get the pressed key number */
		while(key != 66){
			key = KeyPad_getPressedKey(); /* get the pressed key number */
			_delay_ms(300);
			if((key <= 9) && (key >= 0)){
				Lcd_DisplayNumber(key); /* display the pressed keypad switch */
				arr[i] = key;
				i++;
			}
		}
				
			if((i < 4) || (i > 4)){
				i = 0;
				Lcd_ClearDisplay();
				Lcd_DisplayString("enter 4 digit");
				_delay_ms(2000);
			}
			else
			{
			
				break;
			}
			state = 0;
		}
		
		
		
		while(z != 3){
			z++;
			Lcd_ClearDisplay();
			Lcd_DisplayString("Renter new Pass : ");
			Lcd_SetCursorPosition(1 , 4);
			key = KeyPad_getPressedKey(); /* get the pressed key number */
			while(key != 66){
				key = KeyPad_getPressedKey(); /* get the pressed key number */
				_delay_ms(300);
				if((key <= 9) && (key >= 0)){
					Lcd_DisplayNumber(key); /* display the pressed keypad switch */
					arr_2[j] = key;
					j++;
				}
			}
			
			if((j < 4) || (j > 4)){
				j = 0;
				Lcd_ClearDisplay();
				Lcd_DisplayString("enter 4 digit");
				state = 0;
				_delay_ms(2000);
			}
			else
			{
				state = check_pass(arr,arr_2);
				if (state == 1)
				{
					Lcd_ClearDisplay();
					Lcd_DisplayString("Pass Changed");
					z = 0;
					state = 1;
					_delay_ms(1000);
					for (u8 i = 0 ; i < 4 ; i++){
						EEPROM_writeByte(0x0311+i,arr_2[i]);
						_delay_ms(50);
					}
					break;
					//return;
				}
				else if(state == 0){
					j = 0;
				     Lcd_ClearDisplay();
				     Lcd_DisplayString("Wrong Pass");
					 state = 0;
					 _delay_ms(1000);
				}
				}
				
					
				}
		
				if(z >= 3){
						Buzzer_on();
						_delay_ms(5000);
						Buzzer_off();
						z = 0;
						state = 0;
				}
			return state;
			}
	
		
/*global variable */
u16 temp = 0; 
/*********************************************************************************/
/* Function: send_temp
 * Input/outPut Parameters:
 * 	 NO INPUT : void
 *
 * Returns: void
 * Description:	This Function used to send temp via UART using interrupt
 * and passed to function UARTTX_vidSetISR()
 */
/*********************************************************************************/
void send_temp(void)
{
	/*get adc reading*/
		temp = ADC_u16ReadingSync(0);
	/*mathematical equation to calculate temperature */
		temp = (temp*150*5)/(1023*1.5);
		/*send data via UART usig interrupt*/
	    UART_voidSendData_Asynch(temp);

}
/*static global variable*/
static volatile u8 ReadPassState = 5;
int main(void)
{
	/*local variable used to handle system start*/
	u8 flag = 0xFF; 
	//EEPROM_writeByte(0x0310,0xFF);
	/*local variable to get key pressed on keypad*/
	u8 key;
	/*local variable to store status of eeprom*/
	u8 x;
	/*initialized dc motor*/
	HDCMOTOR_voidInit();
	/*initialized bazzer*/
	Buzzer_init();
	/*initialized ADC*/
    ADC_voidInit();
	/*initialized UART*/
   UART_voidInit();
   
   UARTTX_vidSetISR(send_temp);
   /*Enable Global interrupt enable*/
   SET_BIT(SREG,SREG_I);
   /*configuration for lcd */
	Lcd_DisplayControlType c = {LCD_STATE_ON , LCD_STATE_OFF, LCD_STATE_OFF,LCD_LINES_2,LCD_FONT_5X7};

	/*initialized LCD*/
	Lcd_Init(&c);
	/*display string*/
	Lcd_DisplayString("Welcome......");
	/*blocking delay*/
	_delay_ms(1000);
	/*clear display*/
	Lcd_ClearDisplay();	
  while(1)
  {
	  /*check specific location in eeprom*/
	EEPROM_readByte(0x0310,&flag);
	  if ((ReadPassState == 0 )|| (ReadPassState == 5 && flag == 0xFF))
	  {
		  ReadPassState = Enter_new_Pass();
	  }
	else if(ReadPassState == 1 || flag == 1){
		   flag = 1;
		   /*write byte on eeprom*/
		   EEPROM_writeByte(0x0310,flag);
		   /*local variable store states of EEPROM_u8CheckPass()*/
		   x = EEPROM_u8CheckPass();
		  if (x == 1)
		  {
			  /*clear display*/
			  Lcd_ClearDisplay();
			  /*display string on LCD*/
			  Lcd_DisplayString("1-Open Door");
			  Lcd_SetCursorPosition(1,0);
			   /*display string on LCD*/
			  Lcd_DisplayString("2-Change Pass");
			  ReadPassState = 2;
				 
				 while((key != 1) || (key != 2)){
					 key = KeyPad_getPressedKey(); /* get the pressed key number */
					 _delay_ms(300);
					 if (key == 1)
					 {
						 Lcd_ClearDisplay();
						  /*display string on LCD*/
						 Lcd_DisplayString("Door is open");
						 /*start motor in clockwise*/
						 HDCMOTOR_voidStartClockWise();
						 _delay_ms(2000);
						 /*stop motor*/
						 HDCMOTOR_voidStop();
						 _delay_ms(1000);
						  Lcd_ClearDisplay();
						   /*display string on LCD*/
						  Lcd_DisplayString("Door is close");
						   /*start motor in Anti clockwise*/
						  HDCMOTOR_voidStartAntiClockWise();
						  _delay_ms(2000);
						  /*stop motor*/
						 HDCMOTOR_voidStop();
						 ReadPassState = 1;
						break;
					 }
					 else if (key == 2)
					 {
						  
						ReadPassState = 0;
						break;
					 }
				 } 
			  
			  
		  }
	  }
	  
	  
	   }
}









