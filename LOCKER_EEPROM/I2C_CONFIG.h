/*
 * I2C_CONFIG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */
#include "I2C_SEG.h"

#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_
//master or slave
#define I2C_Mode     I2C_Master
//
// salve Address SLA from 1 to 128
#define I2C_OwnSLA  1
/* SCL frequency = CPU Clock frequency/(16 + 2(TWBR) * 4^TWPS)
 * note TWBR should be 10 or higher if the TWI operates in Master mode.
*/
#define I2C_Boudrate		 5
#define I2C_Prescaller 	I2C_1xPrescaller
//write or read
#define I2C_Write    0
#define I2C_Read	 1
//general call
#define I2C_generalCall		GeneralCallDisable
// state codes of Master transmit
#define I2C_MT_TWSR_Start 0x08
#define I2C_MT_TWSR_ReStart 0x10
#define I2C_MT_TWSR_SLA_Wok_ACKok 0x18
#define I2C_MT_TWSR_SLA_Wok_ACKnot 0x20
#define I2C_MT_TWSR_Data_Wok_ACKok 0x28
#define I2C_MT_TWSR_Data_Wok_ACKnot 0x30
#define I2C_MT_TWSR_arbittrationLost 0x38
// state codes of Master receive
#define I2C_MR_TWSR_Start 0x08
#define I2C_MR_TWSR_ReStart 0x10
#define I2C_MR_TWSR_arbittrationLost 0x38
#define I2C_MR_TWSR_SLA_Rok_ACKok 0x40
#define I2C_MR_TWSR_SLA_Rok_ACKnot 0x48
#define I2C_MR_TWSR_Data_Rok_ACKok 0x50
#define I2C_MR_TWSR_Data_Rok_ACKnot 0x58
// state codes of Slave receive
#define I2C_SR_TWSR_SLA_Wok_ACKok 0x60
#define I2C_SR_TWSR_arbittrationLost 0x68

#define I2C_SR_TWSR_Data_Rok_ACKok 0x90
#define I2C_SR_TWSR_Data_Rok_ACKnot 0x98


// EEPROM
#define  I2C_EEPROM_SLA_W 0b10100000
#define  I2C_EEPROM_SLA_R 0b10100001
#endif /* I2C_CONFIG_H_ */
