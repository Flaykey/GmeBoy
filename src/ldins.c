#include "ldins.h"

void LD_A_r8(CPU *cpu, BYTE r)
{
    cpu->reg.a = r;
}

void LD_r8_A(CPU *cpu, BYTE *dest)
{
    *dest = cpu->reg.a;
}

void LD_A_MEM(CPU *cpu)
{
    cpu->reg.a = cpu->memory[GET_HL(&cpu->reg)];
}

void LD_r8_n8(CPU *cpu, BYTE *dest, BYTE val)
{
    *dest = val;
}

void LD_r16_n16(CPU *cpu, BYTE *highR, BYTE *LowR, BYTE HighVal, BYTE LowVal)
{
    *highR = HighVal;
    *LowR = LowVal;

}

void LD_MEM_n8(CPU *cpu, BYTE val)
{
    cpu->memory[GET_HL(&cpu->reg)] = val;
    WORD hl = GET_HL(&cpu->reg);
    cpu->memory[hl] = val;
    SET_HL(&cpu->reg, hl + 1);
}

void LD_MEM_r16(CPU *cpu, BYTE highVal, BYTE LowVal)
{
    cpu->memory[GET_HL(&cpu->reg)] = LowVal;
    cpu->memory[GET_HL(&cpu->reg) + 1] = highVal;


}
