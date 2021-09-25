/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 12/10/2020                */
/* version  : v01                      */
/****************************************************************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H

void OS_voidCreatTask(u8 copy_u8ID, u16 copy_u16pioridic, void (* ptr)(void),u8 copy_u8FirstDelay);
void OS_voidStartOS(void);
void OS_voidDelatTask(u8 copy_u8ID);
void OS_voidPueseTask(u8 copy_u8ID);
void OS_voidResumeTask(u8 copy_u8ID);

#endif
