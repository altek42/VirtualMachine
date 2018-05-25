#include "../include/memory.h"

unsigned char getNextByte(Memory* mem){
	unsigned char byte = mem->bytecode[mem->PC];
	mem->PC += 1;
	if(mem->PC > mem->PCS){
		exitErr(ERR_END_OF_INSTRUCTIONS,mem->PC);
	}
	return byte;
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
