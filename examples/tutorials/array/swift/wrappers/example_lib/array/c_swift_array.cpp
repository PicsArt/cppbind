/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/14/2022-07:29.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/example_lib/array/c_swift_array.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/array.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_STD_STDOUTOFRANGE;

const char* CPPBIND_CPPBIND_ARRAY = "cppbind::Array";

void release_Cppbind_Array(CppBindCObject cself, bool owner) {
    using namespace cppbind;
    if (owner) {
        delete static_cast<cppbind::Array*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_Cppbind_Array(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;
    try {
        auto this_object = new cppbind::Array();
        return {strdup(CPPBIND_CPPBIND_ARRAY), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_Cppbind_Array_front(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->front();
        
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

int _func_Cppbind_Array_back(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->back();
        
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

void _func_Cppbind_Array_push_back(CppBindCObject cself, int element, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;

    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        ctocxxcself->push_back(element);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

int _prop_get_Cppbind_Array_size(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->size();
        
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

bool _prop_get_Cppbind_Array_empty(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->empty();
        
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


int _func_Cppbind_Array__getitem_(CppBindCObject cself,int i) {
    using namespace cppbind;
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    decltype(auto) result = ctocxxcself->operator[](i);
    
    return result;
}

void _func_Cppbind_Array__setitem_(CppBindCObject cself, int i, int value) {
    using namespace cppbind;
    
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    ctocxxcself->operator[](i) = value;
}
int _func_Cppbind_Array_at(CppBindCObject cself, int i, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind;

    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->at(i);
        
        return result;
    } catch (const std::out_of_range& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDOUTOFRANGE);
        cppbind_err->ptr = new std::out_of_range(e);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

