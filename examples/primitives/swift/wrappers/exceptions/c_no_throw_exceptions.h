/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/28/2022-13:29.
 * Please do not change it manually.
 */

#ifndef _C_no_throw_exceptions_WRAPPER_
#define _C_no_throw_exceptions_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_IegenExceptions_NoThrowExc(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExceptions_NoThrowExc(bool do_throw, IEGenCObject* _Nonnull iegen_err);
    void _func_IegenExceptions_NoThrowExc_noop(IEGenCObject* _Nonnull iegen_err);
    char* _Nonnull _prop_get_IegenExceptions_NoThrowExc_prop(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);

    void _prop_set_IegenExceptions_NoThrowExc_prop(IEGenCObject cself, char* _Nonnull s, IEGenCObject* _Nonnull iegen_err);

#if __cplusplus
}
#endif
#endif /* ifndef _C_no_throw_exceptions_WRAPPER_ */
