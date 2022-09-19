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
#include "Mcu_Hw.h"
#include "Dio_Types.h"

/**************************************************************************************************
 *	GLOBAL CONSTANT MACROS
 *************************************************************************************************/
#define FIRST_2BITS_MASK                       0x000000FFu
#define SECOND_2BITS_MASK                      0x0000FF00u
/**************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 *************************************************************************************************/
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
extern void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level);
extern void Dio_FlipChannel(Dio_ChannelType ChannelId);

/**************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 *************************************************************************************************/

 

 #endif    /* DIO_H */
 
/**************************************************************************************************
 *	END OF FILE:	Dio.h
 *************************************************************************************************/