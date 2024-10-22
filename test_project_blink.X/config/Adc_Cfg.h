/*_____________________________ Main.c _____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on:16 sep 2024             /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : Exploring Pic               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/

#ifndef ADC_CFG_H
#define ADC_CFG_H

#include "../include/Adc_Types.h"

/*
 * This code defines a set of macros to calculate the ADC clock periods for different divisions of the oscillator frequency (Fosc) and sets the ADCON0 register accordingly for the PIC12F675 microcontroller.
 *
 * Macros for ADC Periods:
 * -----------------------
 * These macros calculate the ADC clock periods in nanoseconds for different divisions of the oscillator frequency (Fosc).
 * - ADC_PERIOD_FOSC2_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/2.
 * - ADC_PERIOD_FOSC4_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/4.
 * - ADC_PERIOD_FOSC8_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/8.
 * - ADC_PERIOD_FOSC16_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/16.
 * - ADC_PERIOD_FOSC32_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/32.
 * - ADC_PERIOD_FOSC64_NS(xtalFreq_Hz): Calculates the ADC period for Fosc/64.
 *
 * Macro to Check ADC Periods:
 * ---------------------------
 * The CHECK_ADC_PERIODS macro checks which of the calculated ADC periods is less than or equal to 6.25 nanoseconds. the adc freq = 6.25MHZ the fastest to reach 1.6 uS FOR CONVERSION
 * It returns the corresponding bit pattern for the ADCS bits in the ADCON0 register.
 * - If ADC_PERIOD_FOSC2_NS is <= 6.25, it returns 0b00 (Fosc/2).
 * - If ADC_PERIOD_FOSC4_NS is <= 6.25, it returns 0b01 (Fosc/4).
 * - If ADC_PERIOD_FOSC8_NS is <= 6.25, it returns 0b10 (Fosc/8).
 * - If ADC_PERIOD_FOSC16_NS is <= 6.25, it returns 0b11 (Fosc/16).
 * - If ADC_PERIOD_FOSC32_NS is <= 6.25, it returns 0b100 (Fosc/32).
 * - If ADC_PERIOD_FOSC64_NS is <= 6.25, it returns 0b101 (Fosc/64).
 * - If none of the periods are <= 6.25, it defaults to 0b111 (Fosc/64).
 *
 * Macro to Set ADCON0 Register:
 * -----------------------------
 * The SET_ADCON0 macro sets the ADCON0 register with the appropriate ADCS bits and enables the ADC by setting the ADON bit.
 * - It shifts the result of CHECK_ADC_PERIODS(xtalFreq_Hz) left by 6 bits to place it in the ADCS bits of ADCON0.
 * - It ORs this value with 0b00000001 to set the ADON bit, enabling the ADC.
 *
 * Example Usage:
 * --------------
 * uint32_t xtalFreq_Hz = 4000000; // Example crystal frequency
 * SET_ADCON0(xtalFreq_Hz); // Sets the ADCON0 register based on the crystal frequency
 *
 * This setup ensures that the ADC is configured for the fastest possible clock period that meets the requirement of being less than or equal to 1.6 microseconds.
 */
// 10 TICKS FOR ADC CONVERSION, MIN TIME FOR CONVERSION = 1.6 µs (1600 nanoseconds )
#define ADC_PERIOD_FOSC2_NS(xtalFreq_Hz)  (2000000  / ((xtalFreq_Hz)/1000 ))  // Fosc/2
#define ADC_PERIOD_FOSC4_NS(xtalFreq_Hz)  (4000000  / ((xtalFreq_Hz)/1000 ))  // Fosc/4
#define ADC_PERIOD_FOSC8_NS(xtalFreq_Hz)  (8000000  / ((xtalFreq_Hz)/1000 ))  // Fosc/8
#define ADC_PERIOD_FOSC16_NS(xtalFreq_Hz) (16000000 / ((xtalFreq_Hz)/1000 )) // Fosc/16
#define ADC_PERIOD_FOSC32_NS(xtalFreq_Hz) (32000000 / ((xtalFreq_Hz)/1000 )) // Fosc/32
#define ADC_PERIOD_FOSC64_NS(xtalFreq_Hz) (64000000 / ((xtalFreq_Hz)/1000 )) // Fosc/64

// Checks the available clock periods and returns the correct ADCS bits
#define CHECK_ADC_PERIODS(xtalFreq_Hz) \
    (\
    (ADC_PERIOD_FOSC2_NS(xtalFreq_Hz)  >= 1600)   ? 0b000   : \
    (ADC_PERIOD_FOSC4_NS(xtalFreq_Hz)  >= 1600)   ? 0b100   : \
    (ADC_PERIOD_FOSC8_NS(xtalFreq_Hz)  >= 1600)   ? 0b001   : \
    (ADC_PERIOD_FOSC16_NS(xtalFreq_Hz) >= 1600)   ? 0b101   : \
    (ADC_PERIOD_FOSC32_NS(xtalFreq_Hz) >= 1600)   ? 0b010   : \
    (ADC_PERIOD_FOSC64_NS(xtalFreq_Hz) >= 1600)   ? 0b110   : 0b110) // Default to Fosc/64


#define SET_ADC_CONVERSION_SPEED_1_6US(xtalFreq_Hz) \
    (ANSEL &= ~(0b111 << 4) );\
    (ANSEL |= (CHECK_ADC_PERIODS(xtalFreq_Hz) << 4) ) 

#define VCFG_VREF 1
#define VCFG_VDD  0
#define SET_VOLTAGE_REFRENCE( refrence ) \
    (ADCON0 &= ~(0b1 << 6));\
    (ADCON0 |=(refrence << 6))


// Configuration structure for ADC
// Configuration structure for ADC
typedef struct {
    Adc_ChannelType channel;           // ADC channel (AN0 to AN3)
    Adc_ResultFormatType resultFormat; // ADC result format (left or right justified)
} Adc_ConfigType;

// External declaration of the configuration
extern const Adc_ConfigType Adc_Configurations[];

#endif /* ADC_CFG_H */
