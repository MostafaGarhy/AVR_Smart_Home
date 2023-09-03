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
/* DIO_U8_PORTA
 * DIO_U8_PORTB
 * DIO_U8_PORTC
 * DIO_U8_PORTD
 */
#define STEP_PORT			DIO_U8_PORTD

/* 		Rotation Direction Macros		 */
#define STEP_DIR_CW			0
#define STEP_DIR_ACW		1

#endif /* STEPPER_MOTOR_H_ */
