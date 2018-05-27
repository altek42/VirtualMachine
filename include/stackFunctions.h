#ifndef STACK_FUNCTIONS_H
#define STACK_FUNCTIONS_H

#include "memory.h"

void stack_init(Memory* mem);
void stack_push(Memory* mem, unsigned int data);
unsigned int stack_pop(Memory* mem);

void _realloc_stack(Memory* mem, unsigned int size);

#endif //STACK_FUNCTIONS_H
