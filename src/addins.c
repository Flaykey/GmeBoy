#include"addins.h"
void ADC_A(CPU *cpu, BYTE operand)
{
    BYTE carry = GET_FLAG_CARRY(&cpu->reg);
    WORD sum = cpu->reg.a + operand + carry;

    SET_FLAG_ZERO(&cpu->reg, (sum & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, (((cpu->reg.a & 0xF) + (operand & 0xF) + carry) > 0xF));
    SET_FLAG_CARRY(&cpu->reg, sum > 0xFF);

    cpu->reg.a = sum & 0xFF;
}

void ADC_A_r8(CPU *cpu, BYTE r)     { ADC_A(cpu, r); }
void ADC_A_n8(CPU *cpu, BYTE val)   { ADC_A(cpu, val); }
void ADC_A_MEM(CPU *cpu) { ADC_A(cpu, cpu->memory[GET_HL(&cpu->reg)]); }

void ADD_A(CPU *cpu, BYTE operand)
{

    WORD sum = cpu->reg.a + operand ;

    SET_FLAG_ZERO(&cpu->reg, (sum & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, (((cpu->reg.a & 0xF) + (operand & 0xF)) > 0xF));
    SET_FLAG_CARRY(&cpu->reg, sum > 0xFF);

    cpu->reg.a = sum & 0xFF;
}

void ADD_A_r8(CPU *cpu, BYTE r)     { ADD_A(cpu, r); }
void ADD_A_n8(CPU *cpu, BYTE val)   { ADD_A(cpu, val); }
void ADD_A_MEM(CPU *cpu) { ADD_A(cpu, cpu->memory[GET_HL(&cpu->reg)]); }
