/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/17/2022-09:29.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/nested_types/usage/c_swift_list_usage.h"
#include "cxx/nested_types/list_usage.hpp"
#include "cxx/nested_types/list.hpp"
#include "cxx/nested_types/template_list.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_LIST_ITEM;
extern const char* CPPBIND_TEMPLATELISTINT_ITEM;

const char* CPPBIND_CPPBIND_EXAMPLE_LISTWRAPPER = "cppbind::example::ListWrapper";
const char* CPPBIND_CPPBIND_EXAMPLE_INTLISTITEMWRAPPER = "cppbind::example::IntListItemWrapper";

using namespace cppbind::example;

void release_CppbindExample_ListWrapper(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::ListWrapper*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_ListWrapper(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::ListWrapper();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_LISTWRAPPER), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_ListWrapper_push_back(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<List::Item*>(item.ptr);

    auto ctocxxcself = static_cast<cppbind::example::ListWrapper*>(cself.ptr);
    try {
        ctocxxcself->push_back(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _prop_get_CppbindExample_ListWrapper_back(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::ListWrapper*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->back();
        
        char* type_result = strdup(CPPBIND_LIST_ITEM);
        auto value_ptr_result = const_cast<List::Item*>(result);
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

void release_CppbindExample_IntListItemWrapper(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::IntListItemWrapper*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_IntListItemWrapper(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::IntListItemWrapper();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_INTLISTITEMWRAPPER), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_IntListItemWrapper_set(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<TemplateList<int>::Item*>(item.ptr);

    auto ctocxxcself = static_cast<cppbind::example::IntListItemWrapper*>(cself.ptr);
    try {
        ctocxxcself->set(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_CppbindExample_IntListItemWrapper_get(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::IntListItemWrapper*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->get();
        
        char* type_result = strdup(CPPBIND_TEMPLATELISTINT_ITEM);
        auto value_ptr_result = const_cast<TemplateList<int>::Item*>(result);
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

