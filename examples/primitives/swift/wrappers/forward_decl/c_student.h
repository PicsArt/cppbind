#ifndef _C_student_WRAPPER_
#define _C_student_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Student(void* _Nonnull cself);
    void* _Nonnull create_Student();
    void _func_Student_addTeacher(void* _Nonnull cself , void* _Nonnull t);
    CDataArray _func_Student_teachers(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_student_WRAPPER_ */