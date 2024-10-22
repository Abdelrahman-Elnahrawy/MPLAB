/* 
 * File:   Std_Types.h
 * Author: Your Name <your.name at your.org>
 *
 * Created on September 17, 2024, 12:33 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

/* Includes */


/* General Data Types */
typedef unsigned char   uint8;       /* 8-bit unsigned */
typedef signed char     sint8;       /* 8-bit signed */
typedef unsigned short  uint16;      /* 16-bit unsigned */
typedef signed short    sint16;      /* 16-bit signed */
typedef unsigned long   uint32;      /* 32-bit unsigned */
typedef signed long     sint32;      /* 32-bit signed */
typedef float           float32;     /* 32-bit floating point */
typedef double          float64;     /* 64-bit floating point */

/* Standard Return Type */
typedef uint8 Std_ReturnType;

/* Boolean Values */
#ifndef TRUE
#define TRUE  true
#endif


#ifndef FALSE
#define FALSE false
#endif



#ifndef MIN
#define MIN(_x,_y) (((_x) < (_y)) ? (_x) : (_y))
#endif
#ifndef MAX
#define MAX(_x,_y) (((_x) > (_y)) ? (_x) : (_y))
#endif

#define E_OK 					(Std_ReturnType)0
#define E_NOT_OK 				(Std_ReturnType)1

#define E_NO_DTC_AVAILABLE		(Std_ReturnType)2
#define E_SESSION_NOT_ALLOWED	(Std_ReturnType)4
#define E_PROTOCOL_NOT_ALLOWED	(Std_ReturnType)5
#define E_REQUEST_NOT_ACCEPTED	(Std_ReturnType)8
#define E_REQUEST_ENV_NOK		(Std_ReturnType)9
#ifndef E_PENDING	// for WIN32
#define E_PENDING				(Std_ReturnType)10
#endif
#define E_COMPARE_KEY_FAILED	(Std_ReturnType)11
#define E_FORCE_RCRRP			(Std_ReturnType)12

#define STD_HIGH		0x01
#define STD_LOW			0x00

#define STD_ACTIVE		0x01
#define STD_IDLE		0x00

#define STD_ON			0x01
#define STD_OFF         0x00

#define NULL            ((void*)0)


#endif	/* STD_TYPES_H */

