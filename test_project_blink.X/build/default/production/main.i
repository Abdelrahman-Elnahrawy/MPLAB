
# 1 "main.c"


# 25 "efuse.h"
#pragma config FOSC = INTRCIO
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config BOREN = OFF
#pragma config CP = OFF
#pragma config CPD = OFF

# 18 "C:\Program Files\Microchip\xc8\v2.50\pic\include\xc.h"
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);


# 13 "C:\Program Files\Microchip\xc8\v2.50\pic\include\c90\xc8debug.h"
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);

# 13 "C:\Program Files\Microchip\xc8\v2.50\pic\include\c90\stdint.h"
typedef signed char int8_t;

# 20
typedef signed int int16_t;

# 28
typedef __int24 int24_t;

# 36
typedef signed long int int32_t;

# 52
typedef unsigned char uint8_t;

# 58
typedef unsigned int uint16_t;

# 65
typedef __uint24 uint24_t;

# 72
typedef unsigned long int uint32_t;

# 88
typedef signed char int_least8_t;

# 96
typedef signed int int_least16_t;

# 109
typedef __int24 int_least24_t;

# 118
typedef signed long int int_least32_t;

# 136
typedef unsigned char uint_least8_t;

# 143
typedef unsigned int uint_least16_t;

# 154
typedef __uint24 uint_least24_t;

# 162
typedef unsigned long int uint_least32_t;

# 181
typedef signed char int_fast8_t;

# 188
typedef signed int int_fast16_t;

# 200
typedef __int24 int_fast24_t;

# 208
typedef signed long int int_fast32_t;

# 224
typedef unsigned char uint_fast8_t;

# 230
typedef unsigned int uint_fast16_t;

# 240
typedef __uint24 uint_fast24_t;

# 247
typedef unsigned long int uint_fast32_t;

# 268
typedef int32_t intmax_t;

# 282
typedef uint32_t uintmax_t;

# 289
typedef int16_t intptr_t;




typedef uint16_t uintptr_t;


# 7 "C:\Program Files\Microchip\xc8\v2.50\pic\include\builtins.h"
#pragma intrinsic(__nop)
extern void __nop(void);


# 19
#pragma intrinsic(_delay)
extern __nonreentrant void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __nonreentrant void _delaywdt(uint32_t);

# 9 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC10-12Fxxx_DFP/1.7.178/xc8\pic\include\pic.h"
extern unsigned char __osccal_val(void);

# 52 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC10-12Fxxx_DFP/1.7.178/xc8\pic\include\proc\pic12f675.h"
extern volatile unsigned char INDF __at(0x000);

asm("INDF equ 00h");


typedef union {
struct {
unsigned INDF :8;
};
} INDFbits_t;
extern volatile INDFbits_t INDFbits __at(0x000);

# 72
extern volatile unsigned char TMR0 __at(0x001);

asm("TMR0 equ 01h");


typedef union {
struct {
unsigned TMR0 :8;
};
} TMR0bits_t;
extern volatile TMR0bits_t TMR0bits __at(0x001);

# 92
extern volatile unsigned char PCL __at(0x002);

asm("PCL equ 02h");


typedef union {
struct {
unsigned PCL :8;
};
} PCLbits_t;
extern volatile PCLbits_t PCLbits __at(0x002);

# 112
extern volatile unsigned char STATUS __at(0x003);

asm("STATUS equ 03h");


