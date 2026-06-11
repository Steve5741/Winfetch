#include "gpu.h"
#include "../lib.h"

char* gpu_name(void) {
    IDXGIFactory* pFactory = NULL;
    if (FAILED(CreateDXGIFactory(&IID_IDXGIFactory, (void**)&pFactory))) {

        return NULL;
    }

    IDXGIAdapter* pAdapter = NULL;
    if (pFactory->lpVtbl->EnumAdapters(pFactory, 0, &pAdapter) == DXGI_ERROR_NOT_FOUND) {
        pFactory->lpVtbl->Release(pFactory);
        return NULL;
    }

    DXGI_ADAPTER_DESC desc;
    pAdapter->lpVtbl->GetDesc(pAdapter, &desc);

    char* gpu_string = (char*)malloc(128 * sizeof(char));
    if (gpu_string != NULL) {
        WideCharToMultiByte(CP_ACP, 0, desc.Description, -1, gpu_string, 128, NULL, NULL);
    }
    pAdapter->lpVtbl->Release(pAdapter);
    pFactory->lpVtbl->Release(pFactory);

    return gpu_string; 
}
