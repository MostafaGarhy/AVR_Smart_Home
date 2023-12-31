/*
 * stepper_motor.c
 *
 *  Created on: Aug 15, 2023
 *      Author: ma257
 */
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "stepper_motor.h"
#include <util/delay.h>

void HSTEP_VidInit(void)
{
	DIO_VidSetPinDirection(STEP_PORT, PIN0_U8_INDEX, PIN_U8_DIR_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, PIN1_U8_INDEX, PIN_U8_DIR_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, PIN2_U8_INDEX, PIN_U8_DIR_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, PIN3_U8_INDEX, PIN_U8_DIR_OUTPUT);
}

u8 HSTEP_U8SetAngDir(u16 Copy_U16Angle, u8 Copy_U8Direction)
{
	u8 Local_U8ErrorState =  ERR_STATE_OK;
	u16 Local_U16Steps, Local_U16Iterations, Local_U16Counter;
	/* I/P Validation */
	if(Copy_U8Direction > STEP_DIR_ACW || Copy_U16Angle > 360)
	{
		Local_U8ErrorState = ERR_STATE_NOK;
	}
	else
	{
		//Calculations for Number of Loop Iterations according to the angle
		Local_U16Steps = (Copy_U16Angle * 2048UL)/360;
		Local_U16Iterations = Local_U16Steps / 4;
		switch(Copy_U8Direction)
		{
			case  STEP_DIR_CW: 	//Rotate Clock Wise
								for(Local_U16Counter = 0; Local_U16Counter < Local_U16Iterations; Local_U16Counter++)
								{
									//Full_step_1
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_LOW);
									_delay_ms(10);
									//Full_step_2
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
									//Full_step_3
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
									//Full_step_4
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
								}
								break;

			case STEP_DIR_ACW:	//Rotate Anti-Clock Wise
								for(Local_U16Counter = 0; Local_U16Counter < Local_U16Iterations; Local_U16Counter++)
								{
									//Full_step_1
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
									//Full_step_2
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
									//Full_step_3
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_LOW);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_HIGH);
									_delay_ms(10);
									//Full_step_4
									DIO_VidSetPinValue(STEP_PORT, PIN0_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN1_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN2_U8_INDEX, PIN_U8_VALUE_HIGH);
									DIO_VidSetPinValue(STEP_PORT, PIN3_U8_INDEX, PIN_U8_VALUE_LOW);
									_delay_ms(10);
								}
								break;

			default:			/* Do Nothing */
								break;
		}
		Local_U8ErrorState = ERR_STATE_OK;
	}
	return Local_U8ErrorState;
}
