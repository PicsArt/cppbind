/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/28/2021-11:59.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/optionals/c_optionals.h"
#include "cxx/optionals/optionals.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/getters/person.hpp"
#include "cxx/enums/color.hpp"

using namespace iegen::example;

void release_Optionals(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Optionals*>(static_cast<iegen::example::Optionals*>(cself));
}

void* _Nonnull create_Optionals(){
    auto this_object = new iegen::example::Optionals();
    return this_object;
}

void* _Nullable _func_Optionals_optionalPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable task, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_task = static_cast<iegen::example::Task*>(task);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalPtrWithNullptrDefault(c_to_cxx_task);
        
        auto cxx_to_c_result = const_cast<iegen::example::Task*>(result);
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

void* _Nullable _func_Optionals_optionalPtrWithNullDefault(void* _Nonnull cself, void* _Nullable task, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_task = static_cast<iegen::example::Task*>(task);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalPtrWithNullDefault(c_to_cxx_task);
        
        auto cxx_to_c_result = const_cast<iegen::example::Task*>(result);
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

void* _Nullable _func_Optionals_optionalFDPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable project, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_project = static_cast<iegen::example::Project*>(project);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalFDPtrWithNullptrDefault(c_to_cxx_project);
        
        auto cxx_to_c_result = const_cast<iegen::example::Project*>(result);
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

void* _Nullable _func_Optionals_optionalSharedPtrWithNullptrDefault(void* _Nonnull cself, void* _Nullable person, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Person> c_to_cxx_person = nullptr;
    if (person) {
        c_to_cxx_person = *static_cast<std::shared_ptr<iegen::example::Person>*>(person);
    }
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalSharedPtrWithNullptrDefault(c_to_cxx_person);
        
        void* cxx_to_c_result = nullptr;
        if (result) {
            cxx_to_c_result = reinterpret_cast<void*>(new std::shared_ptr<iegen::example::Person>(result));
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

int _func_Optionals_optionalIntWithDefault(void* _Nonnull cself, int value, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalIntWithDefault(value);
        
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

long _func_Optionals_optionalLongWithDefault(void* _Nonnull cself, long value, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalLongWithDefault(value);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    long result;
    return result;
}

double _func_Optionals_optionalDoubleWithDefault(void* _Nonnull cself, double value, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalDoubleWithDefault(value);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    double result;
    return result;
}

float _func_Optionals_optionalFloatWithDefault(void* _Nonnull cself, float value, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalFloatWithDefault(value);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    float result;
    return result;
}

bool _func_Optionals_optionalBoolWithDefault(void* _Nonnull cself, bool value, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalBoolWithDefault(value);
        
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

char* _Nonnull _func_Optionals_optionalStringWithDefault(void* _Nonnull cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err){
    auto c_to_cxx_optionalStr = std::string(optionalStr);
    free(optionalStr);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalStringWithDefault(c_to_cxx_optionalStr);
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

char* _Nonnull _func_Optionals_optionalStringViewWithDefault(void* _Nonnull cself, char* _Nonnull optionalStr, ErrorObj* _Nonnull err){
    auto c_to_cxx_optionalStr = std::string(optionalStr);
    free(optionalStr);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalStringViewWithDefault(c_to_cxx_optionalStr);
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

const char * _Nonnull _func_Optionals_optionalCharPointerWithDefault(void* _Nonnull cself, const char * _Nonnull optionalStr, ErrorObj* _Nonnull err){
    
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalCharPointerWithDefault(optionalStr);
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    const char * result;
    return result;
}

unsigned int _func_Optionals_optionalEnumWithDefault(void* _Nonnull cself, unsigned int c, ErrorObj* _Nonnull err){
    auto c_to_cxx_c = (iegen::example::Color)c;
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalEnumWithDefault(c_to_cxx_c);
        unsigned int cxx_to_c_result = (unsigned int)result;
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    unsigned int result;
    return result;
}

unsigned int _func_Optionals_optionalEnumWithDefaultAndFieldPrefix(void* _Nonnull cself, unsigned int c, ErrorObj* _Nonnull err){
    auto c_to_cxx_c = (iegen::example::ColorShade)c;
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalEnumWithDefaultAndFieldPrefix(c_to_cxx_c);
        unsigned int cxx_to_c_result = (unsigned int)result;
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    unsigned int result;
    return result;
}

void* _Nonnull _func_Optionals_optionalRefWithDefaultComplexValue(void* _Nonnull cself, void* _Nonnull task, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_task = *static_cast<iegen::example::Task*>(task);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalRefWithDefaultComplexValue(c_to_cxx_task);
        
        auto cxx_to_c_result = const_cast<iegen::example::Task*>( &result );
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

void* _Nonnull _func_Optionals_optionalByValWithDefaultComplexValue(void* _Nonnull cself, void* _Nonnull task, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_task = *static_cast<iegen::example::Task*>(task);
  
    
    auto c_to_cxx_cself = static_cast<iegen::example::Optionals*>(cself);
    try {
        const auto& result = c_to_cxx_cself->optionalByValWithDefaultComplexValue(c_to_cxx_task);
        
        auto cxx_to_c_result = const_cast<iegen::example::Task*>( new iegen::example::Task(result) );
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