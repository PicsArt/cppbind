#ifndef _C_addressable_WRAPPER_
#define _C_addressable_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void* _Nonnull create_AddressableRoot(void* _Nonnull parent, char* _Nonnull name);
    char* _Nonnull _func_AddressableRoot_absPath(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_addressable_WRAPPER_ */