
# 1 "config/Dio_Lcfg.c"

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

# 21 "config/../include/Dio_Types.h"
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

# 24 "config/Dio_Cfg.h"
typedef struct {
Dio_PinNumber pinNumber;
Dio_PinDirectionType PinDirection;
Dio_PinState StateType;
Dio_PullType PullType;
} Dio_ConfigType;


extern const Dio_ConfigType Dio_Configurations[6];

# 20 "config/Dio_Lcfg.c"
const Dio_ConfigType Dio_Configurations[6] = {
{DIO_PIN_0, DIO_DIR_OUTPUT , DIO_PIN_LOW,DIO_PULL_NONE},
{DIO_PIN_1, DIO_DIR_OUTPUT , DIO_PIN_LOW,DIO_PULL_NONE},
{DIO_PIN_2, DIO_NOT_APPLICABLE, DIO_PIN_LOW,DIO_PULL_NONE},
{DIO_PIN_3, DIO_DIR_INPUT , DIO_PIN_LOW,DIO_PULL_NONE},
{DIO_PIN_4, DIO_DIR_INPUT , DIO_PIN_LOW,DIO_PULL_NONE},
{DIO_PIN_5, DIO_DIR_INPUT , DIO_PIN_LOW,DIO_PULL_UP }
};
