/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 11/22/2022-06:20.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/hello/c_swift_host.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/host.hpp"
#include "cxx/user.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_HOST = "Host";

void release_Host(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<Host*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_Host(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new Host();
        return {strdup(CPPBIND_HOST), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_Host_hello(CppBindCObject cself, CppBindCObject user, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxuser = *static_cast<UserInfo*>(user.ptr);

    auto ctocxxcself = static_cast<Host*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->hello(ctocxxuser);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

char* _Nonnull _func_Host_welcome(CppBindCObject cself, CppBindCObject user, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxuser = *static_cast<UserInfo*>(user.ptr);

    auto ctocxxcself = static_cast<Host*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->welcome(ctocxxuser);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

