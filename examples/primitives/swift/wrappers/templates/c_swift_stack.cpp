/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/06/2022-15:44.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/templates/c_swift_stack.h"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/number.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_PROJECT;
extern const char* CPPBIND_CPPBIND_EXAMPLE_TASK;
extern const char* CPPBIND_CPPBIND_EXAMPLE_NUMBERINT;

const char* CPPBIND_CPPBIND_EXAMPLE_STACKPRJ = "cppbind::example::Stack<cppbind::example::Project>";
const char* CPPBIND_CPPBIND_EXAMPLE_STACKTASK = "cppbind::example::Stack<cppbind::example::Task>";
const char* CPPBIND_CPPBIND_EXAMPLE_STACKNUMINT = "cppbind::example::Stack<cppbind::example::Number<int>>";

using namespace cppbind::example;

void release_CppbindExample_StackPrj(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Stack<cppbind::example::Project>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_StackPrj(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Project>();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKPRJ), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackPrj_1(CppBindCObject stack, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxstack = *static_cast<cppbind::example::Stack<cppbind::example::Project>*>(stack.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Project>(ctocxxstack);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKPRJ), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackPrj_2(CppBindCObject st, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxst = static_cast<cppbind::example::Project*>(st.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Project>(ctocxxst);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKPRJ), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_StackPrj_push(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<cppbind::example::Project*>(item.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Project>*>(cself.ptr);
    try {
        ctocxxcself->push(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_CppbindExample_StackPrj_pop(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Project>*>(cself.ptr);
    try {
        ctocxxcself->pop();
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_CppbindExample_StackPrj_top(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Project>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        auto value_ptr_result = const_cast<cppbind::example::Project*>(result);
        CppBindCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

bool _func_CppbindExample_StackPrj_empty(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Project>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

void release_CppbindExample_StackTask(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Stack<cppbind::example::Task>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_StackTask(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Task>();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKTASK), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackTask_1(CppBindCObject stack, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxstack = *static_cast<cppbind::example::Stack<cppbind::example::Task>*>(stack.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Task>(ctocxxstack);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKTASK), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackTask_2(CppBindCObject st, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxst = static_cast<cppbind::example::Task*>(st.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Task>(ctocxxst);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKTASK), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_StackTask_push(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<cppbind::example::Task*>(item.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Task>*>(cself.ptr);
    try {
        ctocxxcself->push(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_CppbindExample_StackTask_pop(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Task>*>(cself.ptr);
    try {
        ctocxxcself->pop();
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_CppbindExample_StackTask_top(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Task>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TASK);
        auto value_ptr_result = const_cast<cppbind::example::Task*>(result);
        CppBindCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

bool _func_CppbindExample_StackTask_empty(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Task>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

void release_CppbindExample_StackNumInt(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_StackNumInt(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Number<int>>();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKNUMINT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackNumInt_1(CppBindCObject stack, CppBindCObject* _Nonnull cppbind_err) {
    
    auto& ctocxxstack = *static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(stack.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Number<int>>(ctocxxstack);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKNUMINT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_StackNumInt_2(CppBindCObject st, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxst = static_cast<cppbind::example::Number<int>*>(st.ptr);
    try {
        auto this_object = new cppbind::example::Stack<cppbind::example::Number<int>>(ctocxxst);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STACKNUMINT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_StackNumInt_push(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<cppbind::example::Number<int>*>(item.ptr);
  
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(cself.ptr);
    try {
        ctocxxcself->push(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_CppbindExample_StackNumInt_pop(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(cself.ptr);
    try {
        ctocxxcself->pop();
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_CppbindExample_StackNumInt_top(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->top();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_NUMBERINT);
        auto value_ptr_result = const_cast<cppbind::example::Number<int>*>(result);
        CppBindCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

bool _func_CppbindExample_StackNumInt_empty(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::Stack<cppbind::example::Number<int>>*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->empty();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

