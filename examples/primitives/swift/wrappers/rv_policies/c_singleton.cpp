/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/07/2022-16:23.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/rv_policies/c_singleton.h"
#include "cxx/rv_policies/singleton.hpp"

using namespace iegen::example;

void release_Singleton(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Singleton*>(cself.ptr);
    }
}

IEGenCObject _func_Singleton_getInstance(IEGenCObject* _Nonnull err){
    try {
        const auto& result = iegen::example::Singleton::getInstance();
        
        char* type_result = strdup("iegen::example::Singleton");
        auto value_ptr_result = const_cast<iegen::example::Singleton*>(&result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
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

IEGenCObject _func_Singleton_getInstancePtr(IEGenCObject* _Nonnull err){
    try {
        const auto& result = iegen::example::Singleton::getInstancePtr();
        
        char* type_result = strdup("iegen::example::Singleton");
        auto value_ptr_result = const_cast<iegen::example::Singleton*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
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