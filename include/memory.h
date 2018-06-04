#ifndef MEMORY_H
#define MEMORY_H

#include<stdio.h>
#include "macro/memory.h"
#include "error.h"
#include "stack.h"

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
typedef union __dword dword;

union __double_register{
	double value;
	unsigned long long lvalue;
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
	Stack stack;
} __attribute__((packed));
typedef struct __memory Memory;

unsigned char getNextByte(Memory* mem);
dword getNextDword(Memory* mem);

void memMovSingle (Register *reg1, Register *reg2);
void memMovDouble (DRegister *reg1, DRegister *reg2);

void memAddSingle (Register *reg1, Register *reg2);
void memAddDouble (DRegister *reg1, DRegister *reg2);

void memSubSingle (Register *reg1, Register *reg2);
void memSubDouble (DRegister *reg1, DRegister *reg2);

void memMulSingle (Register *reg1, Register *reg2);
void memMulDouble (DRegister *reg1, DRegister *reg2);

void memDivSingle (Register *reg1, Register *reg2);
void memDivDouble (DRegister *reg1, DRegister *reg2);

void memModSingle (Register *reg1, Register *reg2);
void memOrSingle (Register *reg1, Register *reg2);
void memAndSingle (Register *reg1, Register *reg2);
void memXorSingle (Register *reg1, Register *reg2);

void _memJmpPosCheck(unsigned int pos, Memory* memory);
void memJmp(unsigned int pos, Memory* memory);
void memJeqSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJeqDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memJneSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJneDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memJgtSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJgtDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memJltSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJltDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memJgeSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJgeDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memJleSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory);
void memJleDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory);
void memCall(unsigned int pos, Memory* memory);
void memRet(Memory* memory);

void memPush(Register* reg, Memory *memory);
void memPop(Register* reg, Memory *memory);

void memSetInt (Register *reg, Memory *memory);
void memSetDouble (DRegister *reg, Memory *memory);

void memNotSingle(Register* reg, Memory* memory);
void memNotDouble(DRegister* reg, Memory* memory);

void memShlSingle(Register* reg, Memory* memory);
void memShlDouble(DRegister* reg, Memory* memory);

void memShrSingle(Register* reg, Memory* memory);
void memShrDouble(DRegister* reg, Memory* memory);
#endif //MEMORY_H
