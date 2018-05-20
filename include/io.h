#ifndef IO_H
#define IO_H
#include <stdio.h>
#include "memory.h"
#include "error.h"

void printInt(Memory* memory);
void printDouble(Memory* memory);
void printChar(Memory* memory);
void printStr(Memory* memory);

#endif //IO_H
