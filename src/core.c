#include "../include/core.h"

void Program(Memory* memory){
	unsigned char byte;
	do {
		byte = getNextByte(memory);
		// printf("Exec: %x\n", byte);
		byte = execute(byte, memory);
	} while(byte);
}

unsigned char execute(unsigned char instruction, Memory* memory){
	switch (instruction) {
		case PR_PRINT_INT: printInt(memory); 	break;
		case PR_PRINT_DOU: printDouble(memory);	break;
		case PR_PRINT_CHA: printChar(memory);	break;

		case PR_MOV: executeMemMov(memory); break;
		case PR_ADD: executeMemAdd(memory); break;

		case PR_SET_AX: memSetDouble(&memory->RA,memory);	break;
		case PR_SET_BX: memSetDouble(&memory->RB,memory);	break;
		case PR_SET_CX: memSetDouble(&memory->RC,memory);	break;
		case PR_SET_DX: memSetDouble(&memory->RD,memory);	break;

		case PR_SET_AL: memSetInt(&memory->RA.low,memory);	break;
		case PR_SET_AH: memSetInt(&memory->RA.high,memory);	break;
		case PR_SET_BL: memSetInt(&memory->RB.low,memory);	break;
		case PR_SET_BH: memSetInt(&memory->RB.high,memory);	break;
		case PR_SET_CL: memSetInt(&memory->RC.low,memory);	break;
		case PR_SET_CH: memSetInt(&memory->RC.high,memory);	break;
		case PR_SET_DL: memSetInt(&memory->RD.low,memory);	break;
		case PR_SET_DH: memSetInt(&memory->RD.high,memory);	break;

		case PR_EXIT: return 0b0;
		default:
			exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
	return 0b1;
}

void executeMemMov(Memory* memory) {
	unsigned char byte = getNextByte(memory);
	switch (byte) {
		_CASE_ALL_DOUBLE_REG(memMoveDouble,memory)
		_CASE_ALL_SINGLE_REG(memMoveSingle,memory)

		default: exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
}

void executeMemAdd(Memory* memory){
	unsigned char byte = getNextByte(memory);
	switch (byte) {
		_CASE_ALL_DOUBLE_REG(memAddDouble,memory)
		_CASE_ALL_SINGLE_REG(memAddSingle,memory)

		default: exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
}
