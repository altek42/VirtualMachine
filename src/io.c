#include "../include/io.h"

void printInt(Memory* memory){
	printf("%d", memory->RA.low.value);
}
void printDouble(Memory* memory){
	printf("%f", memory->RA.value);
}
void printChar(Memory* memory){
	printf("%c", getNextByte(memory));
}
void printStr(Memory* memory){
	exitErr(ERR_NO_IMPLEMENTATION,memory->PC);
	printf("%d", memory->RA.low.value);
}
