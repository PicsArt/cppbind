#ifndef __C_HELPERS_H_
#define __C_HELPERS_H_


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

#endif //__C_HELPERS_H_
