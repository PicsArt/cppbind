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

#ifndef _SWIFT_WRAPPERS_MISC_C_SWIFT_YAML_EXAMPLE_H_
#define _SWIFT_WRAPPERS_MISC_C_SWIFT_YAML_EXAMPLE_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_WithExternalAPIComments(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_WithExternalAPIComments(char* _Nonnull s, CppBindCObject* _Nonnull cppbind_err);
    int _func_CppbindExample_WithExternalAPIComments_retInt(int  n, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _prop_get_CppbindExample_WithExternalAPIComments_str(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    void _prop_set_CppbindExample_WithExternalAPIComments_str(CppBindCObject cself, char* _Nonnull s, CppBindCObject* _Nonnull cppbind_err);

    int _func_CppbindExample_WithExternalAPIComments_maxInt(int  a, int  b, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_WithExternalAPIComments_maxString(char* _Nonnull a, char* _Nonnull b, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_AdderInt(CppBindCObject cself, bool owner);
    int _func_CppbindExample_AdderInt_add(int  a, int  b, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_AdderDouble(CppBindCObject cself, bool owner);
    double _func_CppbindExample_AdderDouble_add(double  a, double  b, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_MISC_C_SWIFT_YAML_EXAMPLE_H_ */
