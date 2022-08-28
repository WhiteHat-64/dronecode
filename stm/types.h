/*
 * stm32f103c8_types.h
 *
 *  Created on: Sep 6, 2021
 *      Author: evil
 */

#ifndef TYPES_H_
#define TYPES_H_


#define TRUE		1
#define FALSE		0

#define _REG		volatile
#define _RO			const

#define BIT_SET(var,pos) (var|=(1<<pos))
#define BIT_CLR(var,pos) (var&=(~(1<<pos)))
#define BIT_TEST(var,pos) (var&(1<<pos))
#define GET_BIT_VAL(bitpos) (0x1 << bitpos)


typedef unsigned char U8_t;
typedef signed char S8_t;
typedef unsigned short int U16_t;
typedef signed short int S16_t;
typedef unsigned int U32_t;
typedef signed int S32_t;


#endif /* TYPES_H_ */
