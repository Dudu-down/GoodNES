#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>

typedef struct{
   size_t PRG_BANKS;
   size_t CHR_BANKS;
   uint8_t mapper;
   uint8_t mirror;
} nes_header;

nes_header parser_header (FILE *rom);

void InitCatridge(nes_header header, FILE *rom);

void exitCatridge();

uint8_t mapper_read_prg (uint16_t adress);

void mapper_write_prg (uint16_t adress, uint8_t val);