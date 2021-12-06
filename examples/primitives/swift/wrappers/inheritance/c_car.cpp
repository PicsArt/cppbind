/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/inheritance/c_car.h"
#include "cxx/inheritance/car.hpp"

using namespace iegen::example;

void release_MyCar(CObject cself) {
    delete static_cast<std::shared_ptr<iegen::example::MyCar>*>(cself.ptr);
}

CObject create_MyCar(int numberOfSeats, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::MyCar(numberOfSeats);
        return {strdup("iegen::example::MyCar"), new std::shared_ptr<iegen::example::MyCar>(this_object)};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result;
    return result;
}

char* _Nonnull _func_MyCar_type(CObject cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::MyCar> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::MyCar>*>(cself.ptr);
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