/*
 * IEEPROM.h
 *
 *  Created on: Jul 2, 2023
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_IEEPROM_INC_IEEPROM_H_
#define SOURCE_01_MCAL_IEEPROM_INC_IEEPROM_H_

#include "Std_Types.h"
#include "Bit_Math.h"

void IEEPROM_Init();
void IEEPROM_Write(u16 uiAddress, u16 ucData);
u8 IEEPROM_Read(u16 uiAddress);

void IEEPROM_WriteString(u16 address, u8* string);
void IEEPROM_ReadString(u16 address, u8* string, u8 size);

#endif /* SOURCE_01_MCAL_IEEPROM_INC_IEEPROM_H_ */
