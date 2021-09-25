/**********************************************************************************************************/
/* Author  : Shaimaa Mahmoud  */
/* Data    : 15/8/2020        */
/* Version : 01               */
/*********************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H_H
/******* buss definitions **********/
#define RCC_AHP       0
#define RCC_APB1      1
#define RCC_APB2      2

/************ AHB_ENR BITS***********/
#define    ETHMA_CRXEN                     16
#define    ETHMA_CTXEN                     15
#define    ETHMA_CEN                       14
#define    OTGFS_EN                        12
#define    CRCEN                           5
#define    FLITFEN                         4
#define    SRAM_EN                         2
#define    DMA2_EN                         1
#define    DMA1_EN                         0

/************ APB1_ENR BITS***********/
#define   DAC_EN                           29
#define   PWR_EN                           28
#define   BKP_EN                           27
#define   CAN2_EN                          26
#define   CAN1_EN                          25
#define   I2C2_EN                          22
#define   I2C1_EN                          21
#define   UART5_EN                         20
#define   UART4_EN                         19
#define   USART3_EN                        18
#define   USART2_EN                        17
#define   SPI3_EN                          15
#define   SPI2_EN                          14
#define   WWD_GEN                          11
#define   TIM7_EN                          5
#define   TIM6_EN                          4
#define   TIM5_EN                          3
#define   TIM4_EN                          2
#define   TIM3_EN                          1
#define   TIM2_EN                          0

/************ APB2_ENR BITS***********/
#define   USART1EN                         14
#define   SPI1EN                           12
#define   TIM1EN                           11
#define   ADC2EN                           10
#define   ADC1EN                           9
#define   IOPEEN                           6
#define   IOPDEN                           5
#define   IOPCEN                           4
#define   IOPBEN                           3
#define   IOPAEN                           2
#define   AFIOEN                           0














void RCC_voidEnableClock(u8 ,u8 );
void RCC_voidDisenableClock(u8 ,u8 );
void RCC_voidInitSysClock(void);

#endif
