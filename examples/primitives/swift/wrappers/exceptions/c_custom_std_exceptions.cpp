/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/15/2022-06:30.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/exceptions/c_custom_std_exceptions.h"
#include "cxx/exceptions/exceptions.hpp"

using namespace iegen::example;


IEGenCObject create_SystemError(char* _Nonnull message, IEGenCObject* _Nonnull err){
    auto ctocxxmessage = std::string(message);
    free(message);
    try {
        auto this_object = new iegen::example::SystemError(ctocxxmessage);
        return {strdup("iegen::example::SystemError"), this_object};
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

const char * _Nonnull _func_SystemError_what(IEGenCObject cself, IEGenCObject* _Nonnull err){
    iegen::example::SystemError* ctocxxcself = nullptr;
    if (cself.ptr) {
        if (strcmp(cself.type, "iegen::example::SystemError") == 0)
            ctocxxcself = static_cast<iegen::example::SystemError*>(cself.ptr);
        else if (strcmp(cself.type, "iegen::example::FileError") == 0)
            ctocxxcself = static_cast<iegen::example::FileError*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    try {
        const auto& result = ctocxxcself->what();
        
        return result;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    const char * result {};
    return result;
}

IEGenCObject create_FileError(char* _Nonnull message, IEGenCObject* _Nonnull err){
    auto ctocxxmessage = std::string(message);
    free(message);
    try {
        auto this_object = new iegen::example::FileError(ctocxxmessage);
        return {strdup("iegen::example::FileError"), this_object};
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

const char * _Nonnull _func_FileError_what(IEGenCObject cself, IEGenCObject* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::FileError*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->what();
        
        return result;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    const char * result {};
    return result;
}
