/*
 * EEPROM.h
 *
 *  Created on: Sep 25, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_EEPROM_INC_EEPROM_H_
#define SOURCE_02_ECUA_EEPROM_INC_EEPROM_H_

#include <string.h>
#include "Std_Types.h"
#include "TWI_interface.h"
#include "EEPROM_Defs.h"


void EEPROM_Init();

void EEPROM_WriteByte(u8 pageAddress, u8 dataAddress, u8 data);
u8 EEPROM_ReadByte(u8 pageAddress, u8 dataAddress);

void EEPROM_WriteString(u8 pageAddress, u8 dataAddress, u8* string);
void EEPROM_ReadString(u8 pageAddress, u8 dataAddress, u8* string, u8 size);

u16 EEPROM_Search(u8* string, u8 dataSize);
u8 EEPROM_SearchByAddress(u8* string, u8 dataSize, u8 dataAddress);

#endif /* SOURCE_02_ECUA_EEPROM_INC_EEPROM_H_ */
