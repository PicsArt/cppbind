/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/25/2022-14:38.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_NULLABLES_C_NULLABLEUTILS_H_
#define _SWIFT_WRAPPERS_NULLABLES_C_NULLABLEUTILS_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExampleNullable_NumInt(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExampleNullable_NumInt(int val_, CppBindCObject* _Nonnull cppbind_err);
    int _prop_get_CppbindExampleNullable_NumInt_value(CppBindCObject cself);
    void release_CppbindExampleNullable_NumDouble(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExampleNullable_NumDouble(double val_, CppBindCObject* _Nonnull cppbind_err);
    double _prop_get_CppbindExampleNullable_NumDouble_value(CppBindCObject cself);
    void release_CppbindExampleNullable_NullableUtils(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExampleNullable_NullableUtils(CppBindCObject num, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExampleNullable_NullableUtils_max(CppBindCObject  first, CppBindCObject  second, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExampleNullable_NullableUtils_max_1(CppBindCObject  first, CppBindCObject  second, CppBindCObject* _Nonnull cppbind_err);
    void _func_CppbindExampleNullable_NullableUtils_checkNonnullArg(CppBindCObject  number, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExampleNullable_NullableUtils_checkNonnullReturn(CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _prop_get_CppbindExampleNullable_NullableUtils_nullable(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    void _prop_set_CppbindExampleNullable_NullableUtils_nullable(CppBindCObject cself, CppBindCObject num, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject _prop_get_CppbindExampleNullable_NullableUtils_nonNull(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    void _prop_set_CppbindExampleNullable_NullableUtils_nonNull(CppBindCObject cself, CppBindCObject num, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject _prop_get_CppbindExampleNullable_NullableUtils_numDouble(CppBindCObject cself);
    void _prop_set_CppbindExampleNullable_NullableUtils_numDouble(CppBindCObject cself, CppBindCObject numDouble);

    CppBindCObject _prop_get_CppbindExampleNullable_NullableUtils_numInt(CppBindCObject cself);
    void _prop_set_CppbindExampleNullable_NullableUtils_numInt(CppBindCObject cself, CppBindCObject numInt);


    const char * _Nullable _func_CppbindExampleNullable_reverseString(const char * _Nullable s, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_NULLABLES_C_NULLABLEUTILS_H_ */
