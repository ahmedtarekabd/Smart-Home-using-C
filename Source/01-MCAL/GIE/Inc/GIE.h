/*
 * GIE.h
 *
 *  Created on: Sep 7, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_GIE_HEADER_GIE_H_
#define SOURCE_01_MCAL_GIE_HEADER_GIE_H_

#include "Std_Types.h"
#include "Bit_Math.h"

#define GIE_SREG	(*(u8*) 0x5f)

// i-bit is the Global Interrupt Enable bit
// According to Atmega32 data sheet
#define GIE_l_bit	7

void GIE_EnableGlobalInterrupt();
void GIE_DisableGlobalInterrupt();

#endif /* SOURCE_01_MCAL_GIE_HEADER_GIE_H_ */
