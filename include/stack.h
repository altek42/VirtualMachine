#ifndef STACK_H
#define STACK_H

#include "error.h"

struct __stack{
	unsigned int *data;
	unsigned int top;
};
typedef struct __stack Stack;


#endif //STACK_H
