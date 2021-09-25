/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 15/10/2020                */
/* version  : v01                      */
/****************************************************************************************/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H

#define HSTP_SHIFT_CLOCK       GPIOA,1
#define HSTP_STORE_CLOCK       GPIOA,2
#define HSTP_DATA_SEND         GPIOA,0

void HSTP_voidSendSyncronous( u16 copy_u16SendToData);

#endif
