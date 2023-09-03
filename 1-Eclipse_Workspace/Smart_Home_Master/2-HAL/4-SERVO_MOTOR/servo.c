/***************************************************************************************/
/*    Author	:	Mostafa Ahmed Garhy		                                           */
/*    Date		:	31 Aug 2023				                                           */
/*    SWC		:	HAL Servo Motor Driver	                                           */
/*    File		:	servo.c					                                           */
/*    Version	:	V1.1					                                           */
/*    Desc		:	These APIs allows user to set the servo angle from -90 to +90      */
/***************************************************************************************/
/* LIB */
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/delay.h"
/* MCAL */
#include "servo.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"
#include "../../1-MCAL/5-TIMER/TIMER_Interface.h"

void HSERVO_VidInit(void)
{
    DIO_VidSetPinDirection(DIO_U8_PORTD, DIO_U8_PIN5, DIO_PIN_OUTPUT);
    TIMER1_VidInit();              
    TIMER1_VidSetICR1Value(20000);  
}

void HSERVO_VidSetAngle(s8 Copy_S8Angle)
{
    if(Copy_S8Angle < 0 && Copy_S8Angle >= -90)
    {
        Copy_S8Angle *= -1;

        TIMER1_VidSetOCR1AValue(1500 - (5.5556 * Copy_S8Angle));
        delay_ms(10);  
    }
    else if (Copy_S8Angle == 0)
    {
        TIMER1_VidSetOCR1AValue(1500);
        delay_ms(10);
    }
    else if(Copy_S8Angle > 0 && Copy_S8Angle <= 90)
    {
        TIMER1_VidSetOCR1AValue(1500 + (5.5556 * Copy_S8Angle));
        delay_ms(10);
    }                
}
