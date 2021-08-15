/*
 * LOCKER_FUNS.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */

#include "LOCKER_FUNS.h"
#include "STD_TYPES.h"
#include "util/delay.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "GIE_INT.h"
#include "LED_INT.h"
#include "LCD_INT.h"
#include "I2C_INT.h"
void LOCKER_write_Pass (void)
{
	u8 flagP=0;
			u8 x =1;
			//LCD_voidClrScreen();
			//LCD_voidWriteString("write new Pass ");

		//_delay_ms(1000);
		LCD_voidClrScreen();
			LCD_voidWriteString("3D 0>+ 1>- 2>ok ");
			LCD_voidGoToXY(1,0);
			LCD_voidWriteVariable(x);
	while (flagP!=3)
	{if (DIO_U8GetPin(DIO_PIN_24)==High)
			{x++;
				_delay_ms(50);
				LCD_voidGoToXY(1,flagP);
				LCD_voidWriteVariable(x);

				}
			else if (DIO_U8GetPin(DIO_PIN_25)==High)
						{x--;
						_delay_ms(50);
						LCD_voidGoToXY(1,flagP);
						LCD_voidWriteVariable(x);
						}
			else if (DIO_U8GetPin(DIO_PIN_26)==High)
						{

						I2C_voidMasterEEPROMWrite((u16)flagP,x);
						_delay_ms(50);
						flagP++;
						if (flagP!=3)
						{
						x=1;
						LCD_voidGoToXY(1,flagP);
						LCD_voidWriteVariable(x);
						}
						}
			if (flagP==3)
			{
				LCD_voidClrScreen();
				LCD_voidWriteString("write done");
				_delay_ms(1000);

			}
		}
}


void LOCKER_Check_Pass (void)
{u8 error =1;
	u8 flagP=0;
	u8 x =1;
	u8 arr[3];

		LCD_voidClrScreen();
			LCD_voidWriteString("3D 0>+ 1>- 2>ok ");
			LCD_voidGoToXY(1,0);
			LCD_voidWriteVariable(x);
	while (flagP!=3)
	{if (DIO_U8GetPin(DIO_PIN_24)==High)
			{x++;
				_delay_ms(50);
				LCD_voidGoToXY(1,flagP);
				LCD_voidWriteVariable(x);

				}
			else if (DIO_U8GetPin(DIO_PIN_25)==High)
						{x--;
						_delay_ms(50);
						LCD_voidGoToXY(1,flagP);
						LCD_voidWriteVariable(x);
						}
			else if (DIO_U8GetPin(DIO_PIN_26)==High)
						{arr[flagP]=x;

						//y=I2C_U8MasterEEPROMRead((u16)flagP);
					//	_delay_ms(50);
						flagP++;

						if ((flagP!=3))
						{
						x=1;
						LCD_voidGoToXY(1,flagP);
						LCD_voidWriteVariable(x);
						}
						}
					/*	else if (y!=x)
						{
							LCD_voidClrScreen();
							LCD_voidWriteString("wrong pass ");
							LCD_voidGoToXY(1,0);
							LCD_voidWriteString("Try No. ");
							error++;
							LCD_voidWriteVariable(error);
							_delay_ms(1000);
										flagP=0;
										 x =1;
										LCD_voidClrScreen();
										LCD_voidWriteString("try again ");
										LCD_voidGoToXY(1,0);
										LCD_voidWriteString("write Pass(adm) ");
										//LCD_voidGoToXY(1,0);

									_delay_ms(1000);
									LCD_voidClrScreen();
										LCD_voidWriteString("3D 0>+ 1>- 2>ok ");
										LCD_voidGoToXY(1,0);
										LCD_voidWriteVariable(x);

						}*/
						//}
			      if (flagP==3) // start check
			{	for (u8 i=0;i<3;i++)
				{	if (arr[i]!=I2C_U8MasterEEPROMRead((u16)i))
					{         LCD_voidClrScreen();
							LCD_voidWriteString("wrong pass ");
							LCD_voidGoToXY(1,0);
							LCD_voidWriteString("Try No. ");

							LCD_voidWriteVariable(error);
							error++;
							_delay_ms(1000);

							flagP=0;
						    x =1;
						    if (error!=4)//to print try again when tries <= 3
						    {
							LCD_voidClrScreen();
				        	LCD_voidWriteString("try again ");
				     		LCD_voidGoToXY(1,0);
				     		LCD_voidWriteString("write Pass ");

						_delay_ms(1000);
						LCD_voidClrScreen();
						LCD_voidWriteString("3D 0>+ 1>- 2>ok ");
						LCD_voidGoToXY(1,0);
						LCD_voidWriteVariable(x);
						    }//to print try again when tries <= 3

						break;
					}//end if
				else {LCD_voidGoToXY(1,i+1);}

				}//end for
			if (error==4)
			{u8 v =1;
				LCD_voidClrScreen();
				LCD_voidWriteString("Block 10 SECs ");

				while ( v!=11)
				{LCD_voidGoToXY(1,4);
				_delay_ms(1000);
				LCD_voidWriteVariable(v);
				v++;
				}
				error=1;
				flagP=0;
										    x =1;
							LCD_voidClrScreen();
		       	LCD_voidWriteString("try again ");
				LCD_voidGoToXY(1,0);
	   		LCD_voidWriteString("write Pass ");
																			//LCD_voidGoToXY(1,0);
					_delay_ms(1000);
				LCD_voidClrScreen();
			  LCD_voidWriteString("3D 0>+ 1>- 2>ok ");
					LCD_voidGoToXY(1,0);
					LCD_voidWriteVariable(x);

			}//endif error
			else {}//else if error
			}//end if flagp=3 start of check pass
			      else {} //if flagp=3 start of check pass
		}// end of while falgp!=3
	 LCD_voidClrScreen();
	 LCD_voidWriteString("Pass Correct");

	 for (u8 j=0;j<3;j++)
	 {LED_VoidOn(LED_0);
	 LED_VoidOn(LED_1);
	 LED_VoidOn(LED_2);
	 _delay_ms(500);
	 LED_VoidOff(LED_0);
	 LED_VoidOff(LED_1);
	 LED_VoidOff(LED_2);
	 _delay_ms(500);

	 }

}// end of function
