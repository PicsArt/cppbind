#ifndef _C_object_WRAPPER_
#define _C_object_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Object(void* _Nonnull cself);
    char* _Nonnull _func_Object_toString(void* _Nonnull cself );
    char* _Nonnull _func_Object_className(void* _Nonnull cself );
    bool _func_Object_equals(void* _Nonnull cself , void* _Nonnull other);
    unsigned long _func_Object_hash(void* _Nonnull cself );
    char* _Nonnull _func_Object_debugInfo(void* _Nonnull cself );
    unsigned long _func_Object_bytesCount(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_object_WRAPPER_ */