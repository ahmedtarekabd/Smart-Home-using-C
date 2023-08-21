/*
 * Login.c
 *
 *  Created on: Oct 7, 2022
 *      Author: omar
 */

#include "Login.h"

static void Reset()
{

	Buzzer_turnOn();
	HC05_SendString("The program will reset in 3 seconds.");
	LCD_ClearRow(LCD_ROW0);
	LCD_ClearRow(LCD_ROW1);
	LCD_setAddressPosition(0, 0);
	LCD_displayString("reset in 3 secs");

	// _delay_ms(1000);
	// Reset
	Watchdog_ON();

}

static u8 login_getNumberOfUsers()
{

	return IEEPROM_Read(0);

}

static s8 login_searchForUser(User* user)
{

	u8 numOfUsers = login_getNumberOfUsers();
	u8 username[USERNAME_SIZE];
	u8 password[PASSWORD_SIZE];

	for (u8 i = USER_DATA_BYTE, n = 0; i < MEMORY_SIZE && n < numOfUsers; i += USER_SIZE, n++)
	{

		IEEPROM_ReadString(i, username, USERNAME_SIZE);
		IEEPROM_ReadString(i + USERNAME_SIZE, password, PASSWORD_SIZE);

		if ( strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0)
		{

			// User strcpy
			strcpy(authUser.username, username);
			strcpy(authUser.password, password);
			return i;

		}

	}

	return -1;

}

static User login_getUser()
{

	// Read from the user more than required to check for validation
	// To prevent user of thinking that his inputs were valid and fail to login
	u8 username[USERNAME_SIZE + 1];
	u8 password[PASSWORD_SIZE + 1];
	u8 message[ERROR_MESSAGE_SIZE];


	while (TRUE)
	{
		// Prompt for username
		HC05_SendString("Enter Username...\n");
		HC05_ReceiveString(username, USERNAME_SIZE + 1);

		// Valid size
		if (strlen(username) <= USERNAME_SIZE)
			break;

		snprintf(message, ERROR_MESSAGE_SIZE, "Username size is %d", USERNAME_SIZE);
		HC05_SendString(message);

	}


	while (TRUE)
	{
		// Prompt for password
		HC05_SendString("Enter password...\n");
		HC05_ReceiveString(password, PASSWORD_SIZE + 1);

		// Valid size
		if (strlen(password) <= PASSWORD_SIZE)
			break;

		snprintf(message, ERROR_MESSAGE_SIZE, "Password size is %d\n", PASSWORD_SIZE);
		HC05_SendString(message);
		HC05_SendString("\n");

	}

	User user;
	strcpy(user.username, username);
	strcpy(user.password, password);

	return user;

}

static boolean login_addUser()
{

	u8 numOfUsers = login_getNumberOfUsers();
	u8 newUserAddress = USER_DATA_BYTE + USER_SIZE * numOfUsers;

	if (newUserAddress >= MEMORY_SIZE)
	{
		HC05_SendString("Memory is Full, Cannot add a new user.\n");
		return FALSE;
	}

	// Get user
	User user = login_getUser();

	// Add username
	IEEPROM_WriteString(newUserAddress, user.username);
	IEEPROM_WriteString(newUserAddress + USERNAME_SIZE, user.password);

	IEEPROM_Write(0, numOfUsers + 1);

	HC05_SendString("User added Successfully\n");

	return TRUE;

}

