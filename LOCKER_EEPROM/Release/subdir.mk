################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_PROG.c \
../GIE_PROC.c \
../I2C_PROG.c \
../LCD_PROG.c \
../LED_PROG.c \
../LOCKER_FUNS.c \
../main.c 

OBJS += \
./DIO_PROG.o \
./GIE_PROC.o \
./I2C_PROG.o \
./LCD_PROG.o \
./LED_PROG.o \
./LOCKER_FUNS.o \
./main.o 

C_DEPS += \
./DIO_PROG.d \
./GIE_PROC.d \
./I2C_PROG.d \
./LCD_PROG.d \
./LED_PROG.d \
./LOCKER_FUNS.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


