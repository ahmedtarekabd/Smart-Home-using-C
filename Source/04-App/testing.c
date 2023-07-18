/*
 * testing.c
 *
 *  Created on: Jun 13, 2023
 *      Author: ahmed
 */


#include <string.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"

#include "ADC.h"
#include "Buzzer.h"
#include "Dio.h"
#include "EEPROM.h"
#include "HC-05.h"
#include "LCD.h"
#include "Led.h"
#include "Relay.h"
#include "keypad.h"
#include "UART.h"
#include "LM35.h"
#include "Servo.h"
#include "TWI_interface.h"
#include "DCMotor.h"
#include "Timer1.h"
#include "IEEPROM.h"

#include "Login.h"
#include "Door.h"


#include <avr/io.h>
#include <avr/eeprom.h>

#define NOT_TESTING		0
#define ADC             1		// Done
#define Buzzer          2		// Done
#define Dio             3		// Done (Mesh mehtaga)
#define EEPROM          4		//
#define HC_05           5		// Done
#define LCD             6       // Done
#define Led             7		// Done (Mesh mehtaga)
#define Relay           8		// Done
#define KEYPAD          9		// Done!!!!!!!
#define UART            10		// Done!!
#define LM35            11		// Done
#define Servo           12		// Done!!!
#define TWI_interface   13		//
#define DCMotor         14		// Done
#define Timer1          15		// Done
#define IEEPROM			16
#define internal		17



#define MODULE		NOT_TESTING


#if MODULE == LCD

	void main(void)
	{

		LCD_init();

		LCD_displayChar('a');
         _delay_ms(1000);

        LCD_ClearRow(0);
        LCD_displayFloat(10.6);
        _delay_ms(1000);

        LCD_setAddressPosition(1, 0);
        LCD_displayInt(5);
        _delay_ms(1000);
        LCD_ClearRow(0);
        LCD_ClearRow(1);

        LCD_setAddressPosition(0, 0);
        LCD_displayString("Ahmed");
        LCD_setAddressPosition(1, 0);
        LCD_displayStringWithAnimation("Ahmed");

		while (1);

	}

#elif MODULE == KEYPAD

//#define KEY_PRT 	PORTA
//#define KEY_DDR		DDRA
//#define KEY_PIN		PINA
//
//unsigned char keypad[4][4] = {	{'7','8','9','/'},
//				{'4','5','6','*'},
//				{'1','2','3','-'},
//				{' ','0','=','+'}};
//
//unsigned char colloc, rowloc;
//
//char keyfind()
//{
//	while(1)
//	{
//
//	    do
//	    {
//		KEY_PRT &= 0x0F;      		/* mask PORT for column read only */
//		asm("NOP");
//		colloc = (KEY_PIN & 0x0F); 	/* read status of column */
//	    }while(colloc != 0x0F);
//
//	    do
//	    {
//		do
//		{
//	            _delay_ms(20);             /* 20ms key debounce time */
//		    colloc = (KEY_PIN & 0x0F); /* read status of column */
//		}while(colloc == 0x0F);        /* check for any key press */
//
//		_delay_ms (40);	            /* 20 ms key debounce time */
//		colloc = (KEY_PIN & 0x0F);
//	    }while(colloc == 0x0F);
//
//	   /* now check for rows */
//	    KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
//	    asm("NOP");
//	    colloc = (KEY_PIN & 0x0F);
//	    if(colloc != 0x0F)
//            {
//		rowloc = 0;
//		break;
//	    }
//
//	    KEY_PRT = 0xDF;		/* check for pressed key in 2nd row */
//	    asm("NOP");
//	    colloc = (KEY_PIN & 0x0F);
//	    if(colloc != 0x0F)
//	    {
//		rowloc = 1;
//		break;
//	    }
//
//	    KEY_PRT = 0xBF;		/* check for pressed key in 3rd row */
//	    asm("NOP");
//            colloc = (KEY_PIN & 0x0F);
//	    if(colloc != 0x0F)
//	    {
//		rowloc = 2;
//		break;
//	    }
//
//	    KEY_PRT = 0x7F;		/* check for pressed key in 4th row */
//	    asm("NOP");
//	    colloc = (KEY_PIN & 0x0F);
//	    if(colloc != 0x0F)
//	    {
//		rowloc = 3;
//		break;
//	    }
//	}
//
//	if(colloc == 0x0E)
//	   return(keypad[rowloc][0]);
//	else if(colloc == 0x0D)
//	   return(keypad[rowloc][1]);
//	else if(colloc == 0x0B)
//	   return(keypad[rowloc][2]);
//	else
//	   return(keypad[rowloc][3]);
//}
//
//void main(void)
//{
//	LCD_init();
//
//    DDRA = 0xF0;           	/* set port direction as input-output */
//    KEY_PRT = 0xFF;
//
//	while(1)
//	{
//
//	    LCD_displayChar(keyfind());       /* Display which key is pressed */
//	}
//}


	void main(void)
	{

		Keypad_keypadInit();
        LCD_init();


		while (1)
        {

    		u8 button = Keypad_getButton();

            if (button != KEYPAD_INVALID)
            {
                LCD_displayChar(button);
                _delay_ms(10);			// Make sure to leave the delay to work in proteus properly
            }

        }

	}

