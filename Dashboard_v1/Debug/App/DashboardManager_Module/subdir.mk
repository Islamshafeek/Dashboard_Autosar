################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/DashboardManager_Module/Dashboard_Manager.c 

OBJS += \
./App/DashboardManager_Module/Dashboard_Manager.o 

C_DEPS += \
./App/DashboardManager_Module/Dashboard_Manager.d 


# Each subdirectory must supply rules for building sources it contributes
App/DashboardManager_Module/%.o: ../App/DashboardManager_Module/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


