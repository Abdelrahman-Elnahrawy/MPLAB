#ifndef SPI_CFG_H
#define SPI_CFG_H

#include "../include/Std_Types.h"
#include "../config/Spi_Cfg.h"
#include "../include/Spi_Types.h"

// Configuration structure for SPI
typedef struct {
    Spi_ModeType spiMode;           // SPI mode (clock polarity and phase)
    Spi_ClockSpeedType clockSpeed;  // SPI clock speed
    uint8 sckPin;                   // SCK pin
    uint8 mosiPin;                  // MOSI pin
    uint8 misoPin;                  // MISO pin
    uint8 ssPin;                    // SS (Slave Select) pin
} Spi_ConfigType;

// External declaration of the SPI configuration
extern const Spi_ConfigType Spi_Configurations;

#endif /* SPI_CFG_H */
