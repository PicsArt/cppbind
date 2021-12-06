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
#include "swift/wrappers/enums/c_frame.h"
#include "cxx/enums/frame.hpp"
#include "cxx/enums/color.hpp"

using namespace iegen::example;

void release_Frame(CObject cself) {
    delete static_cast<iegen::example::Frame*>(cself.ptr);
}

CObject create_Frame(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Frame();
        return {strdup("iegen::example::Frame"), this_object};
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
unsigned int _prop_get_Frame_backgroundColor(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Frame*>(cself.ptr);
    const auto& result = c_to_cxx_cself->backgroundColor;
    unsigned int cxx_to_c_result = (unsigned int)result;
    return cxx_to_c_result;
}
void _prop_set_Frame_backgroundColor(CObject cself, unsigned int backgroundColor){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Frame*>(cself.ptr);
    auto c_to_cxx_backgroundColor = (iegen::example::Color)backgroundColor;
    c_to_cxx_cself->backgroundColor = c_to_cxx_backgroundColor;
}

unsigned int _prop_get_Frame_backgroundColorShade(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Frame*>(cself.ptr);
    const auto& result = c_to_cxx_cself->backgroundColorShade;
    unsigned int cxx_to_c_result = (unsigned int)result;
    return cxx_to_c_result;
}
void _prop_set_Frame_backgroundColorShade(CObject cself, unsigned int backgroundColorShade){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Frame*>(cself.ptr);
    auto c_to_cxx_backgroundColorShade = (iegen::example::ColorShade)backgroundColorShade;
    c_to_cxx_cself->backgroundColorShade = c_to_cxx_backgroundColorShade;
}
