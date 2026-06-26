
#include "PcInfo.h"
#include "../lib.h"

UserInfo Get_User_Name(void) {
    UserInfo result = {0.0,0.0};
    DWORD username_len = UNLEN + 1;
    GetUserName(result.username, &username_len);

    return result;
}

typedef NTSTATUS (WINAPI *RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);
static void get_windows_version(int *major, int *minor, int *build) {
    HMODULE hMod = GetModuleHandleA("ntdll.dll");
    if (hMod) {
        RtlGetVersionPtr pFunc = (RtlGetVersionPtr)GetProcAddress(hMod, "RtlGetVersion");
        if (pFunc) {
            RTL_OSVERSIONINFOW osvi = {0};
            osvi.dwOSVersionInfoSize = sizeof(osvi);
            if (pFunc(&osvi) == 0) {
                *major = osvi.dwMajorVersion;
                *minor = osvi.dwMinorVersion;
                *build = osvi.dwBuildNumber;
                return;
            }
        }
    }
    // Fallback
    *major = 10; *minor = 0; *build = 0;
}

static void get_product_type(char *buffer, size_t size) {
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                      "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                      0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        DWORD bufSize = size;
        if (RegQueryValueExA(hKey, "EditionID", NULL, NULL, (LPBYTE)buffer, &bufSize) == ERROR_SUCCESS) {
            if (strcmp(buffer, "Professional") == 0) {
                strncpy(buffer, "Pro", size);
            }
        } else {
            strncpy(buffer, "Unknown", size);
        }
        RegCloseKey(hKey);
    } else {
        strncpy(buffer, "Unknown", size);
    }
}

OsInfo Get_OS_Info(void) {
    OsInfo result = {0};

    int major = 0, minor = 0, build = 0;
    get_windows_version(&major, &minor, &build);

    result.major_version = major;
    result.minor_version = minor;
    result.build_number = build;

    if (major == 10 && minor == 0) {
        if (build >= 22000) {
            snprintf(result.name, sizeof(result.name), "Windows 11");
        } else {
            snprintf(result.name, sizeof(result.name), "Windows 10");
        }
    } else if (major == 6 && minor == 3) {
        snprintf(result.name, sizeof(result.name), "Windows 8.1");
    } else if (major == 6 && minor == 2) {
        snprintf(result.name, sizeof(result.name), "Windows 8");
    } else if (major == 6 && minor == 1) {
        snprintf(result.name, sizeof(result.name), "Windows 7");
    } else if (major == 6 && minor == 0) {
        snprintf(result.name, sizeof(result.name), "Windows Vista");
    } else if (major == 5 && minor == 1) {
        snprintf(result.name, sizeof(result.name), "Windows XP");
    } else {
        snprintf(result.name, sizeof(result.name), "Windows Unknown");
    }

    get_product_type(result.product_type, sizeof(result.product_type));

    return result;
}