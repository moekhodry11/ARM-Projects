/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 17/10/2023      **********************/
/***************  SWC    : BIT_MATH	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)		VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT)		VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)		((VAR >> BIT) & 1)
#define	TOG_BIT(VAR,BIT)		VAR ^= (1 << (BIT))



#endif
