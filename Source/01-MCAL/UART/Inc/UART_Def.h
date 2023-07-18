/*
 * UART_Def.h
 *
 *  Created on: Sep 17, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_01_MCAL_UART_INC_UART_DEF_H_
#define SOURCE_01_MCAL_UART_INC_UART_DEF_H_

#include "Std_Types.h"

// Data Register
#define UART_UDR_REG		(*(u8*) 0x2c)

// Control/Status Register
#define UART_UCSRA_REG		(*(u8*) 0x2b)
#define UART_UCSRB_REG		(*(u8*) 0x2a)
#define UART_UCSRC_REG		(*(u8*) 0x40)

// Baud rate Register
#define UART_UBRRL_REG		(*(u8*) 0x29)
#define UART_UBRRH_REG		(*(u8*) 0x40)


#endif /* SOURCE_01_MCAL_UART_INC_UART_DEF_H_ */
