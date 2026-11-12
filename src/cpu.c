#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "bus.h"

typedef struct {
    uint8_t a; /*acumulador*/
    uint8_t x; /*indice x*/
    uint8_t y; /*indice y*/
    uint16_t pc; /*program counter*/
    uint8_t s; /*stack pointer*/
    uint8_t f; /*status flag, preciso mudar para ativar ou desativar cada flag individual*/
} cpu_register;

static cpu_register cpu;
static status_offset = 0x0100;

uint16_t reset_read(){
    return (bus_read_prg(0xFFFD) << 8) + bus_read_prg(0xFFFC);

}

void cpu_init(){
    cpu.a = cpu.x = cpu.y = 0;
    cpu.pc = reset_read;
    cpu.s = 0x00 - 3;
    cpu.f = 0;
}

/*Fazer teste e validação do init e primeira instrução*/
