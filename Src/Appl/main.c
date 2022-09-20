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
#include "Mcu_Hw.h"
#include "Dio.h"
#include "SysCtrl.h"
#include "IntCtrl.h"
#include "Gpt.h"
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
uint8 onTime = 3;
uint8 offTime = 1;
/**************************************************************************************************
 *	LOCAL FUNCTION PROTOTYPES
 *************************************************************************************************/
 void blink(void);
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
int main(){
	//uint32 i=0;

	IntCtrl_Init();
	SysCtrl_Init();
	Port_Init();
	Gpt_Init();

	Gpt_EnableNotification(Gpt_Timer1, blink);
	Gpt_StartTimer(Gpt_Timer1, offTime);
	//Gpt_EnableNotification(&gpt_config[0], blink);
	//Gpt_StartTimer(&gpt_config[0], offTime);

	// for ( i = 0; i < ACTIVATED_TIMERS_NUM; i++)
	// {
	// 	Gpt_EnableNotification(&gpt_config[i], blink);
	// 	Gpt_StartTimer(&gpt_config[i], offTime);
	// }
	
	GPIOF->GPIODIR |= (1<<2);
	GPIOF->GPIODATA[2] = 0x1u;

	for(;;){}
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
void blink(){
	//uint32 i=0;
	
	if (Dio_ReadChannel(Dio_Channel_F2) == Dio_Low){
		Dio_FlipChannel(Dio_Channel_F2);
		
		Gpt_StartTimer(Gpt_Timer1, onTime);
		//Gpt_StartTimer(&gpt_config[0], onTime);
	}
	else{
		Dio_FlipChannel(Dio_Channel_F2);
		
		Gpt_StartTimer(Gpt_Timer1, offTime);
		//Gpt_StartTimer(&gpt_config[0], offTime);
	}

	// for ( i = 0; i < ACTIVATED_TIMERS_NUM; i++)
	// {
	// 	if (Dio_ReadChannel(Dio_Channel_F2) == Dio_Low){
	// 		Dio_FlipChannel(Dio_Channel_F2);
	// 		Gpt_StartTimer(&gpt_config[i], onTime);
	// 	}
	// 	else{
	// 		Dio_FlipChannel(Dio_Channel_F2);
	// 		Gpt_StartTimer(&gpt_config[i], offTime);
	// 	}
	// }
	
} 
 
/**************************************************************************************************
 *	END OF FILE:
 *************************************************************************************************/
