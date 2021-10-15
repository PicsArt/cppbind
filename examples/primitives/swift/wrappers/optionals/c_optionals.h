/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/13/2021-15:20.
 * Please do not change it manually.
 */

#ifndef _C_optionals_WRAPPER_
#define _C_optionals_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Optionals(void* _Nonnull cself);

    void* _Nonnull create_Optionals();

    void* _Nullable _func_Optionals_optionalPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable task, ErrorObj* _Nonnull err);

    void* _Nullable _func_Optionals_optionalPtrWithNullDefault(void* _Nonnull cself, void* _Nullable task, ErrorObj* _Nonnull err);

    void* _Nullable _func_Optionals_optionalFDPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable project, ErrorObj* _Nonnull err);

    void* _Nullable _func_Optionals_optionalSharedPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable person, ErrorObj* _Nonnull err);

    int _func_Optionals_optionalIntWithDefault(void* _Nonnull cself, int  value, ErrorObj* _Nonnull err);

    long _func_Optionals_optionalLongWithDefault(void* _Nonnull cself, long  value, ErrorObj* _Nonnull err);

    double _func_Optionals_optionalDoubleWithDefault(void* _Nonnull cself, double  value, ErrorObj* _Nonnull err);

    float _func_Optionals_optionalFloatWithDefault(void* _Nonnull cself, float  value, ErrorObj* _Nonnull err);

    bool _func_Optionals_optionalBoolWithDefault(void* _Nonnull cself, bool  value, ErrorObj* _Nonnull err);

    char* _Nonnull _func_Optionals_optionalStringWithDefault(void* _Nonnull cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);

    char* _Nonnull _func_Optionals_optionalStringViewWithDefault(void* _Nonnull cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);

    const char * _Nonnull _func_Optionals_optionalCharPointerWithDefault(void* _Nonnull cself, const char * _Nonnull optionalStr, ErrorObj* _Nonnull err);

    unsigned int _func_Optionals_optionalEnumWithDefault(void* _Nonnull cself, unsigned int  c, ErrorObj* _Nonnull err);

    void* _Nonnull _func_Optionals_optionalRefWithDefaultComplexValue(void* _Nonnull cself, void* _Nonnull task, ErrorObj* _Nonnull err);

    void* _Nonnull _func_Optionals_optionalByValWithDefaultComplexValue(void* _Nonnull cself, void* _Nonnull task, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_optionals_WRAPPER_ */