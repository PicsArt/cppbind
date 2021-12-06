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
#include "swift/wrappers/inheritance/c_square.h"
#include "cxx/inheritance/square.hpp"
#include "cxx/inheritance/rhombus.hpp"
#include "cxx/inheritance/rectangle.hpp"

using namespace iegen::example;

void release_Square(CObject cself) {
    delete static_cast<iegen::example::Parallelogram*>(cself.ptr);
}

CObject create_Square(double side, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::Square(side);
        return {strdup("iegen::example::Square"), static_cast<iegen::example::Parallelogram*>(this_object)};
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

double _prop_get_Square_area(CObject cself){
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Square*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
    const auto& result = c_to_cxx_cself->area();
    
    return result;
}

double _func_Square_perimeter(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Square*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
    try {
        const auto& result = c_to_cxx_cself->perimeter();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    double result;
    return result;
}