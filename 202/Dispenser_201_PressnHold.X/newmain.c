/*
 * File:   NewMain.c
 * Author: Eng Abdelrahman Selim 
 * Created on September 25, 2024, 9:23 PM
 */

#define MAX_TIME       30                // the timer Value in seconds if the ADC reads 5 volts 
#define START_DELAY    1000             // The Power On delay in ms 
#define DEBOUNCE_DELAY 255              // Debounce  Delay in ms (max 255)
#include <xc.h>

// Function Prototypes
void InitAll();     // initialize the ADC , GPIO and the interrupts
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
#define GPIO_PIN_0 0 // Pin 0 Potentiometer In
#define GPIO_PIN_1 1 // Pin 1 Output Control
#define GPIO_PIN_2 2 // Pin 2 
#define GPIO_PIN_3 3 // Pin 3 
#define GPIO_PIN_4 4 // Pin 4 
#define GPIO_PIN_5 5 // Pin 5 Sensor  In


#define POTENTIOMETER       GPIO_PIN_0
#define SENSOR_IN           GPIO_PIN_5
#define OUTPUT_CONTROL      GPIO_PIN_1

#define DIO_READ_PIN(pinNumber)(GPIO & (1 << pinNumber))

// SPI Settings

// ADC Macros
#define ADC_START_CONVERSION() ADCON0 |= (1 << 1) // Start ADC conversion


void main(void) {
    InitAll();
    __delay_ms(START_DELAY);
    DispenserOn=0;
    while (1) {
        while (DispenserOn) { //Check if the flag of Dispenser operation is set
            ADC_START_CONVERSION();
            // ((200 * ((uint32_t) AdcReadResult())) / 1023) Get the ADC value and normalize it to 200 units 
            // Then Multiply that by the Time in full range of seconds to get the number of ticks needed tick = 5ms
            // example the ADC reads 512  MAX_TIME 90
            //adc factor 500*200/1023 = 100   the number of seconds is 90 so it will be 
            // 9000 tick , remember that the tick is 5 ms  so 9000 tick * 5 ms = 45 000 ms 
            uint32_t counter = MAX_TIME * ((200 * ((uint32_t) AdcReadResult())) / 1023);
            DioPinWrite(OUTPUT_CONTROL, HIGH);
            uint8_t DisplayUpdate = 1;  // A flag set to update the screen the moment it enters the loop 
            for (; (counter > 0) && (!DIO_READ_PIN(SENSOR_IN)); counter--) {
                __delay_us(4600); // Delay adjusted for timing (the delay value is calculated manually via try and error ) 
            }
            DispenserOn = 0;
            DioPinWrite(OUTPUT_CONTROL, LOW);
        }
    }
    return;
}

uint16_t AdcReadResult() {
    while (ADCON0 & (1 << 1)) {} // Wait for ADC conversion to complete
    return (uint16_t)((ADRESH << 2) | (ADRESL >> 6)); // Adjust left-justified 10-bit result
}

void InitAll() {
    // Set GPIO directions: GP0, GP3 , GP2 , gp5 as inputs; GP1, GP4 as outputs
    TRISIO = 0b00000000;
    TRISIO |=(1<< POTENTIOMETER ) | (1<< SENSOR_IN ) ;
    // Enable pull-ups on GP0, GP2 , gp5
    WPU = 0b00100101;
    // Enable global, peripheral, and GPIO interrupts
    INTCON = 0b11001000;

    // Enable interrupt-on-change for GP2
    IOC = 0b00100000;

    // Set up ADC: Channel 0, left-justified result, VDD reference, ADC enabled
    ADCON0 = 0b00000001;

    // Select GP0 as analog input, set ADC clock speed for 2 µs conversion with 4 MHz clock
    ANSEL = 0b00010001;

    // Initialize MAX7219 display
}


void DioPinWrite(uint8_t pinNumber, uint8_t state) {
    if (state == HIGH) {
        DioState |= (1 << pinNumber); // Set pin high
    } else {
        DioState &= ~(1 << pinNumber); // Set pin low
    }
    GPIO = DioState;
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
