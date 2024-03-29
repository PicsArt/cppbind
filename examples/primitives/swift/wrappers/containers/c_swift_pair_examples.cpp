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
#include "swift/wrappers/containers/c_swift_pair_examples.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/containers/pair.hpp"
#include "cxx/containers/map.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_MAPITEM;

const char* CPPBIND_CPPBIND_EXAMPLE_PAIREXAMPLES = "cppbind::example::PairExamples";

void release_CppbindExample_PairExamples(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::PairExamples*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_PairExamples(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::PairExamples();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_PAIREXAMPLES), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCDataPair _func_CppbindExample_PairExamples_sumIntPairs(CppBindCObject cself, CppBindCDataPair p1, CppBindCDataPair p2, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto& first_tmp_p1 = *reinterpret_cast<int*>(p1.first);
    auto& second_tmp_p1 = *reinterpret_cast<int*>(p1.second);


    std::pair<int, int> ctocxxp1 { first_tmp_p1, second_tmp_p1 };

    auto& first_tmp_p2 = *reinterpret_cast<int*>(p2.first);
    auto& second_tmp_p2 = *reinterpret_cast<int*>(p2.second);


    std::pair<int, int> ctocxxp2 { first_tmp_p2, second_tmp_p2 };

    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->sumIntPairs(ctocxxp1, ctocxxp2);
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

void _func_CppbindExample_PairExamples_setNestedPair(CppBindCObject cself, CppBindCDataPair p, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto& first_tmp_p = *reinterpret_cast<CppBindCDataPair*>(p.first);
    auto& second_tmp_p = *reinterpret_cast<CppBindCDataPair*>(p.second);
    auto& first_tmp_first_tmp_p = *reinterpret_cast<char**>(first_tmp_p.first);
    auto& second_tmp_first_tmp_p = *reinterpret_cast<char**>(first_tmp_p.second);
    auto ctocxxfirst_tmp_first_tmp_p = std::string(first_tmp_first_tmp_p);
    free(first_tmp_first_tmp_p);
    auto ctocxxsecond_tmp_first_tmp_p = std::string(second_tmp_first_tmp_p);
    free(second_tmp_first_tmp_p);
    std::pair<std::string, std::string> ctocxxfirst_tmp_p { ctocxxfirst_tmp_first_tmp_p, ctocxxsecond_tmp_first_tmp_p };
    auto& first_tmp_second_tmp_p = *reinterpret_cast<char**>(second_tmp_p.first);
    auto& second_tmp_second_tmp_p = *reinterpret_cast<char**>(second_tmp_p.second);
    auto ctocxxfirst_tmp_second_tmp_p = std::string(first_tmp_second_tmp_p);
    free(first_tmp_second_tmp_p);
    auto ctocxxsecond_tmp_second_tmp_p = std::string(second_tmp_second_tmp_p);
    free(second_tmp_second_tmp_p);
    std::pair<std::string, std::string> ctocxxsecond_tmp_p { ctocxxfirst_tmp_second_tmp_p, ctocxxsecond_tmp_second_tmp_p };
    std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>> ctocxxp { ctocxxfirst_tmp_p, ctocxxsecond_tmp_p };

    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        ctocxxcself->setNestedPair(ctocxxp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCDataPair _func_CppbindExample_PairExamples_getNestedPair(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getNestedPair();
        auto _first_data_cxxtocresult = new CppBindCDataPair;
        auto _second_data_cxxtocresult = new CppBindCDataPair;
        const auto& first_result = result.first;
        const auto& second_result = result.second;
        auto _first_data_cxxtocfirst_result = new char*;
        auto _second_data_cxxtocfirst_result = new char*;
        const auto& first_first_result = first_result.first;
        const auto& second_first_result = first_result.second;
        auto cxxtocfirst_first_result = strdup(first_first_result.data());
        auto cxxtocsecond_first_result = strdup(second_first_result.data());
        *_first_data_cxxtocfirst_result = cxxtocfirst_first_result;
        *_second_data_cxxtocfirst_result = cxxtocsecond_first_result;
        CppBindCDataPair cxxtocfirst_result = { _first_data_cxxtocfirst_result, _second_data_cxxtocfirst_result };
        auto _first_data_cxxtocsecond_result = new char*;
        auto _second_data_cxxtocsecond_result = new char*;
        const auto& first_second_result = second_result.first;
        const auto& second_second_result = second_result.second;
        auto cxxtocfirst_second_result = strdup(first_second_result.data());
        auto cxxtocsecond_second_result = strdup(second_second_result.data());
        *_first_data_cxxtocsecond_result = cxxtocfirst_second_result;
        *_second_data_cxxtocsecond_result = cxxtocsecond_second_result;
        CppBindCDataPair cxxtocsecond_result = { _first_data_cxxtocsecond_result, _second_data_cxxtocsecond_result };
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

CppBindCDataPair _func_CppbindExample_PairExamples_getStringPair(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getStringPair();
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

void _func_CppbindExample_PairExamples_setNestedVectorOfPairs(CppBindCObject cself, CppBindCDataArray v, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::vector<std::vector<std::pair<int, std::string>>> ctocxxv;

    auto data_v = reinterpret_cast<CppBindCDataArray*>(v.data);

    for (size_t _i_v = 0; _i_v < v.size; ++_i_v) {
        auto& value_v = data_v[_i_v];
        std::vector<std::pair<int, std::string>> ctocxxvalue_v;

        auto data_value_v = reinterpret_cast<CppBindCDataPair*>(value_v.data);

        for (size_t _i_value_v = 0; _i_value_v < value_v.size; ++_i_value_v) {
            auto& value_value_v = data_value_v[_i_value_v];
            auto& first_tmp_value_value_v = *reinterpret_cast<int*>(value_value_v.first);
            auto& second_tmp_value_value_v = *reinterpret_cast<char**>(value_value_v.second);

            auto ctocxxsecond_tmp_value_value_v = std::string(second_tmp_value_value_v);
            free(second_tmp_value_value_v);
            std::pair<int, std::string> ctocxxvalue_value_v { first_tmp_value_value_v, ctocxxsecond_tmp_value_value_v };
            ctocxxvalue_v.emplace_back(ctocxxvalue_value_v);
        }
        ctocxxv.emplace_back(ctocxxvalue_v);
    }

    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        ctocxxcself->setNestedVectorOfPairs(ctocxxv);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCDataArray _func_CppbindExample_PairExamples_getNestedVectorOfPairs(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getNestedVectorOfPairs();
        auto _data_cxxtocresult = new CppBindCDataArray [result.size()];
        CppBindCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            auto _data_cxxtocvalue_result = new CppBindCDataPair [value_result.size()];
            CppBindCDataArray cxxtocvalue_result = { _data_cxxtocvalue_result, static_cast<long long>(value_result.size()) };
            for (int _i_value_result = 0; _i_value_result < value_result.size(); ++_i_value_result) {
                auto& value_value_result = value_result[_i_value_result];
                auto _first_data_cxxtocvalue_value_result = new int;
                auto _second_data_cxxtocvalue_value_result = new char*;
                const auto& first_value_value_result = value_value_result.first;
                const auto& second_value_value_result = value_value_result.second;

                auto cxxtocsecond_value_value_result = strdup(second_value_value_result.data());
                *_first_data_cxxtocvalue_value_result = first_value_value_result;
                *_second_data_cxxtocvalue_value_result = cxxtocsecond_value_value_result;
                CppBindCDataPair cxxtocvalue_value_result = { _first_data_cxxtocvalue_value_result, _second_data_cxxtocvalue_value_result };
                _data_cxxtocvalue_result[_i_value_result] = cxxtocvalue_value_result;
            }
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

CppBindCDataPair _prop_get_CppbindExample_PairExamples_complexPairObj(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->complexPairObj();
        auto _first_data_cxxtocresult = new CppBindCObject;
        auto _second_data_cxxtocresult = new CppBindCDataArray;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_MAPITEM);
        auto value_ptr_first_result = new cppbind::example::MapItem(first_result);
        CppBindCObject cxxtocfirst_result = {type_first_result, value_ptr_first_result};
        auto _data_cxxtocsecond_result = new CppBindCObject [second_result.size()];
        CppBindCDataArray cxxtocsecond_result = { _data_cxxtocsecond_result, static_cast<long long>(second_result.size()) };
        for (int _i_second_result = 0; _i_second_result < second_result.size(); ++_i_second_result) {
            auto& value_second_result = second_result[_i_second_result];
            
            char* type_value_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_MAPITEM);
            auto value_ptr_value_second_result = new cppbind::example::MapItem(value_second_result);
            CppBindCObject cxxtocvalue_second_result = {type_value_second_result, value_ptr_value_second_result};
            _data_cxxtocsecond_result[_i_second_result] = cxxtocvalue_second_result;
        }
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

void _prop_set_CppbindExample_PairExamples_complexPairObj(CppBindCObject cself, CppBindCDataPair p, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    auto& first_tmp_p = *reinterpret_cast<CppBindCObject*>(p.first);
    auto& second_tmp_p = *reinterpret_cast<CppBindCDataArray*>(p.second);

    auto& ctocxxfirst_tmp_p = *static_cast<cppbind::example::MapItem*>(first_tmp_p.ptr);
    std::vector<MapItem> ctocxxsecond_tmp_p;

    auto data_second_tmp_p = reinterpret_cast<CppBindCObject*>(second_tmp_p.data);

    for (size_t _i_second_tmp_p = 0; _i_second_tmp_p < second_tmp_p.size; ++_i_second_tmp_p) {
        auto& value_second_tmp_p = data_second_tmp_p[_i_second_tmp_p];
        
        auto& ctocxxvalue_second_tmp_p = *static_cast<cppbind::example::MapItem*>(value_second_tmp_p.ptr);
        ctocxxsecond_tmp_p.emplace_back(ctocxxvalue_second_tmp_p);
    }
    std::pair<MapItem, std::vector<MapItem>> ctocxxp { ctocxxfirst_tmp_p, ctocxxsecond_tmp_p };
    try {
        ctocxxcself->setComplexPairObj(ctocxxp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

long _func_CppbindExample_PairExamples_sumPairItems(CppBindCObject cself, CppBindCDataPair p, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto& first_tmp_p = *reinterpret_cast<long*>(p.first);
    auto& second_tmp_p = *reinterpret_cast<long*>(p.second);


    std::pair<long, long> ctocxxp { first_tmp_p, second_tmp_p };

    auto ctocxxcself = static_cast<cppbind::example::PairExamples*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->sumPairItems(ctocxxp);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    long result {};
    return result;
}

