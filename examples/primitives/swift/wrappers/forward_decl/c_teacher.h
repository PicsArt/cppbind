/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:12.
 * Please do not change it manually.
 */

#ifndef _C_teacher_WRAPPER_
#define _C_teacher_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Teacher(void* _Nonnull cself);

    void* _Nonnull create_Teacher(ErrorObj* _Nonnull err);
    void _func_Teacher_addStudent(void* _Nonnull cself, void* _Nonnull s, ErrorObj* _Nonnull err);
    CDataArray _func_Teacher_students(void* _Nonnull cself, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_teacher_WRAPPER_ */