#pragma once
#include<util.h>

typedef struct{
    BYTE a,b,c,d,e,f,g,l;
}Register;


WORD SET_AF(Register& reg);
WORD SET_BC(Register& reg);
WORD SET_DE(Register& reg);
WORD SET_HL(Register& reg);
WORD GET_AF(Register& reg);
WORD GET_BC(Register& reg);
WORD GET_DE(Register& reg);
WORD GET_HL(Register& reg);

