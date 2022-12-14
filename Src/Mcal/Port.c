/*********************************************************************************************************************
 *	FILE DESCRIPTION
 *	----------------------------------------------------------------------------------------------------------------*/
/*********************		\file
 *		\brief
 *
 *		\details
 *
 *
 ********************************************************************************************************************/
  
/*********************************************************************************************************************
 *	INCLUDES
 ********************************************************************************************************************/
 #include "Port.h"
/*********************************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 ********************************************************************************************************************/
 
/*********************************************************************************************************************
 *	LOCAL DATA
 ********************************************************************************************************************/
 
/*********************************************************************************************************************
 *	GLOBAL DATA
 ********************************************************************************************************************/
 
/*********************************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 ********************************************************************************************************************/
 void Port_SetPinDirection(const Port_ConfigType *ConfigPtr);
 void Port_SetPinMode(const Port_ConfigType *ConfigPtr);
 void Port_SetPinInternalAttach(const Port_ConfigType *ConfigPtr);
 void Port_SetPinOutputCurrent(const Port_ConfigType *ConfigPtr);

/*********************************************************************************************************************
 *	LOCAL FUNCTIONS
 ********************************************************************************************************************/
 
/*********************************************************************************************************************
 *	GLOBAL FUNCTIONS
 ********************************************************************************************************************/

 
/***************************************************************************************
 *	\Syntax				: void Port_Init()
 *	\Description		: call local functions that configure required I/O pins
                          direction, alternate function, internal attach and required
                          driving output current
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: None
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 **************************************************************************************/
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
 
  
/***************************************************************************************
 *	\Syntax				: void Port_SetPinDirection(const Port_ConfigType *ConfigPtr)
 *	\Description		: configure pin direction
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: const Port_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 **************************************************************************************/
void Port_SetPinDirection(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    if(ConfigPtr->direction)
    {
        GPIO(port)->GPIODIR |= (1<<pin);        /*Output by setting the pin*/
    }
    else
    {
        GPIO(port)->GPIODIR &= ~(1<<pin);       /*Input by clearing the pin*/
    }
}

/***************************************************************************************
 *	\Syntax				: void Port_SetPinMode(const Port_ConfigType *ConfigPtr)
 *	\Description		: configure pin mode
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: const Port_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 **************************************************************************************/
void Port_SetPinMode(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

    if((ConfigPtr->mode) == Port_Digital)
    {
        
        GPIO(port)->GPIOAFSEL &=~(1<<pin);      /*GPIO mode*/
        GPIO(port)->GPIODEN |= (1<<pin);

    }
    else
    {   
        GPIO(port)->GPIOAFSEL |= (1<<pin);
        GPIO(port)->GPIOPCTL &= ~(0b1111 << (pin * 4));
        GPIO(port)->GPIOPCTL  |= (ConfigPtr->mode<<(4*pin));

    }
}

/***************************************************************************************
 *	\Syntax				: void Port_SetPinInternalAttach(const Port_ConfigType *ConfigPtr)
 *	\Description		: configure pin internal attach
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: const Port_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 **************************************************************************************/
void Port_SetPinInternalAttach(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

	uint16 attach =ConfigPtr->internalAttach;
    switch (attach)
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

/***************************************************************************************
 *	\Syntax				: void Port_SetPinOutputCurrent(const Port_ConfigType *ConfigPtr)
 *	\Description		: configure pin output current
 *
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: Non Reentrant
 *	\Parameters (in)	: const Port_ConfigType *ConfigPtr
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 **************************************************************************************/
void Port_SetPinOutputCurrent(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin >> 4u));
    uint32 pin = (ConfigPtr->pin & 0xfu);

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

/*********************************************************************************************************************
 *	END OF FILE:
 ********************************************************************************************************************/
