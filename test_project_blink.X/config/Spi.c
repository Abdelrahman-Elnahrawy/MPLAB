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

#include <xc.h>
#include "../config/Spi_Cfg.h"
#include "../include/Spi_Types.h"
#include "../include/Std_Types.h"
#include "../include/Spi.h"


#define _XTAL_FREQ 4000000  // Set the system frequency (4 MHz for example)

// Function to delay for one clock cycle based on the clock speed
static void Spi_Delay(Spi_ClockSpeedType clockSpeed) {
    switch (clockSpeed) {
        case SPI_CLOCK_DIV4:
            __delay_us(1);  // Fosc/4
            break;
        case SPI_CLOCK_DIV16:
            __delay_us(4);  // Fosc/16
            break;
        case SPI_CLOCK_DIV64:
            __delay_us(16);  // Fosc/64
            break;
        case SPI_CLOCK_DIV128:
            __delay_us(32);  // Fosc/128
            break;
    }
}

// Initializes the SPI module
uint8 Spi_Init(const Spi_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        return E_NOT_OK;  // Return error if configuration pointer is NULL
    }

    // Configure the SCK, MOSI, and SS as output pins
    TRISIO &= ~(1 << ConfigPtr->sckPin);
    TRISIO &= ~(1 << ConfigPtr->mosiPin);
    TRISIO &= ~(1 << ConfigPtr->ssPin);

    // Configure the MISO as an input pin
    TRISIO |= (1 << ConfigPtr->misoPin);

    // Set the SS pin high (deselect the slave)
    GPIO |= (1 << ConfigPtr->ssPin);

    return E_OK;  // Initialization successful
}

// Sends and receives a single byte of data (full-duplex)
uint8 Spi_TransmitReceive(uint8 data) {
    uint8 receivedData = 0;
    
    // Loop through each bit (MSB first)
    for (uint8 i = 0; i < 8; i++) {
        // Write the MOSI pin based on the MSB
        if (data & 0x80) {
            GPIO |= (1 << Spi_Configurations.mosiPin);  // MOSI high
        } else {
            GPIO &= ~(1 << Spi_Configurations.mosiPin); // MOSI low
        }

        // Toggle SCK pin based on SPI mode
        if (Spi_Configurations.spiMode == SPI_MODE0 || Spi_Configurations.spiMode == SPI_MODE2) {
            // Clock low, then high
            GPIO &= ~(1 << Spi_Configurations.sckPin);  // SCK low
            Spi_Delay(Spi_Configurations.clockSpeed);
            GPIO |= (1 << Spi_Configurations.sckPin);   // SCK high
        } else {
            // Clock high, then low
            GPIO |= (1 << Spi_Configurations.sckPin);   // SCK high
            Spi_Delay(Spi_Configurations.clockSpeed);
            GPIO &= ~(1 << Spi_Configurations.sckPin);  // SCK low
        }
        // Read the MISO pin
        receivedData <<= 1;
        if (GPIO & (1 << Spi_Configurations.misoPin)) {
            receivedData |= 0x01;  // Read 1
        }
        // Shift the data to send the next bit
        data <<= 1;
        Spi_Delay(Spi_Configurations.clockSpeed);  // Delay for the next bit
    }
    return receivedData;
}

// Sends a single byte of data (half-duplex)
void Spi_Transmit(uint8 data) {
    Spi_TransmitReceive(data);  // Reuse the full-duplex function for transmission
}

// Receives a single byte of data (half-duplex)
uint8 Spi_Receive(void) {
    return Spi_TransmitReceive(0xFF);  // Transmit dummy data to receive
}
