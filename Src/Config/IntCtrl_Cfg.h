/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	IntCtrl_Cfg.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/

#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Std_Types.h"
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Mcu_Hw.h"
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\IntCtrl_Types.h" 
/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
#define ACTIVATED_INT_NUM                           (2u)

/*
 * xxx__ for group priority(0->7), subgroup priority (0)
 * xxy__ for group priority(0->3), subgroup priority (0->1)
 * xyy__ for group priority(0->1), subgroup priority (0->3)
 * yyy__ for group priority(0)	 , subgroup priority (0->7)
 */
#define PRIGROUPING                                 XXY

/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
void NVIC_SetPRIx(const IntCtrl_ConfigType *ConfigPtr);

/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
extern const IntCtrl_ConfigType intCtrl_cofig[ACTIVATED_INT_NUM];

 

 #endif    /* INTCTRL_CFG_H */
 
/**************************************************************************************************
 *	END OF FILE:	IntCtrl_Cfg.h
 *************************************************************************************************/