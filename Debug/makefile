################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/MTIMER/subdir.mk
-include MCAL/MGIE/subdir.mk
-include MCAL/MEXTI/subdir.mk
-include MCAL/MDIO/subdir.mk
-include MCAL/MADC/subdir.mk
-include HAL/HLED/subdir.mk
-include HAL/HKPD/subdir.mk
-include HAL/HCLCD/subdir.mk
-include APP/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
IMT_SMART_HOME.lss \

FLASH_IMAGE += \
IMT_SMART_HOME.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: IMT_SMART_HOME.elf secondary-outputs

# Tool invocations
IMT_SMART_HOME.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,IMT_SMART_HOME.map -mmcu=atmega32 -o "IMT_SMART_HOME.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

IMT_SMART_HOME.lss: IMT_SMART_HOME.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S IMT_SMART_HOME.elf  >"IMT_SMART_HOME.lss"
	@echo 'Finished building: $@'
	@echo ' '

IMT_SMART_HOME.hex: IMT_SMART_HOME.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex IMT_SMART_HOME.elf  "IMT_SMART_HOME.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: IMT_SMART_HOME.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 IMT_SMART_HOME.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) IMT_SMART_HOME.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
