/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	17	Aug	2023		                                                    */
/*  SWC		:	ADC Driver			                                                    */
/*  File	:	ADC_Priavte.h		                                                    */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	This Header file includes ADC Registers Addresses						*/
/****************************************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_U8_ADMUX_REG	*((volatile u8*)0x27)
#define ADC_U8_ADCSRA_REG	*((volatile u8*)0x26)
#define ADC_U8_ADCL_REG		*((volatile u16*)0x24)
#define ADC_U8_ADCH_REG		*((volatile u8*)0x25)

#endif
