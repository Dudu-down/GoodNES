#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "catridge.h"

#define PRG_OFFSET 0x8000

/*Modularização dos mapper é feita por ponteiros para funções!!!!*/


uint8_t header[16];


    static uint8_t *prg_rom;
    static uint8_t *chr_rom;
    static uint8_t bank_atual = 0;
    static uint8_t num_banks = 0;


/*explicação sobre mascara> onde tem 1, passa, onde tem 0, vira 0*/


nes_header parser_header (FILE *rom) {
    size_t n;
    n = fread(header, 1, sizeof header, rom);
    if (ferror(rom)) {
        perror("ferror");
        exit(1);
    }

    if (n < sizeof header) {
        printf("header incomplete");
        exit(1);
    }

    nes_header h = {0};
    h.PRG_BANKS = header[4];
    h.CHR_BANKS = header[5];
    h.mapper = (header[7] & 0xF0) | (header[6] >> 4);  /*mascara para pegar o o upper nybble da flag 7 e juntar com o upper nybble da flag 6 que esta sendo passado para a posição de lower */
    h.mirror = header[6] & 0x01;
    num_banks = h.PRG_BANKS;
    printf("%d\n", num_banks);
    return h;
}

void InitCatridge(nes_header header, FILE *rom){
    prg_rom = malloc(header.PRG_BANKS*0x4000);
    fread(prg_rom, 1, header.PRG_BANKS*0x4000, rom);
    chr_rom = malloc(header.CHR_BANKS*0x2000);
    fread(chr_rom, 1, header.CHR_BANKS*0x2000, rom);
    bank_atual = 0;

    /*log*/
    size_t prg_size = header.PRG_BANKS*0x4000;
    size_t chr_size = header.CHR_BANKS*0x2000;
    printf("prg: %ld, chr: %ld\n", prg_size, chr_size);
    
}

void exitCatridge() {
    free(prg_rom);
    free(chr_rom);
}

uint8_t mapper_read_prg (uint16_t adress) {
    if (adress < 0xC000){ /*usando UxROM como exemplo primario, $8000-$BFFF > banco mutavel; $C000-$FFFF > banco fixo(ultimpo banco da ROM). Os bancos contem 16kB cada*/
        return prg_rom[bank_atual * 0x4000 +(adress-PRG_OFFSET)];}
    return prg_rom[(num_banks - 1) * 0x4000 + (adress-0xC000)];

}

void mapper_write_prg (uint16_t adress, uint8_t arg) {
    if (adress >= 0x8000) {
        bank_atual = val;
        printf("%d\n", bank_atual);
    };
}
