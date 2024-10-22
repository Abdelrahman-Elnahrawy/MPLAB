
/*_____________________________EFUSE.H_____________________________________________________
                                      ___           ___           ___
 Author: Abdelrahman Selim           /\  \         /\  \         /\  \
                                    /::\  \       /::\  \       /::\  \
Created on:16 sep 2024             /:/\:\  \     /:/\:\  \     /:/\:\  \
                                  /::\ \:\  \   _\:\ \:\  \   /::\ \:\  \
 Version: 01                     /:/\:\ \:\__\ /\ \:\ \:\__\ /:/\:\ \:\__\
                                 \/__\:\/:/  / \:\ \:\ \/__/ \/__\:\/:/  / 
                                      \::/  /   \:\ \:\__\        \::/  /
                                      /:/  /     \:\/:/  /        /:/  /
 Brief : Exploring Pic               /:/  /       \::/  /        /:/  /
                                     \/__/         \/__/         \/__/
 _________________________________________________________________________________________*/
#ifndef ____EFUSE____
#define ____EFUSE____

#define _XTAL_FREQ 4000000      // setting the freq as 4 MHZ

// PIC12F675 Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR master clear reset bit disabled
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF // Data Code Protection bit (Data memory code protection is disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


#endif


