/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/22/2022-14:13.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/globs/c_swift_complexDefaults.h"
#include "cxx/globs/utils.h"
#include "cxx/simple/task.hpp"
#include "cxx/simple/root.hpp"

extern const char* CPPBIND_CPPBIND_EXAMPLE_TASK;
extern const char* CPPBIND_STD_STDEXCEPTION;


CppBindCObject _func__singleComplexDefaultValue_1(CppBindCObject* _Nonnull cppbind_err) {
    try {
        const auto& result = ::singleComplexDefaultValue();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TASK);
        auto value_ptr_result = const_cast<cppbind::example::Task*>(new cppbind::example::Task(result));
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

CppBindCObject _func__singleComplexDefaultValue(CppBindCObject task, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxtask = *static_cast<cppbind::example::Task*>(task.ptr);
    try {
        const auto& result = ::singleComplexDefaultValue(ctocxxtask);
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TASK);
        auto value_ptr_result = const_cast<cppbind::example::Task*>(new cppbind::example::Task(result));
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

char* _Nonnull _func__multipleMixedDefaultValues_1(CppBindCObject* _Nonnull cppbind_err) {
    try {
        const auto& result = ::multipleMixedDefaultValues();
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

char* _Nonnull _func__multipleMixedDefaultValues_2(CppBindCObject task, int i, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxtask = *static_cast<cppbind::example::Task*>(task.ptr);
    
    try {
        const auto& result = ::multipleMixedDefaultValues(ctocxxtask, i);
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

char* _Nonnull _func__multipleMixedDefaultValues(CppBindCObject task, int i, CppBindCObject r, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxtask = *static_cast<cppbind::example::Task*>(task.ptr);
    
    
    auto& ctocxxr = *static_cast<cppbind::example::Root*>(r.ptr);
    try {
        const auto& result = ::multipleMixedDefaultValues(ctocxxtask, i, ctocxxr);
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

