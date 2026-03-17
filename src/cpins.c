#include"cpins.h"


void CP_A_n8(CPU *cpu, BYTE val)
{
    WORD res = cpu->reg.a - val;
    SET_FLAG_ZERO(&cpu->reg,(res & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg, (cpu->reg.a & 0xF) < (val & 0xF));
    SET_FLAG_CARRY(&cpu->reg, cpu->reg.a < val);
}
void CP_A_r8(CPU *cpu, BYTE dest)    { CP_A_n8(cpu,dest);}
void CP_A_MEM(CPU *cpu) { CP_A_n8(cpu, cpu->memory[GET_HL(&cpu->reg)]); }
