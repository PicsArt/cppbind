#ifndef _C_teacher_WRAPPER_
#define _C_teacher_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Teacher(void* _Nonnull cself);
    void* _Nonnull create_Teacher();
    void _func_Teacher_addStudent(void* _Nonnull cself , void* _Nonnull s);
    CDataArray _func_Teacher_students(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_teacher_WRAPPER_ */