#include "ppu.h"

void VramToFrameBuffer(PPU *ppu, CPU *cpu, WORD address)
{
    for(int tile_y = 0; tile_y < SCREEN_HEIGHT / 8; tile_y++){
        for(int tile_x = 0; tile_x < SCREEN_WIDTH / 8; tile_x++){
            for(int row = 0; row < 8; row++){
                BYTE LOW  = cpu->memory[address++];
                BYTE HIGH = cpu->memory[address++];
                for(int bit = 7; bit >= 0; bit--){
                    BYTE color = ((HIGH >> bit) & 1) << 1 | ((LOW >> bit) & 1);
                    // printf("%x ",color);
                    int pixel_x = tile_x * 8 + (7 - bit);
                    int pixel_y = tile_y * 8 + row;
                    ppu->FrameBuffer[pixel_x][pixel_y] = color;
                }
            }

        }

    }
}

void DisplayFrameBuffer(PPU *ppu)
{
    for(int i = 0; i< SCREEN_WIDTH; i++){
        for(int j = 0; j< SCREEN_HEIGHT; j++){
            switch (ppu->FrameBuffer[i][j])
            {
            case GWHITE:
                DrawPixel(i,j,WHITE);
                break;
            case GLIGHTGRAY:
                DrawPixel(i,j,LIGHTGRAY);
                break;
            case GDARKGRAY:
                DrawPixel(i,j,DARKGRAY);
                break;
            case GBLACK:
                DrawPixel(i,j,BLACK);
                break;
            default:
                break;
            }
        }
    }
}