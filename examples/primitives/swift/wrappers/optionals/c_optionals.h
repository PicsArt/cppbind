/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/26/2021-12:15.
 * Please do not change it manually.
 */

#ifndef _C_optionals_WRAPPER_
#define _C_optionals_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Optionals(CDataObj cself);

    CDataObj create_Optionals();
    CDataObj _func_Optionals_optionalPtrWithNullptrDefault(CDataObj cself, CDataObj  task, ErrorObj* _Nonnull err);
    CDataObj _func_Optionals_optionalPtrWithNullDefault(CDataObj cself, CDataObj  task, ErrorObj* _Nonnull err);
    CDataObj _func_Optionals_optionalFDPtrWithNullptrDefault(CDataObj cself, CDataObj  project, ErrorObj* _Nonnull err);
    CDataObj _func_Optionals_optionalSharedPtrWithNullptrDefault(CDataObj cself, CDataObj  person, ErrorObj* _Nonnull err);
    int _func_Optionals_optionalIntWithDefault(CDataObj cself, int  value, ErrorObj* _Nonnull err);
    long _func_Optionals_optionalLongWithDefault(CDataObj cself, long  value, ErrorObj* _Nonnull err);
    double _func_Optionals_optionalDoubleWithDefault(CDataObj cself, double  value, ErrorObj* _Nonnull err);
    float _func_Optionals_optionalFloatWithDefault(CDataObj cself, float  value, ErrorObj* _Nonnull err);
    bool _func_Optionals_optionalBoolWithDefault(CDataObj cself, bool  value, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Optionals_optionalStringWithDefault(CDataObj cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);
    char* _Nonnull _func_Optionals_optionalStringViewWithDefault(CDataObj cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err);
    const char * _Nonnull _func_Optionals_optionalCharPointerWithDefault(CDataObj cself, const char * _Nonnull optionalStr, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithDefault(CDataObj cself, unsigned int  c, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithDefaultAndFieldPrefix(CDataObj cself, unsigned int  c, ErrorObj* _Nonnull err);
    unsigned int _func_Optionals_optionalEnumWithInternalDefault(CDataObj cself, unsigned int  c, ErrorObj* _Nonnull err);
    CDataObj _func_Optionals_optionalRefWithDefaultComplexValue(CDataObj cself, CDataObj  task, ErrorObj* _Nonnull err);
    CDataObj _func_Optionals_optionalByValWithDefaultComplexValue(CDataObj cself, CDataObj  task, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_optionals_WRAPPER_ */