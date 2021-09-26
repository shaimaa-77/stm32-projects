/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 27/8/2020                */
/* version  : v01                      */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
static u8  MSYSTICK_u8ModeOfInterval;
void MSYSTICK_voidInit()
{
	//ENABLE SYSTIC &CHOOSE THE CLK 
	SYSTICK->STK_CTRL |=(SySTICK_CLKSOURCE <<SYSTICK_REG_CLKSOURCE);
}

void MSYSTICK_voidSetBusyWait(u32 copy_u32LoadValue)
{
	SYSTICK->STK_LOAD = copy_u32LoadValue;
	//enable systick 
	SET_BIT(SYSTICK->STK_CTRL,SYSTICK_REG_ENABLE );
	while(GET_BIT(SYSTICK->STK_CTRL ,SYSTICK_REG_COUNTFLAG)==0);
	//STOP TIMER 
	CLR_BIT(SYSTICK->STK_CTRL,SYSTICK_REG_ENABLE );
	SYSTICK-> STK_LOAD =0;
	SYSTICK-> STK_VAL =0;
}
void MSYSTICK_voidSetIntervalSingle(u32 copy_u32LoadValue , void (*copy_ptr)(void))
{
	//DISABLE TIMER 
	CLR_BIT (SYSTICK -> STK_CTRL ,SYSTICK_REG_ENABLE) ;
	SYSTICK -> STK_VAL =0;
	
	SYSTICK -> STK_LOAD = copy_u32LoadValue;
	// start timer 
	SET_BIT (SYSTICK -> STK_CTRL ,SYSTICK_REG_ENABLE) ;
	MSYSTICK_CallBack = copy_ptr;
	MSYSTICK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL ;
	// enable interrupt 
	SET_BIT(SYSTICK -> STK_CTRL ,SYSTICK_REG_TICK_INT)   ;
  
}
void MSYSTICK_voidSetIntervalPeriodic(u32 copy_u32LoadValue , void (*copy_ptr)(void))
{
	
	SYSTICK -> STK_LOAD = copy_u32LoadValue;
	//enable systick &interrupt
	SET_BIT(SYSTICK -> STK_CTRL ,SYSTICK_REG_ENABLE)   ;
	MSYSTICK_CallBack = copy_ptr;
	MSYSTICK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL;
	SET_BIT (SYSTICK -> STK_CTRL ,SYSTICK_REG_TICK_INT) ;
}
void MSYSTICK_voidStopTimer(void)
{
	//DISABLE INTERRUPT
	CLR_BIT(SYSTICK-> STK_CTRL,SYSTICK_REG_TICK_INT );
	//STOP TIMER 
	CLR_BIT(SYSTICK -> STK_CTRL,SYSTICK_REG_ENABLE );
	SYSTICK -> STK_LOAD =0;
	SYSTICK -> STK_VAL =0;
	
}


u32  MSYSTICK_U32GetRemainingTime(void)
{
	u32 loc_remaining = SYSTICK -> STK_VAL;
	return loc_remaining ;
}


u32  MSYSTICK_U32GetElapsedTime(void)
{
	u32 loc_elapsed = SYSTICK->STK_LOAD - SYSTICK->STK_VAL;
	return loc_elapsed;
}


void MSYSTICK_voidSetCallback(void (* copy_ptr)(void))
{
	MSYSTICK_CallBack =copy_ptr ;
}


void SysTick_Handler(void)
{
	u8 loc_u8temporary;
	if(MSYSTICK_u8ModeOfInterval== MSTK_SINGLE_INTERVAL)
	{
		//DISABLE INTERRUPT
	CLR_BIT(SYSTICK -> STK_CTRL,SYSTICK_REG_TICK_INT );
	//STOP TIMER 
	CLR_BIT(SYSTICK -> STK_CTRL,SYSTICK_REG_ENABLE );
	SYSTICK -> STK_LOAD =0;
	SYSTICK -> STK_VAL =0;
	}
	//CALLBACK NOTIFICATIN
	MSYSTICK_CallBack();
	//CLEAR THE INTERRUPT FLAG
	loc_u8temporary = GET_BIT(SYSTICK-> STK_CTRL,SYSTICK_REG_COUNTFLAG);
}
