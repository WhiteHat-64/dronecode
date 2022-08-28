/*
 * cortexm3_nvic.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#ifndef CORTEXM3_NVIC_H_
#define CORTEXM3_NVIC_H_

#include "types.h"

#define NVIC_BASE_ADDR	0xE000E100

typedef struct NVIC_s{
	U32_t ISER0;	//0x000
	U32_t ISER1;    //0x004
	U32_t ISER2;    //0x008
	U32_t rsvd1[29];
	U32_t ICER0;    //0x080
	U32_t ICER1;    //0x084
	U32_t ICER2;    //0x088
	U32_t rsvd2[29];
	U32_t ISPR0;    //0x100
	U32_t ISPR1;    //0x104
	U32_t ISPR2;    //0x108
	U32_t rsvd3[29];
	U32_t ICPR0;    //0x180
	U32_t ICPR1;    //0x184
	U32_t ICPR2;    //0x188
	U32_t rsvd4[29];
	U32_t IABR0;    //0x200
	U32_t IABR1;    //0x204
	U32_t IABR2;    //0x208
	U32_t rsvd5[61];
	U32_t IPR0;		//0x300
	U32_t IPR1;		//0x304
	U32_t IPR2;		//0x308
	U32_t IPR3;		//0x30C
	U32_t IPR4;		//0x310
	U32_t IPR5;		//0x314
	U32_t IPR6;		//0x318
	U32_t IPR7;		//0x31c
	U32_t IPR8;		//0x320
	U32_t IPR9;		//0x324
	U32_t IPR10;	//0x328
	U32_t IPR11;	//0x32C
	U32_t IPR12;	//0x330
	U32_t IPR13;	//0x334
	U32_t IPR14;	//0x338
	U32_t IPR15;	//0x33C
	U32_t IPR16;	//0x340
	U32_t IPR17;	//0x344
	U32_t IPR18;	//0x348
	U32_t IPR19;	//0x34C
	U32_t IPR20;	//0x350
	U32_t rsvd6[683];
	U32_t STIR;		//0xE00
}NVIC_t;

extern _REG NVIC_t *NVIC;
extern void cortexm3_nvic_config(void);
#endif /* CORTEXM3_NVIC_H_ */
