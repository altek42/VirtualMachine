#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include "errorCode.h"
#include "macro/error.h"

void exitErr(int code);
char* __getErrMsg(int code);

#endif //ERROR_H
