#ifndef _C_project_WRAPPER_
#define _C_project_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Project(void* _Nonnull cself);
    void* _Nonnull create_Project(char* _Nonnull title);
    char* _Nonnull _prop_get_Project_title(void* _Nonnull cself);
    void _func_Project_addTask(void* _Nonnull cself , void* _Nonnull task);
    CDataArray _func_Project_tasks(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_project_WRAPPER_ */