/*_____________________________ DIO_CFG_H _____________________________________
                                      ___           ___           __
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
 _____________________________________________________________________________*/

#ifndef DIO_CFG_H
#define DIO_CFG_H

#include "../include/Dio_Types.h"

// Define the total number of DIO pins
#define DIO_PIN_COUNT 6

// Configuration structure for DIO pins
typedef struct {
    Dio_PinNumber          pinNumber;        // Pin number (0 to 5)
    Dio_PinDirectionType PinDirection;
    Dio_PinState         StateType;
    Dio_PullType         PullType;
} Dio_ConfigType;

// External configuration data
extern const Dio_ConfigType Dio_Configurations[DIO_PIN_COUNT];

#endif /* DIO_CFG_H */
