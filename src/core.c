#include "../include/core.h"

void Program(Memory* memory){
	unsigned char byte;
	do {
		byte = getNextByte(memory);
		// printf("Exec: %x\n", byte);
		byte = execute(byte, memory);
	} while(byte);
}

unsigned char execute(unsigned char instruction, Memory* memory){
	switch (instruction) {
		case PR_PRINT_INT: printInt(memory); 	break;
		case PR_PRINT_DOU: printDouble(memory);	break;
		case PR_PRINT_CHA: printChar(memory);	break;

		case PR_MOV: executeMemMov(memory); break;

		case PR_SET_AX: memSetDouble(&memory->RA,memory);	break;
		case PR_SET_BX: memSetDouble(&memory->RB,memory);	break;
		case PR_SET_CX: memSetDouble(&memory->RC,memory);	break;
		case PR_SET_DX: memSetDouble(&memory->RD,memory);	break;

		case PR_SET_AL: memSetInt(&memory->RA.low,memory);	break;
		case PR_SET_AH: memSetInt(&memory->RA.high,memory);	break;
		case PR_SET_BL: memSetInt(&memory->RB.low,memory);	break;
		case PR_SET_BH: memSetInt(&memory->RB.high,memory);	break;
		case PR_SET_CL: memSetInt(&memory->RC.low,memory);	break;
		case PR_SET_CH: memSetInt(&memory->RC.high,memory);	break;
		case PR_SET_DL: memSetInt(&memory->RD.low,memory);	break;
		case PR_SET_DH: memSetInt(&memory->RD.high,memory);	break;

		case PR_EXIT: return 0b0;
		default:
			exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
	return 0b1;
}

void executeMemMov(Memory* memory) {
	unsigned char byte = getNextByte(memory);
	switch (byte) {
		case IT_AX_BX: memMoveDouble(&memory->RA,&memory->RB);	break;
		case IT_AX_CX: memMoveDouble(&memory->RA,&memory->RC);	break;
		case IT_AX_DX: memMoveDouble(&memory->RA,&memory->RD);	break;
		case IT_BX_AX: memMoveDouble(&memory->RB,&memory->RA);	break;
		case IT_BX_CX: memMoveDouble(&memory->RB,&memory->RC);	break;
		case IT_BX_DX: memMoveDouble(&memory->RB,&memory->RD);	break;
		case IT_CX_AX: memMoveDouble(&memory->RC,&memory->RA);	break;
		case IT_CX_BX: memMoveDouble(&memory->RC,&memory->RB);	break;
		case IT_CX_DX: memMoveDouble(&memory->RC,&memory->RD);	break;
		case IT_DX_AX: memMoveDouble(&memory->RD,&memory->RA);	break;
		case IT_DX_BX: memMoveDouble(&memory->RD,&memory->RB);	break;
		case IT_DX_CX: memMoveDouble(&memory->RD,&memory->RC);	break;

		case IT_AL_AH: memMoveSingle(&memory->RA.low,&memory->RA.high);	break;
		case IT_AL_BL: memMoveSingle(&memory->RA.low,&memory->RB.low);	break;
		case IT_AL_BH: memMoveSingle(&memory->RA.low,&memory->RB.high);	break;
		case IT_AL_CL: memMoveSingle(&memory->RA.low,&memory->RC.low);	break;
		case IT_AL_CH: memMoveSingle(&memory->RA.low,&memory->RC.high);	break;
		case IT_AL_DL: memMoveSingle(&memory->RA.low,&memory->RD.low);	break;
		case IT_AL_DH: memMoveSingle(&memory->RA.low,&memory->RD.high);	break;
		case IT_AH_AL: memMoveSingle(&memory->RA.high,&memory->RA.low);	break;
		case IT_AH_BL: memMoveSingle(&memory->RA.high,&memory->RB.low);	break;
		case IT_AH_BH: memMoveSingle(&memory->RA.high,&memory->RB.high);	break;
		case IT_AH_CL: memMoveSingle(&memory->RA.high,&memory->RC.low);	break;
		case IT_AH_CH: memMoveSingle(&memory->RA.high,&memory->RC.high);	break;
		case IT_AH_DL: memMoveSingle(&memory->RA.high,&memory->RD.low);	break;
		case IT_AH_DH: memMoveSingle(&memory->RA.high,&memory->RD.high);	break;
		case IT_BL_AL: memMoveSingle(&memory->RB.low,&memory->RA.low);	break;
		case IT_BL_AH: memMoveSingle(&memory->RB.low,&memory->RA.high);	break;
		case IT_BL_BH: memMoveSingle(&memory->RB.low,&memory->RB.high);	break;
		case IT_BL_CL: memMoveSingle(&memory->RB.low,&memory->RC.low);	break;
		case IT_BL_CH: memMoveSingle(&memory->RB.low,&memory->RC.high);	break;
		case IT_BL_DL: memMoveSingle(&memory->RB.low,&memory->RD.low);	break;
		case IT_BL_DH: memMoveSingle(&memory->RB.low,&memory->RD.high);	break;
		case IT_BH_AL: memMoveSingle(&memory->RB.high,&memory->RA.low);	break;
		case IT_BH_AH: memMoveSingle(&memory->RB.high,&memory->RA.high);	break;
		case IT_BH_BL: memMoveSingle(&memory->RB.high,&memory->RB.low);	break;
		case IT_BH_CL: memMoveSingle(&memory->RB.high,&memory->RC.low);	break;
		case IT_BH_CH: memMoveSingle(&memory->RB.high,&memory->RC.high);	break;
		case IT_BH_DL: memMoveSingle(&memory->RB.high,&memory->RD.low);	break;
		case IT_BH_DH: memMoveSingle(&memory->RB.high,&memory->RD.high);	break;
		case IT_CL_AL: memMoveSingle(&memory->RC.low,&memory->RA.low);	break;
		case IT_CL_AH: memMoveSingle(&memory->RC.low,&memory->RA.high);	break;
		case IT_CL_BL: memMoveSingle(&memory->RC.low,&memory->RB.low);	break;
		case IT_CL_BH: memMoveSingle(&memory->RC.low,&memory->RB.high);	break;
		case IT_CL_CH: memMoveSingle(&memory->RC.low,&memory->RC.high);	break;
		case IT_CL_DL: memMoveSingle(&memory->RC.low,&memory->RD.low);	break;
		case IT_CL_DH: memMoveSingle(&memory->RC.low,&memory->RD.high);	break;
		case IT_CH_AL: memMoveSingle(&memory->RC.high,&memory->RA.low);	break;
		case IT_CH_AH: memMoveSingle(&memory->RC.high,&memory->RA.high);	break;
		case IT_CH_BL: memMoveSingle(&memory->RC.high,&memory->RB.low);	break;
		case IT_CH_BH: memMoveSingle(&memory->RC.high,&memory->RB.high);	break;
		case IT_CH_CL: memMoveSingle(&memory->RC.high,&memory->RC.low);	break;
		case IT_CH_DL: memMoveSingle(&memory->RC.high,&memory->RD.low);	break;
		case IT_CH_DH: memMoveSingle(&memory->RC.high,&memory->RD.high);	break;
		case IT_DL_AL: memMoveSingle(&memory->RD.low,&memory->RA.low);	break;
		case IT_DL_AH: memMoveSingle(&memory->RD.low,&memory->RA.high);	break;
		case IT_DL_BL: memMoveSingle(&memory->RD.low,&memory->RB.low);	break;
		case IT_DL_BH: memMoveSingle(&memory->RD.low,&memory->RB.high);	break;
		case IT_DL_CL: memMoveSingle(&memory->RD.low,&memory->RC.low);	break;
		case IT_DL_CH: memMoveSingle(&memory->RD.low,&memory->RC.high);	break;
		case IT_DL_DH: memMoveSingle(&memory->RD.low,&memory->RD.high);	break;
		case IT_DH_AL: memMoveSingle(&memory->RD.high,&memory->RA.low);	break;
		case IT_DH_AH: memMoveSingle(&memory->RD.high,&memory->RA.high);	break;
		case IT_DH_BL: memMoveSingle(&memory->RD.high,&memory->RB.low);	break;
		case IT_DH_BH: memMoveSingle(&memory->RD.high,&memory->RB.high);	break;
		case IT_DH_CL: memMoveSingle(&memory->RD.high,&memory->RC.low);	break;
		case IT_DH_CH: memMoveSingle(&memory->RD.high,&memory->RC.high);	break;
		case IT_DH_DL: memMoveSingle(&memory->RD.high,&memory->RD.low);	break;
		default: exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC);
	}
}
