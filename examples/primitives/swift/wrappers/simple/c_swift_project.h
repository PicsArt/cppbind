/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/11/2022-15:39.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_SIMPLE_C_SWIFT_PROJECT_H_
#define _SWIFT_WRAPPERS_SIMPLE_C_SWIFT_PROJECT_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_Project(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_Project(char* _Nonnull title, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _prop_get_CppbindExample_Project_title(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void _func_CppbindExample_Project_addTask(CppBindCObject cself, CppBindCObject  task, CppBindCObject* _Nonnull cppbind_err);
    CppBindCDataArray _func_CppbindExample_Project_tasks(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    bool _func_CppbindExample_Project_equals(CppBindCObject cself, CppBindCObject  p, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_SIMPLE_C_SWIFT_PROJECT_H_ */
