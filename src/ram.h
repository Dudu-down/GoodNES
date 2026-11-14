#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>

uint8_t ram_read(uint16_t adress);

void ram_write(uint16_t adress, uint8_t arg);

void ram_garbage();