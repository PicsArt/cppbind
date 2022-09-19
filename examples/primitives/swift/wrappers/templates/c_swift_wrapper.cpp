/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/06/2022-11:01.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/templates/c_swift_wrapper.h"
#include "cxx/templates/wrapper.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRSTRINGS = "cppbind::example::Wrapper<std::pair<std::string, std::string>>";
const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRINTINT = "cppbind::example::Wrapper<std::pair<int, int>>";
const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERSTRING = "cppbind::example::Wrapper<std::string>";

using namespace cppbind::example;

void release_CppbindExample_WrapperPairStrings(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_WrapperPairStrings(CppBindCDataPair value, CppBindCObject* _Nonnull cppbind_err) {
    auto& first_tmp_value = *reinterpret_cast<char**>(value.first);
    auto& second_tmp_value = *reinterpret_cast<char**>(value.second);
    auto ctocxxfirst_tmp_value = std::string(first_tmp_value);
    free(first_tmp_value);
    auto ctocxxsecond_tmp_value = std::string(second_tmp_value);
    free(second_tmp_value);
    std::pair<std::string, std::string> ctocxxvalue { ctocxxfirst_tmp_value, ctocxxsecond_tmp_value };
    try {
        auto this_object = new cppbind::example::Wrapper<std::pair<std::string, std::string>>(ctocxxvalue);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRSTRINGS), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCDataPair _prop_get_CppbindExample_WrapperPairStrings_value(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->value();
        auto _first_data_cxxtocresult = new char*;
        auto _second_data_cxxtocresult = new char*;
        const auto& first_result = result.first;
        const auto& second_result = result.second;
        auto cxxtocfirst_result = strdup(first_result.data());
        auto cxxtocsecond_result = strdup(second_result.data());
        *_first_data_cxxtocresult = cxxtocfirst_result;
        *_second_data_cxxtocresult = cxxtocsecond_result;
        CppBindCDataPair cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCDataPair result {};
    return result;
}

void _prop_set_CppbindExample_WrapperPairStrings_value(CppBindCObject cself, CppBindCDataPair value, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cself.ptr);
    auto& first_tmp_value = *reinterpret_cast<char**>(value.first);
    auto& second_tmp_value = *reinterpret_cast<char**>(value.second);
    auto ctocxxfirst_tmp_value = std::string(first_tmp_value);
    free(first_tmp_value);
    auto ctocxxsecond_tmp_value = std::string(second_tmp_value);
    free(second_tmp_value);
    std::pair<std::string, std::string> ctocxxvalue { ctocxxfirst_tmp_value, ctocxxsecond_tmp_value };
    try {
        ctocxxcself->setValue(ctocxxvalue);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void release_CppbindExample_WrapperPairIntInt(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_WrapperPairIntInt(CppBindCDataPair value, CppBindCObject* _Nonnull cppbind_err) {
    auto& first_tmp_value = *reinterpret_cast<int*>(value.first);
    auto& second_tmp_value = *reinterpret_cast<int*>(value.second);


    std::pair<int, int> ctocxxvalue { first_tmp_value, second_tmp_value };
    try {
        auto this_object = new cppbind::example::Wrapper<std::pair<int, int>>(ctocxxvalue);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRINTINT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCDataPair _prop_get_CppbindExample_WrapperPairIntInt_value(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->value();
        auto _first_data_cxxtocresult = new int;
        auto _second_data_cxxtocresult = new int;
        const auto& first_result = result.first;
        const auto& second_result = result.second;


        *_first_data_cxxtocresult = first_result;
        *_second_data_cxxtocresult = second_result;
        CppBindCDataPair cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCDataPair result {};
    return result;
}

void _prop_set_CppbindExample_WrapperPairIntInt_value(CppBindCObject cself, CppBindCDataPair value, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cself.ptr);
    auto& first_tmp_value = *reinterpret_cast<int*>(value.first);
    auto& second_tmp_value = *reinterpret_cast<int*>(value.second);


    std::pair<int, int> ctocxxvalue { first_tmp_value, second_tmp_value };
    try {
        ctocxxcself->setValue(ctocxxvalue);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void release_CppbindExample_WrapperString(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Wrapper<std::string>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_WrapperString(char* _Nonnull value, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxvalue = std::string(value);
    free(value);
    try {
        auto this_object = new cppbind::example::Wrapper<std::string>(ctocxxvalue);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERSTRING), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _prop_get_CppbindExample_WrapperString_value(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::string>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->value();
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

void _prop_set_CppbindExample_WrapperString_value(CppBindCObject cself, char* _Nonnull value, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxcself = static_cast<cppbind::example::Wrapper<std::string>*>(cself.ptr);
    auto ctocxxvalue = std::string(value);
    free(value);
    try {
        ctocxxcself->setValue(ctocxxvalue);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

