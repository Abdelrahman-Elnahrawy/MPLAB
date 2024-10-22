/*
 * File:   newmain.c
 * Author: Your Name <your.name at your.org>
 *
 * Created on October 17, 2024, 12:29 AM
 */

#define F_CPU 8000000UL 
#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



// Global variables to manage the state
volatile uint8_t currentAddress;  // Current I2C slave address
volatile uint8_t *dataBuffer;      // Pointer to the data buffer
volatile uint8_t dataLength;       // Length of the data to be sent or received
volatile uint8_t dataIndex;        // Current index in the data buffer
volatile uint8_t isWriting;        // Flag to indicate writing or reading

// TWI Status Register (TWSR) status codes
#define TWI_START              0x08  // Start condition transmitted
#define TWI_REP_START         0x10  // Repeated start condition transmitted
#define TWI_MT_SLA_ACK        0x18  // SLA+W transmitted, ACK received
#define TWI_MT_SLA_NACK       0x20  // SLA+W transmitted, NACK received
#define TWI_MT_DATA_ACK       0x28  // Data byte transmitted, ACK received
#define TWI_MT_DATA_NACK      0x30  // Data byte transmitted, NACK received
#define TWI_MR_SLA_ACK        0x40  // SLA+R transmitted, ACK received
#define TWI_MR_SLA_NACK       0x48  // SLA+R transmitted, NACK received
#define TWI_MR_DATA_ACK       0x50  // Data byte received, ACK returned
#define TWI_MR_DATA_NACK      0x58  // Data byte received, NACK returned


void sendbyteNew(uint8_t adr , uint8_t data){
        currentAddress =(adr << 1) | (0x01) ;
        TWCR |= (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
        
}

void i2cInitNew(){

    // Set SCL frequency to 400kHz (Fast Mode)
    // Assuming 8 MHz clock and TWPS (prescaler) set to 0
    TWBR = 0x02; // Bit rate register
    TWSR &= ~(1 << TWPS1) & ~(1 << TWPS0); // Set prescaler to 1 (no scaling)

    // Enable TWI and TWI interrupt
    TWCR = (1 << TWEN) | (1 << TWIE); // Enable TWI, Enable TWI Interrupt

    // Enable global interrupts
    sei();
}


ISR(TWI_vect) {
      PORTB= 0xFF;
}

int main(void) {
    
    _delay_ms(1000);
    DDRB = 0XFF;
  //  PORTB= 0xFF;
    i2cInitNew();
 
    // Now you can use `received_data` for your application
     sendbyteNew(0x50 , 0x11);
    while(1){}
    return 0;
}


