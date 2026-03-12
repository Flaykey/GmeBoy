#pragma once
#include<util.h>

typedef struct{
    BYTE a , b , c , d , e , f , h , l;
    WORD SP , IP;
}Register;

typedef struct{
    Register reg;
    BYTE memory[0xFFFF];
}CPU;



#define SET_AF(reg, val) do { (reg)->a = (val) >> 8; (reg)->f = (val) & 0xF0; } while(0)
#define SET_BC(reg, val) do { (reg)->b = (val) >> 8; (reg)->c = (val) & 0xFF; } while(0)
#define SET_DE(reg, val) do { (reg)->d = (val) >> 8; (reg)->e = (val) & 0xFF; } while(0)
#define SET_HL(reg, val) do { (reg)->h = (val) >> 8; (reg)->l = (val) & 0xFF; } while(0)

#define GET_AF(reg) (((WORD)(reg)->a << 8 )| ((reg)->f))
#define GET_BC(reg) (((WORD)(reg)->b << 8 )| ((reg)->c))
#define GET_DE(reg) (((WORD)(reg)->d << 8 )| ((reg)->e))
#define GET_HL(reg) (((WORD)(reg)->h << 8 )| ((reg)->l))

#define SET_FLAG_ZERO(reg,val)          do{ ((reg)->f = (((reg)->f & ~(1 << 7) )|((val & 1) << 7))) } while(0)
#define SET_FLAG_SUB(reg,val)           do{ ((reg)->f = (((reg)->f & ~(1 << 6) )|((val & 1) << 6))) } while(0)
#define SET_FLAG_HALF_CARRY(reg,val)    do{ ((reg)->f = (((reg)->f & ~(1 << 5) )|((val & 1) << 5))) } while(0)
#define SET_FLAG_CARRY(reg,val)         do{ ((reg)->f = (((reg)->f & ~(1 << 4) )|((val & 1) << 4))) } while(0)

#define GET_FLAG_ZERO(reg)        (((reg)->f >> 7) & 1)
#define GET_FLAG_SUB(reg)         (((reg)->f >> 6) & 1)
#define GET_FLAG_HALF_CARRY(reg)  (((reg)->f >> 5) & 1)
#define GET_FLAG_CARRY(reg)       (((reg)->f >> 4) & 1)

//Load and store Instructions
void LD_A_r8(CPU *cpu,BYTE r);
void LD_r8_A(CPU *cpu,BYTE *dest);
void LD_A_MEM(CPU *cpu, WORD address);
void LD_r8(CPU *cpu, BYTE *dest, BYTE val);

//arithmeticinstruction 8-bit

//Increment and decrement instructions

// compare instructions

// 8-bit bitwise instructions

//control instructions

//stack operations