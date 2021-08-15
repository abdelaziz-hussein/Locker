/*
 * I2C_PROG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: abdelaziz
 */
#include "Stdio.h"
#include "util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INT.h"
#include "GIE_INT.h"
#include "I2C_SEG.h"
#include "I2C_PRIV.h"
#include "I2C_CONFIG.h"
#include "I2C_INT.h"
void I2C_voidInit(void)
{
	TWCR=0;
	TWBR=I2C_Boudrate; // boudrate
	TWSR=0;
	//TWSR |=  I2C_Prescaller ; // prescaller
	//SETBIT(TWCR,I2C_AckEnable_Bit);// enable ack
	SETBIT(TWCR,I2C_IntrFlag_BIT); // clear Flag
//	CLRBIT(TWCR,I2C_IntEnable_Bit); // intr disable
	//----------------------------------------------
#if  I2C_generalCall == GeneralCallEnable // general call enable or disable
	SETBIT(TWAR,TWGCE);
#elif  I2C_generalCall == GeneralCallDisable
	CLRBIT(TWAR,TWGCE);
#endif
	//------------------------------------------
	// OWN SLA Address Set

//	TWAR |= (I2C_OwnSLA<1);
	//-----------
SETBIT(TWCR,I2c_Enable_Bit);//enable I2C
}

void I2C_voidClrFlag(void)
{
	SETBIT(TWCR,I2C_IntrFlag_BIT);
}
void I2C_voidMasterWrite (u8 SLA , u8 Data)
{// start condition
	I2C_voidClrFlag();
SETBIT(TWCR,I2C_StartCond_Bit);
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_Start)
	{
	//// error();
	}
	CLRBIT(TWCR,I2C_StartCond_Bit);// clear start bit
	// slave address select and write
TWDR=((SLA<<1)|I2C_Write);
I2C_voidClrFlag();
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_SLA_Wok_ACKok)
	{
	// error();
	}
	//sending data
TWDR=Data;
I2C_voidClrFlag();
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{
	// error();
	}
	//stop condition
	I2C_voidClrFlag();
	SETBIT(TWCR,I2C_StopCond_Bit);
_delay_ms(12);
}
u8 I2C_U8MasterRead (u8 SLA)
{u8 Data;
	// start condition
	I2C_voidClrFlag();
SETBIT(TWCR,I2C_StartCond_Bit);
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_Start)
	{
	// error();
	}
	CLRBIT(TWCR,I2C_StartCond_Bit);// clear start bit
	// slave address select and Read
	TWDR=((SLA<<1)|I2C_Read);
	I2C_voidClrFlag();
	while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
		if ((TWSR & 0xF8) != I2C_MR_TWSR_SLA_Rok_ACKok)
		{
		// error();
		}
		// Read Data
		I2C_voidClrFlag();
			while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
		Data=TWDR;
		if ((TWSR & 0xF8) != I2C_MR_TWSR_Data_Rok_ACKok)
				{
				// error();
				}
		//stop condition
			I2C_voidClrFlag();
			SETBIT(TWCR,I2C_StopCond_Bit);
 return Data;
}

u8 I2C_U8SlaveRead (void)
{ u8 Data;
	I2C_voidClrFlag();
	CLRBIT(TWCR,I2C_StartCond_Bit);   // clear start bit
	CLRBIT(TWCR,I2C_StopCond_Bit);    // clear stop  bit
//--------------------------------------------------------
	while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_SR_TWSR_SLA_Wok_ACKok)
					{
					// error();
					}
	while ((TWSR & 0xF8) != I2C_SR_TWSR_Data_Rok_ACKok);
	Data=TWDR;
	while ((TWSR & 0xF8) != I2C_SR_TWSR_Data_Rok_ACKok);
return 0;



}
void I2C_voidSlaveWrite (u8 Data)
{

}
// EEPROM communication

u8 I2C_voidMasterEEPROMWrite (u16 MAdress , u8 Data)
{// start condition
	do {
	SETBIT(TWCR,I2c_Enable_Bit);

SETBIT(TWCR,I2C_StartCond_Bit);
I2C_voidClrFlag();
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);

	if ((TWSR & 0xF8) != I2C_MT_TWSR_Start)
	{return 1;
	// error();
	}
	//CLRBIT(TWCR,I2C_StartCond_Bit);// clear start bit

	// slave address select and write
TWDR=I2C_EEPROM_SLA_W;
//SETBIT(TWCR,I2c_Enable_Bit);
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_SLA_Wok_ACKok)
	{return 2;
	// error();
	}
	}while((TWSR & 0xF8) !=I2C_MT_TWSR_SLA_Wok_ACKok);
