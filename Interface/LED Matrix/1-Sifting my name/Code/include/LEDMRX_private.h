/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 25/11/2023      **********************/
/***************  SWC    : LED_Matrix      **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef LEDMRX_PRIVATE_H
#define LEDMRX_PRIVATE_H

/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/

static void DisableAllColumns(void);
static void SetRowValues(u8 Copy_u8Value);
static void Activate_Column(u8);

static u8 Copy_u8ShiftingCounter=0;
static void voidShiftingCounter();

#endif
