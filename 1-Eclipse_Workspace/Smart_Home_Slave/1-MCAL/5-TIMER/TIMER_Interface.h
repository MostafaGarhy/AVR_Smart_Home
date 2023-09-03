/*
 * TIMER_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: ma257
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/********************************	TIMER0	 *********************************/
void TIMER0_VidOvfInit(void);
void TIMER0_VidCTCInit(void);
void TIMER0_VidOCR0Value(u8 Copy_U8CTCOCRVal);
void TIMER0_VidOvfTCNTValue(u8 Copy_U8OvfTCNTVal);
void TIMER0_VidFastPWMInit(void);

/********************************	TIMER1	 *********************************/
void TIMER1_VidInit(void);
void TIMER1_VidSetICR1Value(u16 Copy_U16ICR1Val);
void TIMER1_VidSetOCR1AValue(u16 Copy_U16OCR1AVal);

/***************	TIMER0 ISR (Ovf - CTC) Prototypes	 ***************/
void __vector_10(void) __attribute__((signal));
void __vector_11(void) __attribute__((signal));

#endif /* TIMER_INTERFACE_H_ */
