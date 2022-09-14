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
 #include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\Dio.h"
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
 *	\Reentrancy			:Reentrant
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint32 port = (GPIO_COMMON_BASE | (ChannelId & SECOND_2BITS_MASK));
    uint32 bit = (ChannelId & FIRST_2BITS_MASK);
        
    if (GPIO(port)->GPIODATA[bit])
    {
        return Dio_High;
    }
    else
    {
        return Dio_Low;
    }

}
 
/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:Reentrant
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint32 port = (GPIO_COMMON_BASE | (ChannelId & SECOND_2BITS_MASK));
    uint32 bit = (ChannelId & FIRST_2BITS_MASK);
        
    GPIO(port)->GPIODATA[bit] = Level;      //something maybe wrong here
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:Reentrant
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    return ((uint8)GPIO(PortId)->GPIODATA[255]);
}

/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:Reentrant
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level)
{
    GPIO(PortId)->GPIODATA[255] = Level;
}
 
/********************************************************************
 *	\Syntax				:
 *	\Description		:
 *
 *	\Sync\Async			:
 *	\Reentrancy			:None Reentrant
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint32 port = (GPIO_COMMON_BASE | (ChannelId & SECOND_2BITS_MASK));
    uint32 bit = (ChannelId & FIRST_2BITS_MASK);

    GPIO(port)->GPIODATA[255] ^=  ( ChannelId & FIRST_2BITS_MASK);
}
/**************************************************************************************************
 *	END OF FILE:
 *************************************************************************************************/