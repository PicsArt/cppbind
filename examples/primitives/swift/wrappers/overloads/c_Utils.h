/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

#ifndef _C_Utils_WRAPPER_
#define _C_Utils_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Utils(CObject cself);

    CObject create_Utils(ErrorObj* _Nonnull err);
    int _func_Utils_sum(int  first, int  second, ErrorObj* _Nonnull err);
    float _func_Utils_sum_1(float  first, float  second, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Utils_concatenate(CObject cself, char* _Nonnull first, char* _Nonnull second, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Utils_concatenate_1(CObject cself, char* _Nonnull first, char* _Nonnull second, char* _Nonnull third, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_Utils_WRAPPER_ */