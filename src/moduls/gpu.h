
#ifndef WINFETCH_GPU_H
#define WINFETCH_GPU_H

typedef struct {
    char name[128];
    double vram;
} GpuInfo;
GpuInfo Get_Gpu_Info(void);

#endif //WINFETCH_GPU_H
