/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 27/8/2020                */
/* version  : v01                      */
/****************************************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_CLKSOURCE_AHB_DIV_BY_8                            0
#define SYSTICK_CLKSOURCE_AHB                                     1


#define SYSTICK_REG_ENABLE                                 0
#define SYSTICK_REG_TICK_INT                               1
#define SYSTICK_REG_CLKSOURCE                              2
#define SYSTICK_REG_COUNTFLAG                              16
#define MSTK_SINGLE_INTERVAL                               0
#define MSTK_PERIODIC_INTERVAL                             1

void (*MSYSTICK_CallBack)(void);

typedef struct 
             {
				u32 STK_CTRL ;
			    u32 STK_LOAD ;
				u32 STK_VAL  ;
				u32  STK_CALIB ;
			 }SYSTICK_t;
			 
#define SYSTICK                      ((volatile SYSTICK_t * ) 0xE000E010)	
void SYSTICK_Handler(void);
#endif
