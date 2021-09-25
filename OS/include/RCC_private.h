/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#ifndef RCC_PRIVATe_H
#define RCC_PRIVATE_H_H


/* register difinition*/

 /*   baise address 0x40021000   */
 
 #define RCC_CR                            *((u32 *)0x40021000) //CLOCK FOR PROCESSOR
 #define RCC_CFGR                          *((u32 *)0x40021004)  //CLOCK FOR PROCESSOR
 #define RCC_CIR                           *((u32 *)0x40021008)
 #define RCC_APB2RSTR                      *((u32 *)0x4002100C)
 #define RCC_APB1RSTR                      *((u32 *)0x40021010)
 #define RCC_AHBENR                        *((u32 *)0x40021014)   //CLOCK FOR PRIPHARIAL
 #define RCC_APB2ENR                       *((u32 *)0x40021018)   //CLOCK FOR PRIPHARIAL
 #define RCC_APB1ENR                       *((u32 *)0x4002101C)   //CLOCK FOR PRIPHARIAL
 #define RCC_BDCR                          *((u32 *)0x40021020)
 #define RCC_CSR                           *((u32 *)0x40021024)
/* CLOCK TYPES*/
#define HSE_CRYSTAL           0
#define HSE_RC                1
#define HSI                   2
#define PLL                   3

/* OPTIONS OF PLL*/
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        3

/*OPITIONS OF MALTI PLL*/
#define RCC_PLL_MULTIPLICATION_FACTOR_2                 0
#define RCC_PLL_MULTIPLICATION_FACTOR_3                 1
#define RCC_PLL_MULTIPLICATION_FACTOR_4                 2
#define RCC_PLL_MULTIPLICATION_FACTOR_5                 3
#define RCC_PLL_MULTIPLICATION_FACTOR_6                 4
#define RCC_PLL_MULTIPLICATION_FACTOR_7                 5
#define RCC_PLL_MULTIPLICATION_FACTOR_8                 6
#define RCC_PLL_MULTIPLICATION_FACTOR_9                 7
#define RCC_PLL_MULTIPLICATION_FACTOR_10                8
#define RCC_PLL_MULTIPLICATION_FACTOR_11                9
#define RCC_PLL_MULTIPLICATION_FACTOR_12                10
#define RCC_PLL_MULTIPLICATION_FACTOR_13                11
#define RCC_PLL_MULTIPLICATION_FACTOR_14                12
#define RCC_PLL_MULTIPLICATION_FACTOR_15                13
#define RCC_PLL_MULTIPLICATION_FACTOR_16                14
//#define RCC_PLL_MULTIPLICATION_FACTOR_16                15

/****************  RCC CR REGISTER BIT****************************/

#define        PLLRDY            25
#define        PLLON             24
#define        CSSON             19
#define        HSEBYP            18
#define        HSERDY            17
#define        HSEON             16
#define        HSIRDY             1
#define		   HSION              0




/*****************RCC CFGR REGISTER BIT**************************/
#define RCC_SW0               0
#define RCC_SW1               1
#define RCC_PLLSRC            16
#define RCC_PLLXTPRE          17
#endif
