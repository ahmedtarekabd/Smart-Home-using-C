/*
 * Login.h
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_03_SERVICE_LOGIN_LOGIN_H_
#define SOURCE_03_SERVICE_LOGIN_LOGIN_H_

#include "EEPROM.h"
#include "UART.h"
#include "HC-05.h"
#include "LCD.h"
#include "watchdog.h"
#include "Buzzer.h"
#include "keypad.h"
#include "IEEPROM.h"


#define USERNAME_SIZE		(8)
#define PASSWORD_SIZE		(8)
#define USER_SIZE		(USERNAME_SIZE + PASSWORD_SIZE)
#define COMMAND_SIZE		(7)		// Max command length is 6 chars + \0
#define ERROR_MESSAGE_SIZE	(20)

#define MAX_LOGIN_TRIALS	3

#define NUMBER_OF_USERS_BYTE	0
#define MAX_NUMBER_OF_USERS		62


/*
 * From byte 0-23: 		Info about like # of users
 * From byte 24-1023:	Users Data
 * */
#define USER_DATA_BYTE		24
#define MEMORY_SIZE			1024

typedef struct
{
	u8 username[USERNAME_SIZE];
	u8 password[PASSWORD_SIZE];
}User;

User authUser;

u8 login();


#endif /* SOURCE_03_SERVICE_LOGIN_LOGIN_H_ */
