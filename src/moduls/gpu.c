#include "gpu.h"
#include "../lib.h"

GpuInfo Get_Gpu_Info(void) {
    GpuInfo result = {0.0, 0.0};
    IDXGIFactory* pFactory = NULL;
    if (FAILED(CreateDXGIFactory(&IID_IDXGIFactory, (void**)&pFactory))) {
        return result;
    }

    IDXGIAdapter* pAdapter = NULL;
    if (pFactory->lpVtbl->EnumAdapters(pFactory, 0, &pAdapter) == DXGI_ERROR_NOT_FOUND) {
        pFactory->lpVtbl->Release(pFactory);
        return result;
    }

    DXGI_ADAPTER_DESC desc;
    pAdapter->lpVtbl->GetDesc(pAdapter, &desc);

    WideCharToMultiByte(CP_ACP, 0, desc.Description, -1, result.name, 128, NULL, NULL);

    result.vram = (double)desc.DedicatedVideoMemory / (1024 * 1024);

    pAdapter->lpVtbl->Release(pAdapter);
    pFactory->lpVtbl->Release(pFactory);

    return result;
}