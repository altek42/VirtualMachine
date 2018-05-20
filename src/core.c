#include "../include/core.h"

void Program(Memory* memory){
	unsigned char byte;
	do {
		byte = getNextByte(memory);
		byte = execute(byte, memory);
	} while(byte);
}

unsigned char execute(unsigned char instruction, Memory* memory){
	switch (instruction) {
		case PR_PRINT_INT:
			print_int(memory);
			break;
		_CASE_REG_INT_MOVE(R0)
		_CASE_REG_INT_MOVE(R1)
		_CASE_REG_INT_MOVE(R2)
		_CASE_REG_INT_MOVE(R3)
		_CASE_REG_REG_MOV(R0,R1)
		_CASE_REG_REG_MOV(R0,R2)
		_CASE_REG_REG_MOV(R0,R3)
		_CASE_REG_REG_MOV(R1,R0)
		_CASE_REG_REG_MOV(R1,R2)
		_CASE_REG_REG_MOV(R1,R3)
		_CASE_REG_REG_MOV(R2,R0)
		_CASE_REG_REG_MOV(R2,R1)
		_CASE_REG_REG_MOV(R2,R3)
		_CASE_REG_REG_MOV(R3,R0)
		_CASE_REG_REG_MOV(R3,R1)
		_CASE_REG_REG_MOV(R3,R2)

		case PR_EXIT:
			return 0b0;
		default:
			exitErr(ERR_UNRECOGNIZED_INSTRUCTION);
	}
	return 0b1;
}
