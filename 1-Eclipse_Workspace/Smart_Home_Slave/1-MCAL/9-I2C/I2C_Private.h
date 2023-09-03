#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/*  TWI Registers Addresses  */
#define TWBR		*((volatile u8*)0x20)
#define TWSR		*((volatile u8*)0x21)
#define TWAR		*((volatile u8*)0x22)
#define TWDR		*((volatile u8*)0x23)
#define TWCR		*((volatile u8*)0x56)

/*  TWSR Register Bits  */
#define TWPS0			0
#define TWPS1			1

/*  TWCR Register Bits  */
#define TWEN			2
#define TWSTO			4
#define TWSTA			5
#define TWEA			6
#define TWINT			7

/*  TWDR Register Bits  */
#define TWDR_RW_BIT			0

#endif
