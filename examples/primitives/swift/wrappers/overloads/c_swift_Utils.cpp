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
#include "swift/wrappers/overloads/c_swift_Utils.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/overloads/utils.hpp"
#include <algorithm>

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_UTILS = "cppbind::example::Utils";

void release_CppbindExample_Utils(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<std::shared_ptr<cppbind::example::Utils>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Utils(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Utils();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_UTILS), new std::shared_ptr<cppbind::example::Utils>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _func_CppbindExample_Utils_sum(int first, int second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;


    try {
        decltype(auto) result = cppbind::example::Utils::sum(first, second);
        
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

float _func_CppbindExample_Utils_sum1(float first, float second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;


    try {
        decltype(auto) result = cppbind::example::Utils::sum(first, second);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    float result {};
    return result;
}

char* _Nonnull _func_CppbindExample_Utils_concatenate(CppBindCObject cself, char* _Nonnull first, char* _Nonnull second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxfirst = std::string(first);
    free(first);

    auto ctocxxsecond = std::string(second);
    free(second);

    std::shared_ptr<cppbind::example::Utils> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->concatenate(ctocxxfirst, ctocxxsecond);
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

char* _Nonnull _func_CppbindExample_Utils_concatenate1(CppBindCObject cself, char* _Nonnull first, char* _Nonnull second, char* _Nonnull third, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxfirst = std::string(first);
    free(first);

    auto ctocxxsecond = std::string(second);
    free(second);

    auto ctocxxthird = std::string(third);
    free(third);

    std::shared_ptr<cppbind::example::Utils> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->concatenate(ctocxxfirst, ctocxxsecond, ctocxxthird);
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

int _func_CppbindExample_Utils_minus(int first, int second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;


    try {
        decltype(auto) result = cppbind::example::Utils::sub(first, second);
        
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

float _func_CppbindExample_Utils_minus1(float first, float second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;


    try {
        decltype(auto) result = cppbind::example::Utils::sub(first, second);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    float result {};
    return result;
}

CppBindCDataArray _func_CppbindExample_Utils_sum2(CppBindCObject cself, CppBindCDataArray first, CppBindCDataArray second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::Utils::ArrayInt ctocxxfirst {};
    auto data_first = reinterpret_cast<int*>(first.data);
    std::copy_n(data_first, 4, ctocxxfirst.begin());

    cppbind::example::Utils::ArrayInt ctocxxsecond {};
    auto data_second = reinterpret_cast<int*>(second.data);
    std::copy_n(data_second, 4, ctocxxsecond.begin());

    std::shared_ptr<cppbind::example::Utils> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->sum(ctocxxfirst, ctocxxsecond);
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

CppBindCDataArray _func_CppbindExample_Utils_sum3(CppBindCObject cself, CppBindCDataArray first, CppBindCDataArray second, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::array<float, 4> ctocxxfirst {};
    auto data_first = reinterpret_cast<float*>(first.data);
    std::copy_n(data_first, 4, ctocxxfirst.begin());

    std::array<float, 4> ctocxxsecond {};
    auto data_second = reinterpret_cast<float*>(second.data);
    std::copy_n(data_second, 4, ctocxxsecond.begin());

    std::shared_ptr<cppbind::example::Utils> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->sum(ctocxxfirst, ctocxxsecond);
        auto _data_cxxtocresult = new float [result.size()];
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

