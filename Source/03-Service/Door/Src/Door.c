/*
 * Door.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ahmed
 */

#include "Door.h"
#include <util/delay.h>

static isOpen = 0;

void Door_Init()
{

	// Init servo
	Servo_Init();

}

void Door_Open()
{

	// Start Servo
	Servo_Start();

	// Set Angle to 90
	Servo_SetAngle(90);
	_delay_ms(10);

	// Stop Servo
	Servo_Stop();

	isOpen = 1;

}

void Door_Close()
{

	// Start Servo
	Servo_Start();

	// Set Angle to 0
	Servo_SetAngle(0);
	_delay_ms(10);

	// Stop Servo
	Servo_Stop();
	isOpen = 0;

}

void Door_Toogle()
{

	if (isOpen)
	{

		Door_Close();

	}
	else
	{

		Door_Open();

	}

}
