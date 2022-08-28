/*
 * cortexm3_scb.h
 *
 *  Created on: Sep 6, 2021
 *      Author: Golden Eagle
 */

#ifndef SCB_H_
#define SCB_H_

#include "types.h"


#define SCB_PENDSTCLR_BP	25

#define SCB_BASE_ADDR 0xE000ED00

typedef struct SCB_s{
	U32_t CPUID;
	U32_t ICSR;
	U32_t VTOR;
	U32_t AIRCR;
	U32_t SCR;
	U32_t CCR;
	U32_t SHPR1;
	U32_t SHPR2;
	U32_t SHPR3;
	U32_t SHCRS;
	U32_t CFSR;
	U32_t HFSR;
	U32_t rsvd;
	U32_t MMAR;		//0x34
	U32_t BFAR;		//0x38
}SCB_t;

extern _REG SCB_t *SCB;

#endif /* SCB_H_ */
