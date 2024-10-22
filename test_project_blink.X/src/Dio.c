/*_____________________________ DIO_C _____________________________________________________
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

#include "../include/Dio.h"
#include "../include/gpio.h"
#include "../config/Gpio_Cfg.h"
#include <xc.h>


static uint8 Gpio_State ;

uint8 Dio_Init(const Dio_ConfigType* ConfigPtr) {
    GPIO = 0x00;
    uint8 result = E_OK;
    if (ConfigPtr == NULL) {
        return E_NOT_OK;  // Return error if configuration pointer is NULL
    }

    // Loop through each pin in the configuration array
    for (uint8 i = 0; i < GPIO_PIN_COUNT; i++) {
        // Check if the pin is marked as "Not Applicable" or if an analog pin is set as output
        if (ConfigPtr[i].PinDirection != DIO_NOT_APPLICABLE) {
            
            if (!(
                (ConfigPtr[i].pinNumber == 0 && (ANSEL & (1 << 0)))   ||  // GP0 corresponds to AN0
                (ConfigPtr[i].pinNumber == 1 && (ANSEL & (1 << 1)))   ||  // GP1 corresponds to AN1
                (ConfigPtr[i].pinNumber == 2 && (ANSEL & (1 << 2)))   ||  // GP2 corresponds to AN2
                (ConfigPtr[i].pinNumber == 4 && (ANSEL & (1 << 3)))
                    ))
            {
                result = Gpio_Pin_Dio(
                     (Gpio_PinNumber)ConfigPtr[i].pinNumber,
                     (Gpio_PinDirectionType)ConfigPtr[i].PinDirection,
                     (Gpio_PinStateType)ConfigPtr[i].StateType,
                     ConfigPtr[i].PullType
                     );
            } else {
                return E_NOT_OK;  // Return error if pin initialization fails  
            }
        }
        if (result != E_OK) {
            return E_NOT_OK;  // Return error if pin initialization fails  
        }
    
    }

    return E_OK;  // All pins initialized successfully
}

// Read the state of a DIO pin
Dio_PinState Dio_ReadPin(Dio_PinNumber pinNumber) {
        if (GPIO & (1 << pinNumber)) {
            return DIO_PIN_HIGH;  // Return high state
        } else {
            return DIO_PIN_LOW;   // Return low state
        }
}

// Write a state (high or low) to a DIO pin

// Function to write a state to a pin
uint8 Dio_WritePin(Dio_PinNumber pinNumber, Dio_PinState state) {
    if (pinNumber <GPIO_PIN_COUNT ){
    if (state == DIO_PIN_HIGH) {
        Gpio_State |= (1 << pinNumber);  // Set pin high
    } else {
        Gpio_State &= ~(1 << pinNumber); // Set pin low
    }
    GPIO = Gpio_State ;
          return E_OK;
    } else {
        
      return E_NOT_OK;
    }
}
uint8 Dio_TogglePin(Dio_PinNumber pinNumber) {
    if (pinNumber < GPIO_PIN_COUNT) {
        // Toggle the current state of the pin
        Gpio_State ^= (1 << pinNumber);  // Flip the bit for the specified pin
        GPIO = Gpio_State;              // Update the GPIO register
        return E_OK;
    } else {
        return E_NOT_OK;
    }
}
