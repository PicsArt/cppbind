#ifndef _C_person_WRAPPER_
#define _C_person_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Person(void* _Nonnull cself);
    void* _Nonnull create_Person(char* _Nonnull name);
    char* _Nonnull _prop_get_Person_fullName(void* _Nonnull cself);

    void _prop_set_Person_setFullName(void* _Nonnull cself, char* _Nonnull val);

#if __cplusplus
}
#endif
#endif /* ifndef _C_person_WRAPPER_ */