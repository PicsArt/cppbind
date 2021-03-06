/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:05.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_swift_square.h"
#include "cxx/inheritance/square.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SQUARE = "cppbind::example::Square";

using namespace cppbind::example;

void release_CppbindExample_Square(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Square*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Square(double side, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Square(side);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_SQUARE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

double _prop_get_CppbindExample_Square_area(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Square*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->area();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    double result {};
    return result;
}

double _func_CppbindExample_Square_perimeter(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Square*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->perimeter();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    double result {};
    return result;
}

