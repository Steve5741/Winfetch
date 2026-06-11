
#ifndef WINFETCH_RAM_H
#define WINFETCH_RAM_H

typedef struct {
    double total;
    double free;
} RamInfo;

RamInfo get_ram_info();

#endif //WINFETCH_RAM_H
