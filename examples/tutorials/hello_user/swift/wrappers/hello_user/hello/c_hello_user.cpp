/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/04/2021-10:56.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/hello_user/hello/c_hello_user.h"
#include "cxx/hello_user.hpp"


void release_UserInfo(void* _Nonnull cself) {
    delete static_cast<UserInfo*>(cself);
}

void* _Nonnull create_UserInfo(char* _Nonnull user_name, unsigned int user_age, ErrorObj* _Nonnull err){
    auto c_to_cxx_user_name = std::string(user_name);
    free(user_name);
    
    try {
        auto this_object = new UserInfo(c_to_cxx_user_name, user_age);
        return this_object;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}
unsigned int _prop_get_UserInfo_age(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself);
    const auto& result = c_to_cxx_cself->age;
    
    return result;
}
char* _Nonnull _prop_get_UserInfo_name(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself);
    const auto& result = c_to_cxx_cself->name;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}
bool _prop_get_UserInfo_want_a_drink(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself);
    const auto& result = c_to_cxx_cself->want_a_drink;
    
    return result;
}
void _prop_set_UserInfo_want_a_drink(void* _Nonnull cself, bool want_a_drink){
    
    auto c_to_cxx_cself = static_cast<UserInfo*>(cself);
    
    c_to_cxx_cself->want_a_drink = want_a_drink;
}

void release_Host(void* _Nonnull cself) {
    delete static_cast<Host*>(cself);
}

void* _Nonnull create_Host(ErrorObj* _Nonnull err){
    try {
        auto this_object = new Host();
        return this_object;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

char* _Nonnull _func_Host_hello(void* _Nonnull cself, void* _Nonnull user, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_user = *static_cast<UserInfo*>(user);
  
    
    auto c_to_cxx_cself = static_cast<Host*>(cself);
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

char* _Nonnull _func_Host_welcome(void* _Nonnull cself, void* _Nonnull user, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_user = *static_cast<UserInfo*>(user);
  
    
    auto c_to_cxx_cself = static_cast<Host*>(cself);
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