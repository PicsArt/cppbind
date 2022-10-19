/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/13/2022-14:16.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/simple/c_swift_path.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/simple/path.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_PATH = "cppbind::example::Path";

void release_CppbindExample_Path(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::Path*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Path(char* _Nonnull _value, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Path*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->toString();
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Path*>(cself.ptr);
    decltype(auto) result = ctocxxcself->value;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

