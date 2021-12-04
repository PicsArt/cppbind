/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-11:54.
 * Please do not change it manually.
 */

#ifndef _C_std_exc_classes_WRAPPER_
#define _C_std_exc_classes_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_StdException(void* _Nonnull cself);
    const char * _Nonnull _func_StdException_what(void* _Nonnull cself, ErrorObj* _Nonnull err);
    void release_StdLogicError(void* _Nonnull cself);
    void release_StdRuntimeError(void* _Nonnull cself);
    void release_StdDomainError(void* _Nonnull cself);
    void release_StdInvalidArgument(void* _Nonnull cself);
    void release_StdLengthError(void* _Nonnull cself);
    void release_StdOutOfRange(void* _Nonnull cself);
    void release_StdRangeError(void* _Nonnull cself);
    void release_StdOverflowError(void* _Nonnull cself);
    void release_StdUnderflowError(void* _Nonnull cself);
    void release_StdBadAlloc(void* _Nonnull cself);
    void release_StdBadCast(void* _Nonnull cself);
    void release_StdBadTypeId(void* _Nonnull cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_std_exc_classes_WRAPPER_ */