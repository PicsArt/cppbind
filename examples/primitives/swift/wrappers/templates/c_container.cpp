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
#include "swift/wrappers/templates/c_container.h"
#include "cxx/templates/container.hpp"

using namespace iegen::example;

void release_ContainerImpl(CObject cself){
    delete static_cast<iegen::example::Container*>(cself.ptr);
}
void release_ContainerHolder(CObject cself) {
    delete static_cast<iegen::example::ContainerHolder*>(cself.ptr);
}

CObject create_ContainerHolder(CObject container, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_container = static_cast<iegen::example::Container*>(container.ptr);
    try {
        auto this_object = new iegen::example::ContainerHolder(c_to_cxx_container);
        return {strdup("iegen::example::ContainerHolder"), this_object};
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

CObject _prop_get_ContainerHolder_container(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::ContainerHolder*>(cself.ptr);
    const auto& result = c_to_cxx_cself->container();
    
    char* type_result = strdup("iegen::example::Container");
    const char * name_result = typeid(*result).name();
    int status = 0;
    char* demangled_result = abi::__cxa_demangle(name_result, NULL, NULL, &status);
    if (status == 0) {
        type_result = demangled_result;
    }
    CObject cxx_to_c_result = {type_result, const_cast<iegen::example::Container*>(result)};
    return cxx_to_c_result;
}