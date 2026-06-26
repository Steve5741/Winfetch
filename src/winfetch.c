#include "winfetch.h"
#include "moduls/cpu.h"
#include "moduls/ram.h"
#include "moduls/gpu.h"
#include "moduls/PcInfo.h"
#include "lib.h"

void fetch(void) {
    RamInfo Ram = Get_Ram_Info();
    GpuInfo Gpu = Get_Gpu_Info();
    CpuInfo Cpu = Get_Cpu_Info();
    UserInfo User = Get_User_Name();
    OsInfo Os = Get_OS_Info();

    printf("os: %s\n", Os);
    printf("user:%s\n------------------------------\n", User.username);
    printf("cpu: %s\n", Cpu.cpu);
    printf("gpu: %s\n", Gpu.name);
    printf("ram: %.2fGB/%.2fGB (%.2f%%)\n",Ram.used, Ram.total, Ram.percent);
    printf("vram: %.0fMB\n", Gpu.vram);
};

void winfetch(char *cmd) {
    if(strcmp(cmd, "winfetch") == 0) {
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