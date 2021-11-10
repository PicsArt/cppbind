/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 11/09/2021-11:44.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/nullables/c_NullableUtils.h"
#include "cxx/nullables/nullable_utils.hpp"

using namespace iegen::example::nullable;

void release_NumInt(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(cself);
}

void* _Nonnull create_NumInt(int val_){
    
    auto this_object = new iegen::example::nullable::NumberInt(val_);
    return new std::shared_ptr<iegen::example::nullable::NumberInt>(this_object);
}
int _prop_get_NumInt_value(void* _Nonnull cself){
    std::shared_ptr<iegen::example::nullable::NumberInt> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(cself);
    const auto& result = c_to_cxx_cself->value;
    
    return result;
}
void release_NumDouble(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::nullable::NumberDouble*>(static_cast<iegen::example::nullable::NumberDouble*>(cself));
}

void* _Nonnull create_NumDouble(double val_){
    
    auto this_object = new iegen::example::nullable::NumberDouble(val_);
    return this_object;
}
double _prop_get_NumDouble_value(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<iegen::example::nullable::NumberDouble*>(cself);
    const auto& result = c_to_cxx_cself->value;
    
    return result;
}
void release_NullableUtils(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself);
}

void* _Nonnull create_NullableUtils(void* _Nullable num){
    
    auto c_to_cxx_num = static_cast<iegen::example::nullable::NumberDouble*>(num);
    auto this_object = new iegen::example::nullable::Utils(c_to_cxx_num);
    return new std::shared_ptr<iegen::example::nullable::Utils>(this_object);
}

void* _Nullable _func_NullableUtils_max(void* _Nullable first, void* _Nonnull second, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_first = static_cast<iegen::example::nullable::NumberDouble*>(first);
  
    
    auto c_to_cxx_second = static_cast<iegen::example::nullable::NumberDouble*>(second);
  
    try {
        const auto& result = iegen::example::nullable::Utils::max(c_to_cxx_first, c_to_cxx_second);
        
        auto cxx_to_c_result = const_cast<iegen::example::nullable::NumberDouble*>(result);
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result;
    return result;
}

void* _Nullable _func_NullableUtils_max_1(void* _Nullable first, void* _Nullable second, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::nullable::NumberInt> c_to_cxx_first = nullptr;
    if (first) {
        c_to_cxx_first = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(first);
    }
  
    
    std::shared_ptr<iegen::example::nullable::NumberInt> c_to_cxx_second = nullptr;
    if (second) {
        c_to_cxx_second = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(second);
    }
  
    try {
        const auto& result = iegen::example::nullable::Utils::max(c_to_cxx_first, c_to_cxx_second);
        
        void* cxx_to_c_result = nullptr;
        if (result) {
            cxx_to_c_result = reinterpret_cast<void*>(new std::shared_ptr<iegen::example::nullable::NumberInt>(result));
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
    void* result;
    return result;
}

void _func_NullableUtils_checkNonnullArg(void* _Nonnull number, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_number = static_cast<iegen::example::nullable::NumberDouble*>(number);
  
    try {
        iegen::example::nullable::Utils::checkNonnullArg(c_to_cxx_number);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void* _Nonnull _func_NullableUtils_checkNonnullReturn(ErrorObj* _Nonnull err){
    try {
        const auto& result = iegen::example::nullable::Utils::checkNonnullReturn();
        
        auto cxx_to_c_result = const_cast<iegen::example::nullable::NumberDouble*>(result);
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result;
    return result;
}

void* _Nullable _prop_get_NullableUtils_nullable(void* _Nonnull cself){
    std::shared_ptr<iegen::example::nullable::Utils> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself);
    const auto& result = c_to_cxx_cself->nullable();
    
    auto cxx_to_c_result = const_cast<iegen::example::nullable::NumberDouble*>(result);
    return cxx_to_c_result;
}

void _prop_set_NullableUtils_nullable(void* _Nonnull cself, void* _Nullable num){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::nullable::Utils>(
              *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself)
              );
    
    auto c_to_cxx_num = static_cast<iegen::example::nullable::NumberDouble*>(num);
    c_to_cxx_cself->setNullable(c_to_cxx_num);
}


void* _Nonnull _prop_get_NullableUtils_nonNull(void* _Nonnull cself){
    std::shared_ptr<iegen::example::nullable::Utils> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself);
    const auto& result = c_to_cxx_cself->nonNull();
    
    auto cxx_to_c_result = const_cast<iegen::example::nullable::NumberDouble*>(result);
    return cxx_to_c_result;
}

void _prop_set_NullableUtils_nonNull(void* _Nonnull cself, void* _Nonnull num){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::nullable::Utils>(
              *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself)
              );
    
    auto c_to_cxx_num = static_cast<iegen::example::nullable::NumberDouble*>(num);
    c_to_cxx_cself->setNonNull(c_to_cxx_num);
}

void* _Nullable _prop_get_NullableUtils_numDouble(void* _Nonnull cself){
    std::shared_ptr<iegen::example::nullable::Utils> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself);
    const auto& result = c_to_cxx_cself->numDouble;
    
    auto cxx_to_c_result = const_cast<iegen::example::nullable::NumberDouble*>(result);
    return cxx_to_c_result;
}
void _prop_set_NullableUtils_numDouble(void* _Nonnull cself, void* _Nullable numDouble){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::nullable::Utils>(
              *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself)
              );
    
    auto c_to_cxx_numDouble = static_cast<iegen::example::nullable::NumberDouble*>(numDouble);
    c_to_cxx_cself->numDouble = c_to_cxx_numDouble;
}

void* _Nonnull _prop_get_NullableUtils_numInt(void* _Nonnull cself){
    std::shared_ptr<iegen::example::nullable::Utils> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself);
    const auto& result = c_to_cxx_cself->numInt;
    
    void* cxx_to_c_result;
    cxx_to_c_result = reinterpret_cast<void*>(new std::shared_ptr<iegen::example::nullable::NumberInt>(result));
    return cxx_to_c_result;
}
void _prop_set_NullableUtils_numInt(void* _Nonnull cself, void* _Nonnull numInt){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::nullable::Utils>(
              *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(cself)
              );
    
    std::shared_ptr<iegen::example::nullable::NumberInt> c_to_cxx_numInt;
    c_to_cxx_numInt = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(numInt);
    c_to_cxx_cself->numInt = c_to_cxx_numInt;
}
