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
 #include "F:\Embedded_Systems_Advanced_FWD\uVisionProjects\Sprints_ARM_MC02\Src\Mcal\Inc\IntCtrl.h"
 
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
 *	\Syntax				: void IntCtrl_Init(void)
 *	\Description		: Initialize NVIC\SCB Module by passing the
 *                        the configuration into NVIC\SCB registers
 *	\Sync\Async			: Synchronous
 *	\Reentrancy			: None Reentrant
 *	\Parameters (in)	: None
 *	\Parameters (out)	: None
 *	\Return value		: None
 *
 *******************************************************************/
 void IntCtrl_Init(void)
 {
   volatile uint8 IRQNumber=0;

   /*Enabling FAULTMASK and PRIMASK using MSR or CPS*/
   __asm("CPSIE f");
   __asm("CPSIE i");

   SCB->CFGCTRL |= 0x10;        /*Enable SWTRIG by setting MAINPEND (bit 1)*/

   NVIC->SWIDETRIG |= 0x00000001; /*This field holds the interrupt ID 
                                    of the required SGI. For example, a 
                                    value of 0x3 generates an interrupt on IRQ3*/
   
   /*onfigure Grouping\Subgrouping system in APINT register in SCB*/
   SCB->APINT.BF.VECTKEY = 0xFA05;
   SCB->APINT.BF.PRIGROUP = PRIGROUPING;

  for (uint8 i = 0; i < ACTIVATED_INT_NUM; i++)
  {
    /*Assign Group\Subgroup priority in NVIC_PRIx and SCB_SYSPRIx registers*/
    NVIC_SetPRIx(&intCtrl_cofig[i]);

    /*Enable\Disable based on your configuration in NVIC_ENx and SCB_Sys register*/
    NVIC_SetENx(&intCtrl_cofig[i]);

  }
  
 }
 
/**************************************************************************************************
 *	END OF FILE: Std_Types.h
 *************************************************************************************************/