/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Gpt.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "Mcu_Hw.h"
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 void Gpt_Init(void);

 void Gpt_EnableNotification(Gpt_ConfigType *ConfigPtr, Gpt_Notification callBackPtr);
 void Gpt_DisableNotification(Gpt_ConfigType *ConfigPtr);
 void Gpt_StartTimer(Gpt_ConfigType *ConfigPtr, Gpt_ValueType loadValue);
 

/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/


 #endif    /* GPT_H */
 
/**************************************************************************************************
 *	END OF FILE:	Gpt.h
 *************************************************************************************************/
