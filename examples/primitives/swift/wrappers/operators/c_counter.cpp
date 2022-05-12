/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:26.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/operators/c_counter.h"
#include "cxx/operators/counter.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_COUNTER = "cppbind::example::Counter";

using namespace cppbind::example;

void release_CppbindExample_Counter(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Counter*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Counter(int count, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Counter(count);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_COUNTER), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _prop_get_CppbindExample_Counter_count(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Counter*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->count();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

CppBindCObject _func_CppbindExample_Counter__add_(CppBindCObject cself, CppBindCObject counter, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxcounter = *static_cast<cppbind::example::Counter*>(counter.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Counter*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->operator+(ctocxxcounter);
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_COUNTER);
        auto value_ptr_result = const_cast<cppbind::example::Counter*>(new cppbind::example::Counter(result));
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

bool _func_CppbindExample_Counter__gt_(CppBindCObject cself, CppBindCObject counter, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxcounter = *static_cast<cppbind::example::Counter*>(counter.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Counter*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->operator>(ctocxxcounter);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

CppBindCObject _func_CppbindExample_Counter__iadd_(CppBindCObject cself, CppBindCObject counter, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxcounter = *static_cast<cppbind::example::Counter*>(counter.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Counter*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->operator+=(ctocxxcounter);
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_COUNTER);
        auto value_ptr_result = const_cast<cppbind::example::Counter*>(&result);
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

