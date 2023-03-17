/*
 * Led.c
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmed
 */

#include "Led.h"
#include <util/delay.h>

void Led_ledInit()
{

	Dio_configChanel(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTC, DIO_PIN7, DIO_OUTPUT);
	Dio_configChanel(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);

}

void Led_turnOn(led_ledId_t led)
{

	switch(led)
	{

	case LED0:
		Dio_writeChanel(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		break;

	case LED1:
		Dio_writeChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);
		break;

	case LED2:
		Dio_writeChanel(DIO_PORTD, DIO_PIN3, DIO_HIGH);
		break;
	}

}

void Led_turnOff(led_ledId_t led)
{

	switch(led)
	{

	case LED0:
		Dio_writeChanel(DIO_PORTC, DIO_PIN2, DIO_LOW);
		break;

	case LED1:
		Dio_writeChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);
		break;

	case LED2:
		Dio_writeChanel(DIO_PORTD, DIO_PIN3, DIO_LOW);
		break;
	}

}

void Led_toggle(led_ledId_t led)
{

	switch(led)
	{

	case LED0:
		Dio_flipChanel(DIO_PORTC, DIO_PIN2);
		break;

	case LED1:
		Dio_flipChanel(DIO_PORTC, DIO_PIN7);
		break;

	case LED2:
		Dio_flipChanel(DIO_PORTD, DIO_PIN3);
		break;
	}

}
