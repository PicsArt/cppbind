/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:26.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/templates/c_stack.h"
#include "cxx/templates/stack.hpp"
#include "cxx/templates/container.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/number.hpp"

using namespace iegen::example;

void release_StackPrj(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<iegen::example::Container*>(cself.ptr);
    }
}

CObject create_StackPrj(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Project>();
        return {strdup("iegen::example::Stack<iegen::example::Project>"), static_cast<iegen::example::Container*>(this_object)};
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

CObject create_StackPrj_1(CObject st, ErrorObj* _Nonnull err){
    
    auto& ctocxxst = *static_cast<iegen::example::Project*>(st.ptr);
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Project>(ctocxxst);
        return {strdup("iegen::example::Stack<iegen::example::Project>"), static_cast<iegen::example::Container*>(this_object)};
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

void _func_StackPrj_push(CObject cself, CObject item, ErrorObj* _Nonnull err){
    
    auto ctocxxitem = static_cast<iegen::example::Project*>(item.ptr);
  
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->push(ctocxxitem);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackPrj_pop(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CObject _func_StackPrj_top(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup("iegen::example::Project");
        CObject cxxtocresult = {type_result, const_cast<iegen::example::Project*>(result)};
        return cxxtocresult;
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

bool _func_StackPrj_empty(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result{};
    return result;
}
void release_StackTask(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<iegen::example::Container*>(cself.ptr);
    }
}

CObject create_StackTask(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Task>();
        return {strdup("iegen::example::Stack<iegen::example::Task>"), static_cast<iegen::example::Container*>(this_object)};
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

CObject create_StackTask_1(CObject st, ErrorObj* _Nonnull err){
    
    auto& ctocxxst = *static_cast<iegen::example::Task*>(st.ptr);
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Task>(ctocxxst);
        return {strdup("iegen::example::Stack<iegen::example::Task>"), static_cast<iegen::example::Container*>(this_object)};
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

void _func_StackTask_push(CObject cself, CObject item, ErrorObj* _Nonnull err){
    
    auto ctocxxitem = static_cast<iegen::example::Task*>(item.ptr);
  
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Task>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->push(ctocxxitem);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackTask_pop(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Task>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CObject _func_StackTask_top(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Task>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup("iegen::example::Task");
        CObject cxxtocresult = {type_result, const_cast<iegen::example::Task*>(result)};
        return cxxtocresult;
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

bool _func_StackTask_empty(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Task>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result{};
    return result;
}
void release_StackNumInt(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<iegen::example::Container*>(cself.ptr);
    }
}

CObject create_StackNumInt(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Number<int>>();
        return {strdup("iegen::example::Stack<iegen::example::Number<int>>"), static_cast<iegen::example::Container*>(this_object)};
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

CObject create_StackNumInt_1(CObject st, ErrorObj* _Nonnull err){
    
    auto& ctocxxst = *static_cast<iegen::example::Number<int>*>(st.ptr);
    try {
        auto this_object = new iegen::example::Stack<iegen::example::Number<int>>(ctocxxst);
        return {strdup("iegen::example::Stack<iegen::example::Number<int>>"), static_cast<iegen::example::Container*>(this_object)};
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

void _func_StackNumInt_push(CObject cself, CObject item, ErrorObj* _Nonnull err){
    
    auto ctocxxitem = static_cast<iegen::example::Number<int>*>(item.ptr);
  
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Number<int>>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->push(ctocxxitem);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_StackNumInt_pop(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Number<int>>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        ctocxxcself->pop();
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CObject _func_StackNumInt_top(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Number<int>>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup("iegen::example::Number<int>");
        CObject cxxtocresult = {type_result, const_cast<iegen::example::Number<int>*>(result)};
        return cxxtocresult;
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

bool _func_StackNumInt_empty(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto ctocxxcself = dynamic_cast<iegen::example::Stack<iegen::example::Number<int>>*>(static_cast<iegen::example::Container*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    bool result{};
    return result;
}
