/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

#ifndef _C_optionals_WRAPPER_
#define _C_optionals_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Optionals(CObject cself);

    CObject create_Optionals(ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalPtrWithNullptrDefault(CObject cself, CObject  task, ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalPtrWithNullDefault(CObject cself, CObject  task, ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalFDPtrWithNullptrDefault(CObject cself, CObject  project, ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalSharedPtrWithNullptrDefault(CObject cself, CObject  person, ErrorObj* _Nonnull err);
    int _func_Optionals_optionalIntWithDefault(CObject cself, int  value, ErrorObj* _Nonnull err);
    long _func_Optionals_optionalLongWithDefault(CObject cself, long  value, ErrorObj* _Nonnull err);
    double _func_Optionals_optionalDoubleWithDefault(CObject cself, double  value, ErrorObj* _Nonnull err);
    float _func_Optionals_optionalFloatWithDefault(CObject cself, float  value, ErrorObj* _Nonnull err);
    bool _func_Optionals_optionalBoolWithDefault(CObject cself, bool  value, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Optionals_optionalStringWithDefault(CObject cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Optionals_optionalStringViewWithDefault(CObject cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);
    const char * _Nonnull _func_Optionals_optionalCharPointerWithDefault(CObject cself, const char * _Nonnull optionalStr, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithDefault(CObject cself, unsigned int  c, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithDefaultAndFieldPrefix(CObject cself, unsigned int  c, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithInternalDefault(CObject cself, unsigned int  c, ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalRefWithDefaultComplexValue(CObject cself, CObject  task, ErrorObj* _Nonnull err);
    CObject _func_Optionals_optionalByValWithDefaultComplexValue(CObject cself, CObject  task, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_optionals_WRAPPER_ */