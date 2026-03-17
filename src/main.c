#include<cpu.h>
#include<ppu.h>
#include<stdio.h>
#include<string.h>
#include"opcodes_table.h"
int main(){
        CPU cpu;
        PPU ppu;
        void INC_SP(CPU* cpu);
        BYTE rom[30] = {
    // LD r8,r8
    0x40,             // LD B,B (just moves itself, safe)
    0x41,             // LD B,C
    0x42,             // LD B,D
    0x43,             // LD B,E
    0x44,             // LD B,H
    0x45,             // LD B,L
    0x47,             // LD B,A
    0x78,             // LD A,B
    0x79,             // LD A,C
    0x7C,             // LD A,H

    // ADD A,r8
    0x80,             // ADD A,B
    0x81,             // ADD A,C
    0x82,             // ADD A,D
    0x83,             // ADD A,E
    0x84,             // ADD A,H
    0x85,             // ADD A,L
    0x87,             // ADD A,A

    // ADC A,r8
    0x88,             // ADC A,B
    0x89,             // ADC A,C
    0x8F,             // ADC A,A

    // SUB A,r8
    0x90,             // SUB A,B
    0x91,             // SUB A,C
    0x97,             // SUB A,A

    // SBC A,r8
    0x98,             // SBC A,B
    0x99,             // SBC A,C
    0x9F,             // SBC A,A

    // AND A,r8
    0xA0,             // AND B
    0xA1,             // AND C
    0xA7,             // AND A
    0x76
};      
        Load_All_Instructions();
        //load rom into ram todo:
        memcpy(&cpu.memory[0x0000], rom, sizeof(rom));
        cpu.reg.IP = 0x0000;
        VramToFrameBuffer(&ppu,&cpu,0x8000);
        InitWindow(100,100,"HELLO");
        while (!WindowShouldClose())
        {
                while(cpu.state != HALTED){
                BYTE opcode = cpu.memory[cpu.reg.IP++];
                cpu.current_opcode = opcode;
                printf("%x \n", cpu.current_opcode);
                Instruction[opcode](&cpu);
                if(cpu.state == HALTED) printf("cpu has halted!!!!\n");
                }
                BeginDrawing();
                DisplayFrameBuffer(&ppu);
                EndDrawing();
        }   
    
}