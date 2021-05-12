#ifndef _C_template_methods_WRAPPER_
#define _C_template_methods_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_TemplateMethods(void* _Nonnull cself);
    void* _Nonnull create_TemplateMethods();
    int _func_TemplateMethods_maxInt(void* _Nonnull cself , int arg0, int arg1);
    char* _Nonnull _func_TemplateMethods_maxString(void* _Nonnull cself , char* _Nonnull arg0, char* _Nonnull arg1);
    CDataPair _func_TemplateMethods_makePairProjectProject(void* _Nonnull cself , void* _Nonnull arg0, void* _Nonnull arg1);
    CDataPair _func_TemplateMethods_makePairTaskProject(void* _Nonnull cself , void* _Nonnull arg0, void* _Nonnull arg1);
#if __cplusplus
}
#endif
#endif /* ifndef _C_template_methods_WRAPPER_ */