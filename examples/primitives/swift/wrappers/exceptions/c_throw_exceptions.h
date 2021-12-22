/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:26.
 * Please do not change it manually.
 */

#ifndef _C_throw_exceptions_WRAPPER_
#define _C_throw_exceptions_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_ThrowExc(CObject cself, bool owner);

    CObject create_ThrowExc(bool do_throw, ErrorObj* _Nonnull err);
    int _func_ThrowExc_getByKey(CDataMap  m, int  key, ErrorObj* _Nonnull err);
    char* _Nonnull _func_ThrowExc_throwsWithReturnValueString(ErrorObj* _Nonnull err);
    CObject _func_ThrowExc_throwsWithReturnValuePtr(ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_ThrowExc_prop(CObject cself);

    void _prop_set_ThrowExc_prop(CObject cself, char* _Nonnull s);

#if __cplusplus
}
#endif
#endif /* ifndef _C_throw_exceptions_WRAPPER_ */
