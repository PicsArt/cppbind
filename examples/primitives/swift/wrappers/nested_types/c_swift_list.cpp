/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/07/2022-09:08.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/nested_types/c_swift_list.h"
#include "cxx/nested_types/list.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_LIST = "cppbind::example::List";
const char* CPPBIND_LIST_ITEM = "cppbind::example::List::Item";
const char* CPPBIND_LIST_ITEM_VALUE = "cppbind::example::List::Item::Value";

using namespace cppbind::example;

void release_CppbindExample_List(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::List*>(cself.ptr);
    }
    free(cself.type);
}

void release_List_Item(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::List::Item*>(cself.ptr);
    }
    free(cself.type);
}

void release_List_Item_Value(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::List::Item::Value*>(cself.ptr);
    }
    free(cself.type);
}

int _prop_get_List_Item_Value_value(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::List::Item::Value*>(cself.ptr);
    decltype(auto) result = ctocxxcself->value;
    
    return result;
}

void _prop_set_List_Item_Value_value(CppBindCObject cself, int value) {
    
    auto ctocxxcself = static_cast<cppbind::example::List::Item::Value*>(cself.ptr);
    
    ctocxxcself->value = value;
}

CppBindCObject create_List_Item_Value(int _value, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::List::Item::Value(_value);
        return {strdup(CPPBIND_LIST_ITEM_VALUE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _prop_get_List_Item_value(CppBindCObject cself) {
    auto ctocxxcself = static_cast<cppbind::example::List::Item*>(cself.ptr);
    decltype(auto) result = ctocxxcself->value;
    
    char* type_result = strdup(CPPBIND_LIST_ITEM_VALUE);
    auto value_ptr_result = result;
    CppBindCObject cxxtocresult = {type_result, value_ptr_result};
    return cxxtocresult;
}

void _prop_set_List_Item_value(CppBindCObject cself, CppBindCObject value) {
    
    auto ctocxxcself = static_cast<cppbind::example::List::Item*>(cself.ptr);
    
    auto ctocxxvalue = static_cast<cppbind::example::List::Item::Value*>(value.ptr);
    ctocxxcself->value = ctocxxvalue;
}

CppBindCObject create_List_Item(CppBindCObject v, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxv = static_cast<cppbind::example::List::Item::Value*>(v.ptr);
    try {
        auto this_object = new cppbind::example::List::Item(ctocxxv);
        return {strdup(CPPBIND_LIST_ITEM), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_List(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::List();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_LIST), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_List_push_back(CppBindCObject cself, CppBindCObject item, CppBindCObject* _Nonnull cppbind_err) {
    
    auto ctocxxitem = static_cast<cppbind::example::List::Item*>(item.ptr);

    auto ctocxxcself = static_cast<cppbind::example::List*>(cself.ptr);
    try {
        ctocxxcself->push_back(ctocxxitem);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_CppbindExample_List_pop_back(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::List*>(cself.ptr);
    try {
        ctocxxcself->pop_back();
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _prop_get_CppbindExample_List_back(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    auto ctocxxcself = static_cast<cppbind::example::List*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->back();
        
        char* type_result = strdup(CPPBIND_LIST_ITEM);
        auto value_ptr_result = result;
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

