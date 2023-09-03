/*
 * stepper_motor.h
 *
 *  Created on: Aug 15, 2023
 *      Author: ma257
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

//Stepper Function to Initialize the first four pins of the port
void HSTEP_VidInit(void);
//Stepper Function to set the stepper angle and the rotation direction
u8 HSTEP_U8SetAngDir(u16 Copy_U16Angle, u8 Copy_U8Direction);

/* 		Stepper Port Macros 		*/
/* PORTA_U8_INDEX
 * PORTB_U8_INDEX
 * PORTC_U8_INDEX
 * PORTD_U8_INDEX
 */
#define STEP_PORT			PORTD_U8_INDEX

/* 		Rotation Direction Macros		 */
#define STEP_DIR_CW			0
#define STEP_DIR_ACW		1

#endif /* STEPPER_MOTOR_H_ */
