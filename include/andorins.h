#pragma once
#include "cpu.h"

void AND_n8(CPU* cpu, BYTE val);
void AND_r8(CPU* cpu);
void AND_MEM(CPU* cpu);

void OR_n8(CPU* cpu, BYTE val);
void OR_r8(CPU* cpu);
void OR_MEM(CPU* cpu);

void XOR_n8(CPU* cpu, BYTE val);
void XOR_r8(CPU* cpu);
void XOR_MEM(CPU* cpu);

