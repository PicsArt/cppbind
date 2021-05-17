#ifndef __C_HELPERS_H_
#define __C_HELPERS_H_

#include <stdbool.h>

typedef struct _CDataArray{
    void* data;
    long long size;
} CDataArray;

typedef struct _CDataPair{
    void* first;
    void* second;
} CDataPair;

typedef struct _CDataMap{
    void* keys;
    void* values;
    long long size;
} CDataMap;

typedef struct _ErrorObj {
    bool is_err;
    int err_type;
    void * err_ptr;
} ErrorObj;

#endif //__C_HELPERS_H_
