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
#include "swift/wrappers/inheritance/c_rectangle.h"
#include "cxx/inheritance/rectangle.hpp"
#include "cxx/inheritance/parallelogram.hpp"

using namespace iegen::example;

void release_RectangleImpl(CObject cself){
    delete dynamic_cast<iegen::example::Rectangle*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
}

CObject create_Rectangle(double length, double width, ErrorObj* _Nonnull err){
    
    
    try {
        auto this_object = new iegen::example::Rectangle(length, width);
        return {strdup("iegen::example::Rectangle"), static_cast<iegen::example::Parallelogram*>(this_object)};
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

double _prop_get_Rectangle_area(CObject cself){
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Rectangle*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
    const auto& result = c_to_cxx_cself->area();
    
    return result;
}

double _prop_get_Rectangle_length(CObject cself){
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Rectangle*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
    const auto& result = c_to_cxx_cself->length();
    
    return result;
}

double _prop_get_Rectangle_width(CObject cself){
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Rectangle*>(static_cast<iegen::example::Parallelogram*>(cself.ptr));
    const auto& result = c_to_cxx_cself->width();
    
    return result;
}