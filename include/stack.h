#ifndef STACK_H
#define STACK_H

#include "error.h"

struct __stack{
	unsigned int *data;
	unsigned int top;
};
typedef struct __stack Stack;

void stack_init(Stack* stack);
void stack_push(Stack* stack, unsigned int data);
unsigned int stack_pop(Stack* stack);

#endif //STACK_H
