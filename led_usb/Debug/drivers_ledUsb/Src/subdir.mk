################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/carlos-leite/Firmware/atividade1/drivers_ledUsb/Src/driver_usb.c 

OBJS += \
./drivers_ledUsb/Src/driver_usb.o 

C_DEPS += \
./drivers_ledUsb/Src/driver_usb.d 


# Each subdirectory must supply rules for building sources it contributes
drivers_ledUsb/Src/driver_usb.o: /home/carlos-leite/Firmware/atividade1/drivers_ledUsb/Src/driver_usb.c drivers_ledUsb/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"/home/carlos-leite/Firmware/atividade1/drivers_ledUsb/Inc" -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I"/home/carlos-leite/Firmware/atividade1/libs/cJSON-1.7.19" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -ftls-model=local-exec -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers_ledUsb-2f-Src

clean-drivers_ledUsb-2f-Src:
	-$(RM) ./drivers_ledUsb/Src/driver_usb.cyclo ./drivers_ledUsb/Src/driver_usb.d ./drivers_ledUsb/Src/driver_usb.o ./drivers_ledUsb/Src/driver_usb.su

.PHONY: clean-drivers_ledUsb-2f-Src

