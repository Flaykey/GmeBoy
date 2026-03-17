#include "ldins.h"

void LD_A_r8(CPU *cpu)
{
    BYTE code = cpu->current_opcode & 0x7;
    cpu->reg.a = GetReg(cpu,code);
}

void LD_r8_A(CPU *cpu)
{
    BYTE code = cpu->current_opcode & 0x7;
    BYTE *dest = &GetReg(cpu,code);
    *dest = cpu->reg.a;
}

void LD_A_MEM(CPU *cpu)
{
    cpu->reg.a = cpu->memory[GET_HL(&cpu->reg)];
}

void LD_r8_n8(CPU *cpu)
{
    BYTE code = (cpu->current_opcode >> 3) & 0x7;
    BYTE *dest = GetRegPointer(cpu,code);
    BYTE val = cpu->memory[cpu->reg.IP++];
    *dest = val;
}

void LD_r8_r8(CPU *cpu)
{
    BYTE opcode = cpu->current_opcode;
    BYTE dst_code = (opcode >> 3) & 0x07;
    BYTE src_code = opcode & 0x07;        

    BYTE *src = GetRegPointer(cpu, src_code); 
    BYTE *dest = GetRegPointer(cpu, dest_code);    

    *dest = *src;
}

void LD_r16_n16(CPU *cpu, BYTE *highR, BYTE *LowR, BYTE HighVal, BYTE LowVal)
{
    *highR = HighVal;
    *LowR = LowVal;

}

void LD_MEM_n8(CPU *cpu, BYTE val)
{
    BYTE val = cpu->memory[cpu->reg.IP++]; 
    cpu->memory[GET_HL(&cpu->reg)] = val;
}

void LD_MEM_r8(CPU *cpu)
{
    BYTE opcode = cpu->current_opcode;
    BYTE src_code = opcode & 0x07;        

    BYTE src = GetReg(cpu, src_code); 
    cpu->memory[GET_HL(&cpu->reg)] = src;

}

void LD_MEM_r16(CPU *cpu, BYTE highVal, BYTE LowVal)
{
    cpu->memory[GET_HL(&cpu->reg)] = LowVal;
    cpu->memory[GET_HL(&cpu->reg) + 1] = highVal;
}
