#ifndef CORE_MACROS_H
#define CORE_MACROS_H

#define _CASE_REG_REG_MOV(reg1, reg2) \
case PR_MOV_##reg1##_##reg2: \
move_reg_reg(&memory->reg1,&memory->reg2); \
break;

#define _CASE_REG_INT_MOVE(reg) \
case PR_LOAD_##reg##_INT: \
move_reg_int(&memory->reg,memory); \
break;


#endif //CORE_MACROS_H
