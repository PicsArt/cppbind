/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/13/2022-14:16.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/forward_decl/c_swift_student.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/forward_decl/student.hpp"
#include "cxx/forward_decl/teacher.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_TEACHER;

const char* CPPBIND_CPPBIND_EXAMPLE_STUDENT = "cppbind::example::Student";

void release_CppbindExample_Student(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<std::shared_ptr<cppbind::example::Student>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Student(char* _Nonnull st_name, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxst_name = std::string(st_name);
    free(st_name);
    try {
        auto this_object = new cppbind::example::Student(ctocxxst_name);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STUDENT), new std::shared_ptr<cppbind::example::Student>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_Student1(CppBindCDataArray teachers, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::vector<Teacher *> ctocxxteachers;

    auto data_teachers = reinterpret_cast<CppBindCObject*>(teachers.data);

    for (size_t _i_teachers = 0; _i_teachers < teachers.size; ++_i_teachers) {
        auto& value_teachers = data_teachers[_i_teachers];
        
        auto ctocxxvalue_teachers = static_cast<cppbind::example::Teacher*>(value_teachers.ptr);
        ctocxxteachers.emplace_back(ctocxxvalue_teachers);
    }
    try {
        auto this_object = new cppbind::example::Student(ctocxxteachers);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_STUDENT), new std::shared_ptr<cppbind::example::Student>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void _func_CppbindExample_Student_addTeacher(CppBindCObject cself, CppBindCObject t, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    auto ctocxxt = static_cast<cppbind::example::Teacher*>(t.ptr);

    std::shared_ptr<cppbind::example::Student> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Student>*>(cself.ptr);
    try {
        ctocxxcself->addTeacher(ctocxxt);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCDataArray _func_CppbindExample_Student_teachers(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::Student> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Student>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->teachers();
        auto _data_cxxtocresult = new CppBindCObject [result.size()];
        CppBindCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            char* type_value_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TEACHER);
            auto value_ptr_value_result = value_result;
            CppBindCObject cxxtocvalue_result = {type_value_result, value_ptr_value_result};
            _data_cxxtocresult[_i_result] = cxxtocvalue_result;
        }
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCDataArray result {};
    return result;
}

char* _Nonnull _prop_get_CppbindExample_Student_name(CppBindCObject cself) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::Student> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Student>*>(cself.ptr);
    decltype(auto) result = ctocxxcself->name;
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

void _prop_set_CppbindExample_Student_name(CppBindCObject cself, char* _Nonnull name) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::Student> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::Student>*>(cself.ptr);
    auto ctocxxname = std::string(name);
    free(name);
    ctocxxcself->name = ctocxxname;
}

