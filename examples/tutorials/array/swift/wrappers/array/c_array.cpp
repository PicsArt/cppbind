/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/23/2022-09:36.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/array/c_array.h"
#include "cxx/array.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_STD_STDOUTOFRANGE;

const char* CPPBIND_CPPBIND_ARRAY = "cppbind::Array";

using namespace cppbind;

void release_Cppbind_Array(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::Array*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_Cppbind_Array(CppBindCObject* _Nonnull cppbind_err) {
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
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->front();
        
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
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->back();
        
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
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->size();
        
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
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->empty();
        
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
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    const auto& result = ctocxxcself->operator[](i);
    
    return result;
}

void _func_Cppbind_Array__setitem_(CppBindCObject cself, int i, int value) {
    
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    ctocxxcself->operator[](i) = value;
}
int _func_Cppbind_Array_at(CppBindCObject cself, int i, CppBindCObject* _Nonnull cppbind_err) {
  
    auto ctocxxcself = static_cast<cppbind::Array*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->at(i);
        
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
