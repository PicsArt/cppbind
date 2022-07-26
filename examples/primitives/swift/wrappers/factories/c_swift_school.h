/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/18/2022-11:01.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_FACTORIES_C_SWIFT_SCHOOL_H_
#define _SWIFT_WRAPPERS_FACTORIES_C_SWIFT_SCHOOL_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_School(CppBindCObject cself, bool owner);

    CppBindCObject func_CppbindExample_School_create(CppBindCDataArray teachers, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject func_CppbindExample_School_create_1(CppBindCObject* _Nonnull cppbind_err);
    void _func_CppbindExample_School_addTeacher(CppBindCObject cself, CppBindCObject  teacher, CppBindCObject* _Nonnull cppbind_err);
    CppBindCDataArray _prop_get_CppbindExample_School_teachers(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_FACTORIES_C_SWIFT_SCHOOL_H_ */
