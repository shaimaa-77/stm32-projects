/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 12/10/2020                */
/* version  : v01                      */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"
 
 
 

 void OS_voidCreatTask(u8 copy_u8ID, u16 copy_u16pioridic, void (* ptr)(void),u8 copy_u8FirstDelay)
 {
	 if(OS_Tasks[copy_u8ID].Fptr== NULL)
	 {
	       OS_Tasks[copy_u8ID].priodicity = copy_u16pioridic;
	       OS_Tasks[copy_u8ID].Fptr = ptr;
	       OS_Tasks[copy_u8ID].FirstDelay = copy_u8FirstDelay ;
	       OS_Tasks[copy_u8ID].state = TASK_READY	 ;
	 }
 }
void OS_voidStartOS(void)
{
	//MSYSTICK_voidSetCallback(piriodic);
	// initailise systick 
	MSYSTICK_voidInit();
	//make tick =1 msec
	MSYSTICK_voidSetIntervalPeriodic(TICK_TIME , piriodic);
	
}


void piriodic(void)  //this func is ordering for tasks which one is run 
{
	
    for(u16 i=0;i<NUMBER_OF_TASKS;i++)
	{
		if ((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].state== TASK_READY))
		
		        if(OS_Tasks[i].FirstDelay==0)
		        {
		        	OS_Tasks[i].FirstDelay= OS_Tasks[i].priodicity -1;
		        	OS_Tasks[i].Fptr ();
		        }
		        else 
		        {
		        	OS_Tasks[i].FirstDelay--;
		        	
		        }
	}
}

void OS_voidDelatTask(u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].state =TASK_DORMANT;
	OS_Tasks[copy_u8ID].Fptr =NULL;
}
void OS_voidPueseTask(u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].state =TASK_PUASE;
}
void OS_voidResumeTask(u8 copy_u8ID)
{
	OS_Tasks[copy_u8ID].state=TASK_READY ;
}
