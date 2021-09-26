/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 24/8/2020                */
/* version  : v01                      */
/****************************************************************************************/
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 #include "NVIC_interface.h"
 #include "NVIC_private.h"
 #include "NVIC_config.h"
 
 
 void MNVIC_voidInit(void)
 {
	 #define SCB_AIRCR                                 *((volatile u32 *) 0xE000ED0C)
      SCB_AIRCR = NVIC_GROUP_SUB ;
 }
 void MNVIC_voidEnableInterrupt (u8 copy_u8IntNumber )
 {

	 if( copy_u8IntNumber <=31)
	 {
		 SET_BIT ( NVIC_ISER0 , copy_u8IntNumber);

	 }
	else if( copy_u8IntNumber <=63)
	 {
		 copy_u8IntNumber -=32;
		 SET_BIT ( NVIC_ISER1 , copy_u8IntNumber);

	 }


 }
 
 void MNVIC_voidDisableInterrupt (u8 copy_u8IntNumber )
 {
	 if(  copy_u8IntNumber <=31)
	 {
		 SET_BIT ( NVIC_ICER0 , copy_u8IntNumber);

	 }
	else if( copy_u8IntNumber <=63)
	 {
		 copy_u8IntNumber -=32;
		 SET_BIT ( NVIC_ICER1 , copy_u8IntNumber);

	 }

 }
 
 void MNVIC_voidEnableInterruptPending (u8 copy_u8IntNumber )
 {

	 if( copy_u8IntNumber <=31)
	 {
		 SET_BIT ( NVIC_ISPR0 , copy_u8IntNumber);

	 }
	else if( copy_u8IntNumber <=63)
	 {
		 copy_u8IntNumber -=32;
		 SET_BIT ( NVIC_ISPR1 , copy_u8IntNumber);

	 }

 }
 void MNVIC_voidDisableInterruptPending (u8 copy_u8IntNumber )
 {

	 if( copy_u8IntNumber <=31)
	 {
		 SET_BIT ( NVIC_ICPR0 , copy_u8IntNumber); 

	 }
	else if( copy_u8IntNumber <=63)
	 {
		 copy_u8IntNumber -=32;
		 SET_BIT ( NVIC_ICPR1 , copy_u8IntNumber);

	 }

 }
 u8  MNVIC_u8GetActiveFlag (u8 copy_u8IntNumber )
 {
	 u8 LOC_u8Result=0;
	 if( copy_u8IntNumber <=31)
	 {
		LOC_u8Result = GET_BIT ( NVIC_IABR0 , copy_u8IntNumber); 
		
	 }
	else if( copy_u8IntNumber <=63)
	 {
		 copy_u8IntNumber -=32;
		 LOC_u8Result = GET_BIT ( NVIC_IABR1 , copy_u8IntNumber);
		 
	 }
	 else 
	 {
		 //return error
	 }
	return LOC_u8Result ; 
 }
 
 void NVIC_VoidSetPriority(u8 copy_u8preipheralIdx , u8 copy_u8group ,u8 copy_u8sub)
 {
	 u8 priority=0;
	 if(copy_u8preipheralIdx <60)
	 {
		 if      ( NVIC_GROUP_SUB == NVIC_GROUP4_SUB0) 
		 {
			 priority |= ( copy_u8group <<4);
			 NVIC_IPR [copy_u8preipheralIdx] =priority;
		 }
	     else if ( NVIC_GROUP_SUB == NVIC_GROUP3_SUB1)
		 {
			 priority |=(( copy_u8group <<5)|(copy_u8sub<<4));
			 NVIC_IPR [copy_u8preipheralIdx] =priority;
		 }
         else if ( NVIC_GROUP_SUB == NVIC_GROUP2_SUB2)
		 {
			  priority |=(( copy_u8group <<6)|(copy_u8sub<<4));
			 NVIC_IPR [copy_u8preipheralIdx] =priority;
		 }
         else if ( NVIC_GROUP_SUB == NVIC_GROUP1_SUB3)
		 {
			  priority |=(( copy_u8group <<7)|(copy_u8sub<<4));
			 NVIC_IPR [copy_u8preipheralIdx] =priority;
		 }
         else if ( NVIC_GROUP_SUB == NVIC_GROUP0_SUB4)
		 {		
            priority |= ( copy_u8sub <<4);
	     	NVIC_IPR [copy_u8preipheralIdx] =priority;
		 }
	 }
	 else
	 {		 
		 /*report error*/
	 }
 }
 
 
