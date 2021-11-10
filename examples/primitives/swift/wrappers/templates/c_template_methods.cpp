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
#include "swift/wrappers/templates/c_template_methods.h"
#include "cxx/templates/template_methods.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

using namespace iegen::example;

void release_TemplateMethods(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::TemplateMethods*>(static_cast<iegen::example::TemplateMethods*>(cself));
}

void* _Nonnull create_TemplateMethods(){
    auto this_object = new iegen::example::TemplateMethods();
    return this_object;
}

int _func_TemplateMethods_maxInt(void* _Nonnull cself, int arg0, int arg1, ErrorObj* _Nonnull err){
    
  
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::TemplateMethods*>(cself);
    try {
        const auto& result = c_to_cxx_cself->max<int>(arg0, arg1);
        
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

char* _Nonnull _func_TemplateMethods_maxString(void* _Nonnull cself, char* _Nonnull arg0, char* _Nonnull arg1, ErrorObj* _Nonnull err){
    auto c_to_cxx_arg0 = std::string(arg0);
    free(arg0);
  
    auto c_to_cxx_arg1 = std::string(arg1);
    free(arg1);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::TemplateMethods*>(cself);
    try {
        const auto& result = c_to_cxx_cself->max<std::string>(c_to_cxx_arg0, c_to_cxx_arg1);
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
    char* result;
    return result;
}

CDataPair _func_TemplateMethods_makePairProjectProject(void* _Nonnull cself, void* _Nonnull arg0, void* _Nonnull arg1, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_arg0 = static_cast<iegen::example::Project*>(arg0);
  
    
    auto c_to_cxx_arg1 = static_cast<iegen::example::Project*>(arg1);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::TemplateMethods*>(cself);
    try {
        const auto& result = c_to_cxx_cself->makePair<iegen::example::Project, iegen::example::Project>(c_to_cxx_arg0, c_to_cxx_arg1);
        auto _first_data_cxx_to_c_result = new void*;
        auto _second_data_cxx_to_c_result = new void*;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        auto cxx_to_c_first_result = const_cast<iegen::example::Project*>(first_result);

        auto cxx_to_c_second_result = const_cast<iegen::example::Project*>(second_result);
        *_first_data_cxx_to_c_result = cxx_to_c_first_result;
        *_second_data_cxx_to_c_result = cxx_to_c_second_result;
        CDataPair cxx_to_c_result = { _first_data_cxx_to_c_result, _second_data_cxx_to_c_result };
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataPair result;
    return result;
}

CDataPair _func_TemplateMethods_makePairRootProject(void* _Nonnull cself, void* _Nonnull arg0, void* _Nonnull arg1, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_arg0 = static_cast<iegen::example::Root*>(arg0);
  
    
    auto c_to_cxx_arg1 = static_cast<iegen::example::Project*>(arg1);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::TemplateMethods*>(cself);
    try {
        const auto& result = c_to_cxx_cself->makePair<iegen::example::Root, iegen::example::Project>(c_to_cxx_arg0, c_to_cxx_arg1);
        auto _first_data_cxx_to_c_result = new void*;
        auto _second_data_cxx_to_c_result = new void*;
        const auto& first_result = result.first;
        const auto& second_result = result.second;

        auto cxx_to_c_first_result = const_cast<iegen::example::Root*>(first_result);

        auto cxx_to_c_second_result = const_cast<iegen::example::Project*>(second_result);
        *_first_data_cxx_to_c_result = cxx_to_c_first_result;
        *_second_data_cxx_to_c_result = cxx_to_c_second_result;
        CDataPair cxx_to_c_result = { _first_data_cxx_to_c_result, _second_data_cxx_to_c_result };
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataPair result;
    return result;
}