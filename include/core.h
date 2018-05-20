#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include "memory.h"
#include "macro/core.h"
#include "instructions.h"
#include "instructionsTarget.h"
#include "error.h"
#include "io.h"

void Program(Memory* memory);
unsigned char execute(unsigned char instruction, Memory* memory);
void executeMemMov(Memory* memory);
void executeMemAdd(Memory* memory);

#endif //CORE_H
