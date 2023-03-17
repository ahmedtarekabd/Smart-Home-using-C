/*
 * UART.h
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_UART_INC_UART_H_
#define SOURCE_01_MCAL_UART_INC_UART_H_

#include "UART_Def.h"


void UART_Init(u32 baudrate);

u8 UART_Receive();
void UART_Transmit(u8 data);

void UART_SendString(u8* string);
void UART_ReciveString(u8* stringPtr, u8 size);


#endif /* SOURCE_01_MCAL_UART_INC_UART_H_ */
