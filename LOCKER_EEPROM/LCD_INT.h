/*
 * LCD_INT.h
 *
 *  Created on: 6\5\2019
 *      Author: abdelaziz
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
void LCD_voidInit(void);
void LCD_voidWriteData(u8 Data);
void LCD_voidWriteCommend (u8 commend);
void LCD_voidWriteString(u8 *ptrs);
void LCD_voidGoToXY (u8 X, u8 Y);
void LCD_voidClrScreen(void);
void LCD_voidReturnHome(void);
void LCD_voidEnable (void);
void LCD_voidWriteVariable(u16 number);
//void LCD_voidPutn(u16 n);

#define LCD_MODE _4_PINS
#define LCD_DISPLAY_MODE Display_On
#define LCD_CURSOR_MODE Cursor_On
#define LCD_BLINK_MODE Blink_off
#define LCD_NoLines TWO_LINES
#define LCD_FONT _5in7Dots

#endif /* LCD_INT_H_ */
