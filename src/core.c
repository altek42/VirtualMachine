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
		case PR_SUB: executeMemSub(memory); break;
		case PR_MUL: executeMemMul(memory); break;
		case PR_DIV: executeMemDiv(memory); break;

		case PR_MOD: executeMemMod(memory); break;
		case PR_OR: executeMemOr(memory); break;
		case PR_AND: executeMemAnd(memory); break;
		case PR_XOR: executeMemXor(memory); break;

		case PR_JMP: executeMemJmp(memory); break;
		case PR_JEQ: executeMemJeq(memory); break;

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

		case PR_NONE: break;
		case PR_EXIT: return 0b0;
		default:
			exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
	return 0b1;
}

_EXECUTE_MEM_FUNC(Mov)
_EXECUTE_MEM_FUNC(Add)
_EXECUTE_MEM_FUNC(Sub)
_EXECUTE_MEM_FUNC(Mul)
_EXECUTE_MEM_FUNC(Div)

_EXECUTE_MEM_SINGLE_FUNC(Mod)
_EXECUTE_MEM_SINGLE_FUNC(Or)
_EXECUTE_MEM_SINGLE_FUNC(And)
_EXECUTE_MEM_SINGLE_FUNC(Xor)

void executeMemJmp(Memory* memory){
	dword dw = getNextDword(memory);
	memJmp(dw.value,memory);
}

_EXECUTE_MEM_JMP(Jeq)
