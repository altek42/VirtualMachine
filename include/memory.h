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

void move_reg_int (Register *reg, Memory *memory);
void move_reg_reg (Register *reg1, Register *reg2);

#endif //MEMORY_H
