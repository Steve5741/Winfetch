#include "winfetch.h"
#include "moduls/cpu.h"
#include "moduls/ram.h"
#include "moduls/gpu.h"
#include "lib.h"

void fetch(void) {
    char os[11];
    char gpu[50];

    printf("%s\n", cpu_name());
    printf("%s\n", gpu_name());
    while (true) {
        Sleep(1000);
        RamInfo ram = get_ram_info();
        double usedRAM = ram.total - ram.free;
        printf("ram:%.2fGB/%.2fGB\n", usedRAM, ram.total);
    }
};

void winfetch(char *cmd) {
    if(strcmp(cmd, "winfetch") == 0) {
        printf("debug\n");
        fetch();
    }else {
        printf("try again\n");
        prompt();
    }
}

void prompt(void) {
    char cmd[255];
    scanf("%s", cmd);
    winfetch(cmd);
}