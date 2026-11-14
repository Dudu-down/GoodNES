#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include"catridge.h"
#include"ram"

/*uma função le todos os endereços, e separa por faixa. cpu nao conhesce dispositivos, so endereços*/
/*$8000-$FFFF é o mapper, falta ele fazer as distinções dele ainda*/
uint8_t bus_read(uint16_t adress) {
    if (adress >= 0x8000) {
        return mapper_read_prg(adress);
    };

    if(adress <= 0x07FF) {
        return ram_read(adress);
    };

}

void bus_write(uint16_t adress, uint8_t arg) {
    if (adress >= 0x8000) {
        mapper_write_prg(adress, arg);
    };

    if (adress <= 0x07FF) {
        ram_write(adress, arg);
    };
}