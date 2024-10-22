/*_____________________________GPIO_TYPES.H_____________________________________________________
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
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

typedef enum {
    GPIO_PIN_LOW = 0,  // Logic Low
    GPIO_PIN_HIGH      // Logic High
} Gpio_PinStateType;

typedef enum {
    GPIO_DIR_INPUT = 0,  // Input direction
    GPIO_DIR_OUTPUT      // Output direction
} Gpio_PinDirectionType;

typedef enum {
    GPIO_PIN_0 = 0,  // Input direction
    GPIO_PIN_1 = 1,  // Input direction
    GPIO_PIN_2 = 2,  // Input direction
    GPIO_PIN_3 = 3,  // Input direction
    GPIO_PIN_4 = 4,  // Input direction
    GPIO_PIN_5 = 5,  // Input direction
} Gpio_PinNumber;
typedef enum {
    // GP0 functions
    GPIO_PIN0_GPIO = 0,        // General Purpose I/O
    GPIO_PIN0_AN0,             // Analog Input AN0 (for PIC12F675 only)
    GPIO_PIN0_CIN_PLUS,        // Comparator CIN+ input
    GPIO_PIN0_ICSPDAT,         // ICSP Data (programming)

    // GP1 functions
    GPIO_PIN1_GPIO,            // General Purpose I/O
    GPIO_PIN1_AN1,             // Analog Input AN1 (for PIC12F675 only)
    GPIO_PIN1_CIN_MINUS,       // Comparator CIN- input
    GPIO_PIN1_VREF,            // Voltage Reference input (PIC12F675 only)
    GPIO_PIN1_ICSPCLK,         // ICSP Clock (programming)

    // GP2 functions
    GPIO_PIN2_GPIO,            // General Purpose I/O
    GPIO_PIN2_AN2,             // Analog Input AN2 (for PIC12F675 only)
    GPIO_PIN2_T0CKI,           // Timer0 Clock Input
    GPIO_PIN2_INT,             // External Interrupt input
    GPIO_PIN2_COUT,            // Comparator Output

    // GP3 functions
    GPIO_PIN3_GPIO,            // General Purpose I/O (input-only)
    GPIO_PIN3_MCLR,            // Master Clear (MCLR) / VPP (Programming voltage input)

    // GP4 functions
    GPIO_PIN4_GPIO,            // General Purpose I/O
    GPIO_PIN4_AN3,             // Analog Input AN3 (for PIC12F675 only)
    GPIO_PIN4_T1G,             // Timer1 Gate input
    GPIO_PIN4_OSC2,            // Oscillator Output (CLKOUT)
    
    // GP5 functions
    GPIO_PIN5_GPIO,            // General Purpose I/O
    GPIO_PIN5_T1CKI,           // Timer1 Clock Input
    GPIO_PIN5_OSC1,            // Oscillator Input (CLKIN)
} Gpio_PinFunctionEnum;

#endif /* GPIO_TYPES_H */
