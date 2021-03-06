#include "../include/memory.h"

unsigned char getNextByte(Memory* mem){
	unsigned char byte = mem->bytecode[mem->PC];
	mem->PC += 1;
	_checkMemPos(mem->PC,mem);
	return byte;
}

void _checkMemPos(unsigned int pos, Memory* mem){
	if(pos > mem->PCS){
		exitErr(ERR_END_OF_INSTRUCTIONS,mem->PC);
	}
}

dword getNextDword(Memory* mem){
	dword dw;
	memSetInt(&dw,mem);
	return dw;
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

void memModSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value % reg2->value;
}
void memOrSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value | reg2->value;
}
void memAndSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value & reg2->value;
}
void memXorSingle (Register *reg1, Register *reg2){
	reg1->value = reg1->value ^ reg2->value;
}

void _memJmpPosCheck(unsigned int pos, Memory* memory){
	if(pos > memory->PCS){
		exitErr(ERR_JMP_SKIP_INSTRUCTIONS,memory->PC);
	}
}

void memJmp(unsigned int pos, Memory* memory){
	_memJmpPosCheck(pos,memory);
	memory->PC = pos;
}

void memJeqDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value == reg2->value){
		memory->PC = pos;
	}
}
void memJeqSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value == reg2->value){
		memory->PC = pos;
	}
}


void memJneDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value != reg2->value){
		memory->PC = pos;
	}
}
void memJneSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value != reg2->value){
		memory->PC = pos;
	}
}

void memJgtSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value > reg2->value){
		memory->PC = pos;
	}
}
void memJgtDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value > reg2->value){
		memory->PC = pos;
	}
}

void memJltSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value < reg2->value){
		memory->PC = pos;
	}
}
void memJltDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value < reg2->value){
		memory->PC = pos;
	}
}


void memJgeSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value >= reg2->value){
		memory->PC = pos;
	}
}
void memJgeDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value >= reg2->value){
		memory->PC = pos;
	}
}


void memJleSingle(unsigned int pos, Register *reg1, Register *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value <= reg2->value){
		memory->PC = pos;
	}
}
void memJleDouble(unsigned int pos, DRegister *reg1, DRegister *reg2, Memory* memory){
	_memJmpPosCheck(pos,memory);
	if(reg1->value <= reg2->value){
		memory->PC = pos;
	}
}

void memCall(unsigned int pos, Memory* memory){
	_memJmpPosCheck(pos,memory);
	stack_push(memory, memory->PC);
	memory->PC = pos;
}

void memRet(Memory* memory){
	memory->PC = stack_pop(memory);
}

void memPush(Register* reg, Memory *memory){
	stack_push(memory, reg->value);
}

void memPop(Register* reg, Memory *memory){
	reg->value = stack_pop(memory);
}

void memNotSingle(Register* reg, Memory* memory){
	reg->value = ~(reg->value);
}
void memNotDouble(DRegister* reg, Memory* memory){
	reg->lvalue = ~(reg->lvalue);
}

void memShlSingle(Register* reg, Memory* memory){
	unsigned char byte = getNextByte(memory);
	reg->value = reg->value << byte;
}
void memShlDouble(DRegister* reg, Memory* memory){
	unsigned char byte = getNextByte(memory);
	reg->lvalue = reg->lvalue << byte;
}

void memShrSingle(Register* reg, Memory* memory){
	unsigned char byte = getNextByte(memory);
	reg->value = reg->value >> byte;
}
void memShrDouble(DRegister* reg, Memory* memory){
	unsigned char byte = getNextByte(memory);
	reg->lvalue = reg->lvalue >> byte;
}

void memLoadSingle(Register* reg, Memory* memory){
	dword address = getNextDword(memory);
	unsigned int pos = memory->PC;
	memory->PC = address.value;
	memSetInt(reg,memory);
	memory->PC = pos;
}
void memLoadDouble(DRegister* reg, Memory* memory){
	dword address = getNextDword(memory);
	unsigned int pos = memory->PC;
	memory->PC = address.value;
	memSetDouble(reg,memory);
	memory->PC = pos;
}

void _storeInt(unsigned int pos, Register* reg, Memory* mem){
	mem->bytecode[pos] = reg->byte0;
	mem->bytecode[pos+1] = reg->byte1;
	mem->bytecode[pos+2] = reg->byte2;
	mem->bytecode[pos+3] = reg->byte3;
}

void _storeDouble(unsigned int pos, DRegister* reg, Memory* mem){
	_storeInt(pos, &reg->low,mem);
	_storeInt(pos+4, &reg->high,mem);
}

void memStoreSingle(Register* reg, Memory* memory){
	dword address = getNextDword(memory);
	unsigned int pos = address.value;
	_checkMemPos(pos+3,memory);
	_storeInt(pos,reg,memory);
}
void memStoreDouble(DRegister* reg, Memory* memory){
	dword address = getNextDword(memory);
	unsigned int pos = address.value;
	_checkMemPos(pos+7,memory);
	_storeDouble(pos,reg,memory);
}

void memConvertToInt(DRegister* reg){
	double val = reg->value;
	reg->high.value=0;
	reg->low.value=(unsigned int)val;
}
void memConvertToDouble(DRegister* reg){
	unsigned int val = reg->low.value;
	reg->value = (double)val;
}
