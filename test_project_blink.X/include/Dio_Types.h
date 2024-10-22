/*_____________________________ DIO_TYPES_H ___________________________________
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
 _____________________________________________________________________________*/

#ifndef DIO_TYPES_H
#define DIO_TYPES_H

#include "Std_Types.h"

// Enumeration for pin state (high or low)
typedef enum {
    DIO_PIN_LOW = 0,
    DIO_PIN_HIGH
} Dio_PinState;

// Enumeration for pin direction (input or output)
typedef enum {
    DIO_DIR_INPUT = 0,
    DIO_DIR_OUTPUT,
    DIO_NOT_APPLICABLE  // Represents an invalid configuration (e.g., when the pin is analog)
} Dio_PinDirectionType;
// Pin numbers (0 to 5 for PIC12F629/675)
typedef enum {
    DIO_PIN_0 = 0,
    DIO_PIN_1,
    DIO_PIN_2,
    DIO_PIN_3,
    DIO_PIN_4,
    DIO_PIN_5
} Dio_PinNumber;


typedef enum {
    DIO_PULL_NONE = 0,  // No pull-up or pull-down
    DIO_PULL_UP,        // Enable pull-up resistor
} Dio_PullType;

#endif /* DIO_TYPES_H */
