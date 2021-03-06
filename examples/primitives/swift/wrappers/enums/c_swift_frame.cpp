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
#include "swift/wrappers/enums/c_swift_frame.h"
#include "cxx/enums/frame.hpp"
#include "cxx/enums/color.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_FRAME = "cppbind::example::Frame";

using namespace cppbind::example;

void release_CppbindExample_Frame(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Frame*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Frame(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Frame();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_FRAME), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _prop_get_CppbindExample_Frame_backgroundColor(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::Frame*>(cself.ptr);
    const auto& result = ctocxxcself->backgroundColor;
    int cxxtocresult = static_cast<int>(result);
    return cxxtocresult;
}

void _prop_set_CppbindExample_Frame_backgroundColor(CppBindCObject cself, int backgroundColor) {
    
    auto ctocxxcself = static_cast<cppbind::example::Frame*>(cself.ptr);
    auto ctocxxbackgroundColor = static_cast<cppbind::example::Color>(backgroundColor);
    ctocxxcself->backgroundColor = ctocxxbackgroundColor;
}

int _prop_get_CppbindExample_Frame_backgroundColorShade(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::Frame*>(cself.ptr);
    const auto& result = ctocxxcself->backgroundColorShade;
    int cxxtocresult = static_cast<int>(result);
    return cxxtocresult;
}

void _prop_set_CppbindExample_Frame_backgroundColorShade(CppBindCObject cself, int backgroundColorShade) {
    
    auto ctocxxcself = static_cast<cppbind::example::Frame*>(cself.ptr);
    auto ctocxxbackgroundColorShade = static_cast<cppbind::example::ColorShade>(backgroundColorShade);
    ctocxxcself->backgroundColorShade = ctocxxbackgroundColorShade;
}

int _func_CppbindExample_Frame_getNextColor(CppBindCObject cself, int color, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcolor = static_cast<cppbind::example::Color>(color);
  
    auto ctocxxcself = static_cast<cppbind::example::Frame*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->getNextColor(ctocxxcolor);
        int cxxtocresult = static_cast<int>(result);
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

