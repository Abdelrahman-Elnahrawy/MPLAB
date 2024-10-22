/*_____________________________ ADC_TYPES_H _____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: 17 SEP 2024            /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : {PROJECT_NAME}               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

#ifndef ADC_TYPES_H
#define ADC_TYPES_H

#include "Std_Types.h"

// Enumeration for ADC channels
typedef enum {
    ADC_CHANNEL_AN0 = 0,  // Channel AN0 (GP0)
    ADC_CHANNEL_AN1,      // Channel AN1 (GP1)
    ADC_CHANNEL_AN2,      // Channel AN2 (GP2)
    ADC_CHANNEL_AN3       // Channel AN3 (GP4)
} Adc_ChannelType;

// Enumeration for ADC result format (left or right justified)
typedef enum {
    ADC_RESULT_LEFT = 0,  // Left-justified result
    ADC_RESULT_RIGHT      // Right-justified result
} Adc_ResultFormatType;

#endif /* ADC_TYPES_H */
