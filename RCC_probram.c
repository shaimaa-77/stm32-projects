/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidEnableClock(u8 Copy_u8BussID,u8 Copy_u8PrelID)
{
   if( Copy_u8PrelID <=31)
   {
      switch(Copy_u8BussID)
	  {
		  case RCC_AHP  :
		  SET_BIT(RCC_AHBENR     ,Copy_u8PrelID);
		  break;
		  case RCC_APB1 :
		   SET_BIT(RCC_APB1ENR   ,Copy_u8PrelID);
		   break;
		  case RCC_APB2 :
		  SET_BIT(RCC_APB2ENR   ,Copy_u8PrelID);
		   break;
		  
	  }
      
   }
   else
   {
	 /*  return error  */
   }
   
}
void RCC_voidDisenableClock(u8 Copy_u8BussID,u8 Copy_u8PrelID)
{
	
   if( Copy_u8PrelID <=31)
   {
      switch(Copy_u8BussID)
	  {
		  case RCC_AHP  :
		  CLR_BIT(RCC_AHBENR     ,Copy_u8PrelID);
		  break;
		  case RCC_APB1 :
		   CLR_BIT(RCC_APB1ENR   ,Copy_u8PrelID);
		   break;
		  case RCC_APB2 :
		  CLR_BIT(RCC_APB2ENR   ,Copy_u8PrelID);
		  
		   break;  
	  }   
   }
   else
   {
	 /*  return error  */
   } 
}
void RCC_voidInitSysClock(void)
{
	#if RCC_CLOCK_TYPE   == RCC_HSE_CRYSTAL       //PUT HSEBYP ZERO
	       SET_BIT(RCC_CR   , HSEON);
		   SET_BIT(RCC_CFGR , RCC_SW0 );
	#elif RCC_CLOCK_TYPE == HSE_RC            // PUT HSEBYP TO ONE
	       SET_BIT(RCC_CR   ,HSEON  );
		   SET_BIT(RCC_CR   ,HSEBYP );
		   SET_BIT(RCC_CFGR , RCC_SW0   );
	#elif RCC_CLOCK_TYPE == RCC_HSI
	      SET_BIT(RCC_CR ,RCC_HSI);
	#elif RCC_CLOCK_TYPE == RCC_PLL
	  #if   RCC_PLL_IN == RCC_PLL_IN_HSI_DIV_2
	  
	  #elif RCC_PLL_IN == RCC_PLL_IN_HSE_DIV_2
	      SET_BIT(RCC_CFGR , RCC_PLLSRC   );
		  SET_BIT(RCC_CFGR , RCC_PLLXTPRE );
	  #elif RCC_PLL_IN == RCC_PLL_IN_HSE
	      SET_BIT(RCC_CFGR  ,RCC_PLLSRC);
	  #endif
	  RCC_CFGR |=(RCC_PLL_MULTIPLICATION_FACTOR <<18);  
	     SET_BIT(RCC_CFGR , RCC_SW1 );
	     SET_BIT(RCC_CR   , RCC_PLLON);
	#else 
	    #error("YOU CHOOSE A WRONG CLOCK TYPE")
	#endif
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
