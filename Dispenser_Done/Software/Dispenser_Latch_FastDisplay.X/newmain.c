/*
 * File:   NewMain.c
 * Author: Eng Abdelrahman Selim 
 * Created on September 25, 2024, 9:23 PM
 */


#define MAX_TIME       90               // the timer value in seconds if the ADC reads 5 volts 
#define START_DELAY    1000             // The delay in ms on powering on
#define DEBOUNCE_DELAY 255              // Debounce delay in ms (max 255)
#include <xc.h>

// Function Prototypes
void InitAll();     // initialize the ADC , GPIO and the interrupts
void Max7219ClearDisplay(void); // function loops all screen digits and clear it
void SpiSend16bit(uint16_t data);
void DioPinWrite(uint8_t pinNumber, uint8_t state);
uint16_t AdcReadResult();
void AdcStartConversion();
uint8_t DispenserOn;     // A flag set when the valve is open
static uint8_t DioState; // A variable to save the current state of the output pins

// Configuration Bits
#pragma config FOSC = INTRCIO // Internal oscillator, I/O on GP4 and GP5
#pragma config WDTE = OFF     // Disable Watchdog Timer
#pragma config PWRTE = OFF    // Disable Power-Up Timer
#pragma config MCLRE = OFF    // Disable MCLR
#pragma config BOREN = OFF    // Disable Brown-out Detect
#pragma config CP = OFF       // Disable Code Protection
#pragma config CPD = OFF      // Disable Data Protection

// Constants and Macros
#define _XTAL_FREQ 4000000 // Set oscillator frequency to 4 MHz

#define LOW 0
#define HIGH 1

// Pin Definitions
#define GPIO_PIN_0 0 // Pin 0
#define GPIO_PIN_1 1 // Pin 1 (MOSI)
#define GPIO_PIN_2 2 // Pin 2 (CLK)
#define GPIO_PIN_3 3 // Pin 3 (Interrupt)
#define GPIO_PIN_4 4 // Pin 4 (Output control)
#define GPIO_PIN_5 5 // Pin 5 (Chip select)

#define OUTPUT_CONTROL    GPIO_PIN_4  
#define SENSOR_IN         GPIO_PIN_3   

#define DIO_READ_PIN(pinNumber)(GPIO & (1 << pinNumber))

// SPI Settings
#define SPI_MOSI  GPIO_PIN_1
#define SPI_CLK   GPIO_PIN_2
#define SPI_CS    GPIO_PIN_5
#define SPI_DELAY __delay_us(1) // SPI delay  1us hence the spi is on 500KHZ as this delay is called twice in SpiSend16bit loop

#define MAX7219_INIT()\
SpiSend16bit(0x0900); /* No decode mode for all digits */ \
SpiSend16bit(0x0A0F); /* Maximum intensity */ \
SpiSend16bit(0x0B07); /* Display all digits (0-7) */ \
SpiSend16bit(0x0C01); /* Exit shutdown mode */ \
SpiSend16bit(0x0F00);  /* Disable test mode */ \
Max7219ClearDisplay()

// Display Registers for MAX7219
#define MAX7219_REG_DIGIT0 0x01
#define MAX7219_REG_DIGIT1 0x02
#define MAX7219_REG_DIGIT2 0x03
#define MAX7219_REG_DIGIT3 0x04

// Number Definitions for MAX7219
#define MAX7219_0 0x7E
#define MAX7219_1 0x30
#define MAX7219_2 0x6D
#define MAX7219_3 0x79
#define MAX7219_4 0x33
#define MAX7219_5 0x5B
#define MAX7219_6 0x5F
#define MAX7219_7 0x70
#define MAX7219_8 0x7F
#define MAX7219_9 0x7B

// Additional Character Definitions
#define MAX7219_H       0x37
#define MAX7219_E       0x4F
#define MAX7219_L       0x0E
#define MAX7219_O       0x1D
#define MAX7219_F       0x47
#define MAX7219_N       0x15
#define MAX7219_DOT_BIT 0x80

// MAX7219 Display Functions Send via spi the digit and the 
#define MAX7219_DISPLAYDATA(digit, bits) SpiSend16bit((digit) << 8 | (bits))

// Display "HELLO"
#define MAX7219_DISPLAY_HELLO()\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT3, MAX7219_H);\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT2, MAX7219_E);\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT1, MAX7219_L);\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT0, MAX7219_O)

// Display "OFF"
#define MAX7219_DISPLAY_OFF()\
Max7219ClearDisplay();\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT3, MAX7219_O);\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT2, MAX7219_F);\
MAX7219_DISPLAYDATA(MAX7219_REG_DIGIT1, MAX7219_F)


// ADC Macros
#define ADC_START_CONVERSION() ADCON0 |= (1 << 1) // Start ADC conversion

const uint8_t MAX7219_No_Table[] = {
    MAX7219_0,
    MAX7219_1,
    MAX7219_2,
    MAX7219_3,
    MAX7219_4,
    MAX7219_5,
    MAX7219_6,
    MAX7219_7,
    MAX7219_8,
    MAX7219_9
};

