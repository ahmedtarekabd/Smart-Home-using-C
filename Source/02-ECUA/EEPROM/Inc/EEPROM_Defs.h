/*
 * EEPROM_Defs.h
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmed
 */

#ifndef SOURCE_02_ECUA_EEPROM_INC_EEPROM_DEFS_H_
#define SOURCE_02_ECUA_EEPROM_INC_EEPROM_DEFS_H_

/*
 * Number of pages 		= 8
 * Number of users/page = 8
 * Max Number of users 	= 8 * 7 = 56
 * */

// ------------ Config ------------
#define FORMAT_EEPROM		0

#define MAX_NUM_OF_PAGES	8
#define MAX_NUM_OF_BYTES	256


// ------------ Data Types ------------
typedef enum
{

	EEPROM_PAGE1,
	EEPROM_PAGE2,
	EEPROM_PAGE3,
	EEPROM_PAGE4,
	EEPROM_PAGE5,
	EEPROM_PAGE6,
	EEPROM_PAGE7,
	EEPROM_PAGE8

}eeprom_page_numbers_t;



#endif /* SOURCE_02_ECUA_EEPROM_INC_EEPROM_DEFS_H_ */
