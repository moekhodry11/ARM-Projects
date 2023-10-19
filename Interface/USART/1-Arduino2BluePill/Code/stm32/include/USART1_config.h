/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 19/10/2023      **********************/
/***************  SWC    : USART1	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef USART1_CONFIG_H
#define USART1_CONFIG_H


/* 
   for Init function argument : configuration structure address
   configuration structure is a Post-build Configuration (Configuration in Run Time)  
   
   DataSize Options:    EIGHT, NINE
   ParityState Options: DISABLED, ENABLED
   ParityType Options:  NOPARITY , EVEN , ODD
   StopBit Options:     ONE , HALF , TWO , ONEHALF

   Example:
   USART_ConfigType USART_config   = {INT_DISABLE , EIGHT , DISABLED , NOPARITY , ONE };
   MUSART1_voidInit(&USART_config);
*/



#endif
