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
#include "swift/wrappers/inheritance/c_vehicle.h"
#include "cxx/inheritance/vehicle.hpp"

using namespace iegen::example;

void release_Vehicle(CObject cself) {
    delete static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself.ptr);
}

int _prop_get_Vehicle_numberOfSeats(CObject cself){
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself.ptr);
    const auto& result = c_to_cxx_cself->numberOfSeats();
    
    return result;
}

char* _Nonnull _func_Vehicle_type(CObject cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->type();
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
    char* result{};
    return result;
}