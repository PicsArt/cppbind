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

#ifndef _C_std_exc_classes_WRAPPER_
#define _C_std_exc_classes_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_StdException(CObject cself, bool owner);
    const char * _Nonnull _func_StdException_what(CObject cself, ErrorObj* _Nonnull err);
    void release_StdLogicError(CObject cself, bool owner);
    void release_StdRuntimeError(CObject cself, bool owner);
    void release_StdDomainError(CObject cself, bool owner);
    void release_StdInvalidArgument(CObject cself, bool owner);
    void release_StdLengthError(CObject cself, bool owner);
    void release_StdOutOfRange(CObject cself, bool owner);
    void release_StdRangeError(CObject cself, bool owner);
    void release_StdOverflowError(CObject cself, bool owner);
    void release_StdUnderflowError(CObject cself, bool owner);
    void release_StdBadAlloc(CObject cself, bool owner);
    void release_StdBadCast(CObject cself, bool owner);
    void release_StdBadTypeId(CObject cself, bool owner);
#if __cplusplus
}
#endif
#endif /* ifndef _C_std_exc_classes_WRAPPER_ */