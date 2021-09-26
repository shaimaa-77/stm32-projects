/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */

/* Date     : 1/10/2020                */
/* version  : v01                      */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SEG7_config.h"
#include "SEG7_interface.h"
#include "SEG7_private.h"


void SEG7_voidInit7Seg( )
{
	#if     SEG7_PORT == GPIOA
		     RCC_voidEnableClock(RCC_APB2 , 2 );

	#elif SEG7_PORT == GPIOB
		     RCC_voidEnableClock(RCC_APB2 , 3 );	
	#elif SEG7_PORT == GPIOC
		     RCC_voidEnableClock(RCC_APB2 , 4 ); 
			 
	#endif
     
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_A   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_B   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_C   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_D   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_E   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_F   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_G   , OUTPUT_10MHZ_PUSH_PULL );
			 GPIO_voidSetPinDirection( SEG7_PORT , SEG7_DOT , OUTPUT_10MHZ_PUSH_PULL );
}

void SEG7_voidDisplayNumbre( u8  copy_u8numbre,u8 * copy_u8PSEGValue)
{
	#ifdef CATHODE
    #ifdef STP
	 if(copy_u8numbre==0)
		* copy_u8PSEGValue = 0x3f;
	 else  if(copy_u8numbre==1)
			* copy_u8PSEGValue = 0x06;
	 else  if(copy_u8numbre==2)
			* copy_u8PSEGValue = 0x5b;
	 else  if(copy_u8numbre==3)
			* copy_u8PSEGValue = 0x4f;
	 else  if(copy_u8numbre==4)
			* copy_u8PSEGValue = 0x66;
	 else if(copy_u8numbre==5)
			* copy_u8PSEGValue = 0x67;
	 else  if(copy_u8numbre==6)
			* copy_u8PSEGValue = 0x7d;
	 else  if(copy_u8numbre==7)
			* copy_u8PSEGValue = 0x07;
	 else  if(copy_u8numbre==8)
			* copy_u8PSEGValue = 0x7f;
	 else  if(copy_u8numbre==9)
			* copy_u8PSEGValue = 0x6f;
#else

	  if( copy_u8numbre == 0)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if (copy_u8numbre == 1)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre == 2)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if (copy_u8numbre == 3)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre == 4)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre == 5)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre == 6)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre ==7)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre ==8)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  else if ( copy_u8numbre == 9)
	  {
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_C    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_D    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_E    , GPIO_LOW  );
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( SEG7_PORT , SEG7_DOT  , GPIO_LOW  );
	  }
	  
	  #endif
#endif

	/*
	#ifdef ANODE
	
	  #if copyu8_numbre == 0 
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	 #elif copyu8_numbre == 1
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	  
	  #elif copyu8_numbre == 2
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_HIEGH );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH );
	  
	  #elif copyu8_numbre == 3
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH);
	  
	  #elif copyu8_numbre == 4
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH );
	  
	  #elif copyu8_numbre == 5
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	 
	  #elif copyu8_numbre == 6
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	  
	  #elif copyu8_numbre ==7
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_HIEGH);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	  
	  #elif copyu8_numbre ==8
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	  
	  #elif copyu8_numbre == 9
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_A    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_B    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_C    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_D    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_E    , GPIO_HIEGH  );
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_F    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_G    , GPIO_LOW);
	  GPIO_voidSetPinValue( 7SEG_PORT , 7SEG_BOT  , GPIO_HIEGH  );
	  
	  #endif
    #endif
	
	
 */
	
}
 void SEG7_voidIncrease(u8 copy_u8Numbre,u8 * copy_u8PSEGValue)
 {
	 if(copy_u8Numbre ==9)
	 {
		 copy_u8Numbre =0;
	 }
	 SEG7_voidDisplayNumbre( copy_u8Numbre , copy_u8PSEGValue);
	 copy_u8Numbre ++;
 }
 void SEG7_voidDecrease(u8 copy_u8Numbre,u8 * copy_u8PSEGValue)
 {
	 if(copy_u8Numbre ==0)
	 {
		 copy_u8Numbre =9;
	 }
	  SEG7_voidDisplayNumbre( copy_u8Numbre , copy_u8PSEGValue);
	 copy_u8Numbre --;
 }
