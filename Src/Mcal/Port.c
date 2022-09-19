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
 #include "Port.h"
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
 void Port_SetPinDirection(const Port_ConfigType *ConfigPtr);
 void Port_SetPinMode(const Port_ConfigType *ConfigPtr);
 void Port_SetPinInternalAttach(const Port_ConfigType *ConfigPtr);
 void Port_SetPinOutputCurrent(const Port_ConfigType *ConfigPtr);

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
 void Port_Init()
 {
    for (int i = 0; i < ACTICATED_PINS_NUM; i++)
    {
        Port_SetPinDirection(&Port_Config[i]);
        Port_SetPinMode(&Port_Config[i]);
        Port_SetPinInternalAttach(&Port_Config[i]);
        Port_SetPinOutputCurrent(&Port_Config[i]);
    }
    
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
void Port_SetPinDirection(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    // uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    // uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

    if(ConfigPtr->direction)
    {
        GPIO(port)->GPIODIR |= (1<<pin);        /*Output by setting the pin*/
    }
    else
    {
        GPIO(port)->GPIODIR &= ~(1<<pin);       /*Input by clearing the pin*/
    }
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
void Port_SetPinMode(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    // uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    // uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

    if(ConfigPtr->mode)
    {
        GPIO(port)->GPIOAFSEL |= (1<<pin);
        GPIO(port)->GPIOPCTL  |= (ConfigPtr->mode<<(4*pin));
    }
    else
    {
        GPIO(port)->GPIOAFSEL &=~(1<<pin);      /*GPIO mode*/
    }
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
void Port_SetPinInternalAttach(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    // uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    // uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

    switch (ConfigPtr->internalAttach)
    {
    case Port_PinOpenDrain:
        GPIO(port)->GPIOODR |= (1<<pin);
        break;

    case Port_PinPullUp:
        GPIO(port)->GPIOPUR |= (1<<pin);
    break;
    
    case Port_PinPullDown:
        GPIO(port)->GPIOPDR |= (1<<pin);
    break;
    
    default:
        break;
    }
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
void Port_SetPinOutputCurrent(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    // uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    // uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

    switch (ConfigPtr->outputcurrent)
    {
    case Port_2ma:
        GPIO(port)->GPIODR2R |= (1<<pin);
        break;

    case Port_4ma:
        GPIO(port)->GPIODR4R |= (1<<pin);
    break;
    
    case Port_8ma:
        GPIO(port)->GPIODR8R |= (1<<pin);
    break;
    
    default:
        break;
    }
}

/**************************************************************************************************
 *	END OF FILE:
 *************************************************************************************************/
