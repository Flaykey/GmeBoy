#include "cpu.h"

int CHECK_cc(CPU *cpu, CONTITION_CODES cc)
{
    switch (cc)
    {
    case Z: return GET_FLAG_ZERO(&cpu->reg);
    case NZ:return !GET_FLAG_ZERO(&cpu->reg);
    case C: return GET_FLAG_CARRY(&cpu->reg);
    case NC:return !GET_FLAG_CARRY(&cpu->reg);
    }

}

BYTE GetReg(CPU *cpu, BYTE code)
{
    switch (code)
    {
    case 0x0:return cpu->reg.b;
    case 0x1:return cpu->reg.c;
    case 0x2:return cpu->reg.d;
    case 0x3:return cpu->reg.e;
    case 0x4:return cpu->reg.h;
    case 0x5:return cpu->reg.l;
    case 0x6:return cpu->memory[GET_HL(&cpu->reg)];
    case 0x7:return cpu->reg.a;
    default:return NULL;
    }
}

BYTE* GetRegPointer(CPU *cpu, BYTE code)
{
    switch(code)
    {
        case 0x0: return &cpu->reg.b;
        case 0x1: return &cpu->reg.c;
        case 0x2: return &cpu->reg.d;
        case 0x3: return &cpu->reg.e;
        case 0x4: return &cpu->reg.h;
        case 0x5: return &cpu->reg.l;
        case 0x6: return &cpu->memory[GET_HL(&cpu->reg)]; // (HL)
        case 0x7: return &cpu->reg.a;
        default: return NULL;
    }
}

BYTE *GetRegPointer_r16(CPU *cpu, BYTE code)
{
    
    return NULL;
}
