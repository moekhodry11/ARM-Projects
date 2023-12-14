/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 08/12/2023      **********************/
/***************  SWC    : OS		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL						   0

/* Array of tasks (Array of structures) */
static Task OS_Tasks[NUMBER_OF_TASKS] = { NULL };

volatile u16 TickCounts = 0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void OS_voidCreateTask(u8 Copy_u8TaskID, u16 Copy_u16Periodicity,
		void (*ptr)(void), u16 Copy_u16FirstDelay, u8 Copy_u8State) {
	OS_Tasks[Copy_u8TaskID].Periodicity = Copy_u16Periodicity;
	OS_Tasks[Copy_u8TaskID].Fptr = ptr;
	OS_Tasks[Copy_u8TaskID].FirstDelay = Copy_u16FirstDelay;
	OS_Tasks[Copy_u8TaskID].State = Copy_u8State;
}

void OS_voidStart(void) {
	/* STK init */
	MSTK_voidInit();
	/* Tick time -> 1ms */
	MSTK_voidSetIntervalPeriodic(1000, Scheduler);
}

void Scheduler(void) {

	u8 LOC_u8TaskCounter;

	for (LOC_u8TaskCounter = 0; LOC_u8TaskCounter < NUMBER_OF_TASKS;
			LOC_u8TaskCounter++) {

		if ((OS_Tasks[LOC_u8TaskCounter].Fptr != NULL)
				&& (OS_Tasks[LOC_u8TaskCounter].State == TASK_READY)) {

			if (OS_Tasks[LOC_u8TaskCounter].FirstDelay == 0) {

				OS_Tasks[LOC_u8TaskCounter].FirstDelay =
						OS_Tasks[LOC_u8TaskCounter].Periodicity - 1;
				OS_Tasks[LOC_u8TaskCounter].Fptr();

			} else {

				OS_Tasks[LOC_u8TaskCounter].FirstDelay--;

			}

		} else {

			/* Do No Thing */

		}

	}

}

void OS_voidSuspendTask(u8 Copy_u8TaskID) {
	OS_Tasks[Copy_u8TaskID].State = TASK_PAUSE;
}

void OS_voidResumeTask(u8 Copy_u8TaskID) {
	OS_Tasks[Copy_u8TaskID].State = TASK_READY;
}

void OS_voidKillTask(u8 Copy_u8TaskID) {
	OS_Tasks[Copy_u8TaskID].Periodicity = 0;
	OS_Tasks[Copy_u8TaskID].Fptr = NULL;
	OS_Tasks[Copy_u8TaskID].FirstDelay = 0;
	OS_Tasks[Copy_u8TaskID].State = TASK_DELETE;
}
