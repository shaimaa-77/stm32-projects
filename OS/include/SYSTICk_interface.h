/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 27/8/2020                */
/* version  : v01                      */
/****************************************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void MSYSTICK_voidInit(void);
void MSYSTICK_voidSetBusyWait(u32);
void MSYSTICK_voidSetIntervalSingle(u32  , void (*copy_ptr)(void));
void MSYSTICK_voidSetIntervalPeriodic(u32 copy_u32LoadValue , void (*copy_ptr)(void));
void MSYSTICK_voidStopTimer(void);
u32  MSYSTICK_U32GetRemainingTime(void);
u32  MSYSTICK_U32GetElapsedTime(void);
void MSYSTICK_voidSetCallback(void (* copy_ptr)(void));

#endif
