#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>

uint8_t ram[2048];

uint8_t ram_read(uint16_t adress) {
    return ram[adress];
}

void ram_write(uint16_t adress, uint8_t arg) {
    ram[adress] = arg;
}

void ram_garbage() {
    for(int i = 0; i <= 2048; i++) {
        ram[i] = 0xFF;
    };
}