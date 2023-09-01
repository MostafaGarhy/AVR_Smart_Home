/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	16	Aug	2023		                                                    */
/*  SWC		:	EXTI Driver			                                                    */
/*  File	:	EXTI_Interface.h	                                                    */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	This API allows user to set the configurations for EXTI Functions		*/
/****************************************************************************************/
#ifndef EXTI_INERFACE_H_
#define EXTI_INERFACE_H_

#include "EXTI_Private.h"
/* **********************************************************
 *  EXTIs Configurations Function:                          *
 *	Copy_U8IntNumber Options: EXTI0 - EXTI1 - EXTI2         *
 *  Copy_U8TriggerSense Options: LOWLVL_TRIG - ANYCHNG_TRIG	*
 *						         FALLING_TRIG - RISING_TRIG	*
 ************************************************************/
u8 EXTI_U8ExIntPeriEnable(u8 Copy_U8IntNumber, u8 Copy_U8TriggerSense);

u8 EXTI_U8ExtIntPeriDisable(u8 Copy_U8IntNumber);

/*  Prototype of INT0 ISR	*/
void __vector_1(void)   __attribute__((signal));
/*  Prototype of INT1 ISR	*/
void __vector_2(void)   __attribute__((signal));
/*  Prototype of INT2 ISR	*/
void __vector_3(void)   __attribute__((signal));

#endif
