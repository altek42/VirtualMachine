#include "../include/core.h"

void Program(Memory* memory){
	unsigned char byte;
	do {
		// printf("PC: %x\n", memory->PC);
		byte = getNextByte(memory);
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
		case PR_JGT: executeMemJgt(memory); break;
		case PR_JLT: executeMemJlt(memory); break;
		case PR_JGE: executeMemJlt(memory); break;
		case PR_JLE: executeMemJlt(memory); break;
		case PR_CALL: executeMemCall(memory); break;
		case PR_RET: executeMemRet(memory); break;

		_CASE_DOUBLE(SET,memSetDouble)
		_CASE_SINGLE(SET,memSetInt)

		_CASE_SINGLE(PUSH,memPush)
		_CASE_SINGLE(POP,memPop)

		_CASE_DOUBLE(NOT,memNotDouble)
		_CASE_SINGLE(NOT,memNotSingle)

		_CASE_DOUBLE(SHL,memShlDouble)
		_CASE_SINGLE(SHL,memShlSingle)

		_CASE_DOUBLE(SHR,memShrDouble)
		_CASE_SINGLE(SHR,memShrSingle)

		_CASE_DOUBLE(LOAD,memLoadDouble)
		_CASE_SINGLE(LOAD,memLoadSingle)

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
void executeMemCall(Memory* memory){
	dword dw = getNextDword(memory);
	memCall(dw.value,memory);
}
void executeMemRet(Memory* memory){
	memRet(memory);
}

_EXECUTE_MEM_JMP(Jeq)
_EXECUTE_MEM_JMP(Jgt)
_EXECUTE_MEM_JMP(Jlt)
_EXECUTE_MEM_JMP(Jge)
_EXECUTE_MEM_JMP(Jle)
