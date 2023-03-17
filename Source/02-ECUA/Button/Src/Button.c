/*
 * Button.c
 *
 *  Created on: Aug 27, 2022
 *      Author: ahmed
 */

#include "Button.h"

void Button_buttonInit()
{

	Dio_configChanel(DIO_PORTB, DIO_PIN0, DIO_INPUT);
	Dio_configChanel(DIO_PORTD, DIO_PIN6, DIO_INPUT);
	Dio_configChanel(DIO_PORTD, DIO_PIN2, DIO_INPUT);

}

button_buttonState_t Button_udtisPressed(button_buttonId_t button)
{

	button_buttonState_t returnValue = 0;

	switch (button)
	{
		case BUTTON0:
			returnValue = Dio_udtreadChanel(DIO_PORTB, DIO_PIN0);
			break;

		case BUTTON1:
			returnValue = Dio_udtreadChanel(DIO_PORTD, DIO_PIN6);
			break;
		case BUTTON2:
			returnValue = Dio_udtreadChanel(DIO_PORTD, DIO_PIN2);
			break;
	}

	return returnValue;

}
