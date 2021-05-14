#ifndef _C_stack_WRAPPER_
#define _C_stack_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_StackProject(void* _Nonnull cself);
    void* _Nonnull create_StackProject();
    void* _Nonnull create_StackProject_1(void* _Nonnull st);
    void _func_StackProject_push(void* _Nonnull cself , void* _Nonnull item);
    void _func_StackProject_pop(void* _Nonnull cself );
    void* _Nonnull _func_StackProject_top(void* _Nonnull cself );
    bool _func_StackProject_empty(void* _Nonnull cself );
    void release_StackRoot(void* _Nonnull cself);
    void* _Nonnull create_StackRoot();
    void* _Nonnull create_StackRoot_1(void* _Nonnull st);
    void _func_StackRoot_push(void* _Nonnull cself , void* _Nonnull item);
    void _func_StackRoot_pop(void* _Nonnull cself );
    void* _Nonnull _func_StackRoot_top(void* _Nonnull cself );
    bool _func_StackRoot_empty(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_stack_WRAPPER_ */