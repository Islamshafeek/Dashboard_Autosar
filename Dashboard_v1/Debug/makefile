################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Service/subdir.mk
-include Mcal/Uart_Driver/subdir.mk
-include Mcal/Timer_Driver/subdir.mk
-include Mcal/Port_Driver/subdir.mk
-include Mcal/Dio_Driver/subdir.mk
-include Hal/TempHal_Driver/subdir.mk
-include Hal/Led_Module/subdir.mk
-include Hal/Lcd_Driver/subdir.mk
-include Hal/KeyPad_Driver/subdir.mk
-include App/Temp_Module/subdir.mk
-include App/Speed_Module/subdir.mk
-include App/SensorManager_Module/subdir.mk
-include App/Ignition_Module/subdir.mk
-include App/Door_Module/subdir.mk
-include App/DashboardManager_Module/subdir.mk
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
Dashboard_v1.lss \

FLASH_IMAGE += \
Dashboard_v1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Dashboard_v1.elf secondary-outputs

# Tool invocations
Dashboard_v1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Dashboard_v1.map -mmcu=atmega32 -o "Dashboard_v1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Dashboard_v1.lss: Dashboard_v1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Dashboard_v1.elf  >"Dashboard_v1.lss"
	@echo 'Finished building: $@'
	@echo ' '

Dashboard_v1.hex: Dashboard_v1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Dashboard_v1.elf  "Dashboard_v1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Dashboard_v1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Dashboard_v1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Dashboard_v1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
