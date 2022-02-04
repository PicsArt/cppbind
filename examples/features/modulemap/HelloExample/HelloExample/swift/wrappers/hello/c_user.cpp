/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-11:00.
 * Please do not change it manually.
 */

#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/hello/c_user.h"
#include "cxx/user.hpp"


void release_UserInfo(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<UserInfo*>(cself.ptr);
    }
}

IEGenCObject create_UserInfo(char* _Nonnull user_name, unsigned int user_age, IEGenCErrorObj* _Nonnull err){
    auto ctocxxuser_name = std::string(user_name);
    free(user_name);
    
    try {
        auto this_object = new UserInfo(ctocxxuser_name, user_age);
        return {strdup("UserInfo"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCObject result {};
    return result;
}
unsigned int _prop_get_UserInfo_age(IEGenCObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->age;
    
    return result;
}
char* _Nonnull _prop_get_UserInfo_name(IEGenCObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->name;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}
bool _prop_get_UserInfo_want_a_drink(IEGenCObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->want_a_drink;
    
    return result;
}
void _prop_set_UserInfo_want_a_drink(IEGenCObject cself, bool want_a_drink){
    
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    
    ctocxxcself->want_a_drink = want_a_drink;
}

