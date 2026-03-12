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

void LD_r8_n8(CPU *cpu, BYTE *dest, BYTE val)
{
    *dest = val;
}

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
void ADC_A_MEM(CPU *cpu, WORD addr) { ADC_A(cpu, cpu->memory[addr]); }

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
void ADD_A_MEM(CPU *cpu, WORD addr) { ADD_A(cpu, cpu->memory[addr]); }

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

void SBC_A_r8(CPU *cpu, BYTE r)        {SBC_A(cpu,r);}
void SBC_A_n8(CPU *cpu, BYTE val)      {SBC_A(cpu,val);}
void SBC_A_MEM(CPU *cpu, WORD address) {SBC_A(cpu,cpu->memory[address]);}

void SUB_A(CPU *cpu, BYTE operand)
{
    WORD sub = cpu->reg.a - operand;

    SET_FLAG_ZERO(&cpu->reg, (sub & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg, 1);
    SET_FLAG_HALF_CARRY(&cpu->reg, (cpu->reg.a & 0xF) < (operand & 0xF));
    SET_FLAG_CARRY(&cpu->reg, cpu->reg.a < operand);

    cpu->reg.a = sub & 0xFF;
}

void SUB_A_r8(CPU *cpu, BYTE r)        {SUB_A(cpu,r);}
void SUB_A_n8(CPU *cpu, BYTE val)      {SUB_A(cpu,val);}
void SUB_A_MEM(CPU *cpu, WORD address) {SUB_A(cpu,cpu->memory[address]);}

void INC(CPU *cpu, BYTE *operand)
{
    WORD inc = *operand + 1;
    SET_FLAG_ZERO(&cpu->reg, ((inc & 0xFF) == 0));
    SET_FLAG_SUB(&cpu->reg,0);
    SET_FLAG_HALF_CARRY(&cpu->reg, (((*operand & 0xF) + 1) > 0xF));

    *operand = inc & 0XFF;
}
void INC_r8(CPU *cpu, BYTE *dest)   {INC(cpu, dest);}
void INC_MEM(CPU *cpu, WORD address){INC(cpu, &cpu->memory[address]);}
void INC_SP(CPU *cpu){cpu->reg.SP++;}

void DEC(CPU *cpu, BYTE *operand)
{
    WORD dec = *operand - 1;

    SET_FLAG_ZERO(&cpu->reg, ((dec & 0XFF) == 0));
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg, ((*operand & 0xF) == 0xF));

    *operand = dec & 0XFF;
}

void DEC_r8(CPU *cpu, BYTE *dest)   {DEC(cpu, dest);}
void DEC_MEM(CPU *cpu, WORD address){DEC(cpu, &cpu->memory[address]);}
void DEC_SP(CPU *cpu){cpu->reg.SP--;}

void CP_A_n8(CPU *cpu, BYTE val)
{
    WORD res = cpu->reg.a - val;
    SET_FLAG_ZERO(&cpu->reg,(res & 0xFF) == 0);
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg, (cpu->reg.a & 0xF) < (val & 0xF));
    SET_FLAG_CARRY(&cpu->reg, cpu->reg.a < val);
}
void CP_A_r8(CPU *cpu, BYTE dest)    { CP_A_n8(cpu,dest);}
void CP_A_MEM(CPU *cpu, WORD address) { CP_A_n8(cpu, cpu->memory[address]); }

void AND_n8(CPU* cpu, BYTE val)
{
    cpu->reg.a &= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 1);
    SET_FLAG_CARRY(&cpu->reg, 0);
    

}
void AND_r8(CPU *cpu, BYTE r){AND_n8(cpu,r);}
void AND_MEM(CPU *cpu, WORD address){AND_n8(cpu,cpu->memory[address]);}

void OR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a |= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void OR_r8(CPU *cpu, BYTE r){OR_n8(cpu,r);}
void OR_MEM(CPU *cpu, WORD address){OR_n8(cpu,cpu->memory[address]);}

void XOR_n8(CPU *cpu, BYTE val)
{
    cpu->reg.a ^= val;
    SET_FLAG_ZERO(&cpu->reg, (cpu->reg.a == 0));
    SET_FLAG_SUB(&cpu->reg, 0);
    SET_FLAG_HALF_CARRY(&cpu->reg, 0);
    SET_FLAG_CARRY(&cpu->reg, 0);

}
void XOR_r8(CPU *cpu, BYTE r){XOR_n8(cpu,r);}
void XOR_MEM(CPU *cpu, WORD address){XOR_n8(cpu,cpu->memory[address]);}

void CPL(CPU *cpu)
{
    cpu->reg.a = ~cpu->reg.a;
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg,1);
}
