/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/29/2022-15:31.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/simple/c_root.h"
#include "cxx/simple/root.hpp"

using namespace iegen::example;

void release_IegenExample_Root(IEGenCObject cself, bool owner) {
    if (owner) {
        delete static_cast<iegen::example::Root*>(cself.ptr);
    }
    free(cself.type);
}

IEGenCObject create_IegenExample_Root(char* _Nonnull _path, IEGenCObject* _Nonnull iegen_err) {
    auto ctocxx_path = std::string(_path);
    free(_path);
    try {
        auto this_object = new iegen::example::Root(ctocxx_path);
        return {strdup("iegen::example::Root"), this_object};
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

void _func_IegenExample_Root_setPath(IEGenCObject cself, char* _Nonnull _path, IEGenCObject* _Nonnull iegen_err) {
    auto ctocxx_path = std::string(_path);
    free(_path);
  
    auto ctocxxcself = static_cast<iegen::example::Root*>(cself.ptr);
    try {
        ctocxxcself->setPath(ctocxx_path);
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
}

char* _Nonnull _prop_get_IegenExample_Root_path(IEGenCObject cself) {
    auto ctocxxcself = static_cast<iegen::example::Root*>(cself.ptr);
    const auto& result = ctocxxcself->path;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

void _prop_set_IegenExample_Root_path(IEGenCObject cself, char* _Nonnull path) {
    
    auto ctocxxcself = static_cast<iegen::example::Root*>(cself.ptr);
    auto ctocxxpath = std::string(path);
    free(path);
    ctocxxcself->path = ctocxxpath;
}

