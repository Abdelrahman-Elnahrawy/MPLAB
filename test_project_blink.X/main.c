/*_____________________________ Main.c _____________________________________________________
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

#include "efuse.h"
#include <xc.h>

#include "include/gpio.h"
#include "include/Dio.h"
#include "include/Adc.h"
/*



 * 
 * 
 * 
 *  
}
*/

//Other Includes


//uint16 analog ;

int main (void){
        Gpio_Init(Gpio_Configurations);
        Dio_Init(Dio_Configurations);
        Adc_Init_pin(ADC_CHANNEL_AN2 ,ADC_RESULT_RIGHT );
    /*



    while (1){
           Adc_StartConversion(ADC_CHANNEL_AN2);
            analog = Adc_ReadResult(); 
            if(analog < 512){
            Dio_WritePin(DIO_PIN_0 ,DIO_PIN_HIGH);
            }
            else {
            Dio_WritePin(DIO_PIN_0 ,DIO_PIN_LOW);
            }
    }  
     */
      
}
