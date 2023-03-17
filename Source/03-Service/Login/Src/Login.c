/*
 * Login.c
 *
 *  Created on: Oct 7, 2022
 *      Author: omar
 */

#include "Login.h"


static u8 login_getNumberOfUsers()
{

	return EEPROM_ReadByte(STATUS_PAGE, NUMBER_OF_USERS_DATA_ADDRESS);

}

static boolean login_addUser(u8* username, u8* password)
{

	u8 numOfUsers = login_getNumberOfUsers();
	u8 pageNumber = EEPROM_PAGE2;

	// Go to the the right page mumber
	while (numOfUsers > MAX_NUMBER_OF_USERS_PER_PAGE)
	{

		numOfUsers -= MAX_NUMBER_OF_USERS_PER_PAGE;
		pageNumber++;

	}

	// Page out of range
	if (pageNumber > MAX_NUM_OF_PAGES)
	{
		return FALSE;
	}

	// Go to data address
	u8 dataAddress = numOfUsers * TOTAL_USER_SIZE;
	// Add username
	EEPROM_WriteString(pageNumber, dataAddress, username);
	EEPROM_WriteString(pageNumber, dataAddress + USERNAME_SIZE, password);

	return TRUE;

}

static void login_searchForUsername()
{

	EEPROM_Search(username, USERNAME_SIZE);

}

/*	Login/Register	*/
static void loginAdminMode()
{

	u8 trials = 0;
	u8 userFound = 0;
	u8 response[3];


	// Check for Login or register

	// Login: 1
	// Checks username 3 trials
	// Checks password 3 trials
	// If failed to find: Buzzer on until reset button



	// Prompt for username
	HC05_SendString("Enter Username...");
	HC05_ReceiveString(username, USERNAME_SIZE);

	// Check if username exists
	userFound = EEPROM_Search(username, USERNAME_SIZE);
	if ( !userFound )
	{


		HC05_SendString("Username not found... Do you want to register? (yes/no)");
		HC05_ReceiveString(response, 3);

		// Anything other than yes
		if ( !( strcmp(response, "yes") == 0) )
		{

			Buzzer_turnOn();
			HC05_SendString("The program will reset in 3 seconds.");
			_delay_ms(2000);
			// Reset
			Watchdog_ON();

		}

		// Add a new User
		if (login_addUser(username, password))
		{

			HC05_SendString("Username Registered and logged in...");


		}
		else
		{

			HC05_SendString("Max number of users registered");
			// Reset
			Buzzer_turnOn();
			HC05_SendString("The program will reset in 3 seconds.");
			_delay_ms(2000);
			// Reset
			Watchdog_ON();

		}

	}

	else
	{

		while (trials != MAX_LOGIN_TRIALS)
		{

			HC05_SendString("Enter Password...");
			HC05_ReceiveString(password, PASSWORD_SIZE);

			if (!EEPROM_Search(password, PASSWORD_SIZE))
			{

				HC05_SendString("Wrong Password...");
				trials++;

			}
			else
			{

				HC05_SendString("Logging in...");
				_delay_ms(1000);
				break;

			}

		}

		if (trials == MAX_LOGIN_TRIALS)
		{

			HC05_SendString("Max number of trials");
			// Reset
			Buzzer_turnOn();
			HC05_SendString("The program will reset in 3 seconds.");
			_delay_ms(2000);
			// Reset
			Watchdog_ON();

		}


	}

}


/*	Login Only	*/
static void loginUserMode()
{

	u8 trials = 0;
	u8 userFound = 0;
	u8 response[3];


	while (trials != MAX_LOGIN_TRIALS)
	{

		LCD_displayString("Enter Username...");
		Keypad_GetString(username, USERNAME_SIZE);
		LCD_displayString("Enter Password...");
		Keypad_GetString(password, PASSWORD_SIZE);
		trials++;

	}

	if (trials == MAX_LOGIN_TRIALS)
	{

		// Press Reset
		Buzzer_turnOn();
		HC05_SendString("The program will reset in 3 seconds.");
		LCD_displayString("The program will reset in 3 seconds.");
		_delay_ms(2000);
		// Reset
		Watchdog_ON();

	}


}

void login()
{

	EEPROM_Init();

	if (HC05_IsConnected())
	{

		/*	Admin Mode 	*/
		loginAdminMode();

	}
	else
	{

		/*	User Mode 	*/
		loginUserMode();

	}

}
