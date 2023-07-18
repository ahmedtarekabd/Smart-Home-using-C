/*
 * Relay.c
 *
 *  Created on: Oct 2, 2022
 *      Author: ahmed
 */

#include "Relay.h"
#include "Timer2.h"

void Relay_Init()
{

	// Normal Lamps
	Dio_configChanel(DIO_PORTA, DIO_PIN1, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTA, DIO_PIN2, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTB, DIO_PIN0, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTD, DIO_PIN6, DIO_OUTPUT);

	Dio_writeChanel(DIO_PORTA, DIO_PIN1, DIO_LOW);
	Dio_writeChanel(DIO_PORTA, DIO_PIN2, DIO_LOW);
	Dio_writeChanel(DIO_PORTB, DIO_PIN0, DIO_LOW);
	Dio_writeChanel(DIO_PORTC, DIO_PIN2, DIO_LOW);
	Dio_writeChanel(DIO_PORTD, DIO_PIN6, DIO_LOW);

	// Dimmer using timer2
	Timer2_Init(TIMER2_FAST_PWM);
	Timer2_Start(TIMER2_BY_256);

}

void Relay_toogle(Relay_t T)
{

	switch (T)
	{

		case Relay_1:
		{
			Dio_flipChanel(DIO_PORTA, DIO_PIN1);
			break;
		}
		case Relay_2:
		{
			Dio_flipChanel(DIO_PORTA, DIO_PIN2);
			break;
		}

		case Relay_3:
		{
			Dio_flipChanel(DIO_PORTB, DIO_PIN0);
			break;
		}

		case Relay_4:
		{
			Dio_flipChanel(DIO_PORTC, DIO_PIN2);
			break;
		}

		case Relay_5:
		{
			Dio_flipChanel(DIO_PORTD, DIO_PIN6);
			break;
		}

	}

}

void Relay_setDimmer(u8 percentage)
{

	if (percentage < 0 || percentage > 100)
		return;

	Timer2_SetDuty(percentage);

}
