/*
 * File:   NewMain.c
 * Author: Eng Abdelrahman Selim 
 * Created on September 25, 2024, 9:23 PM
 */


#define MAX_TIME            5               // the timer value in seconds if the ADC reads 5 volts 
#define START_DELAY         1000             // The delay in ms on powering on
#define SENSOR_PULSE_WIDTH  100                // Time of Sensor Pulse in ms
#define LOW_SENSOR_VOLTAGE  256              // from 0 (as zero volt) to 1024 (as 5 volts) ex 512(2.5V) , 256(1.25V) , 128(0.625V)



// Load Timer1 for 10 ms intervals
// TMR0: Timer1 TICK = 1/125000  = 8 us 
// takes 8 µs (1:32 prescaler). For 10 ms, we need (10 ms / 8 µs) = 1250 increments.
#define TIMER1_RELOAD_VALUE (UINT16_T_MAX- 1250)  // Example reload value (adjust as needed)

#include <xc.h>
// Function Prototypes
void InitAll();     // initialize the ADC , GPIO and the interrupts
void DioPinWrite(uint8_t pinNumber, uint8_t state);
uint16_t AdcReadResult();
void ADC_StartConversion(uint8_t channel);
void Timer1_interrupt ();
void ADC_interrupt ();
void NegativeEdge();
uint8_t DioState;
uint8_t ADCStatus;
uint8_t DispenserOn;

#define ADC_IDLE                  0x00
#define ADC_READING_POTENTIOMETER 0x01
#define ADC_READING_SENSOR_IN     0x02



uint16_t SensorInValue;
uint16_t LastSensorInValue;
uint16_t PotInValue;
uint8_t DebounceCounter;

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
#define GPIO_PIN_0 0 // Pin 0  Analog Input Potentiometer
#define GPIO_PIN_1 1 // Pin 1  Output
#define GPIO_PIN_2 2 // Pin 2 
#define GPIO_PIN_3 3 // Pin 3 
#define GPIO_PIN_4 4 // Pin 4 Sensor Analog_Input
#define GPIO_PIN_5 5 // Pin 5 

#define OUTPUT_GATE        GPIO_PIN_1  
#define SENSOR_ADC         GPIO_PIN_4   
#define POT_ADC            GPIO_PIN_0

#define SENSOR_ADC         GPIO_PIN_4   
#define POT_ADC            GPIO_PIN_0


#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3

#define ADC_GP0_CHANNEL ADC_CHANNEL_0
#define ADC_GP1_CHANNEL ADC_CHANNEL_1
#define ADC_GP2_CHANNEL ADC_CHANNEL_2
#define ADC_GP4_CHANNEL ADC_CHANNEL_3


#define SENSOR_ADC_CHANNEL ADC_GP4_CHANNEL
#define POT_ADC_CHANNEL    ADC_GP0_CHANNEL

#define TMR0_RST_VALUE  
#define DIO_READ_PIN(pinNumber)(GPIO & (1 << pinNumber))

#define UINT16_T_MAX    65535


#define DEBOUNCE_COUNTER ((SENSOR_PULSE_WIDTH)/(10))

uint8_t flag;

#define RELOAD_TIMER1(RELOAD_VALUE)\
        T1CON &= ~0b00000001 ;   /* Stop Timer1 */\
        TMR1 = RELOAD_VALUE;       /* Set reload value */\
        T1CON |= 0b00000001 ;      /* Start Timer1 */

void main(void) {
    InitAll();
    while(1){
        if (DispenserOn &&( DebounceCounter > DEBOUNCE_COUNTER )){
                DioPinWrite(OUTPUT_GATE, HIGH);
                uint32_t Counter = MAX_TIME * ((200 * ((uint32_t) PotInValue )) / 1023);
                for (;(Counter > 0) && DispenserOn ;Counter--){
                    __delay_ms(5);
                }
                DioPinWrite(OUTPUT_GATE, LOW);
                DispenserOn = 0 ;
        } 
    }
    return;
}


