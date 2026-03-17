#include "cpu.h"

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
