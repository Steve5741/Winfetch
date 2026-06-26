
#ifndef WINFETCH_USER_H
#define WINFETCH_USER_H

#include "../lib.h"

typedef struct {
    char username[UNLEN + 1];
} UserInfo;
UserInfo Get_User_Name(void);

typedef struct {
    char name[50];
    int major_version;
    int minor_version;
    int build_number;
    char product_type[20];
} OsInfo;
OsInfo Get_OS_Info(void);

#endif //WINFETCH_USER_H
