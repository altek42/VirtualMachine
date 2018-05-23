#include "../include/error.h"
#include "../include/errorCode.h"

void exitErr(const int code, const unsigned int pc){
	fprintf(stderr, "\nError: %d: %s (PC: 0x%x)\n", code, __getErrMsg(code), pc);
	exit(code);
}

char* __getErrMsg(int code){
	switch (code) {
		CASE_RET(ERR_ARG_COUNT, "An input file is required.");
		CASE_RET(ERR_CAN_NOT_OPEN_FILE, "Unable to open file.");
		CASE_RET(ERR_CAN_NOT_MALLOC_FILE, "Can not allocate memory for input file.");
		CASE_RET(ERR_UNRECOGNIZED_INSTRUCTION, "Unrecognized instruction.");
		CASE_RET(ERR_END_OF_INSTRUCTIONS, "Unexpected end of instructions.");
		CASE_RET(ERR_JMP_SKIP_INSTRUCTIONS, "Jump out of memory.");
		CASE_RET(ERR_NO_IMPLEMENTATION, "No implementation yet.");
	}
	return "";
}
