#include "../include/input.h"

FILE* openFile(const char* fileName){
	FILE* file = fopen(fileName,"rb");
	if (!file){
		exitErr(ERR_CAN_NOT_OPEN_FILE);
	}
	return file;
}

unsigned char* readFile(FILE* fp, size_t* fileSize){
	fseek(fp, 0, SEEK_END);
	*fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	unsigned char* program = malloc(
		sizeof(unsigned char)* (*fileSize)
	);
	if(!program){
		exitErr(ERR_CAN_NOT_MALLOC_FILE);
	}
	size_t size = fread(
		program,
		sizeof(unsigned char),
		(*fileSize),
		fp
	);
	return program;
}


// unsigned char getNextByte(FILE* file){
// 	unsigned char byte;
// 	size_t size = fread(&byte, sizeof(unsigned char),1,file);
// 	if(size < 1){
// 		exitErr(ERR_END_OF_FILE);
// 	}
// 	return byte;
// }
