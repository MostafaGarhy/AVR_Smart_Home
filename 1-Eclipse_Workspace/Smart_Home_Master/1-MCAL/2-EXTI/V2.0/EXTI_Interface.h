/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	16	Aug	2023		                                                    */
/*  SWC		:	EXTI Driver			                                                    */
/*  File	:	EXTI_Interface.h	                                                    */
/*  Version	:	V2.0				                                                    */
/*  Desc	:	This API allows user to set the configurations for EXTI Functions		*/
/****************************************************************************************/
#ifndef EXTI_INERFACE_H_
#define EXTI_INERFACE_H_

/* **********************************************************
 *  EXTIs Configurations Function:                          *
 *	Copy_U8IntNumber Options: EXTI0 - EXTI1 - EXTI2         *
 *  Copy_U8TriggerSense Options: LOWLVL_TRIG - ANYCHNG_TRIG	*
 *						         FALLING_TRIG - RISING_TRIG	*
 ************************************************************/
u8 EXTI_U8ExIntPeriEnable(u8 Copy_U8IntNumber, u8 Copy_U8TriggerSense);

u8 EXTI_U8ExtIntPeriDisable(u8 Copy_U8IntNumber);

u8 EXTI0_U8SetCallback(void(*Copy_pf)(void));
u8 EXTI1_U8SetCallback(void(*Copy_pf)(void));
u8 EXTI2_U8SetCallback(void(*Copy_pf)(void));

/*  Prototype of INT0 ISR	*/
void __vector_1(void)   __attribute__((signal));
/*  Prototype of INT1 ISR	*/
void __vector_2(void)   __attribute__((signal));
/*  Prototype of INT2 ISR	*/
void __vector_3(void)   __attribute__((signal));

#endif
