/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 26/11/2023      **********************/
/***************  SWC    : EXTI		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
/* Done in preprocessor (can't change it in runtime) */
void MEXTI_voidInit			 (void);

/* Same as Init but works in run time */
void MEXTI_voidSetSignalLatch(u8 copy_u8SenseMode , u8 copy_u8EXTILine); 

void MEXTI_voidEnableEXTI  ( u8 copy_u8Line );
void MEXTI_voidDisableEXTI ( u8 copy_u8Line );
void MEXTI_voidSwTrigger   ( u8 copy_u8Line );
void MEXTI_voidSetCallBack ( void (*Copy_ptr) (void) );


/*******************************************************************************
 *                      	Hash Defines for User        		               *
 *******************************************************************************/
 
/* Sense Modes */
#define EXTI_FALLING_EDGE		0
#define EXTI_RISING_EDGE		1
#define EXTI_ON_CHANGE			2

/* Lines */				
#define EXTI_LINE0				0
#define EXTI_LINE1				1
#define EXTI_LINE2				2
#define EXTI_LINE3				3
#define EXTI_LINE4				4
#define EXTI_LINE5				5
#define EXTI_LINE6				6
#define EXTI_LINE7				7
#define EXTI_LINE8				8
#define EXTI_LINE9				9
#define EXTI_LINE10				10
#define EXTI_LINE11				11
#define EXTI_LINE12				12
#define EXTI_LINE13				13
#define EXTI_LINE14				14
#define EXTI_LINE15				15




#endif
