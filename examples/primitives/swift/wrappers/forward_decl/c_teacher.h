/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/28/2022-13:29.
 * Please do not change it manually.
 */

#ifndef _C_teacher_WRAPPER_
#define _C_teacher_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_IegenExample_Teacher(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExample_Teacher(IEGenCObject* _Nonnull iegen_err);
    void _func_IegenExample_Teacher_addStudent(IEGenCObject cself, IEGenCObject  s, IEGenCObject* _Nonnull iegen_err);
    IEGenCDataArray _func_IegenExample_Teacher_students(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_teacher_WRAPPER_ */
