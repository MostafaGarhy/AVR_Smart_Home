#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"

#include "servo.h"
#include "DIO_Interface.h"
#include "TIMER_Interface.h"

void HSERVO_VidInit(void)
{
    DIO_VidSetPinDirection(PORTD_U8_INDEX, PIN5_U8_INDEX, PIN_U8_DIR_OUTPUT);
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