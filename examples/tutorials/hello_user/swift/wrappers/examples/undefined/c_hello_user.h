#ifndef _C_hello_user_WRAPPER_
#define _C_hello_user_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_UserInfo(void* _Nonnull cself);
    void* _Nonnull create_UserInfo(char* _Nonnull user_name, unsigned int user_age);
    unsigned int _prop_get_UserInfo_age(void* _Nonnull cself);
    void _prop_set_UserInfo_age(void* _Nonnull cself, unsigned int age);

    char* _Nonnull _prop_get_UserInfo_name(void* _Nonnull cself);
    void _prop_set_UserInfo_name(void* _Nonnull cself, char* _Nonnull name);

    bool _prop_get_UserInfo_want_a_drink(void* _Nonnull cself);
    void _prop_set_UserInfo_want_a_drink(void* _Nonnull cself, bool want_a_drink);

    void release_Host(void* _Nonnull cself);
    void* _Nonnull create_Host();
    char* _Nonnull _func_Host_hello(void* _Nonnull cself , void* _Nonnull user);
    char* _Nonnull _func_Host_welcome(void* _Nonnull cself , void* _Nonnull user);
#if __cplusplus
}
#endif
#endif /* ifndef _C_hello_user_WRAPPER_ */