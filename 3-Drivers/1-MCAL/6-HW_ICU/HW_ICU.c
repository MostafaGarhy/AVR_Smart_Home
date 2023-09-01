/*
 * HW_ICU.c
 *
 *  Created on: Aug 22, 2023
 *      Author: ma257
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HW_ICU.h"
#include <avr/io.h>

u16 HWICU_VidGetICR1Value(void)
{
	return ICR1;
}

void HWICU_VidIntEnable(void)
{
	//Enable ICU Interrupt
	SET_BIT(TIMSK, TICIE1);
	//Disable the Capture Noise Canceler
	CLR_BIT(TCCR1B, ICNC1);
}

void HWICU_VidIntDisable(void)
{
	//Disable ICU Interrupt
	CLR_BIT(TIMSK, TICIE1);
}

void HWICU_VidSetSenseContol(u8 Copy_U8SenseOption)
{
	switch(Copy_U8SenseOption)
	{
		case FALLING_EDGE : CLR_BIT(TCCR1B, ICES1); break;
		case RISING_EDGE  : SET_BIT(TCCR1B, ICES1); break;
	}
}
