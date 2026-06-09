#include "winfetch.h"
#include "moduls/cpu.h"
#include "moduls/ram.h"
#include "lib.h"

void fetch(void) {
    RamInfo ram = get_ram_info();
    double usedRAM = ram.total - ram.free;
    char os[11];
    char gpu[50];

    printf("%s", cpu_name());
    for (int i; i < 10; i++) {
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