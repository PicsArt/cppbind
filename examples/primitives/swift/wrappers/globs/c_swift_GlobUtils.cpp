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
#include "swift/wrappers/globs/c_swift_GlobUtils.h"
#include "cxx/globs/utils.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_PROJECT;
extern const char* CPPBIND_CPPBIND_EXAMPLE_ROOT;


int _func__mul(int first, int second, CppBindCObject* _Nonnull cppbind_err) {
    
    
    try {
        const auto& result = ::mul(first, second);
        
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

int _func__mulThree(int first, int second, int third, CppBindCObject* _Nonnull cppbind_err) {
    
    
    
    try {
        const auto& result = ::mul(first, second, third);
        
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

char* _Nonnull _func__concat(char* _Nonnull str1, char* _Nonnull str2, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxstr1 = std::string(str1);
    free(str1);
    auto ctocxxstr2 = std::string(str2);
    free(str2);
    try {
        const auto& result = ::concat(ctocxxstr1, ctocxxstr2);
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

char* _Nonnull _func__concat_1(char* _Nonnull str1, char* _Nonnull str2, char* _Nonnull str3, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxstr1 = std::string(str1);
    free(str1);
    auto ctocxxstr2 = std::string(str2);
    free(str2);
    auto ctocxxstr3 = std::string(str3);
    free(str3);
    try {
        const auto& result = ::concat(ctocxxstr1, ctocxxstr2, ctocxxstr3);
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

int _func__maxInt(int a, int b, CppBindCObject* _Nonnull cppbind_err) {
    
    
    try {
        const auto& result = ::max<int>(a, b);
        
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

char* _Nonnull _func__maxString(char* _Nonnull a, char* _Nonnull b, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxa = std::string(a);
    free(a);
    auto ctocxxb = std::string(b);
    free(b);
    try {
        const auto& result = ::max<std::string>(ctocxxa, ctocxxb);
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

CppBindCDataPair _func_CppbindExample_makePairProjectProject(CppBindCObject a, CppBindCObject b, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxa = static_cast<cppbind::example::Project*>(a.ptr);
    
    auto ctocxxb = static_cast<cppbind::example::Project*>(b.ptr);
    try {
        const auto& result = cppbind::example::makePair<cppbind::example::Project, cppbind::example::Project>(ctocxxa, ctocxxb);
        auto _first_data_cxxtocresult = new CppBindCObject;
        auto _second_data_cxxtocresult = new CppBindCObject;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_first_result = const_cast<cppbind::example::Project*>(first_result);
        CppBindCObject cxxtocfirst_result = {type_first_result, value_ptr_first_result};

        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_second_result = const_cast<cppbind::example::Project*>(second_result);
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

CppBindCDataPair _func_CppbindExample_makePairRootProject(CppBindCObject a, CppBindCObject b, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxa = static_cast<cppbind::example::Root*>(a.ptr);
    
    auto ctocxxb = static_cast<cppbind::example::Project*>(b.ptr);
    try {
        const auto& result = cppbind::example::makePair<cppbind::example::Root, cppbind::example::Project>(ctocxxa, ctocxxb);
        auto _first_data_cxxtocresult = new CppBindCObject;
        auto _second_data_cxxtocresult = new CppBindCObject;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ROOT);
        auto value_ptr_first_result = const_cast<cppbind::example::Root*>(first_result);
        CppBindCObject cxxtocfirst_result = {type_first_result, value_ptr_first_result};

        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_second_result = const_cast<cppbind::example::Project*>(second_result);
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

CppBindCObject _func__optionalFDPtr(CppBindCObject project, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxproject = static_cast<cppbind::example::Project*>(project.ptr);
    try {
        const auto& result = ::optionalFDPtr(ctocxxproject);
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_result = const_cast<cppbind::example::Project*>(result);
        CppBindCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func__doNothing(CppBindCObject* _Nonnull cppbind_err) {
    try {
        doNothing();
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}
