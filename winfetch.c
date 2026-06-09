#include "winfetch.h"
#include "lib.h"

void fetch(void) {
    char os[11];
    char gpu[50];
    int ram;

    printf("%s",cpu);
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