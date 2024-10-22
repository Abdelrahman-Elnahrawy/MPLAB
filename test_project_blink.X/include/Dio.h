/*_____________________________ DIO_H _____________________________________________________
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

#ifndef DIO_H
#define DIO_H

#include "../include/Dio_Types.h"
#include "../config/Dio_Cfg.h"

// Initialize DIO pins based on configuration
uint8 Dio_Init(const Dio_ConfigType* ConfigPtr);

// Read the state of a DIO pin (high or low)
Dio_PinState Dio_ReadPin(Dio_PinNumber pinNumber);

// Write a state (high or low) to a DIO pin
uint8 Dio_WritePin(Dio_PinNumber pinNumber, Dio_PinState state);
uint8 Dio_TogglePin(Dio_PinNumber pinNumber);
#endif /* DIO_H */
