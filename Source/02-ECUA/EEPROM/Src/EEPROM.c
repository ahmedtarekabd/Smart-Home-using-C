/*
 * EEPROM.c
 *
 *  Created on: Sep 25, 2022
 *      Author: ahmed
 */

#include "EEPROM.h"
#include <util/delay.h>
#include "Led.h"
#include "LCD.h"


void EEPROM_Init()
{

	TWI_initMaster();
	_delay_ms(1000);

}

void EEPROM_WriteByte(u8 pageAddress, u8 dataAddress, u8 data)
{

	LCD_displayChar('S');
	TWI_sendStartCondition();
	TWI_sendSlaveAddwithWrite( (0xA0 >> 1) | pageAddress);
	TWI_sendMasterDataByte(dataAddress);
	TWI_sendMasterDataByte(data);
	TWI_sendStopCondition();
	LCD_displayChar('E');

	// In order to be able to use ReadByte function right after this function
	_delay_ms(5);

}

u8 EEPROM_ReadByte(u8 pageAddress, u8 dataAddress)
{

	u8 data = 0;

	LCD_displayChar('S');
	TWI_sendStartCondition();
	LCD_displayChar('E');
	TWI_sendSlaveAddwithWrite( (0xA0 >> 1) | pageAddress);
	TWI_sendMasterDataByte(dataAddress);
	TWI_sendRepStartCondition();
	TWI_sendSlaveAddwithRead( (0xA0 >> 1) | pageAddress);
	TWI_readMasterDataByte(&data);
	TWI_sendStopCondition();

	// In order to be able to use ReadByte function right after this function
	_delay_ms(5);

	return data;

}

void EEPROM_WriteString(u8 pageAddress, u8 dataAddress, u8* string)
{

	for (u8* ptr = string; *ptr != '\0'; ptr++)
	{

		EEPROM_WriteByte(pageAddress, dataAddress, *ptr);
		dataAddress++;

	}

}

void EEPROM_ReadString(u8 pageAddress, u8 dataAddress, u8* string, u8 size)
{

	for (u8 i = 0; i < size - 1; i++)
	{

		string[i] = EEPROM_ReadByte(pageAddress, dataAddress);
//		LCD_displayInt(i);
		dataAddress++;

	}

	string[size - 1] = '\0';

}

u16 EEPROM_Search(u8* string, u8 dataSize)
{


	// Page 1 contains Memory details
	u8 pageAddress = EEPROM_PAGE2;
	u8 tmp[dataSize];

	for (u8 i = pageAddress; i < MAX_NUM_OF_PAGES; i++)
	{

		for (u8 j = 0; j < MAX_NUM_OF_BYTES; j += dataSize)
		{

			EEPROM_ReadString(i, j, tmp, dataSize);

			if ( strcmp(string, tmp) == 0 )
			{
				// Page Address | Byte Address
				return  ( i << 8 | j);
			}

		}
	}

	return 0;

}
