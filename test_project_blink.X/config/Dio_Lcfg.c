/*_____________________________ DIO_CFG_C _____________________________________________________
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



#include "Dio_Cfg.h"
#include "../include/Dio_Types.h"
// Configuration of the DIO pins
const Dio_ConfigType Dio_Configurations[DIO_PIN_COUNT] = {
    {DIO_PIN_0, DIO_DIR_OUTPUT    , DIO_PIN_LOW,DIO_PULL_NONE},   // Pin 0 as output
    {DIO_PIN_1, DIO_DIR_OUTPUT    , DIO_PIN_LOW,DIO_PULL_NONE},   // Pin 1 as input
    {DIO_PIN_2, DIO_NOT_APPLICABLE, DIO_PIN_LOW,DIO_PULL_NONE},   // Pin 2 as output
    {DIO_PIN_3, DIO_DIR_INPUT     , DIO_PIN_LOW,DIO_PULL_NONE},   // Pin 3 as input
    {DIO_PIN_4, DIO_DIR_INPUT     , DIO_PIN_LOW,DIO_PULL_NONE},   // Pin 4 as output
    {DIO_PIN_5, DIO_DIR_INPUT     , DIO_PIN_LOW,DIO_PULL_UP  }    // Pin 5 as input
};
