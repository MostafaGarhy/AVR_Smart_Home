/***************************************************************************************/
/*    Author	:	Mostafa Ahmed Garhy		                                           */
/*    Date		:	31 Aug 2023				                                           */
/*    SWC		:	HAL Stepper Motor Driver                                           */
/*    File		:	stepper_motor.c			                                           */
/*    Version	:	V1.0					                                           */
/*    Desc		:	These APIs allows user to set the stepper angle from 0 to 360	   */
/* 					Also, under condition of rotation direction CW or ACW.		       */
/***************************************************************************************/
/* LIB */
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/delay.h"

/* MCAL */
#include "../../1-MCAL/1-DIO/DIO_Interface.h"
#include "stepper_motor.h"

void HSTEP_VidInit(void)
{
	DIO_VidSetPinDirection(STEP_PORT, DIO_U8_PIN0, DIO_PIN_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, DIO_U8_PIN1, DIO_PIN_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, DIO_U8_PIN2, DIO_PIN_OUTPUT);
	DIO_VidSetPinDirection(STEP_PORT, DIO_U8_PIN3, DIO_PIN_OUTPUT);
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
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_LOW);
									delay_ms(10);
									//Full_step_2
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
									//Full_step_3
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
									//Full_step_4
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
								}
								break;

			case STEP_DIR_ACW:	//Rotate Anti-Clock Wise
								for(Local_U16Counter = 0; Local_U16Counter < Local_U16Iterations; Local_U16Counter++)
								{
									//Full_step_1
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
									//Full_step_2
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
									//Full_step_3
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_LOW);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_HIGH);
									delay_ms(10);
									//Full_step_4
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN0, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN1, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN2, DIO_PIN_HIGH);
									DIO_VidSetPinValue(STEP_PORT, DIO_U8_PIN3, DIO_PIN_LOW);
									delay_ms(10);
								}
								break;

			default:			/* Do Nothing */
								break;
		}
		Local_U8ErrorState = ERR_STATE_OK;
	}
	return Local_U8ErrorState;
}
