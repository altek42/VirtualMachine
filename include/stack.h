#ifndef STACK_H
#define STACK_H

#include "error.h"

struct __stack{
	unsigned int *data;
	unsigned int top;
};
typedef struct __stack Stack;

void _realloc_stack(Stack* stack, unsigned int size);

#endif //STACK_H
