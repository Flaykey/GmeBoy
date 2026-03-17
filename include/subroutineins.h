#include "cpu.h"

void CALL_n16(CPU* cpu, WORD address);
void CALL_cc_n16(CPU* cpu, CONTITION_CODES cc, WORD address);
void JP_MEM(CPU* cpu);
void JP_n16(CPU* cpu, WORD address);
void JP_cc_n16(CPU* cpu, CONTITION_CODES cc, WORD address);

void RET(CPU *cpu);
void RET_cc(CPU *cpu, CONTITION_CODES cc);
