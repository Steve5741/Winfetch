
#include "ram.h"
#include "../lib.h"

RamInfo get_ram_info() {
    RamInfo result = {0.0, 0.0};

    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memInfo)) {
        result.total = (double)memInfo.ullTotalPhys / (1024 * 1024 * 1024);
        result.free = (double)memInfo.ullAvailPhys / (1024 * 1024 * 1024);
    }
    return result;
}
