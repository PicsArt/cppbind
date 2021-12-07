/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-08:30.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/simple/c_root.h"
#include "cxx/simple/root.hpp"

using namespace iegen::example;

void release_Root(CObject cself) {
    delete static_cast<iegen::example::Root*>(cself.ptr);
}

CObject create_Root(char* _Nonnull _path, ErrorObj* _Nonnull err){
    auto c_to_cxx__path = std::string(_path);
    free(_path);
    try {
        auto this_object = new iegen::example::Root(c_to_cxx__path);
        return {strdup("iegen::example::Root"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

void _func_Root_setPath(CObject cself, char* _Nonnull _path, ErrorObj* _Nonnull err){
    auto c_to_cxx__path = std::string(_path);
    free(_path);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Root*>(cself.ptr);
    try {
        c_to_cxx_cself->setPath(c_to_cxx__path);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}
char* _Nonnull _prop_get_Root_path(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Root*>(cself.ptr);
    const auto& result = c_to_cxx_cself->path;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}
void _prop_set_Root_path(CObject cself, char* _Nonnull path){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Root*>(cself.ptr);
    auto c_to_cxx_path = std::string(path);
    free(path);
    c_to_cxx_cself->path = c_to_cxx_path;
}
