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
#include "swift/wrappers/simple/c_swift_holder.h"
#include "cxx/simple/holder.hpp"
#include "cxx/simple/task.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_TASK;

const char* CPPBIND_CPPBIND_EXAMPLE_HOLDER = "cppbind::example::Holder";

using namespace cppbind::example;

void release_CppbindExample_Holder(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Holder*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Holder(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Holder();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_HOLDER), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _prop_get_CppbindExample_Holder_task(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Holder*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->task();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TASK);
        auto value_ptr_result = const_cast<cppbind::example::Task*>(&result);
        CppBindCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}
