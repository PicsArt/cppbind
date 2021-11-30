/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 *
 * This file is generated by iegen on 06/23/2021-14:46.
 * Please do not change it manually.
 */

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

typedef struct _ErrorObj {
    int err_type;
    void * err_ptr;
} ErrorObj;

typedef struct _CDataObj {
    int index;
    void* ptr;
} CDataObj;


#endif //__C_HELPERS_H_
