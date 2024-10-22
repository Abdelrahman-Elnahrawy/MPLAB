/*_____________________________Gpio.C_____________________________________________________
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
#include <xc.h>
#include "../config/Gpio_Cfg.h"
#include "../include/Gpio_Types.h"
#include "../include/Std_Types.h"


static uint8 Gpio_State ;


// Internal function to configure pin direction
uint8 Gpio_Init(const Gpio_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        return E_NOT_OK;  // Return error if configuration pointer is NULL
    }

    // Loop through each pin in the configuration array
    for (uint8 i = 0; i < GPIO_PIN_COUNT; i++) {
        Gpio_PinFunctionEnum function = ConfigPtr[i].pinFunction;
        uint8 pinNumber = ConfigPtr[i].pinNumber;
             
        // Configure pin function (GPIO, Analog, or Alternate)
     // Configure pin function (GPIO, Analog, or Alternate)
        switch (function) {
            // GP0 functions
            case GPIO_PIN0_AN0:
                if (pinNumber != 0) return E_NOT_OK;  // Ensure this is GP0
                ANSEL  |= (1 << 0);   // Set GP0 as analog input AN0
                TRISIO |= (1 << 0);
                break;
            case GPIO_PIN0_CIN_PLUS:
                if (pinNumber != 0) return E_NOT_OK;  // Ensure this is GP0
                CMCON &= ~(1 << 0);  // Configure GP0 as Comparator CIN+ input
                break;
            case GPIO_PIN0_ICSPDAT:
                if (pinNumber != 0) return E_NOT_OK;  // Ensure this is GP0
                // No specific register for ICSPDAT, handled by ICSP programmer
                break;
            case GPIO_PIN0_GPIO:
                if (pinNumber != 0) return E_NOT_OK;  // Ensure this is GP0
                ANSEL &= ~(1 << 0);  // Set GP0 as digital I/O
                break;

            // GP1 functions
            case GPIO_PIN1_AN1:
                if (pinNumber != 1) return E_NOT_OK;  // Ensure this is GP1
                ANSEL  |= (1 << 1);   // Set GP1 as analog input AN1
                TRISIO |= (1 << 1);
                break;
            case GPIO_PIN1_CIN_MINUS:
                if (pinNumber != 1) return E_NOT_OK;  // Ensure this is GP1
                CMCON &= ~(1 << 1);  // Configure GP1 as Comparator CIN- input
                break;
            case GPIO_PIN1_VREF:
                if (pinNumber != 1) return E_NOT_OK;  // Ensure this is GP1
                VRCON |= (1 << 1);   // Set GP1 as Voltage Reference input
                break;
            case GPIO_PIN1_ICSPCLK:
                if (pinNumber != 1) return E_NOT_OK;  // Ensure this is GP1
                // No specific register for ICSPCLK, handled by ICSP programmer
                break;
            case GPIO_PIN1_GPIO:
                if (pinNumber != 1) return E_NOT_OK;  // Ensure this is GP1
                ANSEL &= ~(1 << 1);  // Set GP1 as digital I/O
                break;

            // GP2 functions
            case GPIO_PIN2_AN2:
                if (pinNumber != 2) return E_NOT_OK;  // Ensure this is GP2
                ANSEL  |= (1 << 2);   // Set GP2 as analog input AN2
                TRISIO |= (1 << 2);
                break;
            case GPIO_PIN2_T0CKI:
                if (pinNumber != 2) return E_NOT_OK;  // Ensure this is GP2
                OPTION_REG &= ~(1 << 5);  // Set GP2 as Timer0 clock input (T0CKI)
                break;
            case GPIO_PIN2_INT:
                if (pinNumber != 2) return E_NOT_OK;  // Ensure this is GP2
                OPTION_REG &= ~(1 << 6);  // Enable external interrupt on GP2
                break;
            case GPIO_PIN2_COUT:
                if (pinNumber != 2) return E_NOT_OK;  // Ensure this is GP2
                CMCON |= (1 << 6);   // Set GP2 as Comparator output (COUT)
                break;
            case GPIO_PIN2_GPIO:
                if (pinNumber != 2) return E_NOT_OK;  // Ensure this is GP2
                ANSEL &= ~(1 << 2);  // Set GP2 as digital I/O
                break;

            // GP3 functions
            case GPIO_PIN3_MCLR:
                if (pinNumber != 3) return E_NOT_OK;  // Ensure this is GP3
                // Configure GP3 as MCLR (Master Clear/Reset), no special register
                break;
            case GPIO_PIN3_GPIO:
                if (pinNumber != 3) return E_NOT_OK;  // Ensure this is GP3
                // GP3 is input-only, no digital configuration needed
                break;

            // GP4 functions
            case GPIO_PIN4_AN3:
                if (pinNumber != 4) return E_NOT_OK;  // Ensure this is GP4
                ANSEL  |= (1 << 3);   // Set GP4 as analog input AN3
                TRISIO |= (1 << 4);
                break;
            case GPIO_PIN4_T1G:
                if (pinNumber != 4) return E_NOT_OK;  // Ensure this is GP4
                T1CON |= (1 << 7);   // Set GP4 as Timer1 gate input (T1G)
                break;
            case GPIO_PIN4_OSC2:
                if (pinNumber != 4) return E_NOT_OK;  // Ensure this is GP4
                // Set GP4 as oscillator output (CLKOUT), no direct register needed
                break;
            case GPIO_PIN4_GPIO:
                if (pinNumber != 4) return E_NOT_OK;  // Ensure this is GP4
                ANSEL &= ~(1 << 3);  // Set GP4 as digital I/O
                break;

            // GP5 functions
            case GPIO_PIN5_T1CKI:
                if (pinNumber != 5) return E_NOT_OK;  // Ensure this is GP5
                T1CON |= (1 << 1);   // Set GP5 as Timer1 clock input (T1CKI)
                break;
            case GPIO_PIN5_OSC1:
                if (pinNumber != 5) return E_NOT_OK;  // Ensure this is GP5
                // Set GP5 as oscillator input (CLKIN), no direct register needed
                break;
            case GPIO_PIN5_GPIO:
                if (pinNumber != 5) return E_NOT_OK;  // Ensure this is GP5
                // GP5 is already digital by default unless used as CLKIN
                break;

            default:
                return E_NOT_OK;  // Invalid pin function, return error
        }
        
    }

    return E_OK;  // If all configurations are successful
}


// Function to write a state to a pin

uint8 Gpio_Pin_Dio(Gpio_PinNumber pinNumber, 
                   Gpio_PinDirectionType direction,
                   Gpio_PinStateType state,
                   uint8 pullType) 
{
    if (pinNumber >= GPIO_PIN_COUNT) {
        return E_NOT_OK;  // Invalid pin number
    }
    
    // Configure pin direction
    if (direction == GPIO_DIR_INPUT) {
        TRISIO |= (1 << pinNumber);  // Set pin as input
    } else if (direction == GPIO_DIR_OUTPUT) {
        TRISIO &= ~(1 << pinNumber); // Set pin as output
    } else {
        return E_NOT_OK;  // Invalid direction, return error
    }

    // Configure pull-up resistor
    if (pullType == GPIO_PULLUP_ENABLE && pinNumber != 3) {
        OPTION_REG &= ~(1 << 7);  // Enable pull-up resistor for the pin
        WPU |= (1 << pinNumber);  // Enable pull-up
    } else if (pullType == GPIO_PULLUP_DISABLE) {
        WPU &= ~(1 << pinNumber); // Disable pull-up
    } else {
        return E_NOT_OK;  // Invalid pull-up configuration, return error
    }

    // Configure pin state if it's an output pin
    if (direction == GPIO_DIR_OUTPUT) {
        if (state == GPIO_PIN_HIGH) {
            GPIO |= (1 << pinNumber); // Set pin high
        } else if (state == GPIO_PIN_LOW) {
            GPIO &= ~(1 << pinNumber); // Set pin low
        } else {
            return E_NOT_OK;  // Invalid state, return error
        }
    }

    return E_OK;  // Pin initialized successfully
}