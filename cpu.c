#include "cpu.h"

void LD_A_r8(CPU *cpu, BYTE r)
{
    cpu->reg.a = r;
}

void LD_r8_A(CPU *cpu, BYTE *dest)
{
    *dest = cpu->reg.a;
}

void LD_A_MEM(CPU *cpu, WORD address)
{
    cpu->reg.a = cpu->memory[address];
}

void LD_r8(CPU *cpu, BYTE *dest, BYTE val)
{
    *dest = val;
}

