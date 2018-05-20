#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>
#include "error.h"

FILE* openFile(const char* fileName);
unsigned char* readFile(FILE* fp,size_t* fileSize);

// unsigned char getNextByte(FILE* file);

#endif //INPUT_H
