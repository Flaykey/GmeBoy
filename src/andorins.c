#include"andorins.h"

void AND_n8(CPU* cpu, BYTE val)
{
    cpu->reg.a &= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 1);
    SET_FLAG_CARRY(&cpu->reg, 0);
    

}
void AND_r8(CPU *cpu){
    BYTE code = cpu->current_opcode & 0x7;
    AND_n8(cpu,GetReg(cpu,code));
}
void AND_MEM(CPU *cpu){AND_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void OR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a |= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void OR_r8(CPU *cpu){
    BYTE code = cpu->current_opcode & 0x7;
    OR_n8(cpu,GetReg(cpu,code));
}
void OR_MEM(CPU *cpu){OR_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void XOR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a ^= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void XOR_r8(CPU *cpu, BYTE r){
    BYTE code = cpu->current_opcode & 0x7;
    XOR_n8(cpu,GetReg(cpu,code));
}
void XOR_MEM(CPU *cpu){XOR_n8(cpu,cpu->memory[GET_HL(&cpu->reg)]);}
