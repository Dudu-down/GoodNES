#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stddef.h>
#include"catridge.h"

uint8_t bus_read(uint16_t adress);

void bus_write(uint16_t adress, uint8_t arg);