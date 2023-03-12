################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DIO_main.c \
../Src/DIO_prog.c \
../Src/PB_prog.c \
../Src/RCC_program.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/DIO_main.o \
./Src/DIO_prog.o \
./Src/PB_prog.o \
./Src/RCC_program.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/DIO_main.d \
./Src/DIO_prog.d \
./Src/PB_prog.d \
./Src/RCC_program.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/DIO_main.d ./Src/DIO_main.o ./Src/DIO_main.su ./Src/DIO_prog.d ./Src/DIO_prog.o ./Src/DIO_prog.su ./Src/PB_prog.d ./Src/PB_prog.o ./Src/PB_prog.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

