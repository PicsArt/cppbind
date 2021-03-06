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

#ifndef _SWIFT_WRAPPERS_OVERLOADS_C_SWIFT_EMPLOYEE_H_
#define _SWIFT_WRAPPERS_OVERLOADS_C_SWIFT_EMPLOYEE_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_Employee(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_Employee(char* _Nonnull name, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_Employee_1(int age, char* _Nonnull email, CppBindCObject* _Nonnull cppbind_err);
    void _func_CppbindExample_Employee_setData(CppBindCObject cself, char* _Nonnull name, int  age, char* _Nonnull email, CppBindCObject* _Nonnull cppbind_err);
    void _func_CppbindExample_Employee_setData_1(CppBindCObject cself, int  age, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _prop_get_CppbindExample_Employee_name(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _prop_get_CppbindExample_Employee_email(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    int _prop_get_CppbindExample_Employee_age(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_OVERLOADS_C_SWIFT_EMPLOYEE_H_ */
