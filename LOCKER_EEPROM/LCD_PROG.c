/*
 * LCD_PROG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */
#include "stdio.h"
#include "avr/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"

#include "LCD_PRIV.h"
#include "LCD_CONFIG.h"
#include "LCD_INT.h"

#if (LCD_MODE== _8_PINS)




#elif (LCD_MODE== _4_PINS)

void LCD_voidEnable (void)
{
	DIO_VoidSetPin(LCD_Enable_PIN,High);
	_delay_ms(1);
	DIO_VoidSetPin(LCD_Enable_PIN,Low);
	_delay_ms(50);
}
	void LCD_voidInit(void)
{ _delay_ms(50);
//LCD_voidWriteCommend(0b00100000);
LCD_voidWriteCommend(  CONCBIT(0,0,1,0,LCD_NoLines,LCD_FONT,0,0)  );
_delay_ms(1);
//LCD_voidWriteCommend(0);
LCD_voidWriteCommend( CONCBIT(0,0,0,0,1,LCD_DISPLAY_MODE,LCD_CURSOR_MODE,LCD_BLINK_MODE) );
_delay_ms(1);
//LCD_voidWriteCommend(0);
LCD_voidWriteCommend(0b00000001);
_delay_ms(3);
//LCD_voidWriteCommend(0);
LCD_voidWriteCommend(0b00000110);

		/*LCD_voidWriteCommend(0x03);
		_delay_ms(5);
		LCD_voidWriteCommend(0x03);
		_delay_ms(11);
		LCD_voidWriteCommend(0x03);
		LCD_voidWriteCommend(0x02);
		LCD_voidWriteCommend(0x08);
		LCD_voidWriteCommend(0x00);
		LCD_voidWriteCommend(0x0D);
		LCD_voidWriteCommend(0x01);
		_delay_ms(100);
		LCD_voidWriteCommend(0x00);
		LCD_voidWriteCommend(0x06);*/
}
void LCD_voidWriteData(u8 Data)
{DIO_VoidSetPin(LCD_RS_PIN,High);
DIO_VoidSetPin(LCD_RW_PIN,Low);
DIO_VoidSetPin(LCD_DataPin_7,GETBIT(Data,7));
DIO_VoidSetPin(LCD_DataPin_6,GETBIT(Data,6));
DIO_VoidSetPin(LCD_DataPin_5,GETBIT(Data,5));
DIO_VoidSetPin(LCD_DataPin_4,GETBIT(Data,4));

LCD_voidEnable();

DIO_VoidSetPin(LCD_DataPin_7,GETBIT(Data,3));
DIO_VoidSetPin(LCD_DataPin_6,GETBIT(Data,2));
DIO_VoidSetPin(LCD_DataPin_5,GETBIT(Data,1));
DIO_VoidSetPin(LCD_DataPin_4,GETBIT(Data,0));
LCD_voidEnable();

}
void LCD_voidWriteCommend (u8 commend)
{DIO_VoidSetPin(LCD_RS_PIN,Low);
DIO_VoidSetPin(LCD_RW_PIN,Low);
DIO_VoidSetPin(LCD_DataPin_7,GETBIT(commend,7));
DIO_VoidSetPin(LCD_DataPin_6,GETBIT(commend,6));
DIO_VoidSetPin(LCD_DataPin_5,GETBIT(commend,5));
DIO_VoidSetPin(LCD_DataPin_4,GETBIT(commend,4));

LCD_voidEnable();

DIO_VoidSetPin(LCD_DataPin_7,GETBIT(commend,3));
DIO_VoidSetPin(LCD_DataPin_6,GETBIT(commend,2));
DIO_VoidSetPin(LCD_DataPin_5,GETBIT(commend,1));
DIO_VoidSetPin(LCD_DataPin_4,GETBIT(commend,0));

LCD_voidEnable();
}
void LCD_voidWriteString(u8 *ptrs)
{u8 i=0;
while (ptrs[i]!= '\0' )
  { LCD_voidWriteData(ptrs[i]);
	i++;
  }
}
void LCD_voidGoToXY (u8 X, u8 Y)
{if (X==0)
   {LCD_voidWriteCommend((0b10000000)|(Y));

   }
else if (X==1)
	{
	LCD_voidWriteCommend((0b11000000)|(Y));
	}
}
void LCD_voidClrScreen(void)
{
LCD_voidWriteCommend(0b00000001);
}
void LCD_voidReturnHome(void)
{
	LCD_voidWriteCommend(0b00000010);

}
void LCD_voidWriteVariable(u16 number)
{	u8 sum[10],j=0;
		for (u16 i=number;i>0;i=i/10)
		{
			sum[j]=i%10;
			j++;
		}
		for (s8 k=j-1;k>=0;k=k-1)// j-1 alshan akher rakam sum [j] hata5doh we ba3daha betzawed j++ fa keda ha access rakam 3ashwa2y
		{
			LCD_voidWriteData(((sum[k])+48));

		}


}
/*void LCD_voidPutn (u16 n)
{u8 sum[10],j=0;
	for (u16 i=n;i>1;i=i/10)
	{
		sum[j]=i%10;
		j++;
	}
	for (s8 k=j-1;k>=0;k=k-1)// j-1 alshan akher rakam sum [j] hata5doh we ba3daha betzawed j++ fa keda ha access rakam 3ashwa2y
	{
		LCD_voidWriteData((sum[k]+48));

	}

	/*u8 hunds,rem,tens,ones ;
	hunds=n/100 ;
	rem=n%100 ;
	tens=rem/10 ;
	ones=rem%10 ;
	LCD_voidWriteData(hunds+48);
	LCD_voidWriteData(tens+48);
	LCD_voidWriteData(ones+48);*/


#endif

