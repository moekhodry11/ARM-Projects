/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 25/11/2023      **********************/
/***************  SWC    : LED_Matrix      **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

/*******************************************************************************
 *                      Puplic Functions Prototypes                            *
 *******************************************************************************/

void HLEDMRX_voidInit(void);
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);
void HLEDMRX_voidShiftLeft(void);

void HLEDMRX_voidModifyArray(u8 *Copy_u8Data, u8 Copy_u8SizeOfData,u8 *Copy_u8ModifyData);
void HLEDMRX_voidShifting(u8 *Copy_u8Data, u8 Copy_u8SizeOfData,u32 Copy_u32Ticks);

#endif
