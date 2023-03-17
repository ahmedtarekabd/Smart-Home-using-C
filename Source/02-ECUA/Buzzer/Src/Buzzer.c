/*
 * Buzzer.c
 *
 *  Created on: Aug 31, 2022
 *      Author: ahmed
 */

#include "Buzzer.h"

void Buzzer_init()
{

	Dio_configChanel(DIO_PORTA, DIO_PIN3, DIO_OUTPUT);

}

void Buzzer_turnOn()
{

	Dio_writeChanel(DIO_PORTA, DIO_PIN3, DIO_HIGH);

}

void Buzzer_turnOff()
{

	Dio_writeChanel(DIO_PORTA, DIO_PIN3, DIO_LOW);

}
