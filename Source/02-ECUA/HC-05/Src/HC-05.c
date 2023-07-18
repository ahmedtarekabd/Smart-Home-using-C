/*
 * HC-05.c
 *
 *  Created on: Sep 29, 2022
 *      Author: ahmed
 */

#include "HC-05.h"

void HC05_Init()
{

	// HC 05 has to be communicated with 9600 baudrate when data mode
	UART_Init(9600);

	// Enable
	// Command mode -> set
//	// Data mode -> clear
//	Dio_configChanel(DIO_PORTD, DIO_PIN2, DIO_OUTPUT);

//	// State (if the device is connected or not)
//	Dio_configChanel(DIO_PORTD, DIO_PIN3, DIO_INPUT);

}

boolean HC05_IsConnected()
{

	if (Dio_udtreadChanel(DIO_PORTD, DIO_PIN3))
	{
		return TRUE;
	}

	return FALSE;

}

u8 HC05_ReceiveCharNonBlock()
{

	return UART_ReceiveNonBlock();

}

boolean HC05_SendString(u8* string)
{

//	if (HC05_IsConnected())
//	{

		UART_SendString(string);
		return TRUE;

//	}
//	return FALSE;

}

boolean HC05_ReceiveString(u8* string, u8 size)
{

//	if (HC05_IsConnected())
//	{

		UART_ReciveString(string, size);
		return TRUE;

//	}
//	return FALSE;

}
