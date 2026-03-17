#include"subins.h"

void SBC_A(CPU *cpu, BYTE operand)
{
    BYTE carry = GET_FLAG_CARRY(&cpu->reg);
    WORD sub = cpu->reg.a - operand - carry;

    SET_FLAG_ZERO(&cpu->reg, (sub & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg, 1);
    SET_FLAG_HALF_CARRY(&cpu->reg, (cpu->reg.a & 0xF) < ((operand & 0xF) + carry));
    SET_FLAG_CARRY(&cpu->reg, cpu->reg.a < (operand + carry));

    cpu->reg.a = sub & 0xFF;
}

void SBC_A_r8(CPU *cpu){
    BYTE code = cpu->current_opcode & 0x7;
    SBC_A(cpu, GetReg(cpu,code)); 
}
void SBC_A_n8(CPU *cpu) {
    BYTE val = cpu->memory[cpu->reg.IP++];
    SBC_A(cpu, val);
}
void SBC_A_MEM(CPU *cpu) {SBC_A(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void SUB_A(CPU *cpu, BYTE operand)
{
    WORD sub = cpu->reg.a - operand;

    SET_FLAG_ZERO(&cpu->reg, (sub & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg, 1);
    SET_FLAG_HALF_CARRY(&cpu->reg, (cpu->reg.a & 0xF) < (operand & 0xF));
    SET_FLAG_CARRY(&cpu->reg, cpu->reg.a < operand);

    cpu->reg.a = sub & 0xFF;
}

void SUB_A_r8(CPU *cpu){
    BYTE code = cpu->current_opcode & 0x7;
    SUB_A(cpu, GetReg(cpu,code));
}
void SUB_A_n8(CPU *cpu){
    BYTE val = cpu->memory[cpu->reg.IP++];
    SUB_A(cpu, val);
}
void SUB_A_MEM(CPU *cpu) {SUB_A(cpu,cpu->memory[GET_HL(&cpu->reg)]);}
