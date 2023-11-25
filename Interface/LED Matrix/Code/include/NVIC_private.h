/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : NVIC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
 
 
/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

#define	NVIC_ISER0		*((volatile u32*)0xE000E100)			 /* Enable  External Interrupts from 0  to 31 */
#define NVIC_ISER1		*((volatile u32*)0xE000E104)			 /* Enable  External Interrupts from 32 to 63 */


#define NVIC_ICER0		*((volatile u32*)0xE000E180)			 /* Disable External Interrupts from 0  to 31 */
#define NVIC_ICER1		*((volatile u32*)0xE000E184)			 /* Disable External Interrupts from 32 to 63 */

#define NVIC_ISPR0		*((volatile u32*)0xE000E200)		   	 /* External Interrupts Set Pending from 0  to 31 */
#define NVIC_ISPR1		*((volatile u32*)0xE000E204)		   	 /* External Interrupts Set Pending from 32 to 63 */
 
#define NVIC_ICPR0		*((volatile u32*)0xE000E280)			 /* External Interrupts Clear Pending from 0  to 31 */
#define NVIC_ICPR1		*((volatile u32*)0xE000E284)			 /* External Interrupts Clear Pending from 32 to 63 */

#define NVIC_IABR0		*((volatile u32*)0xE000E300) 			 /* External Interrupts Read Active Flag from 0  to 31 */
#define NVIC_IABR1		*((volatile u32*)0xE000E304) 			 /* External Interrupts Read Active Flag from 32 to 63 */

#define NVIC_IPR		 ((u8*)0xE000E400)			 


/*******************************************************************************
 *                      Hash Defines For Conguration                           *
 *******************************************************************************/

#define NVIC_GROUP_4_SUB_0			0x05FA0300
#define NVIC_GROUP_3_SUB_1			0x05FA0400
#define NVIC_GROUP_2_SUB_2          0x05FA0500
#define NVIC_GROUP_1_SUB_3          0x05FA0600
#define NVIC_GROUP_0_SUB_4          0x05FA0700



#endif
