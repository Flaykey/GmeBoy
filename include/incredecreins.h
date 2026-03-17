#pragma once
#include "cpu.h"

void INC(CPU* cpu, BYTE *operand);
void INC_r8(CPU* cpu);
void INC_MEM(CPU* cpu);
void INC_SP(CPU* cpu);
void INC_HL(CPU* cpu);


void DEC(CPU* cpu, BYTE *operand);
void DEC_r8(CPU* cpu);
void DEC_MEM(CPU* cpu);
void DEC_SP(CPU* cpu);
void DEC_HL(CPU *cpu);