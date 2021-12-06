/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/containers/c_vector.h"
#include "cxx/containers/vector.hpp"

using namespace iegen::example;

void release_VectorItem(CObject cself) {
    delete static_cast<iegen::example::VectorItem*>(cself.ptr);
}
int _prop_get_VectorItem_value(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::VectorItem*>(cself.ptr);
    const auto& result = c_to_cxx_cself->value;
    
    return result;
}
void _prop_set_VectorItem_value(CObject cself, int value){
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorItem*>(cself.ptr);
    
    c_to_cxx_cself->value = value;
}


CObject create_VectorItem(int _value, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::VectorItem(_value);
        return {strdup("iegen::example::VectorItem"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result;
    return result;
}
void release_VectorExamples(CObject cself) {
    delete static_cast<iegen::example::VectorExamples*>(cself.ptr);
}

CObject create_VectorExamples(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::VectorExamples();
        return {strdup("iegen::example::VectorExamples"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result;
    return result;
}

void _func_VectorExamples_addIntVector(CObject cself, CDataArray v, ErrorObj* _Nonnull err){
    std::vector<int> c_to_cxx_v;

    auto data_v = reinterpret_cast<int*>(v.data);

    for (size_t _i_v = 0; _i_v < v.size; ++_i_v) {
        auto& value_v = data_v[_i_v];
        
        c_to_cxx_v.emplace_back(value_v);
    }
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        c_to_cxx_cself->addIntVector(c_to_cxx_v);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_VectorExamples_addObjVector(CObject cself, CDataArray v, ErrorObj* _Nonnull err){
    std::vector<VectorItem *> c_to_cxx_v;

    auto data_v = reinterpret_cast<CObject*>(v.data);

    for (size_t _i_v = 0; _i_v < v.size; ++_i_v) {
        auto& value_v = data_v[_i_v];
        
        auto c_to_cxx_value_v = static_cast<iegen::example::VectorItem*>(value_v.ptr);
        c_to_cxx_v.emplace_back(c_to_cxx_value_v);
    }
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        c_to_cxx_cself->addObjVector(c_to_cxx_v);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_VectorExamples_addStringVector(CObject cself, CDataArray v, ErrorObj* _Nonnull err){
    std::vector<std::string> c_to_cxx_v;

    auto data_v = reinterpret_cast<char**>(v.data);

    for (size_t _i_v = 0; _i_v < v.size; ++_i_v) {
        auto& value_v = data_v[_i_v];
        auto c_to_cxx_value_v = std::string(value_v);
        free(value_v);
        c_to_cxx_v.emplace_back(c_to_cxx_value_v);
    }
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        c_to_cxx_cself->addStringVector(c_to_cxx_v);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CDataArray _func_VectorExamples_getStringVector(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getStringVector();
        auto _data_cxx_to_c_result = new char* [result.size()];
        CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            auto cxx_to_c_value_result = strdup(value_result.data());
            _data_cxx_to_c_result[_i_result] = cxx_to_c_value_result;
        }
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataArray result;
    return result;
}

CDataArray _func_VectorExamples_getObjVector(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getObjVector();
        auto _data_cxx_to_c_result = new CObject [result.size()];
        CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            char* type_value_result = strdup("iegen::example::VectorItem");
            CObject cxx_to_c_value_result = {type_value_result, const_cast<iegen::example::VectorItem*>(value_result)};
            _data_cxx_to_c_result[_i_result] = cxx_to_c_value_result;
        }
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataArray result;
    return result;
}

CDataArray _func_VectorExamples_getIntVector(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::VectorExamples*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getIntVector();
        auto _data_cxx_to_c_result = new int [result.size()];
        CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            _data_cxx_to_c_result[_i_result] = value_result;
        }
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataArray result;
    return result;
}