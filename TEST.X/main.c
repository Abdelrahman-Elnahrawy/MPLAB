#include <xc.h>

// Configuration Bits
#pragma config FOSC = INTRCIO   // Internal oscillator
#pragma config WDTE = OFF       // Watchdog Timer disabled
#pragma config PWRTE = OFF      // Power-up Timer disabled
#pragma config MCLRE = OFF      // MCLR pin function is digital input
#pragma config BOREN = OFF      // Brown-out Reset disabled
#pragma config CP = OFF         // Code Protection disabled
#pragma config CPD = OFF        // Data Code Protection disabled

#define _XTAL_FREQ 4000000  // 4MHz internal oscillator

// Define pins
#define SC   GP5
#define CLK  GP2
#define DATA GP1

// MAX7219 Commands
#define MAX7219_NOOP        0x00
#define MAX7219_DIGIT0      0x01
#define MAX7219_DIGIT1      0x02
#define MAX7219_DIGIT2      0x03
#define MAX7219_DIGIT3      0x04
#define MAX7219_DECODEMODE  0x09
#define MAX7219_INTENSITY   0x0A
#define MAX7219_SCANLIMIT   0x0B
#define MAX7219_SHUTDOWN    0x0C
#define MAX7219_DISPLAYTEST 0x0F

// Function to send data to MAX7219
void send_to_max7219(unsigned char address, unsigned char data) {
    SC = 0;  // SC low to begin transmission
    for (char i = 8; i > 0; i--) {
        DATA = (address >> (i-1)) & 0x01;  // Send address bit
        CLK = 1;  // Clock high
        __delay_us(10); // Increase delay for reliability
        CLK = 0;  // Clock low
    }
    for (char i = 8; i > 0; i--) {
        DATA = (data >> (i-1)) & 0x01;  // Send data bit
        CLK = 1;  // Clock high
        __delay_us(10); // Increase delay for reliability
        CLK = 0;  // Clock low
    }
    SC = 1;  // SC high to latch data
    __delay_us(10); // Ensure data is latched
}

// Initialize MAX7219
void max7219_init() {
    send_to_max7219(MAX7219_DISPLAYTEST, 0x00); // Disable display test
    send_to_max7219(MAX7219_SCANLIMIT, 0x03);   // Scan limit = 4 digits
    send_to_max7219(MAX7219_DECODEMODE, 0x0F);  // BCD decode mode for digits 0-3
    send_to_max7219(MAX7219_INTENSITY, 0x08);   // Set brightness (0x00 to 0x0F)
    send_to_max7219(MAX7219_SHUTDOWN, 0x01);    // Exit shutdown mode
}

// Display number on MAX7219
void display_number(int num) {
    send_to_max7219(MAX7219_DIGIT0, num % 10);       // Ones place
    send_to_max7219(MAX7219_DIGIT1, (num / 10) % 10); // Tens place
    send_to_max7219(MAX7219_DIGIT2, 0x0F);           // Blank third digit
    send_to_max7219(MAX7219_DIGIT3, 0x0F);           // Blank fourth digit
}

void main() {
    // Disable analog inputs
    ANSEL = 0x00;  // All pins digital

    // Disable comparators
    CMCON = 0x07;  // Comparators off

    // Configure GPIO direction
    TRISIO = 0b00001000;  // GP3 input, others output

    // Clear GPIO outputs
    GPIO = 0xFF;

    // Initialize MAX7219
    max7219_init();

    int count = 1;
    while (1) {
        send_to_max7219(MAX7219_DISPLAYTEST, 0x01); // Disable display test
        __delay_ms(2000);
        send_to_max7219(MAX7219_DISPLAYTEST, 0x00); // Disable display test
        __delay_ms(2000);
        /*
         * 
        display_number(count);  // Update display
        __delay_ms(1000);       // Wait 1 second
        count++;
        if (count > 10) {
            count = 1;
        }
         */
    }
}
