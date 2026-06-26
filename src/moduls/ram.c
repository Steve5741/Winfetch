
#include "ram.h"
#include "../lib.h"

RamInfo Get_Ram_Info() {
    RamInfo result = {0.0, 0.0, 0.0, 0.0};

    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memInfo)) {
        result.total = (double)memInfo.ullTotalPhys / (1024 * 1024 * 1024);
        result.free = (double)memInfo.ullAvailPhys / (1024 * 1024 * 1024);
        result.used = result.total - result.free;
        result.percent = (result.used / result.total) * 100.0;
    }
    return result;
}
