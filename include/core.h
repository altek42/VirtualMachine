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
void executeMemSub(Memory* memory);
void executeMemMul(Memory* memory);
void executeMemDiv(Memory* memory);
void executeMemMod(Memory* memory);
void executeMemOr(Memory* memory);
void executeMemAnd(Memory* memory);
void executeMemXor(Memory* memory);

void executeMemJmp(Memory* memory);
void executeMemJeq(Memory* memory);
void executeMemJgt(Memory* memory);
void executeMemJlt(Memory* memory);
void executeMemJge(Memory* memory);
void executeMemJle(Memory* memory);
void executeMemCall(Memory* memory);
void executeMemRet(Memory* memory);

#endif //CORE_H
