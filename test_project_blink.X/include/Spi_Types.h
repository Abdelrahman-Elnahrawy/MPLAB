#ifndef SPI_TYPES_H
#define SPI_TYPES_H

#include "../include/Std_Types.h"

// Enumeration for SPI Modes (Clock Polarity and Phase)
typedef enum {
    SPI_MODE0 = 0,  // Clock polarity 0, clock phase 0
    SPI_MODE1,      // Clock polarity 0, clock phase 1
    SPI_MODE2,      // Clock polarity 1, clock phase 0
    SPI_MODE3       // Clock polarity 1, clock phase 1
} Spi_ModeType;

// Enumeration for SPI Clock Speed (bit rate)
typedef enum {
    SPI_CLOCK_DIV4   = 4,    // Fosc/4
    SPI_CLOCK_DIV16  = 16,   // Fosc/16
    SPI_CLOCK_DIV64  = 64,   // Fosc/64
    SPI_CLOCK_DIV128 = 128   // Fosc/128
} Spi_ClockSpeedType;

#endif /* SPI_TYPES_H */