#elif MODULE == ADC

	void main(void)
	{

		ADC_InitADC();
        LCD_init();


		while (1)
        {

    		f32 reading = ADC_f32ReadChannel(ADC_CHANNEL0);
    		_delay_ms(10);

			LCD_displayFloat(reading);
			LCD_setAddressPosition(0, 0);
			_delay_ms(10);
			LCD_ClearRow(0);
			_delay_ms(10);


        }

	}

//	void ADC_Init()
//	{
//		DDRA=0x0;			/* Make ADC port as input */
//		ADCSRA = 0x87;			/* Enable ADC, fr/128  */
//		ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
//
//	}
//
//	int ADC_Read(char channel)
//	{
//		int Ain,AinLow;
//
//		ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */
//
//		ADCSRA |= (1<<ADSC);		/* Start conversion */
//		while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
//
//		_delay_us(10);
//		AinLow = (int)ADCL;		/* Read lower byte*/
//		Ain = (int)ADCH*256;		/* Read higher 2 bits and
//						Multiply with weight */
//		Ain = Ain + AinLow;
//		return(Ain);			/* Return digital value*/
//	}
//
//
//	int main()
//	{
//		char String[5];
//		int value;
//
//		ADC_Init();
//		LCD_init();			/* Initialization of LCD */
//		LCD_displayString("ADC value");	/* Write string on 1st line of LCD */
//		_delay_ms(10);
//		LCD_ClearRow(0);
//
//		while(1)
//		{
//
//			LCD_setAddressPosition(0, 0);	/* LCD16x2 cursor position */
//			value=ADC_Read(0);	/* Read ADC channel 0 */
//			itoa(value,String,10);	/* Integer to string conversion */
//			LCD_displayString(String);
//			LCD_displayString("  ");
//
//			_delay_ms(10);
//
//		}
//		return 0;
//	}

#elif MODULE == LM35

	void main(void)
	{

		LM35_Init();
        LCD_init();


		while (1)
        {

    		u8 reading = LM35_ReadTemperature();
    		_delay_ms(10);

			LCD_displayInt(reading);
			_delay_ms(50);
			LCD_displayString("  ");
			_delay_ms(10);

        }

	}

#elif MODULE == Buzzer

	void main(void)
	{

		Buzzer_init();
        LCD_init();


		while (1)
        {

			Buzzer_turnOn();
			_delay_ms(10);
			Buzzer_turnOff();
			_delay_ms(10);

        }

	}

#elif MODULE == Timer1

	void main(void)
		{


	        LCD_init();
			Servo_Init();

			Servo_Start();


			// Inaccurate degrees due to truncation of compare register
			// 32.5 -> 3
			// Therefore inaccurate duty cycles
			while (1)
	        {

				LCD_setAddressPosition(0, 0);
				LCD_displayInt(1);
				Timer1_SetDuty(0.52/1000);
				_delay_ms(1500);

				LCD_setAddressPosition(0, 0);
				LCD_displayInt(2);
				Timer1_SetDuty(1.4/1000);
				_delay_ms(1500);

				LCD_setAddressPosition(0, 0);
				LCD_displayInt(3);
				Timer1_SetDuty(2.4/1000);
				_delay_ms(1500);

	        }

		}


