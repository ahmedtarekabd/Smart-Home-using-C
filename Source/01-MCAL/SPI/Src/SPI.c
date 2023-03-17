/*
 * SPI.c
 *
 *  Created on: Sep 20, 2022
 *      Author: ahmed
 */

#include "SPI.h"

void SPI_MasterInit()
{

	// SS should be output
	Dio_configChanel(DIO_PORTB, DIO_PIN4, DIO_OUTPUT);
	// SS set to high (No Slave Selected)
	Dio_writeChanel(DIO_PORTB, DIO_PIN4, DIO_HIGH);

	// MOSI should be output
	Dio_configChanel(DIO_PORTB, DIO_PIN5, DIO_OUTPUT);
	// MISO should be input
	// SCK should be output
	Dio_configChanel(DIO_PORTB, DIO_PIN7, DIO_OUTPUT);

	// Enable SPI
	SPI_SPCR_REG |= 1 << 6;

	// Master Mode
	SPI_SPCR_REG |= 1 << 4;

	// MSB is transmitted first
	// Clock rising by default
	// Clock frequency is by default F_CPU / 4 -> 4 MHZ

	// Set clock as 1 MHZ
	SPI_SPCR_REG |= 1;

}

void SPI_SlaveInit()
{

//	// SS should be output
//	Dio_configChanel(DIO_PORTB, DIO_PIN4, DIO_INPUT);
	// MISO should be output
	Dio_configChanel(DIO_PORTB, DIO_PIN6, DIO_OUTPUT);

	// Enable SPI
	SPI_SPCR_REG |= 1 << 6;

	// Slave Mode is selected by default

	// MSB is transmitted first
	// Clock rising by default
	// Clock frequency is by default F_CPU / 4

}

u8 SPI_MasterTranser(u8 data)
{

	SPI_SPDR_REG = data;

	// Wait for the flag
	while ( (SPI_SPSR_REG >> 7) & 1 == 0);

	return SPI_SPDR_REG;

}

void SPI_MasterSend(u8 data)
{

	SPI_MasterTranser(data);

}

u8 SPI_MasterReceive()
{

	return SPI_MasterTranser(0);


}

void SPI_SlaveSend(u8 data)
{

	SPI_SPDR_REG = data;

}

u8 SPI_SlaveReceive()
{

	return SPI_MasterTranser(0);

}
