################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/02-ECUA/EEPROM/EEPROM_program.c 

OBJS += \
./Source/02-ECUA/EEPROM/EEPROM_program.o 

C_DEPS += \
./Source/02-ECUA/EEPROM/EEPROM_program.d 


# Each subdirectory must supply rules for building sources it contributes
Source/02-ECUA/EEPROM/%.o: ../Source/02-ECUA/EEPROM/%.c Source/02-ECUA/EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Button\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Relay\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\SPI\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\HC-05\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\UART\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\DCMotor\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Timer0\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LM35\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\ADC\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\EXTI\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\GIE\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Keypad\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LCD\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\Buzzer\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\SSD\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\00-Lib" -I"E:\Projects\Embedded\Smart_Home\Source\02-ECUA\LED\Inc" -I"E:\Projects\Embedded\Smart_Home\Source\01-MCAL\Dio\Inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


