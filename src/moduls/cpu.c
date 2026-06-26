#include "cpu.h"
#include "../lib.h"

CpuInfo Get_Cpu_Info(void) {
    CpuInfo result = {0.0,0.0};

    __cpuid(result.cpu_info,0x80000002);
    memcpy(result.cpu,result.cpu_info,16);
    __cpuid(result.cpu_info,0x80000003);
    memcpy(result.cpu + 16, result.cpu_info,16);
    __cpuid(result.cpu_info,0x80000004);
    memcpy(result.cpu + 32, result.cpu_info,16);

    return result;
}
