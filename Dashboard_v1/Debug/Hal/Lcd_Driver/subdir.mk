################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hal/Lcd_Driver/lcd.c \
../Hal/Lcd_Driver/lcd_cfg.c 

OBJS += \
./Hal/Lcd_Driver/lcd.o \
./Hal/Lcd_Driver/lcd_cfg.o 

C_DEPS += \
./Hal/Lcd_Driver/lcd.d \
./Hal/Lcd_Driver/lcd_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
Hal/Lcd_Driver/%.o: ../Hal/Lcd_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


