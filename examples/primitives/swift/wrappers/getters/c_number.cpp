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
#include "swift/wrappers/getters/c_number.h"
#include "cxx/getters/number.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_NUMBERINT = "cppbind::example::Number<int>";
const char* CPPBIND_CPPBIND_EXAMPLE_NUMBERDOUBLE = "cppbind::example::Number<double>";

using namespace cppbind::example;

void release_CppbindExample_NumberInt(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Number<int>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_NumberInt(int n, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Number<int>(n);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_NUMBERINT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_CppbindExample_NumberInt_toInt(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toInt();
        
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

int _prop_get_CppbindExample_NumberInt_num(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    const auto& result = ctocxxcself->num;
    
    return result;
}

void _prop_set_CppbindExample_NumberInt_num(CppBindCObject cself, int num) {
    
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

void release_CppbindExample_NumberDouble(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Number<double>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_NumberDouble(double n, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Number<double>(n);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_NUMBERDOUBLE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_CppbindExample_NumberDouble_toInt(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toInt();
        
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

double _prop_get_CppbindExample_NumberDouble_num(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    const auto& result = ctocxxcself->num;
    
    return result;
}

void _prop_set_CppbindExample_NumberDouble_num(CppBindCObject cself, double num) {
    
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

