#include "../include/memory.h"

unsigned char getNextByte(Memory* mem){
	unsigned char byte = mem->bytecode[mem->PC];
	mem->PC += 1;
	if(mem->PC > mem->PCS){
		exitErr(ERR_END_OF_INSTRUCTIONS,mem->PC);
	}
	return byte;
}

void memSetInt (Register *reg, Memory *memory){
	reg->byte0 = getNextByte(memory);
	reg->byte1 = getNextByte(memory);
	reg->byte2 = getNextByte(memory);
	reg->byte3 = getNextByte(memory);
}

void memSetDouble (DRegister *reg, Memory *memory){
	memSetInt(&reg->low,memory);
	memSetInt(&reg->high,memory);
}

void memMovSingle(Register *reg1, Register *reg2){
	reg1->value = reg2->value;
}
void memMovDouble (DRegister *reg1, DRegister *reg2){
	reg1->value = reg2->value;
}

void memAddSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value + reg2->value;
}
void memAddDouble (DRegister *reg1, DRegister *reg2){
	reg1->value = reg1->value + reg2->value;
}

void memSubSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value - reg2->value;
}
void memSubDouble (DRegister *reg1, DRegister *reg2){
	reg1->value = reg1->value - reg2->value;
}

void memMulSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value * reg2->value;
}
void memMulDouble (DRegister *reg1, DRegister *reg2){
	reg1->value = reg1->value * reg2->value;
}

void memDivSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value / reg2->value;
}
void memDivDouble (DRegister *reg1, DRegister *reg2){
	reg1->value = reg1->value / reg2->value;
}
