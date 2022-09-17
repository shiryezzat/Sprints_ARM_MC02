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
 
 #include "IntCtrl_Cfg.h"
 
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
const IntCtrl_ConfigType intCtrl_Cofig[ACTIVATED_INT_NUM]=
{
	//Peripheral			group priority 	subgroup priority
	{GPIO_Port_F,			0u,			0u},
	{Bit32_16_Timer_1A,		1u,			0u}

};
 
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
 void NVIC_SetPRIx(const IntCtrl_ConfigType *ConfigPtr)
 {
    uint32 bitOffset;
    uint32 offset;
    
    	bitOffset = ((((ConfigPtr->vectorName) % 4) * 8) +5) ;
		offset= (ConfigPtr->vectorName) / 4;

		#if		(PRIGROUPING == XXX)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << bitOffset);
		#elif	(PRIGROUPING == XXY)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << (bitOffset+1));
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
    	#elif	(PRIGROUPING == XYY)	
			NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->groupPriority << (bitOffset+2));
			NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
   		#elif	(PRIGROUPING == YYY)
    		NVIC->PRI[(ConfigPtr->vectorName) / 4].R |= (ConfigPtr->subGroupPriority << bitOffset);
    	#endif
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
 void NVIC_SetENx(const IntCtrl_ConfigType *ConfigPtr)
 {
	uint32 bitOffset;

	bitOffset = (ConfigPtr->vectorName %32) ;
	NVIC->EN[ConfigPtr->vectorName /32] |= ((1u) << bitOffset);
 }

/**************************************************************************************************
 *	END OF FILE:
 *************************************************************************************************/