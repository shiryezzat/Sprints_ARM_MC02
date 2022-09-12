/**************************************************************************************************
 *	FILE DESCRIPTION
 *	-----------------------------------------------------------------------------------------------
 *	       File:	Dio.h
 *	     Module:
 *
 *	Description:
 *
 *
 *************************************************************************************************/
#ifndef DIO_H
#define DIO_H
/**************************************************************************************************
 *	INCLUDES
 *************************************************************************************************/
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Common\Mcu_Hw.h"
#include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\Dio_Types.h"

/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
extern void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level);
extern void Dio_FlipChannel(Dio_ChannelType ChannelId)

/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/

 

 #endif    /* DIO_H */
 
/**************************************************************************************************
 *	END OF FILE:	Dio.h
 *************************************************************************************************/