/*
 * I2C_INT.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_
void I2C_voidInit(void);
void I2C_voidClrFlag(void);
#if I2C_Mode==I2C_Master
void I2C_voidMasterWrite (u8 SLA , u8 Data);
u8 I2C_U8MasterRead (u8 SLA);
u8 I2C_U8MasterEEPROMRead (u16 Madress);
u8 I2C_voidMasterEEPROMWrite (u16 MAdress , u8 Data);

#elif I2C_Mode==I2C_Slave
u8 I2C_U8SlaveRead (void);
void I2C_voidSlaveWrite (u8 Data);



#endif
#endif /* I2C_INT_H_ */
