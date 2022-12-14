/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  types to be used in general purpose timers driver
 *
 *********************************************************************************************************************/
#ifndef GPT_Types_H
#define GPT_Types_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    Gpt_Timer0 = 0x40030000u,
    Gpt_Timer1 = 0x40031000u,
    Gpt_Timer2 = 0x40032000u,
    Gpt_Timer3 = 0x40033000u,
    Gpt_Timer4 = 0x40034000u,
    Gpt_Timer5 = 0x40035000u,

    Gpt_WideTimer0 = 0x40036000u,
    Gpt_WideTimer1 = 0x40037000u,
    Gpt_WideTimer2 = 0x4004C000u,
    Gpt_WideTimer3 = 0x4004D000u,
    Gpt_WideTimer4 = 0x4004E000u,
    Gpt_WideTimer5 = 0x4004F000u

} Gpt_ChannelType;

typedef uint32 Gpt_ValueType;

typedef enum
{
    Gpt_OneShot = 1u,
    Gpt_Periodic = 2u
    
} Gpt_ModeType;

typedef void (*Gpt_Notification)();

typedef struct
{
    Gpt_ChannelType channelID;
    Gpt_ModeType channelMode;

} Gpt_ConfigType;

#endif /* GPT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_types.h
 *********************************************************************************************************************/