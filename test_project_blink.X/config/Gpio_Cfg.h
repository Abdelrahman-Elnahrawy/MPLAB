/*_____________________________GPIO_CFG_H_____________________________________________________
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
#ifndef GPIO_CFG_H
#define GPIO_CFG_H

#include "../include/Std_Types.h"
#include "../include/Gpio_Types.h"
#define GPIO_PIN_COUNT 6  // Number of available GPIO pins for PIC12F629/675

// Enable or disable pull-up resistors for individual pins
#define GPIO_PULLUP_ENABLE  1
#define GPIO_PULLUP_DISABLE 0

// Configuration structure
typedef struct {
    Gpio_PinFunctionEnum pinFunction;
    uint8 pinNumber     ;       // Pin number (0 to 5)
} Gpio_ConfigType;

extern const Gpio_ConfigType Gpio_Configurations[GPIO_PIN_COUNT];

#endif /* GPIO_CFG_H */
