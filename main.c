#include <stdio.h>
#include "include/input.h"
#include "include/memory.h"
#include "include/core.h"

int main(int argc, char const *argv[]) {
	if(argc < 2){
		exitErr(ERR_ARG_COUNT,-1);
	}
	printf("FILE: %s\n", argv[1]);
	
	FILE* f = openFile(argv[1]);
	size_t size;
	unsigned char* bytecode = readFile(f,&size);
	fclose(f);
	Memory mem;
	mem.bytecode = bytecode;
	mem.PCS = size;
	mem.PC=0;
	mem.RA.value=0.0;
	mem.RB.value=0.0;
	mem.RC.value=0.0;
	mem.RD.value=0.0;

	Program(&mem);

	free(bytecode);
	return 0;
}
