
# 1 "config/Gpio_Lcfg.c"

# 15 "config/../include/Std_Types.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned long uint32;
typedef signed long sint32;
typedef float float32;
typedef double float64;


typedef uint8 Std_ReturnType;

# 17 "config/../include/Gpio_Types.h"
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

# 26 "config/Gpio_Cfg.h"
typedef struct {
Gpio_PinFunctionEnum pinFunction;
uint8 pinNumber ;
} Gpio_ConfigType;

extern const Gpio_ConfigType Gpio_Configurations[6];

# 19 "config/Gpio_Lcfg.c"
const Gpio_ConfigType Gpio_Configurations[6] = {
{GPIO_PIN0_GPIO,GPIO_PIN_0},
{GPIO_PIN1_GPIO,GPIO_PIN_1},
{GPIO_PIN2_AN2 ,GPIO_PIN_2},
{GPIO_PIN3_GPIO,GPIO_PIN_3},
{GPIO_PIN4_GPIO,GPIO_PIN_4},
{GPIO_PIN5_GPIO,GPIO_PIN_5}
};
