#pragma once
#include "cpu.h"

void ADC_A(CPU *cpu, BYTE operand);
void ADC_A_r8(CPU *cpu, BYTE r);
void ADC_A_n8(CPU *cpu, BYTE val);
void ADC_A_MEM(CPU *cpu);

void ADD_A(CPU *cpu, BYTE operand);
void ADD_A_r8(CPU *cpu, BYTE r);
void ADD_A_n8(CPU *cpu, BYTE val);
void ADD_A_MEM(CPU *cpu);