/*_____________________________Gpio_Cfg.C_____________________________________________________
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

#include "Gpio_Cfg.h"
#include "../include/Gpio_Types.h"

// Example configuration for the GPIO pins
const Gpio_ConfigType Gpio_Configurations[GPIO_PIN_COUNT] = {
    {GPIO_PIN0_GPIO,GPIO_PIN_0},   // Pin 0 as output
    {GPIO_PIN1_GPIO,GPIO_PIN_1},   // Pin 1 as input with pull-up
    {GPIO_PIN2_AN2 ,GPIO_PIN_2},   // Pin 2 as input
    {GPIO_PIN3_GPIO,GPIO_PIN_3},  // Pin 3 as output // only work as input AS it is the reset pin and douesnt support pull up
    {GPIO_PIN4_GPIO,GPIO_PIN_4},  // Pin 4 as input with pull-up
    {GPIO_PIN5_GPIO,GPIO_PIN_5}   // Pin 5 as output
};
