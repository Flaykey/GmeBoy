#include"andorins.h"

void AND_n8(CPU* cpu, BYTE val)
{
    cpu->reg.a &= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 1);
    SET_FLAG_CARRY(&cpu->reg, 0);
    

}
void AND_r8(CPU *cpu, BYTE r){AND_n8(cpu,r);}
void AND_MEM(CPU *cpu){AND_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void OR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a |= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void OR_r8(CPU *cpu, BYTE r){OR_n8(cpu,r);}
void OR_MEM(CPU *cpu){OR_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void XOR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a ^= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void XOR_r8(CPU *cpu, BYTE r){XOR_n8(cpu,r);}
void XOR_MEM(CPU *cpu){XOR_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}
