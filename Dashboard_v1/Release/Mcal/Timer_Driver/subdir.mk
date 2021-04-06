################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Mcal/Timer_Driver/Timer.c 

OBJS += \
./Mcal/Timer_Driver/Timer.o 

C_DEPS += \
./Mcal/Timer_Driver/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
Mcal/Timer_Driver/%.o: ../Mcal/Timer_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