typedef union {
struct {
unsigned C :1;
unsigned DC :1;
unsigned Z :1;
unsigned nPD :1;
unsigned nTO :1;
unsigned RP :2;
unsigned IRP :1;
};
struct {
unsigned :5;
unsigned RP0 :1;
unsigned RP1 :1;
};
struct {
unsigned CARRY :1;
unsigned :1;
unsigned ZERO :1;
};
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __at(0x003);

# 198
extern volatile unsigned char FSR __at(0x004);

asm("FSR equ 04h");


typedef union {
struct {
unsigned FSR :8;
};
} FSRbits_t;
extern volatile FSRbits_t FSRbits __at(0x004);

# 218
extern volatile unsigned char GPIO __at(0x005);

asm("GPIO equ 05h");


typedef union {
struct {
unsigned GP0 :1;
unsigned GP1 :1;
unsigned GP2 :1;
unsigned GP3 :1;
unsigned GP4 :1;
unsigned GP5 :1;
};
struct {
unsigned GPIO0 :1;
unsigned GPIO1 :1;
unsigned GPIO2 :1;
unsigned GPIO3 :1;
unsigned GPIO4 :1;
unsigned GPIO5 :1;
};
} GPIObits_t;
extern volatile GPIObits_t GPIObits __at(0x005);

# 306
extern volatile unsigned char PCLATH __at(0x00A);

asm("PCLATH equ 0Ah");


typedef union {
struct {
unsigned PCLATH :5;
};
} PCLATHbits_t;
extern volatile PCLATHbits_t PCLATHbits __at(0x00A);

# 326
extern volatile unsigned char INTCON __at(0x00B);

asm("INTCON equ 0Bh");


typedef union {
struct {
unsigned GPIF :1;
unsigned INTF :1;
unsigned T0IF :1;
unsigned GPIE :1;
unsigned INTE :1;
unsigned T0IE :1;
unsigned PEIE :1;
unsigned GIE :1;
};
struct {
unsigned :2;
unsigned TMR0IF :1;
unsigned :2;
unsigned TMR0IE :1;
};
} INTCONbits_t;
extern volatile INTCONbits_t INTCONbits __at(0x00B);

# 404
extern volatile unsigned char PIR1 __at(0x00C);

asm("PIR1 equ 0Ch");


typedef union {
struct {
unsigned TMR1IF :1;
unsigned :2;
unsigned CMIF :1;
unsigned :2;
unsigned ADIF :1;
unsigned EEIF :1;
};
struct {
unsigned T1IF :1;
};
} PIR1bits_t;
extern volatile PIR1bits_t PIR1bits __at(0x00C);

# 452
extern volatile unsigned short TMR1 __at(0x00E);

asm("TMR1 equ 0Eh");




extern volatile unsigned char TMR1L __at(0x00E);

asm("TMR1L equ 0Eh");


typedef union {
struct {
unsigned TMR1L :8;
};
} TMR1Lbits_t;
extern volatile TMR1Lbits_t TMR1Lbits __at(0x00E);

# 479
extern volatile unsigned char TMR1H __at(0x00F);

asm("TMR1H equ 0Fh");


typedef union {
struct {
unsigned TMR1H :8;
};
} TMR1Hbits_t;
extern volatile TMR1Hbits_t TMR1Hbits __at(0x00F);

# 499
extern volatile unsigned char T1CON __at(0x010);

asm("T1CON equ 010h");


typedef union {
struct {
unsigned TMR1ON :1;
unsigned TMR1CS :1;
unsigned nT1SYNC :1;
unsigned T1OSCEN :1;
unsigned T1CKPS :2;
unsigned TMR1GE :1;
};
struct {
unsigned :4;
unsigned T1CKPS0 :1;
unsigned T1CKPS1 :1;
};
} T1CONbits_t;
extern volatile T1CONbits_t T1CONbits __at(0x010);

# 564
extern volatile unsigned char CMCON __at(0x019);

asm("CMCON equ 019h");


typedef union {
struct {
unsigned CM :3;
unsigned CIS :1;
unsigned CINV :1;
unsigned :1;
unsigned COUT :1;
};
struct {
unsigned CM0 :1;
unsigned CM1 :1;
unsigned CM2 :1;
};
} CMCONbits_t;
extern volatile CMCONbits_t CMCONbits __at(0x019);

# 623
extern volatile unsigned char ADRESH __at(0x01E);

asm("ADRESH equ 01Eh");


typedef union {
struct {
unsigned ADRESH :8;
};
} ADRESHbits_t;
extern volatile ADRESHbits_t ADRESHbits __at(0x01E);

# 643
extern volatile unsigned char ADCON0 __at(0x01F);

asm("ADCON0 equ 01Fh");


typedef union {
struct {
unsigned ADON :1;
unsigned GO_nDONE :1;
unsigned CHS :2;
unsigned :2;
unsigned VCFG :1;
unsigned ADFM :1;
};
struct {
unsigned :1;
unsigned GO_DONE :1;
unsigned CHS0 :1;
unsigned CHS1 :1;
};
struct {
unsigned :1;
unsigned nDONE :1;
};
struct {
unsigned :1;
unsigned GO :1;
};
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __at(0x01F);

# 727
extern volatile unsigned char OPTION_REG __at(0x081);

asm("OPTION_REG equ 081h");


typedef union {
struct {
unsigned PS :3;
unsigned PSA :1;
unsigned T0SE :1;
unsigned T0CS :1;
unsigned INTEDG :1;
unsigned nGPPU :1;
};
struct {
unsigned PS0 :1;
unsigned PS1 :1;
unsigned PS2 :1;
};
} OPTION_REGbits_t;
extern volatile OPTION_REGbits_t OPTION_REGbits __at(0x081);

# 797
extern volatile unsigned char TRISIO __at(0x085);

asm("TRISIO equ 085h");


typedef union {
struct {
unsigned TRISIO0 :1;
unsigned TRISIO1 :1;
unsigned TRISIO2 :1;
unsigned TRISIO3 :1;
unsigned TRISIO4 :1;
unsigned TRISIO5 :1;
};
} TRISIObits_t;
extern volatile TRISIObits_t TRISIObits __at(0x085);

# 847
extern volatile unsigned char PIE1 __at(0x08C);

asm("PIE1 equ 08Ch");


typedef union {
struct {
unsigned TMR1IE :1;
unsigned :2;
unsigned CMIE :1;
unsigned :2;
unsigned ADIE :1;
unsigned EEIE :1;
};
struct {
unsigned T1IE :1;
};
} PIE1bits_t;
extern volatile PIE1bits_t PIE1bits __at(0x08C);

# 895
extern volatile unsigned char PCON __at(0x08E);

asm("PCON equ 08Eh");


typedef union {
struct {
unsigned nBOR :1;
unsigned nPOR :1;
};
struct {
unsigned nBOD :1;
};
} PCONbits_t;
extern volatile PCONbits_t PCONbits __at(0x08E);

# 929
extern volatile unsigned char OSCCAL __at(0x090);

asm("OSCCAL equ 090h");


typedef union {
struct {
unsigned :2;
unsigned CAL :6;
};
struct {
unsigned :2;
unsigned CAL0 :1;
unsigned CAL1 :1;
unsigned CAL2 :1;
unsigned CAL3 :1;
unsigned CAL4 :1;
unsigned CAL5 :1;
};
} OSCCALbits_t;
extern volatile OSCCALbits_t OSCCALbits __at(0x090);

# 989
extern volatile unsigned char WPU __at(0x095);

asm("WPU equ 095h");


typedef union {
struct {
unsigned WPU0 :1;
unsigned WPU1 :1;
unsigned WPU2 :1;
unsigned :1;
unsigned WPU4 :1;
unsigned WPU5 :1;
};
} WPUbits_t;
extern volatile WPUbits_t WPUbits __at(0x095);

# 1034
extern volatile unsigned char IOC __at(0x096);

asm("IOC equ 096h");


extern volatile unsigned char IOCB __at(0x096);

asm("IOCB equ 096h");


typedef union {
struct {
unsigned IOC0 :1;
unsigned IOC1 :1;
unsigned IOC2 :1;
unsigned IOC3 :1;
unsigned IOC4 :1;
unsigned IOC5 :1;
};
struct {
unsigned IOCB0 :1;
unsigned IOCB1 :1;
unsigned IOCB2 :1;
unsigned IOCB3 :1;
unsigned IOCB4 :1;
unsigned IOCB5 :1;
};
} IOCbits_t;
extern volatile IOCbits_t IOCbits __at(0x096);

# 1125
typedef union {
struct {
unsigned IOC0 :1;
unsigned IOC1 :1;
unsigned IOC2 :1;
unsigned IOC3 :1;
unsigned IOC4 :1;
unsigned IOC5 :1;
};
struct {
unsigned IOCB0 :1;
unsigned IOCB1 :1;
unsigned IOCB2 :1;
unsigned IOCB3 :1;
unsigned IOCB4 :1;
unsigned IOCB5 :1;
};
} IOCBbits_t;
extern volatile IOCBbits_t IOCBbits __at(0x096);

# 1208
extern volatile unsigned char VRCON __at(0x099);

asm("VRCON equ 099h");


typedef union {
struct {
unsigned VR :4;
unsigned :1;
unsigned VRR :1;
unsigned :1;
unsigned VREN :1;
};
struct {
unsigned VR0 :1;
unsigned VR1 :1;
unsigned VR2 :1;
unsigned VR3 :1;
};
} VRCONbits_t;
extern volatile VRCONbits_t VRCONbits __at(0x099);

# 1268
extern volatile unsigned char EEDATA __at(0x09A);

asm("EEDATA equ 09Ah");


extern volatile unsigned char EEDAT __at(0x09A);

asm("EEDAT equ 09Ah");


typedef union {
struct {
unsigned EEDATA :8;
};
} EEDATAbits_t;
extern volatile EEDATAbits_t EEDATAbits __at(0x09A);

# 1291
typedef union {
struct {
unsigned EEDATA :8;
};
} EEDATbits_t;
extern volatile EEDATbits_t EEDATbits __at(0x09A);

# 1306
extern volatile unsigned char EEADR __at(0x09B);

asm("EEADR equ 09Bh");


typedef union {
struct {
unsigned EEADR :7;
};
} EEADRbits_t;
extern volatile EEADRbits_t EEADRbits __at(0x09B);

# 1326
extern volatile unsigned char EECON1 __at(0x09C);

asm("EECON1 equ 09Ch");


typedef union {
struct {
unsigned RD :1;
unsigned WR :1;
unsigned WREN :1;
unsigned WRERR :1;
};
} EECON1bits_t;
extern volatile EECON1bits_t EECON1bits __at(0x09C);

# 1364
extern volatile unsigned char EECON2 __at(0x09D);

asm("EECON2 equ 09Dh");


typedef union {
struct {
unsigned EECON2 :8;
};
} EECON2bits_t;
extern volatile EECON2bits_t EECON2bits __at(0x09D);

# 1384
extern volatile unsigned char ADRESL __at(0x09E);

asm("ADRESL equ 09Eh");


typedef union {
struct {
unsigned ADRESL :8;
};
} ADRESLbits_t;
extern volatile ADRESLbits_t ADRESLbits __at(0x09E);

# 1404
extern volatile unsigned char ANSEL __at(0x09F);

asm("ANSEL equ 09Fh");


typedef union {
struct {
unsigned ANS :4;
unsigned ADCS :3;
};
struct {
unsigned ANS0 :1;
unsigned ANS1 :1;
unsigned ANS2 :1;
unsigned ANS3 :1;
unsigned ADCS0 :1;
unsigned ADCS1 :1;
unsigned ADCS2 :1;
};
} ANSELbits_t;
extern volatile ANSELbits_t ANSELbits __at(0x09F);

# 1484
extern volatile __bit ADCS0 __at(0x4FC);


extern volatile __bit ADCS1 __at(0x4FD);


extern volatile __bit ADCS2 __at(0x4FE);


extern volatile __bit ADFM __at(0xFF);


extern volatile __bit ADIE __at(0x466);


extern volatile __bit ADIF __at(0x66);


extern volatile __bit ADON __at(0xF8);


extern volatile __bit ANS0 __at(0x4F8);


extern volatile __bit ANS1 __at(0x4F9);


extern volatile __bit ANS2 __at(0x4FA);


extern volatile __bit ANS3 __at(0x4FB);


extern volatile __bit CAL0 __at(0x482);


extern volatile __bit CAL1 __at(0x483);


extern volatile __bit CAL2 __at(0x484);


extern volatile __bit CAL3 __at(0x485);


extern volatile __bit CAL4 __at(0x486);


extern volatile __bit CAL5 __at(0x487);


extern volatile __bit CARRY __at(0x18);


extern volatile __bit CHS0 __at(0xFA);


extern volatile __bit CHS1 __at(0xFB);


extern volatile __bit CINV __at(0xCC);


extern volatile __bit CIS __at(0xCB);


extern volatile __bit CM0 __at(0xC8);


extern volatile __bit CM1 __at(0xC9);


extern volatile __bit CM2 __at(0xCA);


extern volatile __bit CMIE __at(0x463);


extern volatile __bit CMIF __at(0x63);


extern volatile __bit COUT __at(0xCE);


extern volatile __bit DC __at(0x19);


extern volatile __bit EEIE __at(0x467);


extern volatile __bit EEIF __at(0x67);


extern volatile __bit GIE __at(0x5F);


extern volatile __bit GO __at(0xF9);


extern volatile __bit GO_DONE __at(0xF9);


extern volatile __bit GO_nDONE __at(0xF9);


extern volatile __bit GP0 __at(0x28);


extern volatile __bit GP1 __at(0x29);


extern volatile __bit GP2 __at(0x2A);


extern volatile __bit GP3 __at(0x2B);


extern volatile __bit GP4 __at(0x2C);


extern volatile __bit GP5 __at(0x2D);


extern volatile __bit GPIE __at(0x5B);


extern volatile __bit GPIF __at(0x58);


extern volatile __bit GPIO0 __at(0x28);


extern volatile __bit GPIO1 __at(0x29);


extern volatile __bit GPIO2 __at(0x2A);


extern volatile __bit GPIO3 __at(0x2B);


extern volatile __bit GPIO4 __at(0x2C);


extern volatile __bit GPIO5 __at(0x2D);


extern volatile __bit INTE __at(0x5C);


extern volatile __bit INTEDG __at(0x40E);


extern volatile __bit INTF __at(0x59);


extern volatile __bit IOC0 __at(0x4B0);


extern volatile __bit IOC1 __at(0x4B1);


extern volatile __bit IOC2 __at(0x4B2);


extern volatile __bit IOC3 __at(0x4B3);


extern volatile __bit IOC4 __at(0x4B4);


extern volatile __bit IOC5 __at(0x4B5);


extern volatile __bit IOCB0 __at(0x4B0);


extern volatile __bit IOCB1 __at(0x4B1);


extern volatile __bit IOCB2 __at(0x4B2);


extern volatile __bit IOCB3 __at(0x4B3);


extern volatile __bit IOCB4 __at(0x4B4);


extern volatile __bit IOCB5 __at(0x4B5);


extern volatile __bit IRP __at(0x1F);


extern volatile __bit PEIE __at(0x5E);


extern volatile __bit PS0 __at(0x408);


extern volatile __bit PS1 __at(0x409);


extern volatile __bit PS2 __at(0x40A);


extern volatile __bit PSA __at(0x40B);


extern volatile __bit RD __at(0x4E0);


extern volatile __bit RP0 __at(0x1D);


extern volatile __bit RP1 __at(0x1E);


extern volatile __bit T0CS __at(0x40D);


extern volatile __bit T0IE __at(0x5D);


extern volatile __bit T0IF __at(0x5A);


extern volatile __bit T0SE __at(0x40C);


extern volatile __bit T1CKPS0 __at(0x84);


extern volatile __bit T1CKPS1 __at(0x85);


extern volatile __bit T1IE __at(0x460);


extern volatile __bit T1IF __at(0x60);


extern volatile __bit T1OSCEN __at(0x83);


extern volatile __bit TMR0IE __at(0x5D);


extern volatile __bit TMR0IF __at(0x5A);


extern volatile __bit TMR1CS __at(0x81);


extern volatile __bit TMR1GE __at(0x86);


extern volatile __bit TMR1IE __at(0x460);


extern volatile __bit TMR1IF __at(0x60);


extern volatile __bit TMR1ON __at(0x80);


extern volatile __bit TRISIO0 __at(0x428);


extern volatile __bit TRISIO1 __at(0x429);


extern volatile __bit TRISIO2 __at(0x42A);


extern volatile __bit TRISIO3 __at(0x42B);


extern volatile __bit TRISIO4 __at(0x42C);


extern volatile __bit TRISIO5 __at(0x42D);


extern volatile __bit VCFG __at(0xFE);


extern volatile __bit VR0 __at(0x4C8);


extern volatile __bit VR1 __at(0x4C9);


extern volatile __bit VR2 __at(0x4CA);


extern volatile __bit VR3 __at(0x4CB);


extern volatile __bit VREN __at(0x4CF);


extern volatile __bit VRR __at(0x4CD);


extern volatile __bit WPU0 __at(0x4A8);


extern volatile __bit WPU1 __at(0x4A9);


extern volatile __bit WPU2 __at(0x4AA);


extern volatile __bit WPU4 __at(0x4AC);


extern volatile __bit WPU5 __at(0x4AD);


extern volatile __bit WR __at(0x4E1);


extern volatile __bit WREN __at(0x4E2);


extern volatile __bit WRERR __at(0x4E3);


extern volatile __bit ZERO __at(0x1A);


extern volatile __bit nBOD __at(0x470);


extern volatile __bit nBOR __at(0x470);


extern volatile __bit nDONE __at(0xF9);


extern volatile __bit nGPPU __at(0x40F);


extern volatile __bit nPD __at(0x1B);


extern volatile __bit nPOR __at(0x471);


extern volatile __bit nT1SYNC __at(0x82);


extern volatile __bit nTO __at(0x1C);

# 76 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC10-12Fxxx_DFP/1.7.178/xc8\pic\include\pic.h"
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);

# 114 "C:\Program Files\Microchip\xc8\v2.50\pic\include\eeprom_routines.h"
extern void eeprom_write(unsigned char addr, unsigned char value);
extern unsigned char eeprom_read(unsigned char addr);

# 118 "C:/Program Files/Microchip/MPLABX/v6.20/packs/Microchip/PIC10-12Fxxx_DFP/1.7.178/xc8\pic\include\pic.h"
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;

# 15 "include/../config/../include/Std_Types.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef float float32;
typedef double float64;


typedef uint8 Std_ReturnType;

# 17 "include/../config/../include/Gpio_Types.h"
typedef enum {
GPIO_PIN_LOW = 0,
GPIO_PIN_HIGH
} Gpio_PinStateType;

typedef enum {
GPIO_DIR_INPUT = 0,
GPIO_DIR_OUTPUT
} Gpio_PinDirectionType;

typedef enum {
GPIO_PIN_0 = 0,
GPIO_PIN_1 = 1,
GPIO_PIN_2 = 2,
GPIO_PIN_3 = 3,
GPIO_PIN_4 = 4,
GPIO_PIN_5 = 5,
} Gpio_PinNumber;
typedef enum {

GPIO_PIN0_GPIO = 0,
GPIO_PIN0_AN0,
GPIO_PIN0_CIN_PLUS,
GPIO_PIN0_ICSPDAT,


GPIO_PIN1_GPIO,
GPIO_PIN1_AN1,
GPIO_PIN1_CIN_MINUS,
GPIO_PIN1_VREF,
GPIO_PIN1_ICSPCLK,


GPIO_PIN2_GPIO,
GPIO_PIN2_AN2,
GPIO_PIN2_T0CKI,
GPIO_PIN2_INT,
GPIO_PIN2_COUT,


GPIO_PIN3_GPIO,
GPIO_PIN3_MCLR,


GPIO_PIN4_GPIO,
GPIO_PIN4_AN3,
GPIO_PIN4_T1G,
GPIO_PIN4_OSC2,


GPIO_PIN5_GPIO,
GPIO_PIN5_T1CKI,
GPIO_PIN5_OSC1,
} Gpio_PinFunctionEnum;

# 26 "include/../config/Gpio_Cfg.h"
typedef struct {
Gpio_PinFunctionEnum pinFunction;
uint8 pinNumber ;
} Gpio_ConfigType;

extern const Gpio_ConfigType Gpio_Configurations[6];

# 20 "include/gpio.h"
uint8 Gpio_Init(const Gpio_ConfigType* ConfigPtr);

uint8 Gpio_Pin_Dio(Gpio_PinNumber pinNumber,
Gpio_PinDirectionType direction,
Gpio_PinStateType state,
uint8 pullType) ;

# 21 "include/../include/Dio_Types.h"
typedef enum {
DIO_PIN_LOW = 0,
DIO_PIN_HIGH
} Dio_PinState;


typedef enum {
DIO_DIR_INPUT = 0,
DIO_DIR_OUTPUT,
DIO_NOT_APPLICABLE
} Dio_PinDirectionType;

typedef enum {
DIO_PIN_0 = 0,
DIO_PIN_1,
DIO_PIN_2,
DIO_PIN_3,
DIO_PIN_4,
DIO_PIN_5
} Dio_PinNumber;


typedef enum {
DIO_PULL_NONE = 0,
DIO_PULL_UP,
} Dio_PullType;

# 24 "include/../config/Dio_Cfg.h"
typedef struct {
Dio_PinNumber pinNumber;
Dio_PinDirectionType PinDirection;
Dio_PinState StateType;
Dio_PullType PullType;
} Dio_ConfigType;


extern const Dio_ConfigType Dio_Configurations[6];

# 22 "include/Dio.h"
uint8 Dio_Init(const Dio_ConfigType* ConfigPtr);


Dio_PinState Dio_ReadPin(Dio_PinNumber pinNumber);


uint8 Dio_WritePin(Dio_PinNumber pinNumber, Dio_PinState state);
uint8 Dio_TogglePin(Dio_PinNumber pinNumber);

# 21 "include/../include/Adc_Types.h"
typedef enum {
ADC_CHANNEL_AN0 = 0,
ADC_CHANNEL_AN1,
ADC_CHANNEL_AN2,
ADC_CHANNEL_AN3
} Adc_ChannelType;


typedef enum {
ADC_RESULT_LEFT = 0,
ADC_RESULT_RIGHT
} Adc_ResultFormatType;

# 90 "include/../config/Adc_Cfg.h"
typedef struct {
Adc_ChannelType channel;
Adc_ResultFormatType resultFormat;
} Adc_ConfigType;


extern const Adc_ConfigType Adc_Configurations[];

# 24 "include/Adc.h"
uint8 Adc_Init(const Adc_ConfigType* ConfigPtr);
void Adc_Init_pin(Adc_ChannelType channel , Adc_ResultFormatType format);

uint8 Adc_StartConversion(Adc_ChannelType channel);


uint16 Adc_ReadResult(void);

# 37 "main.c"
int main (void){
Gpio_Init(Gpio_Configurations);
Dio_Init(Dio_Configurations);
Adc_Init_pin(ADC_CHANNEL_AN2 ,ADC_RESULT_RIGHT );

# 57
}
