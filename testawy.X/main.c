/*
 * File:   NewMain.c
 * Author: Eng Abdelrahman Selim 
 * Created on September 25, 2024, 9:23 PM
 */

#define START_DELAY           10                 // The Power On delay in ms 
#define DEBOUNCE_DELAY        95                 // Debounce  Delay in ms (max 255)
#define TIMER_VALUE           3
#define MAX_NUMBER_OF_REPEATS 5   
#include <xc.h>

// Function Prototypes
void InitAll();     // initialize the ADC , GPIO and the interrupts
void DioPinWrite(uint8_t pinNumber, uint8_t state);
uint8_t DispenserOn;     // A flag set when the valve is open
static uint8_t DioState; // A variable to save the current state of the output pins
uint8_t RepeatFlagEnable ;
uint8_t RepeatFlag;
uint8_t flag = 0;
uint8_t RepeatCounter = 1;
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



void main(void) {
    InitAll();
    __delay_ms(START_DELAY);
    
    DispenserOn=0;
    while (1) {
        while (DispenserOn) { //Check if the flag of Dispenser operation is set
            uint32_t counter = 200*TIMER_VALUE;
            DioPinWrite(OUTPUT_CONTROL, HIGH);
            for (; (counter > 0)  ; counter--) {
                __delay_ms(5); // Delay adjusted for timing (the delay value is calculated manually via try and error ) 
                if(counter == (150*TIMER_VALUE)){
                RepeatFlagEnable = 1;
                }
                if(RepeatFlag){
                    DioPinWrite(GPIO_PIN_4, HIGH);
                }else{
                    DioPinWrite(GPIO_PIN_4, LOW);  
                }
            }
            RepeatFlagEnable = 0;
            if(RepeatFlag == 0 || RepeatCounter > MAX_NUMBER_OF_REPEATS){
                DispenserOn = 0;
                DioPinWrite(OUTPUT_CONTROL, LOW);
                RepeatCounter = 1;
                RepeatFlag = 0;
            } else {
                RepeatFlag = 0;
                RepeatCounter++;  
            }
            if(RepeatFlag){
                DioPinWrite(GPIO_PIN_4, HIGH);
            }else{
                DioPinWrite(GPIO_PIN_4, LOW);  
            }
        }
    }
    return;
}


void InitAll() {
    // Set GPIO directions: GP0, GP3 , GP2 , gp5 as inputs; GP1, GP4 as outputs
    TRISIO = 0b00000000;
    TRISIO |=(1<< POTENTIOMETER ) | (1<< SENSOR_IN ) ;
    // Enable pull-ups on GP0, GP2 , gp5
    WPU = 0b00100001;
    // Enable global, peripheral, and GPIO interrupts
    INTCON = 0b11001000;

    // Enable interrupt-on-change for GP2
    IOC = 0b00100000;

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

void __interrupt() ISR() { 
    if( INTCON & (1 << 0) ){
        for(uint8_t DebounceCounter = 0; (!DIO_READ_PIN(SENSOR_IN)); DebounceCounter++) { 
            __delay_ms(1); 
            if (DebounceCounter >= DEBOUNCE_DELAY) {
                DispenserOn = 1;  // 
                break;
            }
        }
        if(RepeatFlagEnable && (!DIO_READ_PIN(SENSOR_IN)) ){
            RepeatFlag = 1;
        }
        // Clear the interrupt-on-change flag
        INTCON &= ~(1 << 0); // SET GPIF = 0
    }
    
    
}
