/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-10:17.
 * Please do not change it manually.
 */

#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/simple/c_path.h"
#include "cxx/simple/path.hpp"

using namespace iegen::example;

void release_Path(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Path*>(cself.ptr);
    }
}

IEGenCObject create_Path(char* _Nonnull _value, IEGenCErrorObj* _Nonnull err){
    auto ctocxx_value = std::string(_value);
    free(_value);
    try {
        auto this_object = new iegen::example::Path(ctocxx_value);
        return {strdup("iegen::example::Path"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCObject result {};
    return result;
}

char* _Nonnull _func_Path_toString(IEGenCObject cself, IEGenCErrorObj* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Path*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->toString();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result {};
    return result;
}
char* _Nonnull _prop_get_Path_value(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::example::Path*>(cself.ptr);
    const auto& result = ctocxxcself->value;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}
