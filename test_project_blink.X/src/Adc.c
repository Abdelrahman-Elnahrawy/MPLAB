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

#include "../include/Adc.h"
#include "../config/Adc_Cfg.h"
#include "../include/Adc_Types.h"
#include "../include/Std_Types.h"
#include "../efuse.h"
#include <xc.h>

/*
 ADCON0 ? A/D CONTROL REGISTER (ADDRESS: 1Fh)
 bit 7 ADFM: A/D Result Formed Select bit
 * 
1 = Right justified
0 = Left justified
 * 
bit 6 VCFG: Voltage Reference bit
1 = VREF pin
0 = VDD
 * 
bit 5-4 Unimplemented: Read as zero
bit 3-2 CHS1:CHS0: Analog Channel Select bits
 * 
00 = Channel 00 (AN0)
01 = Channel 01 (AN1)
10 = Channel 02 (AN2)
11 = Channel 03 (AN3)
 * 
bit 1 GO/DONE: A/D Conversion Status bit
1 = A/D conversion cycle in progress. Setting this bit starts an A/D conversion cycle.
This bit is automatically cleared by hardware when the A/D conversion has completed.
0 = A/D conversion completed/not in progress
 * 
bit 0 ADON: A/D Conversion STATUS bit
1 = A/D converter module is operating
0 = A/D converter is shut-off and consumes no operating current
 */


uint8 Adc_Init(const Adc_ConfigType* ConfigPtr) {
    
    
#ifdef VREF_VOLTAGE_REFRENCE
    SET_VOLTAGE_REFRENCE(VCFG_VREF);
#else
    SET_VOLTAGE_REFRENCE(VCFG_VDD);
#endif
     
SET_ADC_CONVERSION_SPEED_1_6US(_XTAL_FREQ);  


    if (ConfigPtr == NULL) {
        return E_NOT_OK;  // Do nothing if configuration pointer is NULL
    }

    if (!(
       (ConfigPtr->channel == ADC_CHANNEL_AN0 && (ANSEL & (1 << 0)))   ||  // GP0 corresponds to AN0
       (ConfigPtr->channel == ADC_CHANNEL_AN1 && (ANSEL & (1 << 1)))   ||  // GP1 corresponds to AN1
       (ConfigPtr->channel == ADC_CHANNEL_AN2 && (ANSEL & (1 << 2)))   ||  // GP2 corresponds to AN2
       (ConfigPtr->channel == ADC_CHANNEL_AN3 && (ANSEL & (1 << 3)))
            ))
    {
        return E_NOT_OK;
    
    } else{}


    // Set the result format (left or right justified)
    if (ConfigPtr->resultFormat == ADC_RESULT_RIGHT) {
        ADCON0 |=  (1 << 7);  // ADFM = 1, right-justified result
    } else {
        ADCON0 &= ~(1 << 7); // ADFM = 0, left-justified result
    }
        return E_OK;
}
void Adc_Init_pin(Adc_ChannelType channel , Adc_ResultFormatType format){
        ADCON0 |=  (1 << 0);   // TURNING ON THE PREPHIREAL
#ifdef VREF_VOLTAGE_REFRENCE
    SET_VOLTAGE_REFRENCE(VCFG_VREF);
#else
    SET_VOLTAGE_REFRENCE(VCFG_VDD);
#endif
     
SET_ADC_CONVERSION_SPEED_1_6US(_XTAL_FREQ);  


    // Select ADC channel and configure ANSEL
    switch (channel) {
        case ADC_CHANNEL_AN0:
            ANSEL |= (1 << 0);  // Set GP0 as analog input AN0
            break;
        case ADC_CHANNEL_AN1:
            ANSEL |= (1 << 1);  // Set GP1 as analog input AN1
            break;
        case ADC_CHANNEL_AN2:
            ANSEL |= (1 << 2);  // Set GP2 as analog input AN2
            break;
        case ADC_CHANNEL_AN3:
            ANSEL |= (1 << 3);  // Set GP4 as analog input AN3
            break;
        default:
            return;  // Invalid channel, return
    }

    // Set the result format (left or right justified)
    if (format == ADC_RESULT_RIGHT) {
        ADCON0 |=  (1 << 7);  // ADFM = 1, right-justified result
    } else {
        ADCON0 &= ~(1 << 7);  // ADFM = 0, left-justified result
    }
    
}

uint8 Adc_StartConversion(Adc_ChannelType channel) {
    
    
        if (!(
       (channel == ADC_CHANNEL_AN0 && (ANSEL & (1 << 0)))   ||  // GP0 corresponds to AN0
       (channel == ADC_CHANNEL_AN1 && (ANSEL & (1 << 1)))   ||  // GP1 corresponds to AN1
       (channel == ADC_CHANNEL_AN2 && (ANSEL & (1 << 2)))   ||  // GP2 corresponds to AN2
       (channel == ADC_CHANNEL_AN3 && (ANSEL & (1 << 3)))
            ))
    {
        return E_NOT_OK;
    
    }
        else{
    
    // Select ADC channel
    ADCON0 &= ~( 0b11 <<  2);  // Clear the channel selection bits
    ADCON0 |= (channel << 2);  // Set the channel
    ADCON0 |= (1 << 1);  // Set GO/DONE bit to start conversion
    return E_OK;
        }
}


uint16 Adc_ReadResult(void) {
    while (ADCON0 & (1 << 1));  // Wait for the conversion to complete (GO/DONE bit cleared)

    // Check if the result is right or left justified (based on ADFM)
    if (ADCON0 & (1 << 7)) {
        // Right-justified result (ADFM = 1)
        return (uint16)((ADRESH << 8) | ADRESL);        // Combine ADRESH and ADRESL for 10-bit result
    } else {
        // Left-justified result (ADFM = 0)
        return (uint16)((ADRESH << 2) | (ADRESL >> 6));  // Adjust the result for left-justified 10-bit result
    }
}
