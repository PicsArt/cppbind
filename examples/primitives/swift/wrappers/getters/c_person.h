/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/09/2021-06:13.
 * Please do not change it manually.
 */

#ifndef _C_person_WRAPPER_
#define _C_person_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Person(void* _Nonnull cself);

    void* _Nonnull create_Person(char* _Nonnull name, char* _Nonnull email, int age);
    char* _Nonnull _prop_get_Person_name(void* _Nonnull cself);

    void _prop_set_Person_name(void* _Nonnull cself, char* _Nonnull val);

    char* _Nonnull _prop_get_Person_email(void* _Nonnull cself);
    int _prop_get_Person_age(void* _Nonnull cself);
    void _prop_set_Person_age(void* _Nonnull cself, int age);

#if __cplusplus
}
#endif
#endif /* ifndef _C_person_WRAPPER_ */