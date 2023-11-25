/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : NVIC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/* I have 4 bits for priority
 * Options: NVIC_GROUP_4_SUB_0
            NVIC_GROUP_3_SUB_1
            NVIC_GROUP_2_SUB_2
            NVIC_GROUP_1_SUB_3
		    NVIC_GROUP_0_SUB_4  */ 
			   
#define NVIC_GROUP_DISTRIBUTION		NVIC_GROUP_2_SUB_2 //so i have 2 bits for group and 2 bits for sub

#endif
