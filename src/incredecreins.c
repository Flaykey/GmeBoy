#include"incredecreins.h"


void INC(CPU *cpu, BYTE *operand)
{
    WORD inc = *operand + 1;
    SET_FLAG_ZERO(&cpu->reg, ((inc & 0xFF) == 0));
    SET_FLAG_SUB(&cpu->reg,0);
    SET_FLAG_HALF_CARRY(&cpu->reg, (((*operand & 0xF) + 1) > 0xF));

    *operand = inc & 0XFF;
}
void INC_r8(CPU *cpu){
    BYTE *code = GetRegPointer(cpu,(cpu->current_opcode>>3) & 0x7)  ;
    INC(cpu, code);
}
void INC_MEM(CPU *cpu){INC(cpu, &cpu->memory[GET_HL(&cpu->reg)]);}
void INC_SP(CPU *cpu){cpu->reg.SP++;}

void INC_HL(CPU *cpu)
{
    WORD address = GET_HL(&cpu->reg);
    address++;
    SET_HL(&cpu->reg,address);

}

void DEC(CPU *cpu, BYTE *operand)
{
    WORD dec = *operand - 1;

    SET_FLAG_ZERO(&cpu->reg, ((dec & 0XFF) == 0));
    SET_FLAG_SUB(&cpu->reg,1);
    SET_FLAG_HALF_CARRY(&cpu->reg, ((*operand & 0xF) == 0x0));

    *operand = dec & 0XFF;
}

void DEC_r8(CPU *cpu){
    BYTE *code = GetRegPointer(cpu,cpu->current_opcode>>3  & 0x7 ) ;
    DEC(cpu, code);
}
void DEC_MEM(CPU *cpu){DEC(cpu, &cpu->memory[GET_HL(&cpu->reg)]);}
void DEC_SP(CPU *cpu){cpu->reg.SP--;}

void DEC_HL(CPU *cpu)
{
    WORD address = GET_HL(&cpu->reg);
    address--;
    SET_HL(&cpu->reg,address);

}