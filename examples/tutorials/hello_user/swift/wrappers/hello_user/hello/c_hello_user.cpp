/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-11:54.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/hello_user/hello/c_hello_user.h"
#include "cxx/hello_user.hpp"


void release_UserInfo(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<UserInfo*>(cself.ptr);
    }
}

CObject create_UserInfo(char* _Nonnull user_name, unsigned int user_age, ErrorObj* _Nonnull err){
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
    CObject result{};
    return result;
}
unsigned int _prop_get_UserInfo_age(CObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->age;
    
    return result;
}
char* _Nonnull _prop_get_UserInfo_name(CObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->name;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}
bool _prop_get_UserInfo_want_a_drink(CObject cself){
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = ctocxxcself->want_a_drink;
    
    return result;
}
void _prop_set_UserInfo_want_a_drink(CObject cself, bool want_a_drink){
    
    auto ctocxxcself = static_cast<UserInfo*>(cself.ptr);
    
    ctocxxcself->want_a_drink = want_a_drink;
}

void release_Host(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<Host*>(cself.ptr);
    }
}

CObject create_Host(ErrorObj* _Nonnull err){
    try {
        auto this_object = new Host();
        return {strdup("Host"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

char* _Nonnull _func_Host_hello(CObject cself, CObject user, ErrorObj* _Nonnull err){
    
    auto& ctocxxuser = *static_cast<UserInfo*>(user.ptr);
  
    
    auto ctocxxcself = static_cast<Host*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->hello(ctocxxuser);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}

char* _Nonnull _func_Host_welcome(CObject cself, CObject user, ErrorObj* _Nonnull err){
    
    auto& ctocxxuser = *static_cast<UserInfo*>(user.ptr);
  
    
    auto ctocxxcself = static_cast<Host*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->welcome(ctocxxuser);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}