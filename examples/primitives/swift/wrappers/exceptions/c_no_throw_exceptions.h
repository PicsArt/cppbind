/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-11:54.
 * Please do not change it manually.
 */

#ifndef _C_no_throw_exceptions_WRAPPER_
#define _C_no_throw_exceptions_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_NoThrowExc(CObject cself, bool owner);

    CObject create_NoThrowExc(bool do_throw, ErrorObj* _Nonnull err);
    void _func_NoThrowExc_noop(ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_NoThrowExc_prop(CObject cself);

    void _prop_set_NoThrowExc_prop(CObject cself, char* _Nonnull s);

#if __cplusplus
}
#endif
#endif /* ifndef _C_no_throw_exceptions_WRAPPER_ */