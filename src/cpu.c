#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "bus.h"

typedef struct {
    uint8_t a; /*acumulador*/
    uint8_t x; /*indice x*/
    uint8_t y; /*indice y*/
    uint16_t pc; /*program counter*/ /*pc incrementa a cada fetch. leu instrução, pc++, leu um operando, pc++*/
    uint8_t s; /*stack pointer*/
    uint8_t f; /*status flag, preciso mudar para ativar ou desativar cada flag individual*/
} cpu_register;

static cpu_register cpu;
static status_offset = 0x0100; /*status ou stack?*/

uint16_t reset_read(){
    return (bus_read(0xFFFD) << 8) | bus_read(0xFFFC); /*ler bit fiddling dps*/

}

void cpu_init(){
    cpu.a = cpu.x = cpu.y = 0;
    cpu.pc = reset_read;
    cpu.s = 0x00 - 3;
    cpu.f = 0;
}

uint8_t cpu_fetch(uint16_t adress) {
    return bus_read(adress);
}

void cpu_decode(uint8_t opcode) {
    switch (opcode) { /*entra opcode, destina instrução correta e pc++*/
        case 
    }
}

/*começar com modo de enderessamento, ler e entender melhor na documentação.*/

/*Fazer teste e validação do init e primeira instrução*/
