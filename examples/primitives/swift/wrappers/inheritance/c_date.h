/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:12.
 * Please do not change it manually.
 */

#ifndef _C_date_WRAPPER_
#define _C_date_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Date(void* _Nonnull cself);

    void* _Nonnull create_Date(int d, int m, int y, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Date_value(void* _Nonnull cself, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_Date_date(void* _Nonnull cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_date_WRAPPER_ */