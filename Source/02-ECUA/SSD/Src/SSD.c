/*
 * SSD.c
 *
 *  Created on: Aug 30, 2022
 *      Author: ahmed
 */

#include "SSD.h"


void SSD_init(void)
{

	Dio_configChanel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);	// En2
	Dio_configChanel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);	// En1
	Dio_configChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);	// DP
	Dio_configChanel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);	// A
	Dio_configChanel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);	// B
	Dio_configChanel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);	// C
	Dio_configChanel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);	// D

}


// Total delay of the function
void SSD_displayNumber(u8 number)
{

	// To prevent overflow at 255 -> 0
	while (number >= 100)
		number -= 100;

	u8 rightDigit = ((number/10) % 10) << 4;
	u8 leftDigit = (number % 10) << 4;

	// Right Digit
	// Enable  SSD 1
	Dio_writeChanel(DIO_PORTB, DIO_PIN2, DIO_HIGH);

	// Disable SSD 2
	Dio_writeChanel(DIO_PORTB, DIO_PIN1, DIO_LOW);

	// Write the rightDigit
	Dio_writeChanelGroup(DIO_PORTA, rightDigit, SSD_MASK);

	_delay_us(500);

	// Left Digit
	// Disable SSD 1
	Dio_writeChanel(DIO_PORTB, DIO_PIN2, DIO_LOW);

	// Enable  SSD 2
	Dio_writeChanel(DIO_PORTB, DIO_PIN1, DIO_HIGH);

	// Write the leftDigit
	Dio_writeChanelGroup(DIO_PORTA, leftDigit, SSD_MASK);
	_delay_us(500);


}

void SSD_displayNumberAndDelay(u8 number, u8 msec)
{


	// Display function takes about 3 ms

	for (u16 i = 0; i < msec; i++)
	{

		SSD_displayNumber(number);

	}

}
