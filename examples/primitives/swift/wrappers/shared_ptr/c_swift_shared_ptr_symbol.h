/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:05.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_SHARED_PTR_C_SWIFT_SHARED_PTR_SYMBOL_H_
#define _SWIFT_WRAPPERS_SHARED_PTR_C_SWIFT_SHARED_PTR_SYMBOL_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_SignSharedImpl(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_SignShared(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_SignShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_TextShared(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_TextShared(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_TextShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_DigitShared(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_DigitShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_SymbolUsageShared(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_SymbolUsageShared(CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_SymbolUsageShared_1(CppBindCObject d, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_SymbolUsageShared_getTextType(CppBindCObject cself, CppBindCObject  t, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_SymbolUsageShared_getSignType(CppBindCObject cself, CppBindCObject  s, CppBindCObject* _Nonnull cppbind_err);
    int _func_CppbindExample_SymbolUsageShared_getTextId(CppBindCObject cself, CppBindCObject  t, CppBindCObject* _Nonnull cppbind_err);
    int _func_CppbindExample_SymbolUsageShared_getSignId(CppBindCObject cself, CppBindCObject  s, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_SymbolUsageShared_getTextPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_SymbolUsageShared_getSignPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_SHARED_PTR_C_SWIFT_SHARED_PTR_SYMBOL_H_ */