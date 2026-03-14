#include "cpu.h"

void LD_A_r8(CPU *cpu, BYTE r)
{
    cpu->reg.a = r;
}

void LD_r8_A(CPU *cpu, BYTE *dest)
{
    *dest = cpu->reg.a;
}

void LD_A_MEM(CPU *cpu)
{
    cpu->reg.a = cpu->memory[GET_HL(&cpu->reg)];
}

void LD_r8_n8(CPU *cpu, BYTE *dest, BYTE val)
{
    *dest = val;
}

void LD_r16_n16(CPU *cpu, BYTE *highR, BYTE *LowR, BYTE HighVal, BYTE LowVal)
{
    *highR = HighVal;
    *LowR = LowVal;

}

void LD_MEM_n8(CPU *cpu, BYTE val)
{
    cpu->memory[GET_HL(&cpu->reg)] = val;
    WORD hl = GET_HL(&cpu->reg);
    cpu->memory[hl] = val;
    SET_HL(&cpu->reg, hl + 1);
}

void LD_MEM_r16(CPU *cpu, BYTE highVal, BYTE LowVal)
{
    cpu->memory[GET_HL(&cpu->reg)] = LowVal;
    cpu->memory[GET_HL(&cpu->reg) + 1] = highVal;


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

void SUB_A_r8(CPU *cpu, BYTE r)        {SUB_A(cpu,r);}
void SUB_A_n8(CPU *cpu, BYTE val)      {SUB_A(cpu,val);}
void SUB_A_MEM(CPU *cpu) {SUB_A(cpu,cpu->memory[GET_HL(&cpu->reg)]);}

void INC(CPU *cpu, BYTE *operand)
{
    WORD inc = *operand + 1;
    SET_FLAG_ZERO(&cpu->reg, ((inc & 0xFF) == 0));
    SET_FLAG_SUB(&cpu->reg,0);
    SET_FLAG_HALF_CARRY(&cpu->reg, (((*operand & 0xF) + 1) > 0xF));

    *operand = inc & 0XFF;
}
void INC_r8(CPU *cpu, BYTE *dest)   {INC(cpu, dest);}
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
    SET_FLAG_HALF_CARRY(&cpu->reg, ((*operand & 0xF) == 0xF));

    *operand = dec & 0XFF;
}

void DEC_r8(CPU *cpu, BYTE *dest)   {DEC(cpu, dest);}
void DEC_MEM(CPU *cpu){DEC(cpu, &cpu->memory[GET_HL(&cpu->reg)]);}
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
void CP_A_MEM(CPU *cpu) { CP_A_n8(cpu, cpu->memory[GET_HL(&cpu->reg)]); }

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

int CHECK_cc(CPU *cpu, CONTITION_CODES cc)
{
    switch (cc)
    {
    case Z: return GET_FLAG_ZERO(&cpu->reg);
    case NZ:return !GET_FLAG_ZERO(&cpu->reg);
    case C: return GET_FLAG_CARRY(&cpu->reg);
    case NC:return !GET_FLAG_CARRY(&cpu->reg);
    }

}

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
