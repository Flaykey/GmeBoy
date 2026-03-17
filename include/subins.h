#include "cpu.h"

void SBC_A(CPU *cpu, BYTE operand);
void SBC_A_r8(CPU *cpu, BYTE r);
void SBC_A_n8(CPU *cpu, BYTE val);
void SBC_A_MEM(CPU *cpu);

void SUB_A(CPU *cpu, BYTE operand);
void SUB_A_r8(CPU *cpu, BYTE r);
void SUB_A_n8(CPU *cpu, BYTE val);
void SUB_A_MEM(CPU *cpu);
