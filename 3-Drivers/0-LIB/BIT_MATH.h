#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg, bit)         reg|=(1<<bit)
#define CLR_BIT(reg, bit)         reg&=(~(1<<bit))
#define TOGGLE_BIT(reg, bit)      reg^=(1<<bit)
#define GET_BIT(reg, bit)         ((reg>>bit)&1)

#define NULL_PTR			            ((void*)0)
#define NULL_STR			               '\0'

#endif	/* BIT_MATH.h */
