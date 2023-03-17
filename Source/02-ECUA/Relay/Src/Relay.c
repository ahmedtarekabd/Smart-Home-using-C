/*
 * Relay.c
 *
 *  Created on: Oct 2, 2022
 *      Author: ahmed
 */

#include "Relay.h"

void Relay_Init()
{

	// Normal Lamps
	Dio_configChanel(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);

	// Dimmer using timer1

}

void Relay_toogle(Relay_t T)
{

	switch (T)
	{

		case Relay_1:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN1);
			break;
		}
		case Relay_2:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN2);
			break;
		}

		case Relay_3:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN3);
			break;
		}

		case Relay_4:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN4);
			break;
		}

		case Relay_5:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN5);
			break;
		}

	}

}
