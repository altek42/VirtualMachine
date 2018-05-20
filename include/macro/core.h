#ifndef CORE_MACROS_H
#define CORE_MACROS_H

// #define _CASE_REG_REG_MOV(reg1, reg2) \
// case PR_MOV_##reg1##_##reg2: \
// move_reg_reg(&memory->reg1,&memory->reg2); \
// break;
//
// #define _CASE_REG_INT_MOVE(reg) \
// case PR_LOAD_##reg##_INT: \
// move_reg_int(&memory->reg,memory); \
// break;

#define _CASE_ALL_DOUBLE_REG(funcName,memory) \
case IT_AX_BX: funcName(&memory->RA,&memory->RB);	break; \
case IT_AX_CX: funcName(&memory->RA,&memory->RC);	break; \
case IT_AX_DX: funcName(&memory->RA,&memory->RD);	break; \
case IT_BX_AX: funcName(&memory->RB,&memory->RA);	break; \
case IT_BX_CX: funcName(&memory->RB,&memory->RC);	break; \
case IT_BX_DX: funcName(&memory->RB,&memory->RD);	break; \
case IT_CX_AX: funcName(&memory->RC,&memory->RA);	break; \
case IT_CX_BX: funcName(&memory->RC,&memory->RB);	break; \
case IT_CX_DX: funcName(&memory->RC,&memory->RD);	break; \
case IT_DX_AX: funcName(&memory->RD,&memory->RA);	break; \
case IT_DX_BX: funcName(&memory->RD,&memory->RB);	break; \
case IT_DX_CX: funcName(&memory->RD,&memory->RC);	break;

#define _CASE_ALL_SINGLE_REG(funcName,memory) \
case IT_AL_AH: funcName(&memory->RA.low,&memory->RA.high);	break; \
case IT_AL_BL: funcName(&memory->RA.low,&memory->RB.low);	break; \
case IT_AL_BH: funcName(&memory->RA.low,&memory->RB.high);	break; \
case IT_AL_CL: funcName(&memory->RA.low,&memory->RC.low);	break; \
case IT_AL_CH: funcName(&memory->RA.low,&memory->RC.high);	break; \
case IT_AL_DL: funcName(&memory->RA.low,&memory->RD.low);	break; \
case IT_AL_DH: funcName(&memory->RA.low,&memory->RD.high);	break; \
case IT_AH_AL: funcName(&memory->RA.high,&memory->RA.low);	break; \
case IT_AH_BL: funcName(&memory->RA.high,&memory->RB.low);	break; \
case IT_AH_BH: funcName(&memory->RA.high,&memory->RB.high);	break; \
case IT_AH_CL: funcName(&memory->RA.high,&memory->RC.low);	break; \
case IT_AH_CH: funcName(&memory->RA.high,&memory->RC.high);	break; \
case IT_AH_DL: funcName(&memory->RA.high,&memory->RD.low);	break; \
case IT_AH_DH: funcName(&memory->RA.high,&memory->RD.high);	break; \
case IT_BL_AL: funcName(&memory->RB.low,&memory->RA.low);	break; \
case IT_BL_AH: funcName(&memory->RB.low,&memory->RA.high);	break; \
case IT_BL_BH: funcName(&memory->RB.low,&memory->RB.high);	break; \
case IT_BL_CL: funcName(&memory->RB.low,&memory->RC.low);	break; \
case IT_BL_CH: funcName(&memory->RB.low,&memory->RC.high);	break; \
case IT_BL_DL: funcName(&memory->RB.low,&memory->RD.low);	break; \
case IT_BL_DH: funcName(&memory->RB.low,&memory->RD.high);	break; \
case IT_BH_AL: funcName(&memory->RB.high,&memory->RA.low);	break; \
case IT_BH_AH: funcName(&memory->RB.high,&memory->RA.high);	break; \
case IT_BH_BL: funcName(&memory->RB.high,&memory->RB.low);	break; \
case IT_BH_CL: funcName(&memory->RB.high,&memory->RC.low);	break; \
case IT_BH_CH: funcName(&memory->RB.high,&memory->RC.high);	break; \
case IT_BH_DL: funcName(&memory->RB.high,&memory->RD.low);	break; \
case IT_BH_DH: funcName(&memory->RB.high,&memory->RD.high);	break; \
case IT_CL_AL: funcName(&memory->RC.low,&memory->RA.low);	break; \
case IT_CL_AH: funcName(&memory->RC.low,&memory->RA.high);	break; \
case IT_CL_BL: funcName(&memory->RC.low,&memory->RB.low);	break; \
case IT_CL_BH: funcName(&memory->RC.low,&memory->RB.high);	break; \
case IT_CL_CH: funcName(&memory->RC.low,&memory->RC.high);	break; \
case IT_CL_DL: funcName(&memory->RC.low,&memory->RD.low);	break; \
case IT_CL_DH: funcName(&memory->RC.low,&memory->RD.high);	break; \
case IT_CH_AL: funcName(&memory->RC.high,&memory->RA.low);	break; \
case IT_CH_AH: funcName(&memory->RC.high,&memory->RA.high);	break; \
case IT_CH_BL: funcName(&memory->RC.high,&memory->RB.low);	break; \
case IT_CH_BH: funcName(&memory->RC.high,&memory->RB.high);	break; \
case IT_CH_CL: funcName(&memory->RC.high,&memory->RC.low);	break; \
case IT_CH_DL: funcName(&memory->RC.high,&memory->RD.low);	break; \
case IT_CH_DH: funcName(&memory->RC.high,&memory->RD.high);	break; \
case IT_DL_AL: funcName(&memory->RD.low,&memory->RA.low);	break; \
case IT_DL_AH: funcName(&memory->RD.low,&memory->RA.high);	break; \
case IT_DL_BL: funcName(&memory->RD.low,&memory->RB.low);	break; \
case IT_DL_BH: funcName(&memory->RD.low,&memory->RB.high);	break; \
case IT_DL_CL: funcName(&memory->RD.low,&memory->RC.low);	break; \
case IT_DL_CH: funcName(&memory->RD.low,&memory->RC.high);	break; \
case IT_DL_DH: funcName(&memory->RD.low,&memory->RD.high);	break; \
case IT_DH_AL: funcName(&memory->RD.high,&memory->RA.low);	break; \
case IT_DH_AH: funcName(&memory->RD.high,&memory->RA.high);	break; \
case IT_DH_BL: funcName(&memory->RD.high,&memory->RB.low);	break; \
case IT_DH_BH: funcName(&memory->RD.high,&memory->RB.high);	break; \
case IT_DH_CL: funcName(&memory->RD.high,&memory->RC.low);	break; \
case IT_DH_CH: funcName(&memory->RD.high,&memory->RC.high);	break; \
case IT_DH_DL: funcName(&memory->RD.high,&memory->RD.low);	break;

#define _EXECUTE_MEM_FUNC(opr) \
void executeMem##opr(Memory* memory) { \
	unsigned char byte = getNextByte(memory); \
	switch (byte) { \
		_CASE_ALL_DOUBLE_REG(mem##opr##Double,memory) \
		_CASE_ALL_SINGLE_REG(mem##opr##Single,memory) \
		default: exitErr(ERR_UNRECOGNIZED_INSTRUCTION, memory->PC); \
	} \
}


#endif //CORE_MACROS_H
