/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-08:30.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/misc/c_yaml_example.h"
#include "cxx/misc/yaml_example.hpp"

using namespace iegen::example;

void release_WithExternalAPIComments(CObject cself) {
    delete static_cast<iegen::example::WithExternalAPIComments*>(cself.ptr);
}

CObject create_WithExternalAPIComments(char* _Nonnull s, ErrorObj* _Nonnull err){
    auto c_to_cxx_s = std::string(s);
    free(s);
    try {
        auto this_object = new iegen::example::WithExternalAPIComments(c_to_cxx_s);
        return {strdup("iegen::example::WithExternalAPIComments"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

int _func_WithExternalAPIComments_retInt(int n, ErrorObj* _Nonnull err){
    
  
    try {
        const auto& result = iegen::example::WithExternalAPIComments::retInt(n);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result{};
    return result;
}

char* _Nonnull _prop_get_WithExternalAPIComments_str(CObject cself){
    auto c_to_cxx_cself = static_cast<iegen::example::WithExternalAPIComments*>(cself.ptr);
    const auto& result = c_to_cxx_cself->str();
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}

void _prop_set_WithExternalAPIComments_str(CObject cself, char* _Nonnull s){
    
    auto c_to_cxx_cself = static_cast<iegen::example::WithExternalAPIComments*>(cself.ptr);
    auto c_to_cxx_s = std::string(s);
    free(s);
    c_to_cxx_cself->setStr(c_to_cxx_s);
}


int _func_WithExternalAPIComments_maxInt(int arg0, int arg1, ErrorObj* _Nonnull err){
    
  
    
  
    try {
        const auto& result = iegen::example::WithExternalAPIComments::max<int>(arg0, arg1);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result{};
    return result;
}

char* _Nonnull _func_WithExternalAPIComments_maxString(char* _Nonnull arg0, char* _Nonnull arg1, ErrorObj* _Nonnull err){
    auto c_to_cxx_arg0 = std::string(arg0);
    free(arg0);
  
    auto c_to_cxx_arg1 = std::string(arg1);
    free(arg1);
  
    try {
        const auto& result = iegen::example::WithExternalAPIComments::max<std::string>(c_to_cxx_arg0, c_to_cxx_arg1);
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}
void release_AdderInt(CObject cself) {
    delete static_cast<iegen::example::Adder<int>*>(cself.ptr);
}

int _func_AdderInt_add(int a, int b, ErrorObj* _Nonnull err){
    
  
    
  
    try {
        const auto& result = iegen::example::Adder<int>::add(a, b);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result{};
    return result;
}
void release_AdderDouble(CObject cself) {
    delete static_cast<iegen::example::Adder<double>*>(cself.ptr);
}

double _func_AdderDouble_add(double a, double b, ErrorObj* _Nonnull err){
    
  
    
  
    try {
        const auto& result = iegen::example::Adder<double>::add(a, b);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    double result{};
    return result;
}