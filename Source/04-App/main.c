/*
 * main.c
 *
 *  Created on: Aug 23, 2022
 *      Author: ahmed
 */

#include <string.h>
#include <stdlib.h>
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
#include "Timer1.h"
#include "IEEPROM.h"

#include "Login.h"
#include "Door.h"


#include <avr/io.h>
#include <avr/eeprom.h>


#define FORMAT_EEPROM	0

#if FORMAT_EEPROM == 1

	int main(void)
	{

		// No Users
		IEEPROM_Write(0, 0);
		for (u16 i = 1; i < MEMORY_SIZE; i++)
		{
			IEEPROM_Write(i, 0xff);
		}

	}

#elif FORMAT_EEPROM == 0

u8 userType;
u8 dimmerLamp[4];
u8 input[2];

void setup();
void loop();


void main(void)
{

	setup();
	while (1)
	{
		loop();
	}

}

void setup()
{

	Watchdog_OFF();
	LCD_init();
	Keypad_keypadInit();
	IEEPROM_Init();
	HC05_Init();
	Buzzer_init();
	LM35_Init();
	DCMotor_Init(DCMOTOR_1);
	Door_Init();
	Relay_Init();

	userType = login();
//	userType = '2';
	HC05_SendString("Enter command...\n");
	LCD_setAddressPosition(0, 0);
	LCD_displayString("Enter command...");
	LCD_setAddressPosition(1, 0);

}

void loop()
{


	// Get Command
	u8 command = '\0';

	// Admin Mode
	if (userType == '1')
	{

		command = HC05_ReceiveCharNonBlock();

		switch (command) {
			// 6 Lamps
			case '1':
				// Relay 1 On function
				Relay_toogle(Relay_1);
				break;
			case '2':
				// Relay 2 On function
				Relay_toogle(Relay_2);
				break;
			case '3':
				// Relay 3 On function
				Relay_toogle(Relay_3);
				break;
			case '4':
				// Relay 4 On function
				Relay_toogle(Relay_4);
				break;
			case '5':
				// Relay 5 On function
				Relay_toogle(Relay_5);
				break;
			case '6':

				// Relay 6 On function
				HC05_SendString("Enter percentage (0-100)...\n");
				HC05_ReceiveString(dimmerLamp, 4);
				u8* nextToLastDigit;
				Relay_setDimmer(strtol(dimmerLamp, &nextToLastDigit, 10));
				break;

			case '7':
				// switch servo
				Door_Toogle();
				break;
		}

	}

	// User Mode
	else
	{

		command = Keypad_getButton();

		switch (command) {
			// 6 Lamps
			case '1':
				// Relay 1 On function
				Relay_toogle(Relay_1);
				break;
			case '2':
				// Relay 2 On function
				Relay_toogle(Relay_2);
				break;
			case '3':
				// Relay 3 On function
				Relay_toogle(Relay_3);
				break;
			case '4':
				// Relay 4 On function
				Relay_toogle(Relay_4);
				break;
			case '5':
				// Relay 5 On function
				Relay_toogle(Relay_5);
				break;
			case '6':

				// Relay 6 On function
				LCD_setAddressPosition(1, 0);
				LCD_displayString("Enter from 0-100");
				Keypad_GetString(dimmerLamp, 4);
				u8* nextToLastDigit;
				Relay_setDimmer(strtol(dimmerLamp, &nextToLastDigit, 10));
				LCD_ClearRow(1);
				LCD_setAddressPosition(1, 0);
				break;
		}

	}

	command = '\0';

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


#endif	// Format EEPROM

