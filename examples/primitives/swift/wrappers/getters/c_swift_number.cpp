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
#include "swift/wrappers/getters/c_swift_number.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/getters/number.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_NUMBERINT = "cppbind::example::Number<int>";
const char* CPPBIND_CPPBIND_EXAMPLE_NUMBERDOUBLE = "cppbind::example::Number<double>";

void release_CppbindExample_NumberInt(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::Number<int>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_NumberInt(int n, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->toInt();
        
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    decltype(auto) result = ctocxxcself->num;
    
    return result;
}

void _prop_set_CppbindExample_NumberInt_num(CppBindCObject cself, int num) {
    using namespace cppbind::example;
    
    auto ctocxxcself = static_cast<cppbind::example::Number<int>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

void release_CppbindExample_NumberDouble(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::Number<double>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_NumberDouble(double n, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->toInt();
        
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
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    decltype(auto) result = ctocxxcself->num;
    
    return result;
}

void _prop_set_CppbindExample_NumberDouble_num(CppBindCObject cself, double num) {
    using namespace cppbind::example;
    
    auto ctocxxcself = static_cast<cppbind::example::Number<double>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

