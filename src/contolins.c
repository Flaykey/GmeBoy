#include "controlins.h"
void CPL(CPU *cpu)
{
    cpu->reg.a = ~cpu->reg.a;
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg,1);
}

void NOP(CPU *cpu)
{
}

void CCF(CPU *cpu)
{
    SET_FLAG_CARRY(&cpu->reg, !(GET_FLAG_CARRY(&cpu->reg)));
    SET_FLAG_ZERO(&cpu->reg,0);
    SET_FLAG_HALF_CARRY(&cpu->reg,0);
}

void SCF(CPU *cpu)
{
    SET_FLAG_CARRY(&cpu->reg , 1);
    SET_FLAG_ZERO(&cpu->reg,0);
    SET_FLAG_HALF_CARRY(&cpu->reg,0);
}

void HALT(CPU *cpu)
{
    cpu->state = HALTED;
}

void STOP(CPU *cpu)
{
    cpu->state = STOPPED;

}

void EI(CPU *cpu)
{
    cpu->IME = 1;
}

void DI(CPU *cpu)
{
    cpu->IME = 0;
}
