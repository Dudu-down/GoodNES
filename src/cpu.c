#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "bus.h"
#include"ram"

typedef struct {
    uint8_t a; /*acumulador*/
    uint8_t x; /*indice x*/
    uint8_t y; /*indice y*/
    uint16_t pc; /*program counter*/ /*pc incrementa a cada fetch. leu instrução, pc++, leu um operando, pc++*/
    uint8_t s; /*stack pointer*/
    uint8_t f; /*status flag, preciso mudar para ativar ou desativar cada flag individual*/
} cpu_register;

static cpu_register cpu;
static uint8_t stack_page = 0x01;
static uint8_t ram_page = 0x00;

uint16_t reset_read(){
    return (bus_read(0xFFFD) << 8) + bus_read(0xFFFC); /*ler bit fiddling dps*/

};

void cpu_init(){
    cpu.a = cpu.x = cpu.y = 0;
    cpu.pc = reset_read();
    cpu.s = 0x00 - 3;
    cpu.f = 0;
    ram_garbage();

    printf("%4X", cpu.pc);
    printf("%2X", cpu.s);
};

uint8_t cpu_fetch() {
    uint8_t byte = bus_read(cpu.pc);
    cpu.pc++;
    return byte;
};

/*void cpu_decode(uint8_t opcode) {
    switch (opcode) { entra opcode, destina instrução correta e pc++
        case 
    };
} */




/*começar com modo de enderessamento, ler e entender melhor na documentação.*/

/*Fazer teste e validação do init e primeira instrução*/
