/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Gpt_Types.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
 #include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Std_Types.h"

/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
#define GPT_PREDEF_TIMER_1US_16BIT
#define GPT_PREDEF_TIMER_1US_24BIT
#define GPT_PREDEF_TIMER_1US_32BIT
#define GPT_PREDEF_TIMER_100US_32BIT
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
typedef enum
{
    Gpt_Timer0 = 0x30u,
    Gpt_Timer1 = 0x31u,
    Gpt_Timer2 = 0x32u,
    Gpt_Timer3 = 0x33u,
    Gpt_Timer4 = 0x34u,
    Gpt_Timer5 = 0x35u,

    Gpt_WideTimer0 = 0x36u,
    Gpt_WideTimer1 = 0x37u,
    Gpt_WideTimer2 = 0x4Cu,
    Gpt_WideTimer3 = 0x4Du,
    Gpt_WideTimer4 = 0x4Eu,
    Gpt_WideTimer5 = 0x4Fu
    
} Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef enum
{
    Gpt_OneShot = 1u,
    Gpt_Periodic = 2u
    
} Gpt_ModeType;

typedef struct
{
    Gpt_ChannelType channelID;
    Gpt_ModeType channelMode;

} Gpt_ConfigType;

typedef void (*Gpt_Notification)();
 

 #endif    /* GPT_TYPES_H */
 
/**************************************************************************************************
 *	END OF FILE:	Gpt_Types.h
 *************************************************************************************************/