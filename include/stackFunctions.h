#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H

#include "memory.h"

void stack_init(Memory* mem);
void stack_push(Memory* mem, unsigned int data);
unsigned int stack_pop(Memory* mem);

#endif //STACK_FUNCTIONS_H
