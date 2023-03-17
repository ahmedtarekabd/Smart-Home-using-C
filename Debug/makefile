################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Source/04-App/subdir.mk
-include Source/03-Service/Login/Src/subdir.mk
-include Source/03-Service/Door/Src/subdir.mk
-include Source/02-ECUA/Servo/Src/subdir.mk
-include Source/02-ECUA/SSD/Src/subdir.mk
-include Source/02-ECUA/Relay/Src/subdir.mk
-include Source/02-ECUA/LM35/Src/subdir.mk
-include Source/02-ECUA/LED/Src/subdir.mk
-include Source/02-ECUA/LCD/Src/subdir.mk
-include Source/02-ECUA/Keypad/Src/subdir.mk
-include Source/02-ECUA/HC-05/Src/subdir.mk
-include Source/02-ECUA/EEPROM/Src/subdir.mk
-include Source/02-ECUA/DCMotor/Src/subdir.mk
-include Source/02-ECUA/Buzzer/Src/subdir.mk
-include Source/02-ECUA/Button/Src/subdir.mk
-include Source/01-MCAL/Watchdog/Src/subdir.mk
-include Source/01-MCAL/UART/Src/subdir.mk
-include Source/01-MCAL/Timer1/Src/subdir.mk
-include Source/01-MCAL/Timer0/Src/subdir.mk
-include Source/01-MCAL/TWI/Src/subdir.mk
-include Source/01-MCAL/SPI/Src/subdir.mk
-include Source/01-MCAL/GIE/Src/subdir.mk
-include Source/01-MCAL/EXTI/Src/subdir.mk
-include Source/01-MCAL/Dio/Src/subdir.mk
-include Source/01-MCAL/ADC/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Smart_Home
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Smart_Home.lss \
Smart_Home.lss \

FLASH_IMAGE += \
Smart_Home.hex \
Smart_Home.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: Smart_Home.elf secondary-outputs

# Tool invocations
Smart_Home.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Smart_Home.map -mmcu=atmega32 -o "Smart_Home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Smart_Home.lss: Smart_Home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Smart_Home.elf  >"Smart_Home.lss"
	@echo 'Finished building: $@'
	@echo ' '

Smart_Home.hex: Smart_Home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Smart_Home.elf  "Smart_Home.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Smart_Home.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Smart_Home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Smart_Home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
