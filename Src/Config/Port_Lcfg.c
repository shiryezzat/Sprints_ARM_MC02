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
 #include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Config\Port_Cfg.h"
/**************************************************************************************************
 *	LOCAL MACROS CONSTANT\FUNCTION
 *************************************************************************************************/
 
/**************************************************************************************************
 *	LOCAL DATA
 *************************************************************************************************/
 
/**************************************************************************************************
 *	GLOBAL DATA
 *************************************************************************************************/
 //configrations array
const Port_ConfigType Port_Config[ACTICATED_PINS_NUM]=
{
    //channel     direction       mode             internal attach                output current
    {Port_Pin_F0, Port_PinInput,  Port_PinDigital, Port_PinPullUp,                Port_PinOutputCurrentDefault},
    {Port_Pin_F4, Port_PinInput,  Port_PinDigital, Port_PinPullUp,                Port_PinOutputCurrentDefault},
    {Port_Pin_F2, Port_PinOutput, Port_PinDigital, Port_PinInternalAttachDefault, Port_4ma}
};
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
 *	\Reentrancy			:
 *	\Parameters (in)	:
 *	\Parameters (out)	:
 *	\Return value		:
 *
 *******************************************************************/
void Port_SetPinDirection(const Port_ConfigType *ConfigPtr)
{
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

    if(ConfigPtr->direction)
    {
        GPIO(port)->GPIODIR |= (1<<pin);        //Output by setting the pin
    }
    else
    {
        GPIO(port)->GPIODIR &= ~(1<<pin);       //Input by clearing the pin
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
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);
    if(ConfigPtr->mode)
    {
        GPIO(port)->GPIOAFSEL |= (1<<pin);
        GPIO(port)->GPIOPCTL  |= (ConfigPtr->mode<<(4*pin));
    }
    else
    {
        GPIO(port)->GPIOAFSEL &=~(1<<pin);      //GPIO mode
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
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

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
    uint32 port = (GPIO_COMMON_BASE | (ConfigPtr->pin & SECOND_2BITS_MASK));
    uint32 pin = (ConfigPtr->pin & FIRST_2BITS_MASK);

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