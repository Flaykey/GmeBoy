#pragma once
#include "cpu.h"

void ADC_A(CPU *cpu, BYTE operand);
void ADC_A_r8(CPU *cpu);
void ADC_A_n8(CPU *cpul);
void ADC_A_MEM(CPU *cpu);

void ADD_A(CPU *cpu, BYTE operand);
void ADD_A_r8(CPU *cpu);
void ADD_A_n8(CPU *cpu);
void ADD_A_MEM(CPU *cpu);