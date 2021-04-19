#include <string.h>
#include <memory>
#include "swift/wrappers/examples/undefined/c_hello_user.h"
#include "cxx/hello_user.hpp"

void release_UserInfo(void* _Nonnull cself){
        delete dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
}
void* _Nonnull create_UserInfo(char* _Nonnull user_name, unsigned int user_age){
    auto c_to_cxx_user_name = std::string(user_name);
    free(user_name);
    
    auto this_object = new hello_user::UserInfo(c_to_cxx_user_name, user_age);
    return static_cast<hello_user::UserInfo*>(this_object);
}
unsigned int _prop_get_UserInfo_age(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    auto result = c_to_cxx_cself->age;
    
    return result;
}
void _prop_set_UserInfo_age(void* _Nonnull cself, unsigned int age){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    
    c_to_cxx_cself->age = age;
}

char* _Nonnull _prop_get_UserInfo_name(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    auto result = c_to_cxx_cself->name;
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
void _prop_set_UserInfo_name(void* _Nonnull cself, char* _Nonnull name){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    auto c_to_cxx_name = std::string(name);
    free(name);
    c_to_cxx_cself->name = c_to_cxx_name;
}

bool _prop_get_UserInfo_want_a_drink(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    auto result = c_to_cxx_cself->want_a_drink;
    
    return result;
}
void _prop_set_UserInfo_want_a_drink(void* _Nonnull cself, bool want_a_drink){
    auto c_to_cxx_cself = dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(cself));
    
    c_to_cxx_cself->want_a_drink = want_a_drink;
}

void release_Host(void* _Nonnull cself){
        delete dynamic_cast<hello_user::Host*>(static_cast<hello_user::Host*>(cself));
}
void* _Nonnull create_Host(){
    auto this_object = new hello_user::Host();
    return static_cast<hello_user::Host*>(this_object);
}
char* _Nonnull _func_Host_hello(void* _Nonnull cself , void* _Nonnull user){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_user = *dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(user));
  
    auto c_to_cxx_cself = dynamic_cast<hello_user::Host*>(static_cast<hello_user::Host*>(cself));
    const auto& result = c_to_cxx_cself->hello(c_to_cxx_user);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
char* _Nonnull _func_Host_welcome(void* _Nonnull cself , void* _Nonnull user){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_user = *dynamic_cast<hello_user::UserInfo*>(static_cast<hello_user::UserInfo*>(user));
  
    auto c_to_cxx_cself = dynamic_cast<hello_user::Host*>(static_cast<hello_user::Host*>(cself));
    const auto& result = c_to_cxx_cself->welcome(c_to_cxx_user);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}