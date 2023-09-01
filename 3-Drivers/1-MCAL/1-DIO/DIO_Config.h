/********************************************************************************/
/*      Author      :   Mostafa Ahmed Ali                                       */
/*      Date        :   15th Oct 2022                                           */
/*      SWC         :   DIO Driver                                              */
/*      Version     :   V1.3                                                    */
/*      Desc        :   A Configuration file for Pins Initial Directions and    */
/*                      Values Macros definitions of the DIO Driver.            */
/********************************************************************************/
#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

/*****************************************/
/*    Select Pins Initial Directions     */
/*    Options:                           */
/*             DIO_PIN_Initial_OUTPUT    */
/*             DIO_PIN_Initial_INPUT     */
/*****************************************/
/* DDRA */
#define DIO_PINA0_INITIAL_DIR               DIO_PIN_Initial_OUTPUT
#define DIO_PINA1_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA2_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA3_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA4_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA5_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA6_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINA7_INITIAL_DIR               DIO_PIN_Initial_OUTPUT   

/* DDRB */
#define DIO_PINB0_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB1_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB2_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB3_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB4_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB5_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB6_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINB7_INITIAL_DIR               DIO_PIN_Initial_OUTPUT   

/* DDRC */
#define DIO_PINC0_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC1_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC2_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC3_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC4_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC5_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC6_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PINC7_INITIAL_DIR               DIO_PIN_Initial_OUTPUT   

/* DDRD */
#define DIO_PIND0_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND1_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND2_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND3_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND4_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND5_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND6_INITIAL_DIR               DIO_PIN_Initial_OUTPUT         
#define DIO_PIND7_INITIAL_DIR               DIO_PIN_Initial_OUTPUT   

/*****************************************/
/*    Select Pins Initial Values         */
/*    Options:                           */
/*             DIO_PIN_Initial_HIGH      */
/*             DIO_PIN_Initial_LOW       */
/*             DIO_PIN_Initial_PULLUP    */
/*             DIO_PIN_Initial_FLOATING  */
/*****************************************/

/* PORTA */
#define DIO_PINA0_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA1_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA2_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA3_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA4_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA5_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA6_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINA7_INITIAL_VAL               DIO_PIN_Initial_FLOATING 

/* PORTB */     
#define DIO_PINB0_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB1_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB2_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB3_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB4_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB5_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB6_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINB7_INITIAL_VAL               DIO_PIN_Initial_FLOATING 

/* PORTC */     
#define DIO_PINC0_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC1_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC2_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC3_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC4_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC5_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC6_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PINC7_INITIAL_VAL               DIO_PIN_Initial_FLOATING 

/* PORTD */     
#define DIO_PIND0_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND1_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND2_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND3_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND4_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND5_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND6_INITIAL_VAL               DIO_PIN_Initial_FLOATING         
#define DIO_PIND7_INITIAL_VAL               DIO_PIN_Initial_FLOATING 

#endif      /* DIO_Config.h */
