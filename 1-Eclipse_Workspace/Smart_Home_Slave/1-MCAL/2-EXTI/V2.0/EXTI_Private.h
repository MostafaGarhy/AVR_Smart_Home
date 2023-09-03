/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	16	Aug	2023		                                                    */
/*  SWC		:	EXTI Driver			                                                    */
/*  File	:	EXTI_Priavte.h		                                                    */
/*  Version	:	V2.0				                                                    */
/*  Desc	:	This Header file includes EXTIx and the Sense Control Macros			*/
/****************************************************************************************/

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/* EXTI Registers */
#define MCUCR 			*((volatile u8*)0x55)
#define GICR			*((volatile u8*)0x5B)

/* EXTI MCUCR Bits Macros */
#define ISC00 			0
#define ISC01 			1
#define ISC10 			2
#define ISC11 			3
#define ISC2			6

/* EXTI GICR Bits Macros */
#define INT0			6
#define INT1			7
#define INT2			5

/* EXTI Numbers Macros */
#define EXTI0		    0
#define EXTI1		    1
#define EXTI2		    2

/* Sense Control Triggering Macros */
#define LOWLVL_TRIG		0
#define ANYCHNG_TRIG	1
#define FALLING_TRIG	2
#define RISING_TRIG 	3

#endif /* EXTI_PRIVATE_H_ */
