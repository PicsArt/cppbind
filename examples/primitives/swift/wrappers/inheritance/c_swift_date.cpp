/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:05.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_swift_date.h"
#include "cxx/inheritance/date.hpp"
#include "cxx/inheritance/datetime.hpp"

extern const char* CPPBIND_CPPBIND_EXAMPLE_DATETIME;
extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_MYDATE = "cppbind::example::Date";

using namespace cppbind::example;

void release_CppbindExample_MyDate(CppBindCObject cself, bool owner) {
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_MYDATE) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::Date>*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_DATETIME) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::DateTime>*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

std::shared_ptr<cppbind::example::Date> recover_obj_from_CppbindExample_MyDate(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_MYDATE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::Date>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_DATETIME) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::DateTime>*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_MyDate(int d, int m, int y, CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::Date(d, m, y);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_MYDATE), new std::shared_ptr<cppbind::example::Date>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_MyDate_value(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    std::shared_ptr<cppbind::example::Date> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_MyDate(cself);
    try {
        const auto& result = ctocxxcself->value();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

char* _Nonnull _prop_get_CppbindExample_MyDate_date(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    std::shared_ptr<cppbind::example::Date> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_MyDate(cself);
    try {
        const auto& result = ctocxxcself->date();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
