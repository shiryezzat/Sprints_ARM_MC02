/**************************************************************************************************
 *	FILE DESCRIPTION
 *	---------------------------------------------------------------------------------------------*/
/**		\file
 *		\brief
 *
 *		\details
 *
 *
 *************************************************************************************************/
  
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\Gpt.h"
/**************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL FUNCTIONS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTIONS
 *************************************************************************************************/
 
 
/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
 void Gpt_Init()
 {
    for (int i = 0; i < ACTIVATED_TIMERS_NUM; i++)
    {
        Gpt_SetTimerModuleInit(&gpt_config[i]);
        Gpt_SetTimerMode(&gpt_config[i]);
    }

    // #if(GPT_PREDEF_TIMER_1US_16BIT)
    // //enable GPT_PREDEF_TIMER_1US_16BIT at value 0
    // #endif
 }

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
 void Gpt_EnableNotification(Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr)
{    
    
    uint32 timer = 0x40000000u | ((ConfigPtr->channelID)<<12u);
    uint8 j;

    // set call back to global array
    for (Gpt_ChannelType i=Gpt_Timer0, j=0; i <= Gpt_WideTimer5; i++, j++)
    {
        callBacksArray[j] = callBackPtr;
        if (i==Gpt_WideTimer1)
        {
            i=Gpt_WideTimer2-1;
        }   
    }
    TIMER(timer)->GPTMIMR |= 1;         /*enable time out interrupt*/
}


/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Gpt_DisableNotification(Gpt_ConfigType *ConfigPtr)
{
    uint32 timer = 0x40000000u | ((ConfigPtr->channelID)<<12u);
    TIMER(timer)->GPTMICR = 0x10F1F;        /*disable interrupts*/
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Gpt_StartTimer(Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue)
{
    uint32 timer = 0x40000000u | ((ConfigPtr->channelID)<<12u);

    TIMER(timer)->GPTMTAILR = loadValue * 0xF423FF;
    TIMER(timer)->GPTMICR = 0x1;        /* TimerA timeout flag bit clears*/
    TIMER(timer)->GPTMCTL |= (1u << 0);
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void TIMER1A_Handler(void)
{

    Gpt_Notification callback = callBacksArray[1];

    if (callback != NULL)
    {   
        TIMER1->GPTMICR |= 1 << 0;      /*clear interrupt status flag*/
        callback();                     /*jump to callback*/
    }
}

/**************************************************************************************************
 *	END OF FILE:    Gpt.c
 *************************************************************************************************/