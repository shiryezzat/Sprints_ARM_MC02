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
#include "Gpt.h"
/**************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL DATA
 *************************************************************************************************/
 Gpt_Notification callBacksArray[12] = {NULL};

/**************************************************************************************************
 *	GLOBAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 *************************************************************************************************/ 
 void Gpt_SetTimerModuleInit(Gpt_ConfigType *ConfigPtr);
 void Gpt_SetTimerMode(Gpt_ConfigType *ConfigPtr);

/**************************************************************************************************
 *	LOCAL FUNCTIONS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTIONS
 *************************************************************************************************/
 
/********************************************************************
 *	\Syntax				: void Gpt_Init()
 *	\Description		: Initialize the General Purpose Timers module
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: None
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
 void Gpt_Init()
 {
    uint8 i;
    for (i = 0; i < ACTIVATED_TIMERS_NUM; i++)
    {
        Gpt_SetTimerModuleInit(&gpt_config[i]);
        Gpt_SetTimerMode(&gpt_config[i]);
    }
 }

  
/********************************************************************
 *	\Syntax				: void Gpt_SetTimerModuleInit(Gpt_ConfigType *ConfigPtr)
 *	\Description		: Set Timer Module
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: Gpt_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
void Gpt_SetTimerModuleInit(Gpt_ConfigType *ConfigPtr)
{
    TIMER(ConfigPtr->channelID)->GPTMCTL = 0;       /* Disable timer */
    TIMER(ConfigPtr->channelID)->GPTMCFG = 0x0u;    /* Concatenate */
    TIMER(ConfigPtr->channelID)->GPTMTAMR &= ~(1u << 4u);   /* Count down*/
    TIMER(ConfigPtr->channelID)->GPTMIMR = 0;       /* Disable Interrupts */
}

/********************************************************************
 *	\Syntax				: void Gpt_SetTimerMode(Gpt_ConfigType *ConfigPtr)
 *	\Description		: Set Timer Mode
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: Gpt_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
void Gpt_SetTimerMode(Gpt_ConfigType *ConfigPtr)
{
    switch (ConfigPtr->channelMode)
    {
    case Gpt_OneShot:
        TIMER(ConfigPtr->channelID)->GPTMTAMR |= 1u << 0u;
        break;
    case Gpt_Periodic:
        TIMER(ConfigPtr->channelID)->GPTMTAMR |= 1u << 1u;
        break;
    }
}

/********************************************************************
 *	\Syntax				: void Gpt_EnableNotification(Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr)
 *	\Description		: Enable channel to trigger an interrupt 
 *                        when time out and setting callBack Functoin
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
 void Gpt_EnableNotification(Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr)
{
    uint8 j=0;
	Gpt_ChannelType i=Gpt_Timer0;

	/* set call back to global array*/
	while(i <= Gpt_WideTimer5)
	{
		callBacksArray[j] = callBackPtr;
		i++;
        
		if (i==Gpt_WideTimer1)
			{
				i=Gpt_WideTimer2;
			}
			j++;
	}
    
    TIMER(ConfigPtr->channelID)->GPTMIMR |= 1;         /*enable time out interrupt*/

    // // set call back to global array
    // switch (ConfigPtr->channelID)
    // {
    // case Gpt_Timer0:
    //     callBacksArray[0] = callBackPtr;
    //     break;
    // case Gpt_Timer1:
    //     callBacksArray[1] = callBackPtr;
    //     break;
    // case Gpt_Timer2:
    //     callBacksArray[2] = callBackPtr;
    //     break;
    // case Gpt_Timer3:
    //     callBacksArray[3] = callBackPtr;
    //     break;
    // case Gpt_Timer4:
    //     callBacksArray[4] = callBackPtr;
    //     break;
    // case Gpt_Timer5:
    //     callBacksArray[5] = callBackPtr;
    //     break;
    // case Gpt_WideTimer0:
    //     callBacksArray[6] = callBackPtr;
    //     break;
    // case Gpt_WideTimer1:
    //     callBacksArray[7] = callBackPtr;
    //     break;
    // case Gpt_WideTimer2:
    //     callBacksArray[8] = callBackPtr;
    //     break;
    // case Gpt_WideTimer3:
    //     callBacksArray[9] = callBackPtr;
    //     break;
    // case Gpt_WideTimer4:
    //     callBacksArray[10] = callBackPtr;
    //     break;
    // case Gpt_WideTimer5:
    //     callBacksArray[11] = callBackPtr;
    //     break;
    // }

}


/********************************************************************
 *	\Syntax				: void Gpt_DisableNotification(Gpt_ConfigType *ConfigPtr)
 *	\Description		: Disable channel triggering an interrupt 
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: Gpt_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
void Gpt_DisableNotification(Gpt_ConfigType *ConfigPtr)
{
    TIMER(ConfigPtr->channelID)->GPTMICR = 0x10F1F;        /*disable interrupts*/
}

/********************************************************************
 *	\Syntax				: void Gpt_StartTimer(Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue)
 *	\Description		: load the Interval value and start counting
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
void Gpt_StartTimer(Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue)
{
    TIMER(ConfigPtr->channelID)->GPTMTAILR = loadValue * 0xF423FF;
    TIMER(ConfigPtr->channelID)->GPTMICR |= (1<<0);        /* TimerA timeout flag bit clears*/
    TIMER(ConfigPtr->channelID)->GPTMCTL |= (1u << 0);
}




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
