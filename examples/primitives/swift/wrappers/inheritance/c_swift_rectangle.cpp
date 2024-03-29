/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/17/2022-16:24.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_swift_rectangle.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/inheritance/rectangle.hpp"
#include "cxx/inheritance/square.hpp"

extern const char* CPPBIND_CPPBIND_EXAMPLE_SQUARE;
extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_RECTANGLE = "cppbind::example::Rectangle";

void release_CppbindExample_RectangleImpl(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::Rectangle>::value, "cppbind::example::Rectangle type must have virtual destructor");
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_RECTANGLE) == 0)
            delete static_cast<cppbind::example::Rectangle*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_SQUARE) == 0)
            delete static_cast<cppbind::example::Square*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

cppbind::example::Rectangle* recover_obj_from_CppbindExample_Rectangle(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_RECTANGLE) == 0)
            return static_cast<cppbind::example::Rectangle*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_SQUARE) == 0)
            return static_cast<cppbind::example::Square*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_Rectangle(double length, double width, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Rectangle(length, width);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_RECTANGLE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

double _prop_get_CppbindExample_Rectangle_area(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::Rectangle* ctocxxcself = recover_obj_from_CppbindExample_Rectangle(cself);
    try {
        decltype(auto) result = ctocxxcself->area();
        
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

double _prop_get_CppbindExample_Rectangle_length(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::Rectangle* ctocxxcself = recover_obj_from_CppbindExample_Rectangle(cself);
    try {
        decltype(auto) result = ctocxxcself->length();
        
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

double _prop_get_CppbindExample_Rectangle_width(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::Rectangle* ctocxxcself = recover_obj_from_CppbindExample_Rectangle(cself);
    try {
        decltype(auto) result = ctocxxcself->width();
        
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

