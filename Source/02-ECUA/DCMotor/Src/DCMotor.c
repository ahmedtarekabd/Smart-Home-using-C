/*
 * DCMotor.c
 *
 *  Created on: Sep 14, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_DCMOTOR_SRC_DCMOTOR_C_
#define SOURCE_02_ECUA_DCMOTOR_SRC_DCMOTOR_C_

#include "DCMotor.h"

void DCMotor_Init(dcmotor_motorID_t motorID)
{

	switch (motorID)
	{

	case DCMOTOR_1:
		// Enable
		Dio_configChanel(DIO_PORTD, DIO_PIN4, DIO_OUTPUT);
		// Motor is stop
		Dio_writeChanel(DIO_PORTD, DIO_PIN4, DIO_LOW);

		// Switches of H bridges
		Dio_configChanel(DIO_PORTD, DIO_PIN2, DIO_OUTPUT);
		Dio_configChanel(DIO_PORTD, DIO_PIN3, DIO_OUTPUT);
		break;

	case DCMOTOR_2:
		// Enable
		Dio_configChanel(DIO_PORTC, DIO_PIN5, DIO_OUTPUT);
		// Motor is stop
		Dio_writeChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);

		// Switches of H bridges
		Dio_configChanel(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);
		Dio_configChanel(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);
		break;

	}


}


void DCMotor_Start(dcmotor_motorID_t motor, dcmotor_direction_t direction)
{

	switch(motor)
	{

	case DCMOTOR_1:

		// Enable
		Dio_writeChanel(DIO_PORTD, DIO_PIN4, DIO_HIGH);
		switch (direction)
		{

		case DCMOTOR_CLOCKWISE:
			Dio_writeChanel(DIO_PORTD, DIO_PIN2, DIO_HIGH);
			Dio_writeChanel(DIO_PORTD, DIO_PIN3, DIO_LOW);
			break;

		case DCMOTOR_ANTICLOCKWISE:
			Dio_writeChanel(DIO_PORTD, DIO_PIN2, DIO_LOW);
			Dio_writeChanel(DIO_PORTD, DIO_PIN3, DIO_HIGH);
			break;

		}

		break;
	case DCMOTOR_2:

		Dio_writeChanel(DIO_PORTD, DIO_PIN5, DIO_HIGH);
		switch (direction)
		{

		case DCMOTOR_CLOCKWISE:
			Dio_writeChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
			Dio_writeChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
			break;

		case DCMOTOR_ANTICLOCKWISE:
			Dio_writeChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
			Dio_writeChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
			break;

		}

		break;

	}

}

void DCMotor_Stop(dcmotor_motorID_t motor)
{

	switch(motor)
	{

	case DCMOTOR_1:
		Dio_writeChanel(DIO_PORTD, DIO_PIN4, DIO_LOW);
		break;
	case DCMOTOR_2:
		Dio_writeChanel(DIO_PORTD, DIO_PIN5, DIO_LOW);
		break;

	}

}

#endif /* SOURCE_02_ECUA_DCMOTOR_SRC_DCMOTOR_C_ */
