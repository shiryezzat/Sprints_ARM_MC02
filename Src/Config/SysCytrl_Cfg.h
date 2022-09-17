/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	SysCtrl_Cfg.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef SYSCTRL_CFG_H
#define SYSCTRL_CFG_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Std_Types.h"
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Mcu_Hw.h"
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\SysCtrl_Types.h"
/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
#define ACTICATED_PERIPHIRALS_NUM           2
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/
extern const SysCtrl_ConfigType SysCtrl_Config[ACTICATED_PERIPHIRALS_NUM];

 

 #endif    /* SYSCTRL_CFG_H */
 
/**************************************************************************************************
 *	END OF FILE:	SysCtrl_Cfg.h
 *************************************************************************************************/