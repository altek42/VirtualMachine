#include "../include/stack.h"
#include "../include/stackFunctions.h"

void stack_init(Memory* mem){
	mem->stack.top=0;
	mem->stack.data=NULL;
}

void stack_push(Memory* mem, unsigned int data){
	(mem->stack.top)++;
	_realloc_stack(mem, mem->stack.top+1);
	mem->stack.data[mem->stack.top] = data;
}

unsigned int stack_pop(Memory* mem){
	if(mem->stack.top == -1){
		exitErr(ERR_STACK_POP_INDEX, 0);
	}
	unsigned int value = mem->stack.data[mem->stack.top];
	if(mem->stack.top == 0){
		mem->stack.top=-1;
		free(mem->stack.data);
		mem->stack.data=NULL;
		return value;
	}
	_realloc_stack(mem, mem->stack.top);
	(mem->stack.top)--;
	return value;
}

void _realloc_stack(Memory* mem, unsigned int size){
	void *ptr = realloc(mem->stack.data, size * sizeof(unsigned int));
	if(ptr == NULL){
		exitErr(ERR_STACK_REALLOC, mem->PC);
	}
	mem->stack.data = (unsigned int*) ptr;
}
