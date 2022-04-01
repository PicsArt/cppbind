/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/28/2022-13:26.
 * Please do not change it manually.
 */

#ifndef _C_user_WRAPPER_
#define _C_user_WRAPPER_

#include "c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_UserInfo(IEGenCObject cself, bool owner);

    IEGenCObject create_UserInfo(char* _Nonnull user_name, unsigned int user_age, IEGenCObject* _Nonnull iegen_err);
    unsigned int _prop_get_UserInfo_age(IEGenCObject cself);
    char* _Nonnull _prop_get_UserInfo_name(IEGenCObject cself);
    bool _prop_get_UserInfo_want_a_drink(IEGenCObject cself);
    void _prop_set_UserInfo_want_a_drink(IEGenCObject cself, bool want_a_drink);

#if __cplusplus
}
#endif
#endif /* ifndef _C_user_WRAPPER_ */
