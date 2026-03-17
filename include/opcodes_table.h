#include "addins.h"
#include"andorins.h"
#include "controlins.h"
#include "cpins.h"
#include "incredecreins.h"
#include "ldins.h"
#include "subins.h"
#include "subroutineins.h"

extern void (*Instruction[0x100])(CPU *cpu);

void Assign_ALU();
void Assign_LD();