// send memory address

TWDR=(MAdress>>8);
//SETBIT(TWCR,I2c_Enable_Bit);
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{return 8;
	// error();
	}
//while (DIO_U8GetPin(DIO_PIN_17)==Low);
TWDR=(MAdress);
//SETBIT(TWCR,I2c_Enable_Bit);

//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{return 3;
	// error();
	}
	//sending data
//SETBIT(TWCR,I2c_Enable_Bit);
TWDR=Data;
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
//while (DIO_U8GetPin(DIO_PIN_17)==Low);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{return 4;
	// error();
	}

	//stop condition
	//SETBIT(TWCR,I2c_Enable_Bit);
	//I2C_voidClrFlag();
	//SETBIT(TWCR,I2C_StopCond_Bit);
	TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit)|(1<<I2C_StopCond_Bit);

	while (GETBIT(TWCR,I2C_StopCond_Bit)==0);
	_delay_ms(12);
	return 17;
}
u8 I2C_U8MasterEEPROMRead (u16 Madress)
{u8 data1;
u8 state=35;
data1=30;
// start condition
do {SETBIT(TWCR,I2c_Enable_Bit);
	I2C_voidClrFlag();
SETBIT(TWCR,I2C_StartCond_Bit);
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);

	if ((TWSR & 0xF8) != I2C_MT_TWSR_Start)
	{ state =1;
	// error();
	}

	//CLRBIT(TWCR,I2C_StartCond_Bit);// clear start bit
	// slave address select and write
//	SETBIT(TWCR,I2c_Enable_Bit);
	TWDR=I2C_EEPROM_SLA_W;
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	if ((TWSR & 0xF8) != I2C_MT_TWSR_SLA_Wok_ACKok)
	{ state = 2;
	// error();
	}
} while ((TWSR & 0xF8) != I2C_MT_TWSR_SLA_Wok_ACKok);

// send memory address

TWDR=(Madress>>8);
SETBIT(TWCR,I2c_Enable_Bit);
I2C_voidClrFlag();
while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{return 8;
	// error();
	}
//	SETBIT(TWCR,I2c_Enable_Bit);
TWDR=Madress;
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
//while (DIO_U8GetPin(DIO_PIN_17)==Low);
if ((TWSR & 0xF8) != I2C_MT_TWSR_Data_Wok_ACKok)
	{state =3;
	// error();
	}

// repeated start condition
//SETBIT(TWCR,I2c_Enable_Bit);
//I2C_voidClrFlag();
//SETBIT(TWCR,I2C_StartCond_Bit);
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit)|(1<<I2C_StartCond_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);

	if ((TWSR & 0xF8) != I2C_MT_TWSR_ReStart)
	{
		state =4;
	}

	//CLRBIT(TWCR,I2C_StartCond_Bit);// clear start bit
	// slave address select and read
//	SETBIT(TWCR,I2c_Enable_Bit);
TWDR=I2C_EEPROM_SLA_R;
//I2C_voidClrFlag();
TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
//TWDR=8;
	if ((TWSR & 0xF8) != I2C_MR_TWSR_SLA_Rok_ACKok)
	{state =5;
		//DIO_VoidSetPin(DIO_PIN_31,High);
	// error();
	}

		// Read Data
//SETBIT(TWCR,I2c_Enable_Bit);
//	I2C_voidClrFlag();
	TWCR=(1<<I2C_IntrFlag_BIT)|(1<<I2c_Enable_Bit);

		while (GETBIT(TWCR,I2C_IntrFlag_BIT)==0);
	//	while (DIO_U8GetPin(DIO_PIN_17)==Low);
		//*ptr=TWDR;
		if ((TWSR & 0xF8) != I2C_MR_TWSR_Data_Rok_ACKnot)
			{state = 6;
				//DIO_VoidSetPin(DIO_PIN_31,High);
			// error();
			}
		data1 = TWDR;

		//*ptr=4;


		//stop condition

		SETBIT(TWCR,I2c_Enable_Bit);
			I2C_voidClrFlag();
			SETBIT(TWCR,I2C_StopCond_Bit);
			while (GETBIT(TWCR,I2C_StopCond_Bit)==0);

			return data1;

}

