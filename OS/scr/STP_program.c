/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 15/10/2020                */
/* version  : v01                      */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void HSTP_voidInit(void)
{
	GPIO_voidSetPinDirection(HSTP_SHIFT_CLOCK ,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(HSTP_STORE_CLOCK ,OUTPUT_10MHZ_PUSH_PULL);
	GPIO_voidSetPinDirection(HSTP_DATA_SEND   ,OUTPUT_10MHZ_PUSH_PULL);
}


void HSTP_voidSendSyncronous( u16 copy_u16SendToData)
{
	u16 Loc_u16bit ;
	if(NUMBER_OF_ICS==1)
	{
	        for(s8 loc_s8counter =7 ;loc_s8counter >=0;loc_s8counter --)
	        {
	        	Loc_u16bit = GET_BIT(copy_u16SendToData,loc_s8counter);
	        	GPIO_voidSetPinValue(HSTP_DATA_SEND,Loc_u16bit);
	        	
	        	    //SEND CLOCK TO SHIFT CLOCK
		             GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIEGH);
		             MSYSTICK_voidSetBusyWait(1);
		             GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
	        }
	}
	else if (NUMBER_OF_ICS==2)
	{
		     for(s8 loc_s8counter =15 ;loc_s8counter >=0;loc_s8counter --)
	        {
	        	Loc_u16bit = GET_BIT(copy_u16SendToData,loc_s8counter);
	        	GPIO_voidSetPinValue(HSTP_DATA_SEND,Loc_u16bit);
	        	//SEND CLOCK TO SHIFT CLOCK
		             GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_HIEGH);
		             MSYSTICK_voidSetBusyWait(1);
		             GPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,GPIO_LOW);
	        }
	}
	          //SEND CLOCK TO DATA STORE CLOCK
	        	GPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_HIEGH);
	        	MSYSTICK_voidSetBusyWait(1);
	        	GPIO_voidSetPinValue(HSTP_STORE_CLOCK,GPIO_LOW);
	   
}
