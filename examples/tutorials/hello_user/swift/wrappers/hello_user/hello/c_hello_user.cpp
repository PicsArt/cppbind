/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/30/2021-09:23.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/hello_user/hello/c_hello_user.h"
#include "cxx/hello_user.hpp"


void release_UserInfo(CDataObj cself) {
    delete static_cast<UserInfo*>(cself.ptr);
}

CDataObj create_UserInfo(char* _Nonnull user_name, unsigned int user_age){
    auto c_to_cxx_user_name = std::string(user_name);
    free(user_name);
    
    auto this_object = new UserInfo(c_to_cxx_user_name, user_age);
    return {0, this_object};
}
unsigned int _prop_get_UserInfo_age(CDataObj cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = c_to_cxx_cself->age;
    
    return result;
}
char* _Nonnull _prop_get_UserInfo_name(CDataObj cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = c_to_cxx_cself->name;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}
bool _prop_get_UserInfo_want_a_drink(CDataObj cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself.ptr);
    const auto& result = c_to_cxx_cself->want_a_drink;
    
    return result;
}
void _prop_set_UserInfo_want_a_drink(CDataObj cself, bool want_a_drink){
    
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself.ptr);
    
    c_to_cxx_cself->want_a_drink = want_a_drink;
}

void release_Host(CDataObj cself) {
    delete static_cast<Host*>(cself.ptr);
}

CDataObj create_Host(){
    auto this_object = new Host();
    return {0, this_object};
}

char* _Nonnull _func_Host_hello(CDataObj cself, CDataObj user, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_user = *static_cast<UserInfo*>(user.ptr);
  
    
    auto c_to_cxx_cself = static_cast<Host*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->hello(c_to_cxx_user);
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result = nullptr;
    return result;
}

char* _Nonnull _func_Host_welcome(CDataObj cself, CDataObj user, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_user = *static_cast<UserInfo*>(user.ptr);
  
    
    auto c_to_cxx_cself = static_cast<Host*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->welcome(c_to_cxx_user);
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result = nullptr;
    return result;
}