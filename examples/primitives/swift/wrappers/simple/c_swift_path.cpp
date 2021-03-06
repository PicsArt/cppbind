/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:05.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/simple/c_swift_path.h"
#include "cxx/simple/path.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_PATH = "cppbind::example::Path";

using namespace cppbind::example;

void release_CppbindExample_Path(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Path*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Path(char* _Nonnull _value, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxx_value = std::string(_value);
    free(_value);
    try {
        auto this_object = new cppbind::example::Path(ctocxx_value);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_PATH), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_Path_toString(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Path*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toString();
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

char* _Nonnull _prop_get_CppbindExample_Path_value(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::Path*>(cself.ptr);
    const auto& result = ctocxxcself->value;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

