################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CANopenNode/extra/CO_trace.c 

OBJS += \
./CANopenNode/extra/CO_trace.o 

C_DEPS += \
./CANopenNode/extra/CO_trace.d 


# Each subdirectory must supply rules for building sources it contributes
CANopenNode/extra/%.o CANopenNode/extra/%.su: ../CANopenNode/extra/%.c CANopenNode/extra/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I"D:/Study/Code/cubeIDE/fesc/CANopenNode" -I"D:/Study/Code/cubeIDE/fesc/CANopenNode_STM32" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CANopenNode-2f-extra

clean-CANopenNode-2f-extra:
	-$(RM) ./CANopenNode/extra/CO_trace.d ./CANopenNode/extra/CO_trace.o ./CANopenNode/extra/CO_trace.su

.PHONY: clean-CANopenNode-2f-extra

