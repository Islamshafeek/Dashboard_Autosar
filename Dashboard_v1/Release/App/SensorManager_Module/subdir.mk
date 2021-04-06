################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/SensorManager_Module/Sensor_Manager.c 

OBJS += \
./App/SensorManager_Module/Sensor_Manager.o 

C_DEPS += \
./App/SensorManager_Module/Sensor_Manager.d 


# Each subdirectory must supply rules for building sources it contributes
App/SensorManager_Module/%.o: ../App/SensorManager_Module/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


