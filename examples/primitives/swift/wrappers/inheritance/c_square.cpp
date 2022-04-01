/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/29/2022-15:31.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_square.h"
#include "cxx/inheritance/square.hpp"

using namespace iegen::example;

void release_IegenExample_Square(IEGenCObject cself, bool owner) {
    if (owner) {
        delete static_cast<iegen::example::Square*>(cself.ptr);
    }
    free(cself.type);
}

IEGenCObject create_IegenExample_Square(double side, IEGenCObject* _Nonnull iegen_err) {
    try {
        auto this_object = new iegen::example::Square(side);
        return {strdup("iegen::example::Square"), this_object};
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

double _prop_get_IegenExample_Square_area(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err) {
    auto ctocxxcself = static_cast<iegen::example::Square*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->area();
        
        return result;
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
    double result {};
    return result;
}

double _func_IegenExample_Square_perimeter(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err) {
    auto ctocxxcself = static_cast<iegen::example::Square*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->perimeter();
        
        return result;
    } catch (const std::exception& e) {
        iegen_err->type = strdup("std::exception");
        iegen_err->ptr = new std::exception(e);
    } catch (...) {
        iegen_err->type = strdup("Uncaught Exception");
    }
    double result {};
    return result;
}

