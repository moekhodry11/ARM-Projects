/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 13/12/2023      **********************/
/***************  SWC    : KPD             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define KPD_u8_KEY_NOT_PRESSED        0xff

void HKPD_voidInit(void);
u8 HKPD_u8GetKeyState(u8 * Copy_pu8RetnedKey);

#endif
