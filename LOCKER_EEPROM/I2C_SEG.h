/*
 * I2C_SEG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */

#ifndef I2C_SEG_H_
#define I2C_SEG_H_

#define TWBR *((volatile u8*) 0x20)
#define TWCR *((volatile u8*) 0x56)
#define I2C_IntrFlag_BIT     7
#define I2C_AckEnable_Bit    6
#define I2C_StartCond_Bit    5 // how to clear it after transmit
#define I2C_StopCond_Bit     4
#define I2c_Enable_Bit		 2
#define I2C_IntEnable_Bit    0

#define TWSR *((volatile u8*) 0x21)
#define TWDR *((volatile u8*) 0x23)
#define TWAR *((volatile u8*) 0x22)
#define TWGCE 				 0




#endif /* I2C_SEG_H_ */
