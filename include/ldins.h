#include"cpu.h"


void LD_A_r8(CPU *cpu,BYTE r);
void LD_r8_A(CPU *cpu,BYTE *dest);
void LD_A_MEM(CPU *cpu);
void LD_r8_n8(CPU *cpu, BYTE *dest, BYTE val);
void LD_r16_n16(CPU *cpu, BYTE *highR, BYTE *LowR, BYTE highVal, BYTE LowVal);
void LD_MEM_n8(CPU *cpu, BYTE val);
void LD_MEM_r16(CPU *cpu, BYTE highVal, BYTE LowVal);