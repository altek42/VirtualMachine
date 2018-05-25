#include "../include/stack.h"

void stack_init(Stack* stack){
	stack->top=-1;
	stack->data=NULL;
}


void stack_push(Stack* stack, unsigned int data){
	(stack->top)++;
	void *ptr = realloc(stack->data, (stack->top+1) * sizeof(unsigned int));
	if(ptr == NULL){
		exitErr(ERR_STACK_PUSH_REALLOC, 0);
	}
	stack->data = (unsigned int*) ptr;
	stack->data[stack->top] = data;
	printf("PUSH TOP: %d VAL: %d\n", stack->top, data);
}

unsigned int stack_pop(Stack* stack){
	if(stack->top == -1){
		exitErr(ERR_STACK_POP_INDEX, 0);
	}
	unsigned int value = stack->data[stack->top];
	if(stack->top == 0){
		stack->top=-1;
		free(stack->data);
		return value;
	}

	void *ptr = realloc(stack->data, stack->top * sizeof(unsigned int));
	if(ptr == NULL){
		exitErr(ERR_STACK_POP_REALLOC, 0);
	}
	stack->data = (unsigned int*) ptr;
	(stack->top)--;
	printf("POP TOP: %d VAL: %d\n", stack->top, value);
	return value;
}
