/*
 * Dio.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Eng_Fawzi
 */
#include "Dio.h"
#include "Bit_Math.h"

void Dio_configChanel(dio_port_t port, dio_pin_t pin, dio_dir_t dir)
{
	switch (port)
	{
	case DIO_PORTA:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRA_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRA_REG,pin);
			}
			break;
		}

	case DIO_PORTB:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRB_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRB_REG,pin);
			}
			break;
		}

	case DIO_PORTC:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRC_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRC_REG,pin);
			}
			break;
		}

	case DIO_PORTD:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRD_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRD_REG,pin);
			}
			break;
		}
	}
}

void Dio_writeChanel(dio_port_t port, dio_pin_t pin, dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTA_REG,pin);
		}
		break;

	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,pin);
		}
		break;

	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,pin);
		}
		break;

	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTD_REG,pin);
		}
		break;
	}
}

void Dio_writeChanelGroup(dio_port_t port, u8 data, u8 mask)
{

	switch (port)
	{

	case DIO_PORTA:
		// DIO_PORTA_REG &= data;						WRONG because we should use AND to set the left 4 bit to 0
		// 												then use OR to set the left 4 bit to required value
		DIO_PORTA_REG = (DIO_PORTA_REG & mask) | data;
		break;
	case DIO_PORTB:
		DIO_PORTB_REG = (DIO_PORTB_REG & mask) | data;
		break;
	case DIO_PORTC:
		DIO_PORTC_REG = (DIO_PORTC_REG & mask) | data;
		break;
	case DIO_PORTD:
		DIO_PORTD_REG = (DIO_PORTD_REG & mask) | data;
		break;

	}

}

dio_level_t Dio_udtreadChanel(dio_port_t port, dio_pin_t pin)
{

	dio_level_t returnValue = 0;

	switch(port)
	{

	case DIO_PORTA:
		returnValue = CHECK_BIT(DIO_PINA_REG, pin);
		break;

	case DIO_PORTB:
		returnValue = CHECK_BIT(DIO_PINB_REG, pin);
		break;

	case DIO_PORTC:
		returnValue = CHECK_BIT(DIO_PINC_REG, pin);
		break;

	case DIO_PORTD:
		returnValue = CHECK_BIT(DIO_PIND_REG, pin);
		break;

	}

	return returnValue;

}


void Dio_flipChanel(dio_port_t port, dio_pin_t pin)
{

	switch(port)
	{

	case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG, pin);
		break;

	case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG, pin);
		break;

	case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG, pin);
		break;

	case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG, pin);
		break;

	}

}
