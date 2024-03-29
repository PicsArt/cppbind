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
#include "swift/wrappers/templates/c_swift_template_methods.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/templates/template_methods.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_PROJECT;
extern const char* CPPBIND_CPPBIND_EXAMPLE_ROOT;

const char* CPPBIND_CPPBIND_EXAMPLE_TEMPLATEMETHODS = "cppbind::example::TemplateMethods";

void release_CppbindExample_TemplateMethods(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::TemplateMethods*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_TemplateMethods(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::TemplateMethods();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_TEMPLATEMETHODS), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_CppbindExample_TemplateMethods_maxInt(CppBindCObject cself, int a, int b, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;


    auto ctocxxcself = static_cast<cppbind::example::TemplateMethods*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->max<int>(a, b);
        
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

char* _Nonnull _func_CppbindExample_TemplateMethods_maxString(CppBindCObject cself, char* _Nonnull a, char* _Nonnull b, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxa = std::string(a);
    free(a);

    auto ctocxxb = std::string(b);
    free(b);

    auto ctocxxcself = static_cast<cppbind::example::TemplateMethods*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->max<std::string>(ctocxxa, ctocxxb);
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

CppBindCDataPair _func_CppbindExample_TemplateMethods_makePairProjectProject(CppBindCObject cself, CppBindCObject a, CppBindCObject b, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    auto ctocxxa = static_cast<cppbind::example::Project*>(a.ptr);

    
    auto ctocxxb = static_cast<cppbind::example::Project*>(b.ptr);

    auto ctocxxcself = static_cast<cppbind::example::TemplateMethods*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->makePair<cppbind::example::Project, cppbind::example::Project>(ctocxxa, ctocxxb);
        auto _first_data_cxxtocresult = new CppBindCObject;
        auto _second_data_cxxtocresult = new CppBindCObject;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_first_result = first_result;
        CppBindCObject cxxtocfirst_result = {type_first_result, value_ptr_first_result};

        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_second_result = second_result;
        CppBindCObject cxxtocsecond_result = {type_second_result, value_ptr_second_result};
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

CppBindCDataPair _func_CppbindExample_TemplateMethods_makePairRootProject(CppBindCObject cself, CppBindCObject a, CppBindCObject b, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    auto ctocxxa = static_cast<cppbind::example::Root*>(a.ptr);

    
    auto ctocxxb = static_cast<cppbind::example::Project*>(b.ptr);

    auto ctocxxcself = static_cast<cppbind::example::TemplateMethods*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->makePair<cppbind::example::Root, cppbind::example::Project>(ctocxxa, ctocxxb);
        auto _first_data_cxxtocresult = new CppBindCObject;
        auto _second_data_cxxtocresult = new CppBindCObject;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ROOT);
        auto value_ptr_first_result = first_result;
        CppBindCObject cxxtocfirst_result = {type_first_result, value_ptr_first_result};

        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_second_result = second_result;
        CppBindCObject cxxtocsecond_result = {type_second_result, value_ptr_second_result};
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

CppBindCDataArray _func_CppbindExample_TemplateMethods_mergeInt(CppBindCDataArray first, CppBindCDataArray second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::vector<int> ctocxxfirst;

    auto data_first = reinterpret_cast<int*>(first.data);

    for (size_t _i_first = 0; _i_first < first.size; ++_i_first) {
        auto& value_first = data_first[_i_first];
        
        ctocxxfirst.emplace_back(value_first);
    }

    std::vector<int> ctocxxsecond;

    auto data_second = reinterpret_cast<int*>(second.data);

    for (size_t _i_second = 0; _i_second < second.size; ++_i_second) {
        auto& value_second = data_second[_i_second];
        
        ctocxxsecond.emplace_back(value_second);
    }

    try {
        decltype(auto) result = cppbind::example::TemplateMethods::merge<int>(ctocxxfirst, ctocxxsecond);
        auto _data_cxxtocresult = new int [result.size()];
        CppBindCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            _data_cxxtocresult[_i_result] = value_result;
        }
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCDataArray result {};
    return result;
}

CppBindCDataArray _func_CppbindExample_TemplateMethods_mergeString(CppBindCDataArray first, CppBindCDataArray second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::vector<std::string> ctocxxfirst;

    auto data_first = reinterpret_cast<char**>(first.data);

    for (size_t _i_first = 0; _i_first < first.size; ++_i_first) {
        auto& value_first = data_first[_i_first];
        auto ctocxxvalue_first = std::string(value_first);
        free(value_first);
        ctocxxfirst.emplace_back(ctocxxvalue_first);
    }

    std::vector<std::string> ctocxxsecond;

    auto data_second = reinterpret_cast<char**>(second.data);

    for (size_t _i_second = 0; _i_second < second.size; ++_i_second) {
        auto& value_second = data_second[_i_second];
        auto ctocxxvalue_second = std::string(value_second);
        free(value_second);
        ctocxxsecond.emplace_back(ctocxxvalue_second);
    }

    try {
        decltype(auto) result = cppbind::example::TemplateMethods::merge<std::string>(ctocxxfirst, ctocxxsecond);
        auto _data_cxxtocresult = new char* [result.size()];
        CppBindCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            auto cxxtocvalue_result = strdup(value_result.data());
            _data_cxxtocresult[_i_result] = cxxtocvalue_result;
        }
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCDataArray result {};
    return result;
}