void InitAll() {
// Set GPIO directions: GP0 and GP4 as inputs (analog), GP1, GP2, GP3, GP5 as outputs
// TRISIO: Controls whether each pin is an input (1) or output (0)
// Bit 5: GP5 direction -> 0 = Output
// Bit 4: GP4 direction -> 1 = Input (Analog)
// Bit 3: GP3 direction -> 0 = Output
// Bit 2: GP2 direction -> 0 = Output
// Bit 1: GP1 direction -> 0 = Output
// Bit 0: GP0 direction -> 1 = Input (Analog)
TRISIO = 0b00011001;  // Set GP0 , GP3 and GP4 as inputs (for analog), GP1, GP2, GP5 as outputs

// Enable weak pull-ups on GP0
// WPU: Controls the internal weak pull-up resistors (only for input pins)
// Bit 5: GP5 pull-up -> 0 = Disabled (Output, no pull-up needed)
// Bit 4: GP4 pull-up -> 0 = Disabled (Analog input, no pull-up)
// Bit 3: unused
// Bit 2: GP2 pull-up -> 0 = Disabled (Output, no pull-up needed)
// Bit 1: GP1 pull-up -> 0 = Disabled (Output, no pull-up needed)
// Bit 0: GP0 pull-up -> 0 = Disabled (Analog input, no pull-up)
WPU = 0b00000000;  

// Enable global interrupts and Timer0 interrupts, disable interrupt-on-change
// INTCON: Global and peripheral interrupt control
// Bit 7: GIE  -> 1 = Global Interrupt Enable (Enables interrupts globally)
// Bit 6: PEIE -> 1 = Peripheral Interrupt Enable for timer 1
// Bit 5: T0IE -> 0 = Timer0 Interrupt Enable
// Bit 4: INTE -> 0 = External Interrupt Enable (Not used, no external interrupts)
// Bit 3: GPIE -> 0 = Interrupt-on-Change Disable (Not needed)
// Bit 2: T0IF -> 0 = Timer0 Overflow Flag (Cleared, not an initial interrupt)
// Bit 1: INTF -> 0 = External Interrupt Flag (Not relevant, no external interrupt)
// Bit 0: GPIF -> 0 = Interrupt-on-Change Flag (Cleared, not relevant)
INTCON = 0b11000000;  // Enable global interrupts and Timer1 interrupts

// Set up ADC to read from GP0 (AN0) initially
// ADCON0: Controls the ADC module
// Bit 7: ADFM -> 0 = Left justified (Most significant bits of the result in ADRESH, suitable for 8-bit resolution)
// Bit 6: VCFG -> 0 = VDD is used as the reference voltage
// Bit 5-4: Unimplemented (Read as 0)
// Bit 3-2: CHS1:CHS0 -> 00 = Select Channel 00 (AN0, GP0 as analog input)
// Bit 1: GO/DONE -> 0 = A/D conversion is not started (set this bit to 1 to start conversion)
// Bit 0: ADON -> 1 = ADC is enabled
ADCON0 = 0b00000001;  // ADC enabled, left justified, VDD as reference, read from AN0 (GP0)


// ANSEL: Analog Select Register
// Bit 7: Unimplemented (Read as 0)
// Bit 6-4: ADCS<2:0> -> 000 = FOSC/2 (A/D Conversion Clock Select bits)
// Bit 3: ANS3 -> 0 = GP4 is digital
// Bit 2: ANS2 -> 0 = GP2 is digital
// Bit 1: ANS1 -> 0 = GP1 is digital
// Bit 0: ANS0 -> 1 = GP0 is analog (AN0)
ANSEL = 0b00011001;  // Set GP0 , GP4 as analog input ,set 8 Tosc 2 µs conversion with 4 MHz clock


// OPTION_REG: Configures Timer0 and prescaler
// Bit 7: WPUEN     -> 0   = Weak pull-ups are enabled (controlled by WPU register)
// Bit 6: INTEDG    -> 0   = Interrupt on falling edge (Not used, irrelevant here)
// Bit 5: T0CS      -> 0   = Timer0 clock source is the internal instruction cycle clock (FOSC/4)
// Bit 4: T0SE      -> 0   = Timer0 increments on low-to-high transition (irrelevant with internal clock)
// Bit 3: PSA       -> 0   = Prescaler assigned to Timer0
// Bit 2-0: PS<2:0> -> 000 = Prescaler set to 1:1
OPTION_REG = 0b00000000;  

// Configure T1CON register:
// bit 7: Unimplemented, always 0
// bit 6: TMR1GE = 0 -> Timer1 is on regardless of gate pin
// bit 5-4: T1CKPS1:T1CKPS0 = 11 -> 1:8 Prescale Value
// bit 3: T1OSCEN = 0 -> LP oscillator is off (using internal clock)
// bit 2: T1SYNC = 1 -> Synchronize external clock input (ignored since internal clock is used)
// bit 1: TMR1CS = 0 -> Internal clock (FOSC/4)
// bit 0: TMR1ON = 1 -> Enables Timer1
T1CON = 0b00110101;  // Prescaler 1:8, internal clock, Timer1 ON

RELOAD_TIMER1(TIMER1_RELOAD_VALUE);

// PIE1: Peripheral Interrupt Enable Register
// Bit 7: EEIE -> 0 EE Write Complete Interrupt Enable bit
// Bit 6: ADIE -> 1 A/D Converter Interrupt Enable bit
// Bit 5: Unused
// Bit 4: Unused
// Bit 3: CMIE -> Comparator Interrupt Enable bit
// Bit 2: Unused
// Bit 1: Unused
// Bit 0: TMR1IE-> TMR1 Overflow Interrupt Enable bit
PIE1 = 0b01000001;  // Enable ADC interrupt
}

