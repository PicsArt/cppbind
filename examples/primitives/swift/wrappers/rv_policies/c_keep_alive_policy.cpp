/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/23/2022-11:06.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/rv_policies/c_keep_alive_policy.h"
#include "cxx/rv_policies/keep_alive_policy.hpp"

using namespace iegen::example;

void release_Child1(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Child1*>(cself.ptr);
    }
}

IEGenCObject create_Child1(char* _Nonnull name, IEGenCObject* _Nonnull err){
    auto ctocxxname = std::string(name);
    free(name);
    try {
        auto this_object = new iegen::example::Child1(ctocxxname);
        return {strdup("iegen::example::Child1"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
char* _Nonnull _prop_get_Child1_name(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Child1*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->name();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
void release_Child3Impl(IEGenCObject cself, bool owner){
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Child3*>(cself.ptr);
    }
}

IEGenCObject create_Child3(char* _Nonnull name, IEGenCObject* _Nonnull err){
    auto ctocxxname = std::string(name);
    free(name);
    try {
        auto this_object = new iegen::example::Child3(ctocxxname);
        return {strdup("iegen::example::Child3"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
char* _Nonnull _prop_get_Child3_name(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Child3*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->name();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
void release_Child2(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<std::shared_ptr<iegen::example::Child2>*>(cself.ptr);
    }
}

IEGenCObject create_Child2(char* _Nonnull name, IEGenCObject* _Nonnull err){
    auto ctocxxname = std::string(name);
    free(name);
    try {
        auto this_object = new iegen::example::Child2(ctocxxname);
        return {strdup("iegen::example::Child2"), new std::shared_ptr<iegen::example::Child2>(this_object)};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
char* _Nonnull _prop_get_Child2_name(IEGenCObject cself, IEGenCObject* _Nonnull err){
    std::shared_ptr<iegen::example::Child2> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<iegen::example::Child2>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->name();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
void release_Parent1(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Parent1*>(cself.ptr);
    }
}

IEGenCObject create_Parent1(char* _Nonnull name, IEGenCObject child1, IEGenCObject child2, IEGenCObject _child3, IEGenCObject* _Nonnull err){
    auto ctocxxname = std::string(name);
    free(name);
    
    auto ctocxxchild1 = static_cast<iegen::example::Child1*>(child1.ptr);
    
    std::shared_ptr<iegen::example::Child2> ctocxxchild2;
    ctocxxchild2 = *static_cast<std::shared_ptr<iegen::example::Child2>*>(child2.ptr);
    
    auto ctocxx_child3 = static_cast<iegen::example::Child3*>(_child3.ptr);
    try {
        auto this_object = new iegen::example::Parent1(ctocxxname, ctocxxchild1, ctocxxchild2, ctocxx_child3);
        return {strdup("iegen::example::Parent1"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
char* _Nonnull _prop_get_Parent1_name(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->name();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
IEGenCObject _prop_get_Parent1_child1(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->child1();
        
        char* type_result = strdup("iegen::example::Child1");
        auto value_ptr_result = const_cast<iegen::example::Child1*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

void _prop_set_Parent1_child1(IEGenCObject cself, IEGenCObject child1, IEGenCObject* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    
    auto ctocxxchild1 = static_cast<iegen::example::Child1*>(child1.ptr);
    try {
        ctocxxcself->setChild1(ctocxxchild1);
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
}

IEGenCObject _prop_get_Parent1_child2(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->child2();
        
        char* type_result = strdup("iegen::example::Child2");
        void* cxxtocresult_ptr;
        cxxtocresult_ptr = new std::shared_ptr<iegen::example::Child2>(result);
        IEGenCObject cxxtocresult = {type_result, cxxtocresult_ptr};
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
IEGenCObject _prop_get_Parent1_child3(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    const auto& result = ctocxxcself->child3;
    
    char* type_result = strdup("iegen::example::Child3");
    auto value_ptr_result = const_cast<iegen::example::Child3*>(result);
    IEGenCObject cxxtocresult = {type_result, value_ptr_result};
    return cxxtocresult;
}
void _prop_set_Parent1_child3(IEGenCObject cself, IEGenCObject child3){
    
    auto ctocxxcself = static_cast<iegen::example::Parent1*>(cself.ptr);
    
    auto ctocxxchild3 = static_cast<iegen::example::Child3*>(child3.ptr);
    ctocxxcself->child3 = ctocxxchild3;
}

void release_Parent2(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Parent2*>(cself.ptr);
    }
}

IEGenCObject create_Parent2(char* _Nonnull name, IEGenCObject* _Nonnull err){
    auto ctocxxname = std::string(name);
    free(name);
    try {
        auto this_object = new iegen::example::Parent2(ctocxxname);
        return {strdup("iegen::example::Parent2"), this_object};
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}
char* _Nonnull _prop_get_Parent2_name(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->name();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
IEGenCDataArray _prop_get_Parent2_children1(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->children1();
        auto _data_cxxtocresult = new IEGenCObject [result.size()];
        IEGenCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            char* type_value_result = strdup("iegen::example::Child1");
            auto value_ptr_value_result = const_cast<iegen::example::Child1*>(value_result);
            IEGenCObject cxxtocvalue_result = {type_value_result, value_ptr_value_result};
            _data_cxxtocresult[_i_result] = cxxtocvalue_result;
        }
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCDataArray result {};
    return result;
}

void _func_Parent2_addChild1(IEGenCObject cself, IEGenCObject c, IEGenCObject* _Nonnull err){
    
    auto ctocxxc = static_cast<iegen::example::Child1*>(c.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        ctocxxcself->addChild1(ctocxxc);
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
}

void _func_Parent2_addChildren1(IEGenCObject cself, IEGenCDataArray c, IEGenCObject* _Nonnull err){
    std::vector<Child1 *> ctocxxc;

    auto data_c = reinterpret_cast<IEGenCObject*>(c.data);

    for (size_t _i_c = 0; _i_c < c.size; ++_i_c) {
        auto& value_c = data_c[_i_c];
        
        auto ctocxxvalue_c = static_cast<iegen::example::Child1*>(value_c.ptr);
        ctocxxc.emplace_back(ctocxxvalue_c);
    }
  
    
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        ctocxxcself->addChildren1(ctocxxc);
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
}

void _func_Parent2_addChild2(IEGenCObject cself, IEGenCObject c, IEGenCObject* _Nonnull err){
    
    std::shared_ptr<iegen::example::Child2> ctocxxc;
    ctocxxc = *static_cast<std::shared_ptr<iegen::example::Child2>*>(c.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        ctocxxcself->addChild2(ctocxxc);
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
}

void _func_Parent2_addChildren2(IEGenCObject cself, IEGenCDataArray c, IEGenCObject* _Nonnull err){
    std::vector<std::shared_ptr<Child2>> ctocxxc;

    auto data_c = reinterpret_cast<IEGenCObject*>(c.data);

    for (size_t _i_c = 0; _i_c < c.size; ++_i_c) {
        auto& value_c = data_c[_i_c];
        
        std::shared_ptr<iegen::example::Child2> ctocxxvalue_c;
        ctocxxvalue_c = *static_cast<std::shared_ptr<iegen::example::Child2>*>(value_c.ptr);
        ctocxxc.emplace_back(ctocxxvalue_c);
    }
  
    
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        ctocxxcself->addChildren2(ctocxxc);
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
}
IEGenCDataArray _prop_get_Parent2_children2(IEGenCObject cself, IEGenCObject* _Nonnull err){
    auto ctocxxcself = static_cast<iegen::example::Parent2*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->children2();
        auto _data_cxxtocresult = new IEGenCObject [result.size()];
        IEGenCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            char* type_value_result = strdup("iegen::example::Child2");
            void* cxxtocvalue_result_ptr;
            cxxtocvalue_result_ptr = new std::shared_ptr<iegen::example::Child2>(value_result);
            IEGenCObject cxxtocvalue_result = {type_value_result, cxxtocvalue_result_ptr};
            _data_cxxtocresult[_i_result] = cxxtocvalue_result;
        }
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCDataArray result {};
    return result;
}