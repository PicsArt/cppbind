/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/25/2021-10:01.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/getters/c_number.h"
#include "cxx/getters/number.hpp"

using namespace iegen::example;

void release_NumberInt(void* _Nonnull cself) {
    delete static_cast<iegen::example::Number<int>*>(cself);
}

void* _Nonnull create_NumberInt(int n, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::Number<int>(n);
        return this_object;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

int _func_NumberInt_toInt(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Number<int>*>(cself);
    try {
        const auto& result = c_to_cxx_cself->toInt();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result;
    return result;
}
int _prop_get_NumberInt_num(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Number<int>*>(cself);
    const auto& result = c_to_cxx_cself->num;
    
    return result;
}
void _prop_set_NumberInt_num(void* _Nonnull cself, int num){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Number<int>*>(cself);
    
    c_to_cxx_cself->num = num;
}

void release_NumberDouble(void* _Nonnull cself) {
    delete static_cast<iegen::example::Number<double>*>(cself);
}

void* _Nonnull create_NumberDouble(double n, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::example::Number<double>(n);
        return this_object;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

int _func_NumberDouble_toInt(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Number<double>*>(cself);
    try {
        const auto& result = c_to_cxx_cself->toInt();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result;
    return result;
}
double _prop_get_NumberDouble_num(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<iegen::example::Number<double>*>(cself);
    const auto& result = c_to_cxx_cself->num;
    
    return result;
}
void _prop_set_NumberDouble_num(void* _Nonnull cself, double num){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Number<double>*>(cself);
    
    c_to_cxx_cself->num = num;
}
