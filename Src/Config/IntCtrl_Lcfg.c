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
	//Peripheral,  		group priority, subgroup priority
	{GPIO_Port_F, 		0u,				0u},
	{Bit32_16_Timer_1A, 1u,				0u}

};
 

/**************************************************************************************************
 *	END OF FILE:
 *************************************************************************************************/
