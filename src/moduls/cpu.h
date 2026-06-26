
#ifndef WINFETCH_CPU_H
#define WINFETCH_CPU_H

typedef struct {
    int cpu_info[4];
    char cpu[49];
} CpuInfo;
CpuInfo Get_Cpu_Info(void);

#endif //WINFETCH_CPU_H
