/*
 * TWI_program.c
 *
 * Created: 9/16/2022 10:02:50 PM
 *  Author: AMIT
 */

 /* UTILES_LIB */
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//#include "ATMEGA32_REG.h"

/* MCAL */
#include "TWI_interface.h"
#include <util/delay.h>
#include "LCD.h"


#define TWCR	(* (u8*) 0x56)
#define TWBR	(* (u8*) 0x20)
#define TWSR	(* (u8*) 0x21)
#define TWAR	(* (u8*) 0x22)
#define TWDR	(* (u8*) 0x23)

#define TWEN	2
#define TWINT	7
#define TWEA	6

void TWI_initMaster(void)
{
	// Set Prescaller = 1
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);

//	// Set Freq. = 400KHZ
//	TWBR = 12;

	// This solved the setup and hold time warnings
	// Set Freq. = 100KHZ
	TWBR = 72;

	// Enable ACK
	SET_BIT(TWCR,TWEA);

	// Enable TWI
    SET_BIT(TWCR,TWEN);

}


void TWI_initSlave(u8 slaveAdd)
{
	// Set Slave Address
	TWAR = slaveAdd<<1;

	// Disable General Call
	CLR_BIT(TWAR,0);

	// Enable ACK
	SET_BIT(TWCR,TWEA);

	// Enable TWI
    SET_BIT(TWCR,TWEN);

}


void TWI_sendStartCondition(void)
{

	// Send Start Condition
	SET_BIT(TWCR,5);

	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	/* Enable TWI and clear interrupt flag, ACK */
//	while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */

	// Wait for the flag
	while(CHECK_BIT(TWCR, TWINT) == 0);

	LCD_displayChar('C');

	// Check ACK = SC ACK
	while((TWSR & 0xF8) != 0x08);


}


void TWI_sendRepStartCondition(void)
{

	// Send Start Condition
	SET_BIT(TWCR,5);

	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	/* Enable TWI and clear interrupt flag, ACK */

	// Wait for the flag
	while(0 == GET_BIT(TWCR,TWINT));

	// Check ACK = Repeated SC ACK
	while((TWSR & 0xF8) != 0x10);
}


void TWI_sendStopCondition(void)
{

	// Send Stop Condition
	SET_BIT(TWCR,4);

	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	/* Enable TWI and clear interrupt flag, ACK */

	while (GET_BIT(TWCR, 4) == 1);

}


void TWI_sendSlaveAddwithWrite(u8 slaveAdd)
{
	// Set slave address
	TWDR = slaveAdd<<1;

	// Select write operation
	CLR_BIT(TWDR,0);

	// Clear SC bit
	CLR_BIT(TWCR,5);

	// Clear flag to start next job
	SET_BIT(TWCR,TWINT);
	// Enable TWI
	SET_BIT(TWCR,TWEN);

	// Wait for the flag
	while(0 == GET_BIT(TWCR,TWINT));

	// Check ACK = Master transmit ( slave address + Write request ) ACK
	while((TWSR & 0xF8) != 0x18);
}


void TWI_sendSlaveAddwithRead(u8 slaveAdd)
{
	// Set slave address
	TWDR = slaveAdd<<1;

	// Select read operation
	SET_BIT(TWDR,0);

	// Clear SC bit
	CLR_BIT(TWCR,5);

	// Clear flag to start next job
	SET_BIT(TWCR,TWINT);
	// Enable TWI
	SET_BIT(TWCR,TWEN);

	// Wait for the flagz
	while(0 == GET_BIT(TWCR,TWINT));

	// Check ACK = Master transmit ( slave address + Read request ) ACK
	while((TWSR & 0xF8) != 0x40);
}


void TWI_sendMasterDataByte(u8 data)
{

	// Write Data into data register
	TWDR = data;

	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	/* Enable TWI and clear interrupt flag, ACK */
	// Wait for the flag
	while(0 == GET_BIT(TWCR,TWINT));

	// Check ACK = Master transmit data ACK
	while((TWSR & 0xF8) != 0x28);
}


void TWI_readMasterDataByte(u8* returnedData)
{
	if(returnedData != 0)
	{

		TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);	/* Enable TWI and clear interrupt flag, ACK */

	    // Check ACK = Master received data with ACK
		while((TWSR & 0xF8) != 0x50);

		// Read Data from data register
		*returnedData = TWDR;
	}
}
