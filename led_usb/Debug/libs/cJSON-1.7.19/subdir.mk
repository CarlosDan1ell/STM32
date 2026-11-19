################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19/cJSON.c \
/home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19/cJSON_Utils.c 

OBJS += \
./libs/cJSON-1.7.19/cJSON.o \
./libs/cJSON-1.7.19/cJSON_Utils.o 

C_DEPS += \
./libs/cJSON-1.7.19/cJSON.d \
./libs/cJSON-1.7.19/cJSON_Utils.d 


# Each subdirectory must supply rules for building sources it contributes
libs/cJSON-1.7.19/cJSON.o: /home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19/cJSON.c libs/cJSON-1.7.19/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/carlos-leite/Firmware/atividade1/drivers_ledUsb/Inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"/home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -ftls-model=local-exec -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
libs/cJSON-1.7.19/cJSON_Utils.o: /home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19/cJSON_Utils.c libs/cJSON-1.7.19/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/carlos-leite/Firmware/atividade1/drivers_ledUsb/Inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"/home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -ftls-model=local-exec -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-libs-2f-cJSON-2d-1-2e-7-2e-19

clean-libs-2f-cJSON-2d-1-2e-7-2e-19:
	-$(RM) ./libs/cJSON-1.7.19/cJSON.cyclo ./libs/cJSON-1.7.19/cJSON.d ./libs/cJSON-1.7.19/cJSON.o ./libs/cJSON-1.7.19/cJSON.su ./libs/cJSON-1.7.19/cJSON_Utils.cyclo ./libs/cJSON-1.7.19/cJSON_Utils.d ./libs/cJSON-1.7.19/cJSON_Utils.o ./libs/cJSON-1.7.19/cJSON_Utils.su

.PHONY: clean-libs-2f-cJSON-2d-1-2e-7-2e-19

