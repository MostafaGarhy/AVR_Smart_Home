/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	16	Aug	2023		                                                    */
/*  SWC		:	EXTI Driver			                                                    */
/*  File	:	EXTI_Program.c		                                                    */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	This API allows user to make External INTs using the EXTI Peripheral.	*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "DIO_interface.h"
#include <avr/interrupt.h>

u8 EXTI_U8ExIntPeriEnable(u8 Copy_U8IntNumber, u8 Copy_U8TriggerSense)
{
	u8 Local_U8ErrorState = ERR_STATE_OK;
	/* I/P Validation */
	if(Copy_U8IntNumber > EXTI2 || Copy_U8TriggerSense > RISING_TRIG)
	{
		Local_U8ErrorState = ERR_STATE_NOK;
	}
	else
	{
		switch(Copy_U8TriggerSense)
		{
			case LOWLVL_TRIG:	/*  Low Level Triggering  */
								switch(Copy_U8IntNumber)
								{
									case EXTI0 :/*  Set The Sense Control and Enable EXTI0  */
												//Set the sense control for INT0 as Low Level
												CLR_BIT(MCUCR, ISC00);
												CLR_BIT(MCUCR, ISC01);
												//Set the INT0 Enable
												SET_BIT(GICR, INT0);
												break;
									case EXTI1 :/*  Set The Sense Control and Enable EXTI1  */
												//Set the sense control for INT1 as Low Level
												CLR_BIT(MCUCR, ISC10);
												CLR_BIT(MCUCR, ISC11);
												//Set the INT1 Enable
												SET_BIT(GICR, INT1);
												break;
									default: 	Local_U8ErrorState = ERR_STATE_NOK; break;
								}
								break;
			case ANYCHNG_TRIG:	/*  Any Logical Change  */
								switch(Copy_U8IntNumber)
								{
									case EXTI0 :/* Set The Sense Control and Enable EXTI0   */
												//Set the sense control for INT0 as Any Logical Change
												SET_BIT(MCUCR, ISC00);
												CLR_BIT(MCUCR, ISC01);
												//Set the INT0 Enable
												SET_BIT(GICR, INT0);
												break;
									case EXTI1 :/*  Set The Sense Control and Enable EXTI1  */
												//Set the sense control for INT1 as Any Logical Change
												SET_BIT(MCUCR, ISC10);
												CLR_BIT(MCUCR, ISC11);
												//Set the INT1 Enable
												SET_BIT(GICR, INT1);
												break;
									default: 	Local_U8ErrorState = ERR_STATE_NOK; break;
								}
								break;
			case FALLING_TRIG:	/*  Falling Edge  */
								switch(Copy_U8IntNumber)
								{
									case EXTI0 :/*  Set The Sense Control and Enable EXTI0  */
												//Set the sense control for INT0 as Falling Edge
												CLR_BIT(MCUCR, ISC00);
												SET_BIT(MCUCR, ISC01);
												//Set the INT0 Enable
												SET_BIT(GICR, INT0);
												break;
									case EXTI1 :/*  Set The Sense Control and Enable EXTI1  */
												//Set the sense control for INT1 as Falling Edge
												CLR_BIT(MCUCR, ISC10);
												SET_BIT(MCUCR, ISC11);
												//Set the INT1 Enable
												SET_BIT(GICR, INT1);
												break;
									case EXTI2 :/*  Set The Sense Control and Enable EXTI2  */
												//Set the sense control for INT2 as Falling Edge
												CLR_BIT(MCUCR, ISC2);
												//Set the INT2 Enable
												SET_BIT(GICR, INT2);
												break;
									default: 	Local_U8ErrorState = ERR_STATE_NOK; break;
								}
								break;
			case RISING_TRIG:	/*  Rising Edge  */
								switch(Copy_U8IntNumber)
								{
									case EXTI0 :/*  Set The Sense Control and Enable EXTI0  */
												//Set the sense control for INT0 as Rising Edge
												SET_BIT(MCUCR, ISC00);
												SET_BIT(MCUCR, ISC01);
												//Set the INT0 Enable
												SET_BIT(GICR, INT0);
												break;
									case EXTI1 :/*  Set The Sense Control and Enable EXTI1  */
												//Set the sense control for INT1 as Rising Edge
												SET_BIT(MCUCR, ISC10);
												SET_BIT(MCUCR, ISC11);
												//Set the INT1 Enable
												SET_BIT(GICR, INT1);
												break;
									case EXTI2 :/*  Set The Sense Control and Enable EXTI2  */
												//Set the sense control for INT2 as Rising Edge
												SET_BIT(MCUCR, ISC2);
												//Set the INT2 Enable
												SET_BIT(GICR, INT2);
												break;
									default: 	Local_U8ErrorState = ERR_STATE_NOK; break;
								}
								break;
			default: 	Local_U8ErrorState = ERR_STATE_NOK; break;
		}
		//Set the Global INTs
		SET_BIT(SREG, 7);
		Local_U8ErrorState = ERR_STATE_OK;
	}
	return Local_U8ErrorState;
}

u8 EXTI_U8ExtIntPeriDisable(u8 Copy_U8IntNumber)
{
	u8 Local_U8ErrorState = ERR_STATE_OK;
	/* I/P Validation */
	if(Copy_U8IntNumber > EXTI2)
	{
		Local_U8ErrorState = ERR_STATE_NOK;
	}
	else
	{
		switch(Copy_U8IntNumber)
		{
			case EXTI0 : 	/*  Disable the EXTI0  */
							CLR_BIT(GICR, INT0); break;
			case EXTI1 : 	/*  Disable the EXTI0  */
							CLR_BIT(GICR, INT1); break;
			case EXTI2 : 	/*  Disable the EXTI0  */
							CLR_BIT(GICR, INT2); break;
			default	   :    /*  Do Nothing  */	 break;
		}
	}
	return Local_U8ErrorState;
}

/*  ISR0 Implementation  */
void __vector_1(void)
{
	//Do Action
	DIO_VidTogglePinValue(PORTA_U8_INDEX, PIN0_U8_INDEX);
}

/*  ISR1 Implementation  */
void __vector_2(void)
{
	DIO_VidTogglePinValue(PORTA_U8_INDEX, PIN1_U8_INDEX);
}

/*  ISR1 Implementation  */
void __vector_3(void)
{
	DIO_VidTogglePinValue(PORTA_U8_INDEX, PIN2_U8_INDEX);
}

