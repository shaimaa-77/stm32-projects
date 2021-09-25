/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 1/10/2020                */
/* version  : v01                      */
/****************************************************************************************/

#ifndef SEG7_INTERFACE_H
#define SEG7_INTERFACE_H

#define SEG7_A                 PIN0
#define SEG7_B                 PIN1
#define SEG7_C                 PIN2
#define SEG7_D                 PIN3
#define SEG7_E                 PIN4
#define SEG7_F                 PIN5
#define SEG7_G                 PIN6
#define SEG7_DOT               PIN7

#define SEG7_PORT              GPIOA

void SEG7_voidInit7Seg( );
void SEG7_voidDisplayNumbre( u8  copy_u8numbre,u8 * copy_u8PSEGValue);
void SEG7_voidDecrease(u8 copy_u8Numbre,u8 * copy_u8PSEGValue);
void SEG7_voidIncrease(u8 copy_u8Numbre,u8 * copy_u8PSEGValue);


#endif
