#include"subroutineins.h"

void CALL_n16(CPU *cpu, WORD address)
{
    cpu->reg.SP--;
    cpu->memory[cpu->reg.SP] = (cpu->reg.IP >> 8) & 0xFF;
    cpu->reg.SP--;
    cpu->memory[cpu->reg.SP] = cpu->reg.IP & 0xFF;

    cpu->reg.IP = address;

}

void CALL_cc_n16(CPU *cpu,CONTITION_CODES cc, WORD address)
{
    if(CHECK_cc(cpu, cc)){
        CALL_n16(cpu,address);
    }
}

void JP_MEM(CPU *cpu)
{
    cpu->reg.IP = GET_HL(&cpu->reg);
}

void JP_n16(CPU *cpu, WORD address)
{
    cpu->reg.IP = address;

}

void JP_cc_n16(CPU *cpu,CONTITION_CODES cc, WORD address)
{
    if(CHECK_cc(cpu,cc)){
        cpu->reg.IP = address;
    }
}

void RET(CPU *cpu)
{
    WORD address = 0;
    address |= cpu->memory[cpu->reg.SP];
    cpu->reg.SP++;
    address |= cpu->memory[cpu->reg.SP] << 8;
    cpu->reg.SP++;

    cpu->reg.IP = address;
}

void RET_cc(CPU *cpu, CONTITION_CODES cc)
{
    if(CHECK_cc(cpu,cc)){
        RET(cpu);
    }
}
