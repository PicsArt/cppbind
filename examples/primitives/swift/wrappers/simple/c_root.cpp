/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/30/2021-08:56.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/simple/c_root.h"
#include "cxx/simple/root.hpp"

using namespace iegen::example;

void release_Root(CDataObj cself) {
    delete static_cast<iegen::example::Root*>(cself.ptr);
}

CDataObj create_Root(char* _Nonnull _path){
    auto c_to_cxx__path = std::string(_path);
    free(_path);
    auto this_object = new iegen::example::Root(c_to_cxx__path);
    return {0, this_object};
}

void _func_Root_setPath(CDataObj cself, char* _Nonnull _path, ErrorObj* _Nonnull err){
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
char* _Nonnull _prop_get_Root_path(CDataObj cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Root*>(cself.ptr);
    const auto& result = c_to_cxx_cself->path;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}
void _prop_set_Root_path(CDataObj cself, char* _Nonnull path){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Root*>(cself.ptr);
    auto c_to_cxx_path = std::string(path);
    free(path);
    c_to_cxx_cself->path = c_to_cxx_path;
}
