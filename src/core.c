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


		case PR_EXIT:
			return 0b0;
		default:
			exitErr(ERR_UNRECOGNIZED_INSTRUCTION);
	}
	return 0b1;
}
