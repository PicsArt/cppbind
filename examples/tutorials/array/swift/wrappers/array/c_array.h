/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/23/2022-09:36.
 * Please do not change it manually.
 */

#ifndef _C_array_WRAPPER_
#define _C_array_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Cppbind_Array(CppBindCObject cself, bool owner);

    CppBindCObject create_Cppbind_Array(CppBindCObject* _Nonnull cppbind_err);
    int _func_Cppbind_Array_front(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    int _func_Cppbind_Array_back(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void _func_Cppbind_Array_push_back(CppBindCObject cself, int  element, CppBindCObject* _Nonnull cppbind_err);
    int _prop_get_Cppbind_Array_size(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    bool _prop_get_Cppbind_Array_empty(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);


    int _func_Cppbind_Array__getitem_(CppBindCObject cself, int  i);


    void _func_Cppbind_Array__setitem_(CppBindCObject cself, int i, int value);
    int _func_Cppbind_Array_at(CppBindCObject cself, int  i, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_array_WRAPPER_ */
