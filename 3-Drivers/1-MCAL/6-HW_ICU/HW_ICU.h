/*
 * HW_ICU.h
 *
 *  Created on: Aug 22, 2023
 *      Author: ma257
 */

#ifndef HW_ICU_H_
#define HW_ICU_H_

u16 HWICU_VidGetICR1Value(void);
void HWICU_VidIntEnable(void);
void HWICU_VidIntDisable(void);
void HWICU_VidSetSenseContol(u8 Copy_U8SenseOption);

#define RISING_EDGE			1
#define FALLING_EDGE		0

#endif /* HW_ICU_H_ */
