/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/22/2022-09:36.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/globs/c_swift_primitiveDefaults.h"
#include "cxx/globs/utils.h"
#include "cxx/enums/color.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

int _func__optionalColor(int c, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxc = static_cast<cppbind::example::Color>(c);
    try {
        decltype(auto) result = ::optionalColor(ctocxxc);
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

char* _Nonnull _func__optionalString(char* _Nonnull optional_str, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxoptional_str = std::string(optional_str);
    free(optional_str);
    try {
        decltype(auto) result = ::optionalString(ctocxxoptional_str);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

int _func__optionalInt(int i, CppBindCObject* _Nonnull cppbind_err) {
    
    try {
        decltype(auto) result = ::optionalInt(i);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

