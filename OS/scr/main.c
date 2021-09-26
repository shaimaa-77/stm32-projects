

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"

void TASK1 (void);
void TASK2 (void);
void TASK3 (void);
void TASK4 (void);
s8 gol_numbre;
u8 gol_value1;
u8 gol_value2;
u16 gol_STPvalue;
u8 gol_flag ;
void main (void)
{
	       	//initailize RCC CLK SOURCE
	RCC_voidInitSysClock();
               //ENABLE THE BUS FOR GPIOA
    RCC_voidEnableClock(RCC_APB2 , IOPAEN );
    // INIT SHIFT REGISTER
    HSTP_voidInit();
    // creat tasks
    OS_voidCreatTask(0,0,TASK1,0);
    OS_voidCreatTask(1,100,TASK2,0);
	OS_voidCreatTask(2,1000, TASK3,0);
	OS_voidCreatTask(3,4000, TASK4,0);
	//START os
	 OS_voidStartOS();
	while(1)
	{
		
	}
}
void TASK1(void)
{
	SEG7_voidDisplayNumbre((gol_numbre %10) , &gol_value1);

}
void TASK2(void)
{
	if(gol_numbre <9)
	{
	SEG7_voidDisplayNumbre(0 , &gol_value2);
	}
	else
	{
		SEG7_voidDisplayNumbre((gol_numbre /10), &gol_value2);
	}

}
void TASK3(void)
{
	if(gol_numbre <100 )
	{
		if(gol_flag==0)
	{
		gol_STPvalue = gol_value1  ;
		 gol_STPvalue =(gol_STPvalue <<8) | gol_value2 ;
		 HSTP_voidSendSyncronous(gol_STPvalue);
		 gol_numbre ++;
	}
	else {gol_flag =1;}
	}
}
void TASK4(void)
{
	if(gol_flag ==1)
	{
	if(gol_numbre >0)
		{
			gol_STPvalue = gol_value1  ;
			 gol_STPvalue =(gol_STPvalue <<8) | gol_value2 ;
			 HSTP_voidSendSyncronous(gol_STPvalue);
			 gol_numbre --;

		}
	else
	{
		gol_flag =0;
	}
	}
}
