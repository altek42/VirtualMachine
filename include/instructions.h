#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define PR_EXIT	0x00

#define PR_PRINT_INT	0x10
#define PR_PRINT_DOU	0x11
#define PR_PRINT_CHA	0x12
#define PR_PRINT_STR	0x13
#define PR_SCAN 	0x14
#define PR_ALLOC	0x15

#define PR_MOV	0x16
#define PR_ADD	0x17
#define PR_SUB	0x18
#define PR_MUL	0x19
#define PR_DIV	0x1a

#define PR_MOD	0x1b
#define PR_OR	0x1c
#define PR_AND	0x1d
#define PR_XOR	0x1e
#define PR_JMP	0x1f
#define PR_JEQ	0x20
#define PR_JNE	0x21
#define PR_JGT	0x22
#define PR_JLT	0x23
#define PR_JGE	0x24
#define PR_JLE	0x25
#define PR_CALL	0x26
#define PR_RET	0x27

#define PR_PUSH_AL	0x28
#define PR_PUSH_AH	0x29
#define PR_PUSH_BL	0x2a
#define PR_PUSH_BH	0x2b
#define PR_PUSH_CL	0x2c
#define PR_PUSH_CH	0x2d
#define PR_PUSH_DL	0x2e
#define PR_PUSH_DH	0x2f

#define PR_POP_AL	0x30
#define PR_POP_AH	0x31
#define PR_POP_BL	0x32
#define PR_POP_BH	0x33
#define PR_POP_CL	0x34
#define PR_POP_CH	0x35
#define PR_POP_DL	0x36
#define PR_POP_DH	0x37


#define PR_NOT_AX	0x38
#define PR_NOT_BX	0x39
#define PR_NOT_CX	0x3a
#define PR_NOT_DX	0x3b
#define PR_NOT_AL	0x3c
#define PR_NOT_AH	0x3d
#define PR_NOT_BL	0x3e
#define PR_NOT_BH	0x3f
#define PR_NOT_CL	0x40
#define PR_NOT_CH	0x41
#define PR_NOT_DL	0x42
#define PR_NOT_DH	0x43

#define PR_SHL_AX	0x44
#define PR_SHL_BX	0x45
#define PR_SHL_CX	0x46
#define PR_SHL_DX	0x47
#define PR_SHL_AL	0x48
#define PR_SHL_AH	0x49
#define PR_SHL_BL	0x4a
#define PR_SHL_BH	0x4b
#define PR_SHL_CL	0x4c
#define PR_SHL_CH	0x4d
#define PR_SHL_DL	0x4e
#define PR_SHL_DH	0x4f

#define PR_SHR_AX	0x50
#define PR_SHR_BX	0x51
#define PR_SHR_CX	0x52
#define PR_SHR_DX	0x53
#define PR_SHR_AL	0x54
#define PR_SHR_AH	0x55
#define PR_SHR_BL	0x56
#define PR_SHR_BH	0x57
#define PR_SHR_CL	0x58
#define PR_SHR_CH	0x59
#define PR_SHR_DL	0x5a
#define PR_SHR_DH	0x5b

#define PR_SET_AX	0x5c
#define PR_SET_BX	0x5d
#define PR_SET_CX	0x5e
#define PR_SET_DX	0x5f
#define PR_SET_AL	0x60
#define PR_SET_AH	0x61
#define PR_SET_BL	0x62
#define PR_SET_BH	0x63
#define PR_SET_CL	0x64
#define PR_SET_CH	0x65
#define PR_SET_DL	0x66
#define PR_SET_DH	0x67

#define PR_LOAD_AX	0x68
#define PR_LOAD_BX	0x69
#define PR_LOAD_CX	0x6a
#define PR_LOAD_DX	0x6b
#define PR_LOAD_AL	0x6c
#define PR_LOAD_AH	0x6d
#define PR_LOAD_BL	0x6e
#define PR_LOAD_BH	0x6f
#define PR_LOAD_CL	0x70
#define PR_LOAD_CH	0x71
#define PR_LOAD_DL	0x72
#define PR_LOAD_DH	0x73

#define PR_STORE_AX	0x74
#define PR_STORE_BX	0x75
#define PR_STORE_CX	0x76
#define PR_STORE_DX	0x77
#define PR_STORE_AL	0x78
#define PR_STORE_AH	0x79
#define PR_STORE_BL	0x7a
#define PR_STORE_BH	0x7b
#define PR_STORE_CL	0x7c
#define PR_STORE_CH	0x7d
#define PR_STORE_DL	0x7e
#define PR_STORE_DH	0x7f

#define PR_CT_INT_A	0x80
#define PR_CT_DOU_A	0x81
#define PR_CT_INT_B	0x82
#define PR_CT_DOU_B	0x83
#define PR_CT_INT_C	0x84
#define PR_CT_DOU_C	0x85
#define PR_CT_INT_D	0x86
#define PR_CT_DOU_D	0x87

#endif //INSTRUCTIONS_H
