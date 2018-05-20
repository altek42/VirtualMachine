#ifndef MEMORY_H
#define MEMORY_H

#include<stdio.h>
#include "macro/memory.h"
#include "error.h"

/**
*	Example:
*	value=0xffaa3311
*	byte0=0x11
*	byte1=0x33
*	byte2=0xaa
*	byte3=0xff
**/
union __dword{
	unsigned int value;
	struct {
		unsigned char byte0 : 8;
		unsigned char byte1 : 8;
		unsigned char byte2 : 8;
		unsigned char byte3 : 8;//oldest
	};
};
typedef union __dword Register;

union __double_register{
	double value;
	struct{
		Register low;
		Register high;
	};
};
typedef union __double_register DRegister;

struct __memory{
	DRegister RA;
	DRegister RB;
	DRegister RC;
	DRegister RD;
	unsigned int PC;
	unsigned char* bytecode;
	unsigned int PCS;
} __attribute__((packed));
typedef struct __memory Memory;

unsigned char getNextByte(Memory* mem);

void memSetInt (Register *reg, Memory *memory);
void memSetDouble (DRegister *reg, Memory *memory);
void memMoveSingle (Register *reg1, Register *reg2);
void memMoveDouble (DRegister *reg1, DRegister *reg2);

#endif //MEMORY_H
