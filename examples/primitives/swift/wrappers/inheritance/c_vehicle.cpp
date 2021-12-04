/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-11:54.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_vehicle.h"
#include "cxx/inheritance/vehicle.hpp"

using namespace iegen::example;

void release_Vehicle(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself);
}

int _prop_get_Vehicle_numberOfSeats(void* _Nonnull cself){
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself);
    const auto& result = c_to_cxx_cself->numberOfSeats();
    
    return result;
}

char* _Nonnull _func_Vehicle_type(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself);
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
    char* result = nullptr;
    return result;
}