#include "opcodes_table.h"

void Assign_ALU()
{
    for(int i = 0; i < 8; i++)
    {
        Instruction[0x80 + i] = ADD_A_r8;
        Instruction[0x88 + i] = ADC_A_r8;
        Instruction[0x90 + i] = SUB_A_r8;
        Instruction[0x98 + i] = SBC_A_r8;

        Instruction[0xA0 + i] = AND_r8;
        Instruction[0xA8 + i] = XOR_r8;
        Instruction[0xB0 + i] = OR_r8;
        Instruction[0xB8 + i] = CP_A_r8;
    }
}

void Assign_LD()
{
    BYTE address = 0x40;
    for(int i = 0; i < 64; i++,address++){
        if(address == 0x76)
            Instruction[address] = HALT;
        else if(address >= 0x70 && address <= 0x77)
            Instruction[address] = LD_MEM_r8;
        else
            Instruction[address] = LD_r8_r8; 
    }

    address = 0x06;
    for(int i = 0; i < 8; i++,address+= 0x08){
         Instruction[address] = LD_r8_n8; 
    }

}


void Assign_INC_DEC(){
    for(int i = 0; i < 8; i++){
        Instruction[0x04 + 8*i] = INC_r8;
        Instruction[0x05 + 8*i] = DEC_r8;
    }
}