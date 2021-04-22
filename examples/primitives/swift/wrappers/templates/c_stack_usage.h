#ifndef _C_stack_usage_WRAPPER_
#define _C_stack_usage_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_StackUsage(void* _Nonnull cself);
    void* _Nonnull create_StackUsage();
    void* _Nonnull _func_StackUsage_firstItemOfSpecialized(void* _Nonnull cself , void* _Nonnull p);
    void* _Nonnull _func_StackUsage_firstItemOfTemplateProject(void* _Nonnull cself , void* _Nonnull arg0);
#if __cplusplus
}
#endif
#endif /* ifndef _C_stack_usage_WRAPPER_ */