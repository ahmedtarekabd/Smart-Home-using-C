################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/02-ECUA/Keypad/Src/keypad.c 

OBJS += \
./Source/02-ECUA/Keypad/Src/keypad.o 

C_DEPS += \
./Source/02-ECUA/Keypad/Src/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Source/02-ECUA/Keypad/Src/%.o: ../Source/02-ECUA/Keypad/Src/%.c Source/02-ECUA/Keypad/Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Timer2\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\03-Service\Door\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\03-Service\Login\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\03-Service\Door\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Servo\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Watchdog\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\IEEPROM\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Button\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\03-Service\Login\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\TWI\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\EEPROM\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Relay\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\SPI\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\HC-05\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\UART\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\DCMotor\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Timer0\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Timer1\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LM35\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\ADC\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\EXTI\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\GIE\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Keypad\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LCD\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Buzzer\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\SSD\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\00-Lib" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LED\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Dio\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


