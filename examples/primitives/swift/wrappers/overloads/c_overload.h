#ifndef _C_overload_WRAPPER_
#define _C_overload_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_OverloadedFunctions(void* _Nonnull cself);
    void* _Nonnull create_OverloadedFunctions();
    char* _Nonnull _func_OverloadedFunctions_concatenate(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second);
    char* _Nonnull _func_OverloadedFunctions_concatenate_1(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second, char* _Nonnull third);
#if __cplusplus
}
#endif
#endif /* ifndef _C_overload_WRAPPER_ */