#pragma once
#include<stdio.h>
#include"cpu.h"
#include"raylib.h"
#define SCREEN_WIDTH 144
#define SCREEN_HEIGHT 160
#define SCALEX 16
#define SCALEY 9

typedef enum{
    GWHITE,
    GLIGHTGRAY,
    GDARKGRAY,
    GBLACK
}GAMEBOYCOLOR;

typedef struct{
    GAMEBOYCOLOR FrameBuffer[SCREEN_WIDTH][SCREEN_HEIGHT];
}PPU;

void VramToFrameBuffer(PPU* ppu, CPU* cpu, WORD address);
void DisplayFrameBuffer(PPU* ppu);

