#ifndef SPI_H
#define SPI_H

#include "Spi_Types.h"
#include "../config/Spi_Cfg.h"

// Initializes the SPI module
uint8 Spi_Init(const Spi_ConfigType* ConfigPtr);

// Sends and receives a single byte of data (full-duplex)
uint8 Spi_TransmitReceive(uint8 data);

// Sends a single byte of data (half-duplex)
void Spi_Transmit(uint8 data);

// Receives a single byte of data (half-duplex)
uint8 Spi_Receive(void);

#endif /* SPI_H */
