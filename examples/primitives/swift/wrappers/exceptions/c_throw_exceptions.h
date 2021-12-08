/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-12:32.
 * Please do not change it manually.
 */

#ifndef _C_throw_exceptions_WRAPPER_
#define _C_throw_exceptions_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_ThrowExc(void* _Nonnull cself);

    void* _Nonnull create_ThrowExc(bool do_throw, ErrorObj* _Nonnull err);
    int _func_ThrowExc_getByKey(CDataMap  m, int  key, ErrorObj* _Nonnull err);
    char* _Nonnull _func_ThrowExc_throwsWithReturnValueString(ErrorObj* _Nonnull err);
    void* _Nonnull _func_ThrowExc_throwsWithReturnValuePtr(ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_ThrowExc_prop(void* _Nonnull cself);

    void _prop_set_ThrowExc_prop(void* _Nonnull cself, char* _Nonnull s);

#if __cplusplus
}
#endif
#endif /* ifndef _C_throw_exceptions_WRAPPER_ */