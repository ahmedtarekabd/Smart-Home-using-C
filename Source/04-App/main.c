/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: ahmed
 */

#include <string.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"

#include "ADC.h"
#include "Buzzer.h"
#include "Dio.h"
#include "EEPROM.h"
#include "HC-05.h"
#include "LCD.h"
#include "Led.h"
#include "Relay.h"
#include "keypad.h"
#include "UART.h"
#include "LM35.h"
#include "Servo.h"
#include "TWI_interface.h"
#include "DCMotor.h"

#include "Login.h"
#include "Door.h"

#include "Timer0.h"

#include <avr/io.h>




//#if FORMAT_EEPROM == 1
//
//int main(void)
//{
//
//
//
//}
//
//#else

u8 x = 0;
u8 input[3];

void setup();
void loop();


void main(void)
{

//	PORTA = 0xff;

	LCD_init();

	LCD_displayChar('a');

//	setup();
	while (1)
	{
//		loop();
	}

}

void setup()
{

	Watchdog_OFF();
	LCD_init();
	Keypad_keypadInit();
	EEPROM_Init();
	HC05_Init();
	Buzzer_init();
	LM35_Init();
	DCMotor_Init(DCMOTOR_1);

	login();

}



void loop()
{

	// Get Command
	// Execute

	/*	Admin Mode 	*/
	if (HC05_IsConnected())
	{

		// 6 Lamps
		HC05_ReceiveString(input, 2);
		/*	Admin Mode 	*/
		if (strcmp(input, "1") == 0)
		{

			// Relay 1 On function
			Relay_toogle(Relay_1);

		}
		else if (strcmp(input, "2") == 0)
		{

			// Relay 2 On function
			Relay_toogle(Relay_2);

		}
		else if (strcmp(input, "3") == 0)
		{

			// Relay 3 On function
			Relay_toogle(Relay_3);

		}
		else if (strcmp(input, "4") == 0)
		{

			// Relay 4 On function
			Relay_toogle(Relay_4);

		}
		else if (strcmp(input, "5") == 0)
		{

			// Relay 5 On function
			Relay_toogle(Relay_5);

		}
		// Repeat until lamp 6

		// Door
		else if (strcmp(input, "7") == 0)
		{

			// switch servo
			Door_Toogle();

		}



	}
	/*	User Mode 	*/
	else
	{


		Keypad_GetString(input, 2);
		// 6 Lamps
		if (strcmp(input, "1") == 0)
		{

			// Relay 1 On function
			Relay_toogle(Relay_1);

		}
		else if (strcmp(input, "2") == 0)
		{

			// Relay 2 On function
			Relay_toogle(Relay_2);

		}
		else if (strcmp(input, "3") == 0)
		{

			// Relay 3 On function
			Relay_toogle(Relay_3);

		}
		else if (strcmp(input, "4") == 0)
		{

			// Relay 4 On function
			Relay_toogle(Relay_4);

		}
		else if (strcmp(input, "5") == 0)
		{

			// Relay 5 On function
			Relay_toogle(Relay_5);

		}


	}

	// AC -> Temp Sensor, DC Motor
	if (LM35_ReadTemperature() > 28)
	{

		// Run dc motor
		DCMotor_Start(DCMOTOR_1, DCMOTOR_CLOCKWISE);

	}
	else if (LM35_ReadTemperature() < 21)
	{

		// Stop DC motor
		DCMotor_Stop(DCMOTOR_1);

	}

}


//#endif	// Format EEPROM

