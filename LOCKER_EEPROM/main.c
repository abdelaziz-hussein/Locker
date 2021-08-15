/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */
#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "GIE_INT.h"
#include "LED_INT.h"
#include "LCD_INT.h"
#include "I2C_INT.h"
#include "LOCKER_FUNS.h"
int main ()
{
	DIO_VoidInit();
	LCD_voidInit();
	LED_VoidInit();
	GIE_voidEnable();
	I2C_voidInit();
	LCD_voidWriteString("Welcome ");
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString("prss 0 Ad / 1G ");
	while (1)
	{
	if (DIO_U8GetPin(DIO_PIN_24)==High)
		{
		LCD_voidClrScreen();
		LCD_voidWriteString("enter old pass");
		_delay_ms(1000);
		LOCKER_Check_Pass();
		LCD_voidClrScreen();
		LCD_voidWriteString("enter New pass");
		_delay_ms(1000);
		LOCKER_write_Pass();
		LCD_voidClrScreen();
				LCD_voidWriteString("enter conf pass");
				_delay_ms(1000);
				LOCKER_Check_Pass();
				LCD_voidGoToXY(1,0);
				 LCD_voidWriteString("pass confirmed ");
				 _delay_ms(500);
				LCD_voidClrScreen();
				LCD_voidWriteString("Welcome ");
						LCD_voidGoToXY(1,0);
						LCD_voidWriteString("prss 0 Ad / 1G ");
		}
	else if (DIO_U8GetPin(DIO_PIN_25)==High)
	{   LCD_voidClrScreen();
	    LCD_voidWriteString("enter the pass");
	    _delay_ms(1000);
		LOCKER_Check_Pass();
		 LCD_voidGoToXY(1,0);
		 LCD_voidWriteString("Opening Locker ");
		 _delay_ms(500);
		LCD_voidClrScreen();
		LCD_voidWriteString("Welcome ");
		LCD_voidGoToXY(1,0);
		LCD_voidWriteString("prss 0 Ad / 1G ");
	}
	}


}

