#include<cpu.h>
#include<ppu.h>
#include<stdio.h>

int main(){
    CPU cpu;
    PPU ppu;
void INC_SP(CPU* cpu);
        BYTE rom[] = {
    0x21, 0x00, 0x80,   // LD HL,0x8000
    0x36, 0xAA, 0x36, 0xAA,  // Row 1
    0x36, 0x55, 0x36, 0x55,  // Row 2
    0x36, 0xAA, 0x36, 0xAA,  // Row 1
    0x36, 0x55, 0x36, 0x55,  // Row 4
    0x36, 0xAA, 0x36, 0xAA,  // Row 1
    0x36, 0x55, 0x36, 0x55,  // Row 6
    0x36, 0xAA, 0x36, 0xAA,  // Row 1
    0x36, 0x55, 0x36, 0x55,  // Row 8
    0x76                     // HALT
};
   cpu.reg.IP = 0x0000;
   void (*instruction[512])(CPU* cpu);
    for(int i = 0; i<=sizeof(rom) / sizeof(rom[0]); i++){
        if(cpu.state == HALTED) break;
        // printf("Current instruction : %x \n" , rom[cpu.reg.IP]);
        switch(rom[cpu.reg.IP]){
                case 0x21:
                        cpu.reg.IP++;
                        BYTE low = rom[cpu.reg.IP];
                        cpu.reg.IP++;
                        BYTE high = rom[cpu.reg.IP];
                        LD_r16_n16(&cpu,&cpu.reg.h,&cpu.reg.l,high,low);
                        break;
                case 0x36:
                        cpu.reg.IP++;
                        LD_MEM_n8(&cpu,rom[cpu.reg.IP]);
                        break;
                case 0x3E:
                        cpu.reg.IP++;
                        LD_A_r8(&cpu,rom[cpu.reg.IP]);
                        break;
                case 0x23:
                        INC_HL(&cpu);
                        break;
                case 0x06:
                        cpu.reg.IP++;
                        LD_r8_n8(&cpu,&cpu.reg.b,rom[cpu.reg.IP]);
                        break;
                case 0x80:	
                        ADD_A_r8(&cpu, cpu.reg.b);
                        break;
                case 0x0E: 
                        cpu.reg.IP++;
                        LD_r8_n8(&cpu,&cpu.reg.c,rom[cpu.reg.IP]);
                        break;
                case 0x81:	
                        ADD_A_r8(&cpu, cpu.reg.c);
                        break;
                case 0x32:	
                        WORD hl = GET_HL(&cpu.reg);
                        cpu.memory[hl] = cpu.reg.a;
                        hl--;
                        SET_HL(&cpu.reg,hl);
                        break;
                case 0xAF:	
                    XOR_r8(&cpu, cpu.reg.a);
                    break;
                case 0x90:	
                        SUB_A_r8(&cpu,cpu.reg.b);
                        break;
                case 0x76:
                        HALT(&cpu);
        }
        // printf("HL: %04X, Memory: %02X\n", GET_HL(&cpu.reg), cpu.memory[GET_HL(&cpu.reg) - 1]);
        cpu.reg.IP++;
    }
    InitWindow(SCREEN_WIDTH*SCALEX, SCREEN_HEIGHT*SCALEY,"GAMEBOY");
    SetTargetFPS(60);

    VramToFrameBuffer(&ppu,&cpu,0x8000);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        DisplayFrameBuffer(&ppu);
        EndDrawing();
    }
    
}