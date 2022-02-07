/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/07/2022-12:05.
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

using namespace iegen::example;

void release_NumberInt(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Number<int>*>(cself.ptr);
    }
}

IEGenCObject create_NumberInt(int n, IEGenCObject* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::Number<int>(n);
        return {strdup("iegen::example::Number<int>"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

int _func_NumberInt_toInt(IEGenCObject cself, IEGenCObject* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Number<int>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toInt();
        
        return result;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}
int _prop_get_NumberInt_num(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::example::Number<int>*>(cself.ptr);
    const auto& result = ctocxxcself->num;
    
    return result;
}
void _prop_set_NumberInt_num(IEGenCObject cself, int num){
    
    auto ctocxxcself = static_cast<iegen::example::Number<int>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

void release_NumberDouble(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Number<double>*>(cself.ptr);
    }
}

IEGenCObject create_NumberDouble(double n, IEGenCObject* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::Number<double>(n);
        return {strdup("iegen::example::Number<double>"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

int _func_NumberDouble_toInt(IEGenCObject cself, IEGenCObject* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Number<double>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toInt();
        
        return result;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}
double _prop_get_NumberDouble_num(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::example::Number<double>*>(cself.ptr);
    const auto& result = ctocxxcself->num;
    
    return result;
}
void _prop_set_NumberDouble_num(IEGenCObject cself, double num){
    
    auto ctocxxcself = static_cast<iegen::example::Number<double>*>(cself.ptr);
    
    ctocxxcself->num = num;
}

