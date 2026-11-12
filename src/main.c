#include <stdio.h>
#include <stdlib.h>
#include "catridge.h"

int main(int argc, char *argv[]){
    

    if(argc < 2) {
        printf("uso: ./godNES rom.nes");        
        return 1;
    }

    FILE *rom = fopen(argv[1], "rb");
    if(!rom) {
        perror("fopen");
        return 1;
    }

    nes_header h = parser_header(rom);
    printf("PRG_BANKS: %ld; CRH_BANKS %ld; Mapper_id %d; mirror: %d\n", h.PRG_BANKS, h.CHR_BANKS, h.mapper, h.mirror);
    InitCatridge(h, rom);
    uint8_t reset1 = mapper_read_prg(0xFFFC);
    uint8_t reset2 = mapper_read_prg(0xFFFD);
    uint8_t teste = mapper_read_prg(0x8500);
    printf("%02X%02X\n", reset2, reset1);
    printf("%d\n", teste);
    mapper_write_prg(0x8000, 5);
    teste = mapper_read_prg(0x8500);
    printf("%d\n", teste);
    exitCatridge();
    return 0;




}