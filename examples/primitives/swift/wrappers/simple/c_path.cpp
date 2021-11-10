/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/09/2021-11:44.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/simple/c_path.h"
#include "cxx/simple/path.hpp"

using namespace iegen::example;

void release_Path(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Path*>(static_cast<iegen::example::Path*>(cself));
}

void* _Nonnull create_Path(char* _Nonnull _value){
    auto c_to_cxx__value = std::string(_value);
    free(_value);
    auto this_object = new iegen::example::Path(c_to_cxx__value);
    return this_object;
}

char* _Nonnull _func_Path_toString(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Path*>(cself);
    try {
        const auto& result = c_to_cxx_cself->toString();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result;
    return result;
}
char* _Nonnull _prop_get_Path_value(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Path*>(cself);
    const auto& result = c_to_cxx_cself->value;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}