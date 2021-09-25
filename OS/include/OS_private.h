/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 12/10/2020                */
/* version  : v01                      */
/****************************************************************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H
typedef enum
{
	TASK_DORMANT,
	TASK_READY,
	TASK_PUASE,
	TASK_WAINTINH,
}state_TYPE;
typedef struct
{
	u16 priodicity;
	u16 FirstDelay;
		u8 state;
	void (*Fptr)(void);

}TASK;
//arry of tasks "arry of structure"
TASK OS_Tasks[4]={NULL};
void piriodic(void);
#endif
