/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/30/2021-09:10.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/templates/c_stack.h"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/number.hpp"

using namespace iegen::example;

void release_StackPrj(CDataObj cself) {
    delete static_cast<iegen::example::Stack<iegen::example::Project>*>(cself.ptr);
}

CDataObj create_StackPrj(){
    auto this_object = new iegen::example::Stack<iegen::example::Project>();
    return {0, this_object};
}

CDataObj create_StackPrj_1(CDataObj st){
    
    auto& c_to_cxx_st = *static_cast<iegen::example::Project*>(st.ptr);
    auto this_object = new iegen::example::Stack<iegen::example::Project>(c_to_cxx_st);
    return {0, this_object};
}

void _func_StackPrj_push(CDataObj cself, CDataObj item, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_item = static_cast<iegen::example::Project*>(item.ptr);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Project>*>(cself.ptr);
    try {
        c_to_cxx_cself->push(c_to_cxx_item);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackPrj_pop(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Project>*>(cself.ptr);
    try {
        c_to_cxx_cself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CDataObj _func_StackPrj_top(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Project>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->top();
        
        int code_result = 0;
        CDataObj cxx_to_c_result = {code_result, const_cast<iegen::example::Project*>(result)};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataObj result;
    return result;
}

bool _func_StackPrj_empty(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Project>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result;
    return result;
}
void release_StackTask(CDataObj cself) {
    delete static_cast<iegen::example::Stack<iegen::example::Task>*>(cself.ptr);
}

CDataObj create_StackTask(){
    auto this_object = new iegen::example::Stack<iegen::example::Task>();
    return {0, this_object};
}

CDataObj create_StackTask_1(CDataObj st){
    
    auto& c_to_cxx_st = *static_cast<iegen::example::Task*>(st.ptr);
    auto this_object = new iegen::example::Stack<iegen::example::Task>(c_to_cxx_st);
    return {0, this_object};
}

void _func_StackTask_push(CDataObj cself, CDataObj item, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_item = static_cast<iegen::example::Task*>(item.ptr);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Task>*>(cself.ptr);
    try {
        c_to_cxx_cself->push(c_to_cxx_item);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackTask_pop(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Task>*>(cself.ptr);
    try {
        c_to_cxx_cself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CDataObj _func_StackTask_top(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Task>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->top();
        
        int code_result = 0;
        CDataObj cxx_to_c_result = {code_result, const_cast<iegen::example::Task*>(result)};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataObj result;
    return result;
}

bool _func_StackTask_empty(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Task>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result;
    return result;
}
void release_StackNumInt(CDataObj cself) {
    delete static_cast<iegen::example::Stack<iegen::example::Number<int>>*>(cself.ptr);
}

CDataObj create_StackNumInt(){
    auto this_object = new iegen::example::Stack<iegen::example::Number<int>>();
    return {0, this_object};
}

CDataObj create_StackNumInt_1(CDataObj st){
    
    auto& c_to_cxx_st = *static_cast<iegen::example::Number<int>*>(st.ptr);
    auto this_object = new iegen::example::Stack<iegen::example::Number<int>>(c_to_cxx_st);
    return {0, this_object};
}

void _func_StackNumInt_push(CDataObj cself, CDataObj item, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_item = static_cast<iegen::example::Number<int>*>(item.ptr);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Number<int>>*>(cself.ptr);
    try {
        c_to_cxx_cself->push(c_to_cxx_item);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackNumInt_pop(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Number<int>>*>(cself.ptr);
    try {
        c_to_cxx_cself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CDataObj _func_StackNumInt_top(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Number<int>>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->top();
        
        int code_result = 0;
        CDataObj cxx_to_c_result = {code_result, const_cast<iegen::example::Number<int>*>(result)};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataObj result;
    return result;
}

bool _func_StackNumInt_empty(CDataObj cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Stack<iegen::example::Number<int>>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result;
    return result;
}