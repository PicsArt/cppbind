/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-12:32.
 * Please do not change it manually.
 */

#ifndef _C_employee_WRAPPER_
#define _C_employee_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Employee(void* _Nonnull cself);

    void* _Nonnull create_Employee(char* _Nonnull name, ErrorObj* _Nonnull err);

    void* _Nonnull create_Employee_1(int age, char* _Nonnull email, ErrorObj* _Nonnull err);
    void _func_Employee_setData(void* _Nonnull cself, char* _Nonnull name, int  age, char* _Nonnull email, ErrorObj* _Nonnull err);
    void _func_Employee_setData_1(void* _Nonnull cself, int  age, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_Employee_name(void* _Nonnull cself);
    char* _Nonnull _prop_get_Employee_email(void* _Nonnull cself);
    int _prop_get_Employee_age(void* _Nonnull cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_employee_WRAPPER_ */