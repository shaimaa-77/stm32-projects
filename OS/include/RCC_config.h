/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#ifndef RCC_CONGIH_H
#define RCC_CONGIH_H


/* options of clock types :
   * HSE_CRYSTAL
   *HSE_RC
   *HSI
   *PLL
   */
#define  RCC_CLOCK_TYPE    HSE_CRYSTAL

/* Options:    
               * RCC_PLL_IN_HSI_DIV_2
               * RCC_PLL_IN_HSE_DIV_2
			   * RCC_PLL_IN_HSE      */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2 //option
#define RCC_PLL_MULTIPLICATION_FACTOR    RCC_PLL_MULTIPLICATION_FACTOR_3 //OPTITION
#endif

#endif