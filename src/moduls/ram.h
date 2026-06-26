
#ifndef WINFETCH_RAM_H
#define WINFETCH_RAM_H

typedef struct {
    double total;
    double free;
    double percent;
    double used;
} RamInfo;

RamInfo Get_Ram_Info();

#endif //WINFETCH_RAM_H
