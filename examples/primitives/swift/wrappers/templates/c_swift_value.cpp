/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/13/2022-14:16.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/templates/c_swift_value.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/templates/value.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_TEMPLATEVALUE = "cppbind::example::TemplateValue";

void release_CppbindExample_TemplateValue(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::TemplateValue*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_TemplateValueInt(int value, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::TemplateValue(value);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_TEMPLATEVALUE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_TemplateValueString(char* _Nonnull value, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxvalue = std::string(value);
    free(value);
    try {
        auto this_object = new cppbind::example::TemplateValue(ctocxxvalue);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_TEMPLATEVALUE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_CppbindExample_TemplateValue_add_valueInt(CppBindCObject cself, int other, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;

    auto ctocxxcself = static_cast<cppbind::example::TemplateValue*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->add_value<int>(other);
        
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

char* _Nonnull _func_CppbindExample_TemplateValue_add_valueString(CppBindCObject cself, char* _Nonnull other, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxother = std::string(other);
    free(other);

    auto ctocxxcself = static_cast<cppbind::example::TemplateValue*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->add_value<std::string>(ctocxxother);
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

