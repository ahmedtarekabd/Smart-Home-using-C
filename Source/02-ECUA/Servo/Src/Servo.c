/*
 * Servo.c
 *
 *  Created on: Nov 3, 2022
 *      Author: ahmed
 */

#include "Servo.h"


void Servo_Init()
{

	// Init timer 1 as fast pwm
	// set frequency to 50
	Timer1_Init(TIMER1_FAST_PWM);
	Timer1_SetFrequency(50);

}

void Servo_Start()
{

	// Set prescaler to 256
	Timer1_Start(TIMER1_BY_256);

}

void Servo_Stop()
{

	// Stop timer funnction (by setting no clock)
	Timer1_Stop();

}

void Servo_SetAngle(u8 angle)
{

	// Validation
	if (angle < 0 || angle > 180)
	{
		return;
	}

	// Servo operate at duty cycles with Ton from 0.52ms to 2.4ms: 0 to 180 degree
	f32 percentage = (angle / 180.0);
	f32 minValue = (0.52 / 1000);
	f32 Ton = minValue + (2.4 - 0.52) / 1000 * percentage;

	Timer1_SetDuty(Ton);

}
