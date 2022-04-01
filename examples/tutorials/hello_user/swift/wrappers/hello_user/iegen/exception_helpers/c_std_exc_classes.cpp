/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/28/2022-13:25.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/hello_user/iegen/exception_helpers/c_std_exc_classes.h"
#include <stdexcept>
#include <new>
#include <typeinfo>


using namespace std;

void release_Std_StdException(IEGenCObject cself, bool owner) {
    static_assert(std::has_virtual_destructor<std::exception>::value, "std::exception type must have virtual destructor");
    if (owner) {
        if (strcmp(cself.type, "std::exception") == 0)
            delete static_cast<std::exception*>(cself.ptr);
        else if (strcmp(cself.type, "std::domain_error") == 0)
            delete static_cast<std::domain_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::invalid_argument") == 0)
            delete static_cast<std::invalid_argument*>(cself.ptr);
        else if (strcmp(cself.type, "std::length_error") == 0)
            delete static_cast<std::length_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::out_of_range") == 0)
            delete static_cast<std::out_of_range*>(cself.ptr);
        else if (strcmp(cself.type, "std::overflow_error") == 0)
            delete static_cast<std::overflow_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::range_error") == 0)
            delete static_cast<std::range_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::underflow_error") == 0)
            delete static_cast<std::underflow_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::bad_alloc") == 0)
            delete static_cast<std::bad_alloc*>(cself.ptr);
        else if (strcmp(cself.type, "std::bad_cast") == 0)
            delete static_cast<std::bad_cast*>(cself.ptr);
        else if (strcmp(cself.type, "std::bad_typeid") == 0)
            delete static_cast<std::bad_typeid*>(cself.ptr);
        else if (strcmp(cself.type, "std::logic_error") == 0)
            delete static_cast<std::logic_error*>(cself.ptr);
        else if (strcmp(cself.type, "std::runtime_error") == 0)
            delete static_cast<std::runtime_error*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

std::exception* downcast_Std_StdException(IEGenCObject iegenObj) {
    if (iegenObj.ptr) {
        if (strcmp(iegenObj.type, "std::exception") == 0)
            return static_cast<std::exception*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::domain_error") == 0)
            return static_cast<std::domain_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::invalid_argument") == 0)
            return static_cast<std::invalid_argument*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::length_error") == 0)
            return static_cast<std::length_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::out_of_range") == 0)
            return static_cast<std::out_of_range*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::overflow_error") == 0)
            return static_cast<std::overflow_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::range_error") == 0)
            return static_cast<std::range_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::underflow_error") == 0)
            return static_cast<std::underflow_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::bad_alloc") == 0)
            return static_cast<std::bad_alloc*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::bad_cast") == 0)
            return static_cast<std::bad_cast*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::bad_typeid") == 0)
            return static_cast<std::bad_typeid*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::logic_error") == 0)
            return static_cast<std::logic_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::runtime_error") == 0)
            return static_cast<std::runtime_error*>(iegenObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << iegenObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

const char * _Nonnull _func_Std_StdException_what(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err) {
    std::exception* ctocxxcself = downcast_Std_StdException(cself);
    try {
        const auto& result = ctocxxcself->what();
        
        return result;
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
    const char * result {};
    return result;
}

std::logic_error* downcast_Std_StdLogicError(IEGenCObject iegenObj) {
    if (iegenObj.ptr) {
        if (strcmp(iegenObj.type, "std::logic_error") == 0)
            return static_cast<std::logic_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::domain_error") == 0)
            return static_cast<std::domain_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::invalid_argument") == 0)
            return static_cast<std::invalid_argument*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::length_error") == 0)
            return static_cast<std::length_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::out_of_range") == 0)
            return static_cast<std::out_of_range*>(iegenObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << iegenObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

std::runtime_error* downcast_Std_StdRuntimeError(IEGenCObject iegenObj) {
    if (iegenObj.ptr) {
        if (strcmp(iegenObj.type, "std::runtime_error") == 0)
            return static_cast<std::runtime_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::overflow_error") == 0)
            return static_cast<std::overflow_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::range_error") == 0)
            return static_cast<std::range_error*>(iegenObj.ptr);
        else if (strcmp(iegenObj.type, "std::underflow_error") == 0)
            return static_cast<std::underflow_error*>(iegenObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << iegenObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

