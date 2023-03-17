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


#define USERNAME_SIZE		(8 + 1)		// null character
#define PASSWORD_SIZE		(8 + 1)		// null character
#define TOTAL_USER_SIZE		(USERNAME_SIZE + PASSWORD_SIZE)

#define MAX_LOGIN_TRIALS	3

#define STATUS_PAGE								EEPROM_PAGE1
#define NUMBER_OF_USERS_DATA_ADDRESS			0
#define MAX_NUMBER_OF_USERS_PER_PAGE			14


u8 username[USERNAME_SIZE];
u8 password[PASSWORD_SIZE];

void login();

#endif /* SOURCE_03_SERVICE_LOGIN_LOGIN_H_ */
