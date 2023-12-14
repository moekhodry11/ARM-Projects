/*****************************************/
/* Author  :  Ahmed Elbadry              */
/* Version :  V01                        */
/* Date    : 26 August 2020              */
/*****************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */

void MSTK_voidInit(void);/* Choose clock type */

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks ); /* Synchronous function */

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) ); /* Count only once  (A_synchronous function) then fires interrupt     */

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) ); /* Count preiodically  (A_synchronous function) then fires interrupt  */

void MSTK_voidStopInterval(void); /* Used only with A_synchronous function */

u32  MSTK_u32GetElapsedTime(void); /* Time that has been counted scence the call */

u32  MSTK_u32GetRemainingTime(void);/* Remaining time for interrupt */

#endif
