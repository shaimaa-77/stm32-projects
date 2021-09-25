/****************************************************************************************/
/* Author   : Shaimaa Mahmoud          */
/* Date     : 11/8/2020                */
/* version  : v01                      */
/****************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)              VAR |=(1<<(BIT))
#define CLR_BIT(VAR,BIT)              VAR &=(~(1<<(BIT)))
#define GET_BIT(VAR,BIT)              ((VAR >>BIT)&1)
#define TOG_BIT(VAR,BIT)              VAR ^=(1<<(BIT))

#endif