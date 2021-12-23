/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:26.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/inheritance/c_parallelogram.h"
#include "cxx/inheritance/parallelogram.hpp"

using namespace iegen::example;

void release_ParallelogramImpl(CObject cself, bool owner){
    delete cself.type;
    if (owner) {
        delete static_cast<iegen::example::Parallelogram*>(cself.ptr);
    }
}

double _prop_get_Parallelogram_area(CObject cself){
    auto ctocxxcself = static_cast<iegen::example::Parallelogram*>(cself.ptr);
    const auto& result = ctocxxcself->area();
    
    return result;
}

double _func_Parallelogram_perimeter(CObject cself, ErrorObj* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Parallelogram*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->perimeter();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    double result{};
    return result;
}
