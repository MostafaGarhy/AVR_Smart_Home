/********************************************************************************/
/*      Author      :   Mostafa Ahmed Ali                                       */
/*      Date        :   15th Oct 2022                                           */
/*      SWC         :   DIO Driver                                              */
/*      Version     :   V1.3                                                    */
/*      Desc        :   DIO Interfacing APIs Declarations                       */
/********************************************************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_VidInit              (void)                                                  ;
u8 DIO_VidSetPinDirection     (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Dir)          ;
u8 DIO_VidSetPinValue         (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Val)          ;
u8 DIO_VidGetPinValue         (u8 Copy_U8Port, u8 Copy_U8Pin, u8 *Copy_U8PinValue)    ;
u8 DIO_VidTogglePinValue      (u8 Copy_U8Port, u8 Copy_U8Pin)                         ;
u8 DIO_VidSetPortDirection    (u8 Copy_U8Port, u8 Copy_U8Dir)                         ;
u8 DIO_VidSetPortValue        (u8 Copy_U8Port, u8 Copy_U8Val)                         ;

/* DIO_U8_PORTx Macros */
#define DIO_U8_PORTA			        0
#define DIO_U8_PORTB 			        1
#define DIO_U8_PORTC			        2
#define DIO_U8_PORTD 			        3

/* DIO_U8_PINx Macros */        
#define DIO_U8_PIN0 			        0
#define DIO_U8_PIN1 			        1
#define DIO_U8_PIN2 			        2
#define DIO_U8_PIN3 			        3
#define DIO_U8_PIN4 			        4
#define DIO_U8_PIN5 			        5
#define DIO_U8_PIN6 			        6
#define DIO_U8_PIN7 			        7

/* Pins Directions */
#define DIO_PIN_INPUT                 	0
#define DIO_PIN_OUTPUT          		1

/* Pins Values */
#define DIO_PIN_LOW  		            0
#define DIO_PIN_HIGH   		            1

/* All Port Directions */
#define DIO_PORT_ALL_INPUT             0x00
#define DIO_PORT_ALL_OUTPUT            0xFF

/* Port Values */
#define DIO_PORT_ALL_LOW               0x00
#define DIO_PORT_ALL_HIGH              0xFF

#endif      /* DIO_Interface.h */
