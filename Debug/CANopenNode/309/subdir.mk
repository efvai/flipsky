################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode/309/CO_gateway_ascii.c 

OBJS += \
./CANopenNode/309/CO_gateway_ascii.o 

C_DEPS += \
./CANopenNode/309/CO_gateway_ascii.d 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/309/%.o CANopenNode/309/%.su: ../CANopenNode/309/%.c CANopenNode/309/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"D:/Study/Code/cubeIDE/fesc/CANopenNode" -I"D:/Study/Code/cubeIDE/fesc/CANopenNode_STM32" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CANopenNode-2f-309

clean-CANopenNode-2f-309:
	-$(RM) ./CANopenNode/309/CO_gateway_ascii.d ./CANopenNode/309/CO_gateway_ascii.o ./CANopenNode/309/CO_gateway_ascii.su

.PHONY: clean-CANopenNode-2f-309

