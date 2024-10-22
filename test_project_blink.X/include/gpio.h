/*_____________________________Gpio.h_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on:17 sep 2024             /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : PIC EXPLORING               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/
#ifndef GPIO_H
#define GPIO_H

#include "../config/Gpio_Cfg.h"
#include "Gpio_Types.h"
// API to initialize the GPIO driver
uint8 Gpio_Init(const Gpio_ConfigType* ConfigPtr);

uint8 Gpio_Pin_Dio(Gpio_PinNumber pinNumber, 
                   Gpio_PinDirectionType direction,
                   Gpio_PinStateType state,
                   uint8 pullType) ;

#endif /* GPIO_H */