void DioPinWrite(uint8_t pinNumber, uint8_t state) {
    if (state == HIGH) {
        DioState |= (1 << pinNumber); // Set pin high
    } else {
        DioState &= ~(1 << pinNumber); // Set pin low
    }
    GPIO = DioState;
}

void ADC_StartConversion(uint8_t channel) {
    // Clear the CHS bits (ADCON0<5:3>) to select the desired ADC channel
    ADCON0 &= 0b11110011;  // Clear CHS bits (bit 5-3)  
    // Set the CHS bits to select the channel (0 for AN0, 1 for AN1, etc.)
    ADCON0 |= (channel << 2);  // Shift the channel number to bit 5-3
    // Start ADC conversion by setting the GO/DONE bit (ADCON0<2>)
    ADCON0 |= (1 << 1);  // Set GO/DONE bit to start conversion
}

uint16_t AdcReadResult() {
    return (uint16_t)((ADRESH << 2) | (ADRESL >> 6)); // Adjust left-justified 10-bit result
}


// Timer1 Interrupt Service Routine
void __interrupt() ISR(void) {
    if (PIR1 & 0b00000001) {
        Timer1_interrupt ();
        // Clear the Timer1 overflow interrupt flag
        PIR1 &= 0b11111110;  // Clear the TMR1IF bit

    }
    // Check if the ADC conversion complete interrupt flag is set
    else if (PIR1 &  0b01000000) {  // Check ADIF bit in PIR1
        ADC_interrupt ();
        PIR1 &= 0b10111111; // clear ADC interrupt flag bit
        }
    else {}
}

void Timer1_interrupt (){
    RELOAD_TIMER1(TIMER1_RELOAD_VALUE);
    if(flag < 100){
            ADCStatus = ADC_READING_SENSOR_IN;
            ADC_StartConversion(SENSOR_ADC_CHANNEL);
            flag ++;
    } else {
            ADCStatus = ADC_READING_POTENTIOMETER;
            ADC_StartConversion(POT_ADC_CHANNEL);
            flag = 0;
    }
    
    if(LastSensorInValue > LOW_SENSOR_VOLTAGE && SensorInValue < LOW_SENSOR_VOLTAGE ){
        NegativeEdge();
    }
    
    if(DispenserOn && SensorInValue < LOW_SENSOR_VOLTAGE ){
        DebounceCounter++;
    } else {
        DebounceCounter = 0;
    }
    if( SensorInValue > LOW_SENSOR_VOLTAGE ){
        DispenserOn = 0;
    }
}


void ADC_interrupt (){
        if(ADCStatus == ADC_READING_SENSOR_IN){
                LastSensorInValue = SensorInValue;
                SensorInValue = AdcReadResult();
        }
        else if(ADCStatus == ADC_READING_POTENTIOMETER){
            PotInValue = AdcReadResult();  
        }
        else{
            AdcReadResult();  // read the values and threw it away hehehe
        }
        ADCStatus  = ADC_IDLE; 
}


void NegativeEdge(){         
    if(DispenserOn){
        DispenserOn = 0;
    } else {
        DispenserOn = 1;
    }
}