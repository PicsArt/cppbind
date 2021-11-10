/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/09/2021-11:44.
 * Please do not change it manually.
 */

#ifndef _C_student_WRAPPER_
#define _C_student_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Student(void* _Nonnull cself);

    void* _Nonnull create_Student(char* _Nonnull st_name);

    void* _Nonnull create_Student_1(CDataArray teachers);
    void _func_Student_addTeacher(void* _Nonnull cself, void* _Nonnull t, ErrorObj* _Nonnull err);
    CDataArray _func_Student_teachers(void* _Nonnull cself, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_Student_name(void* _Nonnull cself);
    void _prop_set_Student_name(void* _Nonnull cself, char* _Nonnull name);

#if __cplusplus
}
#endif
#endif /* ifndef _C_student_WRAPPER_ */