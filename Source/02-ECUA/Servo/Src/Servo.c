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

	// Set prescaler to 64
	Timer1_Start(TIMER1_BY_64);

}

void Servo_Stop()
{

	// Stop timer funnctio (by setting no clock)
	Timer1_Stop();

}

void Servo_SetAngle(u8 angle)
{

	f32 value = 1 / (( angle * 0.0056 ) + 1);

	u8 percentage = (value / 50) * 100;

	Timer1_SetDuty(percentage);

}
