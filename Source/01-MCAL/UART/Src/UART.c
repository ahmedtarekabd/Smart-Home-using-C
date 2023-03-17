/*
 * UART.c
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmed
 */

#include "UART.h"
#include "Led.h"

void UART_Init(u32 baudrate)
{

	// Enable Tx, Rx
	UART_UCSRB_REG |= 3 << 3;

	// Set baudrate
	u32 ubrr = ( 16000000UL / (16 * baudrate) - 1);
	UART_UBRRH_REG |= ubrr >> 8;
	UART_UBRRL_REG |= ubrr;

	// Write in UCSRC, set frame size to 8-bit
	UART_UCSRC_REG |= (1 << 7) | (3 << 1);

	// By default stop bit -> 1 bit
	// By default parity bit is disabled

}

u8 UART_Receive()
{

	// Wait for unread data
//	while ( !((UART_UCSRA_REG >> 7) & 1) );
	if ( ((UART_UCSRA_REG >> 3) & 1) )
	{
		Led_toggle(LED1);
	}

	if ( ((UART_UCSRA_REG >> 7) & 1) )
	{
		return UART_UDR_REG;
	}
	else
	{
		return '\0';
	}


}

void UART_Transmit(u8 data)
{
	// Wait for unread data (flag is 1 if it is ready)
	while (((UART_UCSRA_REG >> 5) & 1) == 0);

	UART_UDR_REG = data;

}

void UART_SendString(u8* string)
{

	for (u8* i = string; *i != '\0'; i++)
	{

		UART_Transmit(*i);

	}

}


void UART_ReciveString(u8* string, u8 size)
{
	
	
	u8 tmp = UART_Receive();
	u8 i = 0;


	while ((tmp != '\n') && (tmp != '\r') && (tmp != '\0') && (i < size - 1))
	{

		string[i] = tmp;
		tmp = UART_Receive();
		i++;

	}

	// For precise memory allocation, add 1 to the size of the array for the null char
	string[i] = '\0';

}
