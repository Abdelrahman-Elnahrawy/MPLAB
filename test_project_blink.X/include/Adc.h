
/*_____________________________{FILE_NAME}______________________________________
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
 _____________________________________________________________________________*/

#ifndef ADC_H
#define ADC_H

#include "../include/Adc_Types.h"
#include "../config/Adc_Cfg.h"


// Initializes the ADC module
uint8 Adc_Init(const Adc_ConfigType* ConfigPtr);
void Adc_Init_pin(Adc_ChannelType channel , Adc_ResultFormatType format);
// Starts ADC conversion on the given channel
uint8 Adc_StartConversion(Adc_ChannelType channel);

// Reads the ADC conversion result (10-bit or 8-bit)
uint16 Adc_ReadResult(void);

#endif /* ADC_H */
