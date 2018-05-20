#include "../include/memory.h"

unsigned char getNextByte(Memory* mem){
	unsigned char byte = mem->bytecode[mem->PC];
	mem->PC += 1;
	if(mem->PC > mem->PCS){
		exitErr(ERR_END_OF_INSTRUCTIONS);
	}
	return byte;
}

void move_reg_int (Register *reg, Memory *memory){
	reg->byte0 = getNextByte(memory);
	reg->byte1 = getNextByte(memory);
	reg->byte2 = getNextByte(memory);
	reg->byte3 = getNextByte(memory);
}

void move_reg_reg (Register *reg1, Register *reg2){
	reg1->value = reg2->value;
}
