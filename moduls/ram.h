
#ifndef WINFETCH_RAM_H
#define WINFETCH_RAM_H

// Структура для хранения данных о RAM
typedef struct {
    double total;
    double free;
} RamInfo;

// Изменили void на RamInfo
RamInfo get_ram_info();

#endif //WINFETCH_RAM_H
