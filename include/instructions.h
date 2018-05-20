#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define PR_EXIT 0x00

#define PR_PRINT_INT 0x0A

#define PR_LOAD_R0_INT 0x10
#define PR_LOAD_R1_INT 0x11
#define PR_LOAD_R2_INT 0x12
#define PR_LOAD_R3_INT 0x13

#define PR_MOV_R0_R1 0x30
#define PR_MOV_R0_R2 0x31
#define PR_MOV_R0_R3 0x32
#define PR_MOV_R1_R0 0x33
#define PR_MOV_R1_R2 0x34
#define PR_MOV_R1_R3 0x35
#define PR_MOV_R2_R0 0x36
#define PR_MOV_R2_R1 0x37
#define PR_MOV_R2_R3 0x38
#define PR_MOV_R3_R0 0x39
#define PR_MOV_R3_R1 0x3A
#define PR_MOV_R3_R2 0x3B

#define PR_ADD_R0_R1

#endif //INSTRUCTIONS_H
