/*
 * IEEPROM.c
 *
 *  Created on: Jul 2, 2023
 *      Author: ahmed
 */

#include "IEEPROM.h"
#include <util/delay.h>
#include <avr/eeprom.h>
#include "GIE.h"

#define EECR	(* (u8*) 0x3c)
#define EEDR	(* (u8*) 0x3d)
#define EEARH	(* (u8*) 0x3f)
#define EEARL	(* (u8*) 0x3e)
#define SPMCR	(* (u8*) 0x57)

#define EEMWE	2
#define EEWE	1
#define EERE	0
#define SPMEN	0

void IEEPROM_Init()
{

	GIE_DisableGlobalInterrupt();
	EECR = 0;

}

void IEEPROM_Write(u16 uiAddress, u16 ucData)
{

	eeprom_write_byte(uiAddress, ucData);

}

u8 IEEPROM_Read(u16 uiAddress)
{

	return eeprom_read_byte(uiAddress);

}

void IEEPROM_WriteString(u16 address, u8* string)
{

	for (u8* ptr = string; *ptr != '\0'; ptr++)
	{

		eeprom_write_byte(address, *ptr);
		address++;

	}
	eeprom_write_byte(address, '\0');

}

void IEEPROM_ReadString(u16 address, u8* string, u8 size)
{

	for (u8 i = 0; i < size - 1; i++)
	{

		string[i] = eeprom_read_byte(address);
		address++;

	}

	string[size - 1] = '\0';

}