static boolean login_removeUser()
{

	// Check if there are existing users
	u8 numOfUsers = login_getNumberOfUsers();
	if (numOfUsers == 0)
	{
		// No user's exits
		HC05_SendString("No users registered. Add a user.\n");
		return FALSE;
	}

	// Get user
	User user = login_getUser();

	// Search for the user
	s8 userIndex = login_searchForUser(&user);
	if (userIndex == -1)
	{
		// User not found
		HC05_SendString("User not found.\n");
		return FALSE;
	}

	// Remove if exists -> replace it with the last registered user
	u8 lastUserAddress = USER_DATA_BYTE + USER_SIZE * numOfUsers - USER_SIZE;

	// Get last user
	IEEPROM_ReadString(lastUserAddress, user.username, USERNAME_SIZE);
	IEEPROM_ReadString(lastUserAddress + USERNAME_SIZE, user.password, PASSWORD_SIZE);

	// Replace the last user with the user that should be removed
	IEEPROM_WriteString(userIndex, user.username);
	IEEPROM_WriteString(userIndex + USERNAME_SIZE, user.password);

	// Clear it's data -> 0xff
	u8 clear[8] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, '\0'};
	strcpy(user.username, clear);
	strcpy(user.password, clear);
	IEEPROM_WriteString(lastUserAddress, user.username);
	IEEPROM_WriteString(lastUserAddress + USERNAME_SIZE, user.password);

	// Decrease the number of users
	IEEPROM_Write(0, numOfUsers - 1);

	HC05_SendString("User removed Successfully\n");

	return TRUE;

}

/*	Login/Register	*/
static void loginAdminMode()
{

	u8 trials = 1;
	u8 successOp = TRUE;

	// No need to validate length because they are known
	u8 command[COMMAND_SIZE] = "";

	// Read command

	/* Available commands
	 * To Remove a user: remove <username> <password>
	 * To Add a user: add <username> <password>
	 * To Login a user: login <username> <password>
	 * */

	HC05_SendString("Available Commands:\n remove\n add\n login\n");

	while (TRUE)
	{

		HC05_ReceiveString(command, COMMAND_SIZE);

		if ( strcmp(command, "remove") == 0 )
		{

			// Call remove function
			login_removeUser();

		}
		else if ( strcmp(command, "add") == 0 )
		{

			// Call add function
			login_addUser();

		}
		else if ( strcmp(command, "login") == 0 )
		{


			// Call login function
			User user = login_getUser();

			// User found
			if (login_searchForUser(&user) != -1)
			{
				authUser = user;
				break;
			}
			else if (trials >= 3)
			{
				Reset();
			}
			else
			{
				trials++;
			}

		}
		else
		{
			HC05_SendString("Invalid command\n");
		}
		strcpy(command, "");

	}

}


/*	Login Only	*/
static void loginUserMode()
{

	u8 trials = 1;
	u8 userFound = 0;
	u8 response[3];

	User user;

	while (trials != MAX_LOGIN_TRIALS)
	{

		LCD_displayString("Enter Username...");
		Keypad_GetString(user.username, USERNAME_SIZE);
		LCD_displayString("Enter Password...");
		Keypad_GetString(user.password, PASSWORD_SIZE);

		// If user found
		if (login_searchForUser(&user))
		{
			return;
		}

		trials++;

	}

	// User not found for 3 attempts
	Reset();

}

u8 login()
{


	LCD_displayString("Admin: Use mobile");
	LCD_setAddressPosition(1, 0);
	LCD_displayString("User: Use Keypad");

	u8 userType = '\0';
	u8 keypad = KEYPAD_INVALID;
	u8 hc05 = '\0';
	while (TRUE)
	{

		keypad = Keypad_getButton();
		_delay_ms(5);			// Make sure to leave the delay to work in proteus properly

		if (keypad != KEYPAD_INVALID)
		{
			userType = '2';
			break;
		}
		if (hc05 != '\0')
		{
			userType = '1';
			break;
		}

		hc05 = HC05_ReceiveCharNonBlock();

	}

	LCD_ClearRow(0);
	LCD_ClearRow(1);
	LCD_setAddressPosition(0, 0);


	if (userType == '1')
	{

		/*	Admin Mode 	*/
		loginAdminMode();
		return '1';

	}
	else
	{

		/*	User Mode 	*/
		loginUserMode();
		return '2';

	}

}