void main(void) {
    InitAll();
    __delay_ms(START_DELAY);
    MAX7219_DISPLAY_HELLO();
    DispenserOn =0;
    while(1){
        while (DispenserOn) { //Check if the flag of Dispenser operation is set
            ADC_START_CONVERSION();
            // ((200 * ((uint32_t) AdcReadResult())) / 1023) Get the ADC value and normalize it to 200 units 
            // Then Multiply that by the Time in full range of seconds to get the number of ticks needed tick = 5ms
            // example the ADC reads 512  MAX_TIME 90
            //adc factor 500*200/1023 = 100   the number of seconds is 90 so it will be 
            // 9000 tick , remember that the tick is 5 ms  so 9000 tick * 5 ms = 45 000 ms 
            uint32_t Counter = MAX_TIME * ((200 * ((uint32_t) AdcReadResult())) / 1023);
            DioPinWrite(OUTPUT_CONTROL, HIGH); //Set the OutputPin 
            for (;(Counter > 0) && DispenserOn; Counter--) {
                if (Counter % 10 == 0) {                                        //Display the data every 10 ticks (about 5 ms)
                    uint8_t Current_Digit = 1;                                  // the current digit to display 
                    for (uint16_t i = 1; i < 10000; i *= 10, Current_Digit++) { // i represent the unit (units),(tens),(hundreds) etc 
                        uint16_t value = (Counter % (i * 20)) / (i*2);          //calculate the value in the i (units),(tens),(hundreds) etc 
                        if (i == 100) {
                            MAX7219_DISPLAYDATA((uint16_t) Current_Digit, MAX7219_DOT_BIT | MAX7219_No_Table[value]);   // if its the digit beside the ms display the dot
                        } else {
                            MAX7219_DISPLAYDATA((uint16_t) Current_Digit, MAX7219_No_Table[value]);
                        }
                    }
                }
                                __delay_us(1250); // this delay is adjusted manually by aproximating the time to excute the loop above and simulation
            }
            DispenserOn = 0;
            DioPinWrite(OUTPUT_CONTROL, LOW);
            MAX7219_DISPLAY_OFF();
            __delay_ms(1000);
            MAX7219_DISPLAY_HELLO();
        }
    }
    return;
}

uint16_t AdcReadResult() {
    while (ADCON0 & (1 << 1)) {} // Wait for ADC conversion to complete
    return (uint16_t)((ADRESH << 2) | (ADRESL >> 6)); // Adjust left-justified 10-bit result
}

void InitAll() {
    // Set GPIO directions: GP0, GP3 as inputs; GP1, GP2, GP4, GP5 as outputs
    TRISIO = 0b00001001;

    // Enable pull-ups on GP0, GP3
    WPU = 0b00000001;

    // Enable global, peripheral, and GPIO interrupts
    INTCON = 0b11001000;

    // Enable interrupt-on-change for GP3
    IOC = 0b00001000;

    // Set up ADC: Channel 0, left-justified result, VDD reference, ADC enabled
    ADCON0 = 0b00000001;

    // Select GP0 as analog input, set ADC clock speed for 2 µs conversion with 4 MHz clock
    ANSEL = 0b00010001;
    
    // Initialize MAX7219 display
    MAX7219_INIT();
}

void SpiSend16bit(uint16_t data) {
    DioPinWrite(SPI_CS, LOW); //select slave
    for (int bit = 0; bit < 16; bit++) { // loop on the 16bit of data given
        if (data & (1 << (15 - bit))) {  // check if the bit is high or low 
            DioPinWrite(SPI_MOSI, HIGH);
        } else {
            DioPinWrite(SPI_MOSI, LOW);
        }
        SPI_DELAY; // wait till the pin state is set
        DioPinWrite(SPI_CLK, HIGH); // Clock pulse
        SPI_DELAY;
        DioPinWrite(SPI_CLK, LOW);
    }
    DioPinWrite(SPI_CS, HIGH); // Deselect slave
}

void DioPinWrite(uint8_t pinNumber, uint8_t state) {
    if (state == HIGH) {
        DioState |= (1 << pinNumber); // Set pin high
    } else {
        DioState &= ~(1 << pinNumber); // Set pin low
    }
    GPIO = DioState;
}

void Max7219ClearDisplay(void) {
    for (uint8_t i = MAX7219_REG_DIGIT0; i <= MAX7219_REG_DIGIT3; i++) {
        SpiSend16bit((uint16_t)(i << 8)); // Clear each digit
    }
}
  
void __interrupt() ISR() {  // interrupt on change on pin3 as its the only pin that has interrupt on change enabled
       //Hold the code and recheck the value of the pin 10 times while in the de-bounce delay
       //if any ripples happened in the loop the loop resets and start counting fro zero
    for(uint8_t DebounceCounter = 0; (!DIO_READ_PIN(SENSOR_IN)); DebounceCounter++) { 
        __delay_ms(1); 
        if (DebounceCounter >= DEBOUNCE_DELAY) {
            DispenserOn = !DispenserOn;  // Toggle the state of the dispenser flag if on turn off and vice versa
            break;
        }
    }
        // Clear the interrupt-on-change flag
        INTCON &= ~(1 << 0); // SET GPIF = 0
}
