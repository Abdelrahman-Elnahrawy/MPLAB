/*_____________________________{FILE_NAME}_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on: {DATE}                 /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : {PROJECT_NAME}               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

#include "Adc_Cfg.h"
#include <xc.h>
#include <stdint.h>
#include "../include/Std_Types.h"

// Example configuration for the ADC module
const Adc_ConfigType Adc_Configurations[] = {
    {ADC_CHANNEL_AN0, ADC_RESULT_LEFT},  // Channel AN0, 10-bit resolution
    {ADC_CHANNEL_AN1, ADC_RESULT_LEFT},  // Channel AN1, 10-bit resolution
    {ADC_CHANNEL_AN2, ADC_RESULT_LEFT},  // Channel AN2, 10-bit resolution
    {ADC_CHANNEL_AN3, ADC_RESULT_LEFT}   // Channel AN3, 10-bit resolution
};
