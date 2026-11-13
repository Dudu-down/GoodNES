#include <stdio.h>
#include <stdlib.h>
#include "catridge.h"
#include "cpu.h"

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
    cpu_init();
    for(int i = 0; i <= 10; i++) {
        cpu_fetch;
    }
    
    exitCatridge();*/


    return 0;




}