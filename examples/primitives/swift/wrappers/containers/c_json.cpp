/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/16/2021-13:56.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/containers/c_json.h"
#include "cxx/containers/json.hpp"


using namespace iegen::example;
void release_JsonExamples(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::JsonExamples*>(static_cast<iegen::example::JsonExamples*>(cself));
}

void* _Nonnull create_JsonExamples(){
    auto this_object = new iegen::example::JsonExamples();
    return static_cast<iegen::example::JsonExamples*>(this_object);
}

void _func_JsonExamples_setJson(void* _Nonnull cself, char * _Nullable j, ErrorObj* _Nonnull err){
    auto c_to_cxx_j = nlohmann::json::parse(j);
    free(j);
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::JsonExamples*>(static_cast<iegen::example::JsonExamples*>(cself));
    try {
      c_to_cxx_cself->setJson(c_to_cxx_j);
    }
    catch (const std::exception& e) {
        err->is_err = true;
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->is_err = true;
    }
}

char * _Nullable _func_JsonExamples_getJson(void* _Nonnull cself, ErrorObj* _Nonnull err){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::JsonExamples*>(static_cast<iegen::example::JsonExamples*>(cself));
    try {
      const auto& result = c_to_cxx_cself->getJson();
      auto result_str = result.dump();
    auto cxx_to_c_result = strdup(result_str.c_str());
      return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->is_err = true;
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->is_err = true;
    }
    char * _Nullable result;
    return result;
}

char * _Nullable _func_JsonExamples_getSimpleJsonExample(void* _Nonnull cself, ErrorObj* _Nonnull err){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::JsonExamples*>(static_cast<iegen::example::JsonExamples*>(cself));
    try {
      const auto& result = c_to_cxx_cself->getSimpleJsonExample();
      auto result_str = result.dump();
    auto cxx_to_c_result = strdup(result_str.c_str());
      return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->is_err = true;
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->is_err = true;
    }
    char * _Nullable result;
    return result;
}