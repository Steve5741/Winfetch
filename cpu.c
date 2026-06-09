#include "cpu.h"
#include "../lib.h"

char* cpu_name(void) {
    int cpu_info[4];
    static char cpu[49];

    memset(cpu, 0, sizeof(cpu));

    __cpuid(cpu_info,0x80000002);
    memcpy(cpu,cpu_info,16);
    __cpuid(cpu_info,0x80000003);
    memcpy(cpu + 16, cpu_info,16);
    __cpuid(cpu_info,0x80000004);
    memcpy(cpu + 32, cpu_info,16);

    return cpu;
}
