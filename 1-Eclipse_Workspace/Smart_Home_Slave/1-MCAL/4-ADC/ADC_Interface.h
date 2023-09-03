/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	17	Aug	2023		                                                    */
/*  SWC		:	ADC Driver			                                                    */
/*  File	:	ADC_Interface.h	                                                        */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	ADC Functions															*/
/****************************************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_VidInit(void);
u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelNum);

#endif
