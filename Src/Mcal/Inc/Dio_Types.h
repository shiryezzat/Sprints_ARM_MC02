/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Dio_Types.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Std_Types.h"
/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/

/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
typedef enum
{
    Dio_Channel_A0 = 0x4001u,
    Dio_Channel_A1 = 0x4002u,
    Dio_Channel_A2 = 0x4004u,
    Dio_Channel_A3 = 0x4008u,
    Dio_Channel_A4 = 0x4010u,
    Dio_Channel_A5 = 0x4020u,
    Dio_Channel_A6 = 0x4040u,
    Dio_Channel_A7 = 0x4080u,

    Dio_Channel_B0 = 0x5001u,
    Dio_Channel_B1 = 0x5002u,
    Dio_Channel_B2 = 0x5004u,
    Dio_Channel_B3 = 0x5008u,
    Dio_Channel_B4 = 0x5010u,
    Dio_Channel_B5 = 0x5020u,
    Dio_Channel_B6 = 0x5040u,
    Dio_Channel_B7 = 0x5080u,

    Dio_Channel_C0 = 0x6001u,
    Dio_Channel_C1 = 0x6002u,
    Dio_Channel_C2 = 0x6004u,
    Dio_Channel_C3 = 0x6008u,
    Dio_Channel_C4 = 0x6010u,
    Dio_Channel_C5 = 0x6020u,
    Dio_Channel_C6 = 0x6040u,
    Dio_Channel_C7 = 0x6080u,

    Dio_Channel_D0 = 0x7001u,
    Dio_Channel_D1 = 0x7002u,
    Dio_Channel_D2 = 0x7004u,
    Dio_Channel_D3 = 0x7008u,
    Dio_Channel_D4 = 0x7010u,
    Dio_Channel_D5 = 0x7020u,
    Dio_Channel_D6 = 0x7040u,
    Dio_Channel_D7 = 0x7080u,

    Dio_Channel_E0 = 0x2401u,
    Dio_Channel_E1 = 0x2402u,
    Dio_Channel_E2 = 0x2404u,
    Dio_Channel_E3 = 0x2408u,
    Dio_Channel_E4 = 0x2410u,
    Dio_Channel_E5 = 0x2420u,
    Dio_Channel_E6 = 0x2440u,
    Dio_Channel_E7 = 0x2480u,

    Dio_Channel_F0 = 0x2501u,
    Dio_Channel_F1 = 0x2502u,
    Dio_Channel_F2 = 0x2504u,
    Dio_Channel_F3 = 0x2508u,
    Dio_Channel_F4 = 0x2510u,
    Dio_Channel_F5 = 0x2520u,
    Dio_Channel_F6 = 0x2540u,
    Dio_Channel_F7 = 0x2580u

}Dio_ChannelType;

typedef enum
{
    Dio_Port_A = 0x40004000u,
    Dio_Port_B = 0x40005000u,
    Dio_Port_C = 0x40006000u,
    Dio_Port_D = 0x40007000u,
    Dio_Port_E = 0x40024000u,
    Dio_Port_F = 0x40025000u

}Dio_PortType;

typedef enum
{
    Dio_Low  = 0x0000,
    Dio_High = 0x0000

}Dio_LevelType;

typedef uint8 Dio_PortLevelType;
 
 #endif    /* DIO_TYPES_H */
 
/**************************************************************************************************
 *	END OF FILE:	Dio_Types.h
 *************************************************************************************************/