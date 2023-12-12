/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 12/12/2023      **********************/
/***************  SWC    : ULTRASONIC      **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include <ULTRASONIC_config.h>
#include <ULTRASONIC_interface.h>
#include <ULTRASONIC_private.h>
#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HULTRASONIC_voidInit(void) {
	/* Set IO pins direction */
	MGPIO_voidSetPinDirection(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN,
			GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN,
			GPIO_INPUT_FLOATING);

	MSTK_voidInit();

}

u16 HULTRASONIC_u16GetDistance(void) {
	/* Send trigger pulse */
	MGPIO_voidSetPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_LOW);
	MSTK_voidSetBusyWait(2);
	MGPIO_voidSetPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_HIGH);
	MSTK_voidSetBusyWait(10);
	MGPIO_voidSetPinValue(ULTRASONIC_TRIG_PORT, ULTRASONIC_TRIG_PIN, GPIO_LOW);

	TimeOutFlag = 0;
	MSTK_voidSetIntervalSingle(1000000, HULTRASONIC_voidNOP);
	/* Wait for rising edge */
	while (MGPIO_u8GetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN) == 0 && TimeOutFlag == 0);
	Time_Start = MSTK_u32GetElapsedTime();
	/* Start timer */

	/* Wait for falling edge */
	while (MGPIO_u8GetPinValue(ULTRASONIC_ECHO_PORT, ULTRASONIC_ECHO_PIN) == 1 && TimeOutFlag == 0);

	/* Stop timer */
	Time_End = MSTK_u32GetElapsedTime();
	MSTK_voidStopInterval();

	/* Calculate distance */
	Time_Diff = Time_End - Time_Start;

	// Calculate distance in centimeters
	f32 distance = (float) Time_Diff * 0.0343 / 2;

	return (u16) distance;

}

static void HULTRASONIC_voidNOP(void) {
	TimeOutFlag = 1;
}