#elif MODULE == Servo

	void main(void)
	{

		LCD_init();
		Servo_Init();

		Servo_Start();

		while (1)
        {

			LCD_setAddressPosition(0, 0);
			LCD_displayInt(0);
			Servo_SetAngle(0);
			_delay_ms(1500);

			LCD_setAddressPosition(0, 0);
			LCD_displayInt(90);
			Servo_SetAngle(90);
			_delay_ms(1500);

			LCD_setAddressPosition(0, 0);
			LCD_displayInt(180);
			Servo_SetAngle(180);
			_delay_ms(1500);

        }

	}

#elif MODULE == UART

	void main(void)
	{

        LCD_init();
		UART_Init(9600);

		UART_SendString("Ahmed");
		UART_Transmit('b');

		u8 str[100];

		while (1)
		{

			// Char
//			u8 ch = UART_Receive();
//			LCD_displayChar(ch);

			// String
			UART_ReciveString(str, 100);
			LCD_displayString(str);

		}

	}

#elif MODULE == HC_05

	void main(void)
	{

        LCD_init();
		HC05_Init();

		HC05_SendString("Ahmed");

		u8 str[100];

		while (1)
		{


			HC05_ReceiveString(str, 100);
			LCD_displayString(str);

		}

	}

#elif MODULE == HC_05

	void main(void)
	{

        LCD_init();
		HC05_Init();

		HC05_SendString("Ahmed");

		u8 str[100];

		while (1)
		{


			HC05_ReceiveString(str, 100);
			LCD_displayString(str);

		}

	}

#elif MODULE == EEPROM

	void main(void)
	{

        LCD_init();
		EEPROM_Init();


//		EEPROM_WriteString(0, 0, "Ahmed");


//		u8 str[100];
//		EEPROM_ReadString(0, 0, str, 6);
//		LCD_displayString(str);

		LCD_displayChar(EEPROM_ReadByte(0, 0));
		LCD_displayChar(EEPROM_ReadByte(0, 1));
		EEPROM_WriteString(0, 0, "test");

		while (1);

	}

#elif MODULE == internal

	void main(void)
	{

        LCD_init();


        eeprom_write_byte(0, 'A');

		LCD_displayChar(eeprom_read_byte(0));
		LCD_displayChar(eeprom_read_byte(0));

		while (1);

	}

#elif MODULE == IEEPROM

	void main(void)
	{

		/*
		 * Won't work in Proteus because I couldn't solve the problem of
		 * setting the the EEWR within 4 cycles after setting EEMWE (Proteus's problem!)
		 * */

        LCD_init();
        IEEPROM_Init();

        u8 str[10];

		LCD_displayChar('T');

		IEEPROM_WriteString(0, "Ahmed");

		IEEPROM_ReadString(0, str, 6);		// Null char
		LCD_displayString(str);

		while (1);

	}

#elif MODULE == DCMotor

	void main(void)
	{

        LCD_init();
		DCMotor_Init(DCMOTOR_1);

		while (1)
		{

			DCMotor_Start(DCMOTOR_1, DCMOTOR_CLOCKWISE);
			_delay_ms(3000);
			DCMotor_Stop(DCMOTOR_1);
			_delay_ms(2000);

		}

	}

#elif MODULE == Relay

	void main(void)
	{

        LCD_init();
		Relay_Init();

		while (1)
		{

			Relay_setDimmer(0);
			_delay_ms(1000);
			Relay_setDimmer(10);
			_delay_ms(1000);
			Relay_setDimmer(20);
			_delay_ms(1000);
			Relay_setDimmer(30);
			_delay_ms(1000);
			Relay_setDimmer(40);
			_delay_ms(1000);
			Relay_setDimmer(50);
			_delay_ms(1000);
			Relay_setDimmer(60);
			_delay_ms(1000);
			Relay_setDimmer(70);
			_delay_ms(1000);
			Relay_setDimmer(80);
			_delay_ms(1000);
			Relay_setDimmer(90);
			_delay_ms(1000);
			Relay_setDimmer(100);
			_delay_ms(1000);

		}

	}

#endif
