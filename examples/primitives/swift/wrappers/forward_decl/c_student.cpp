/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/15/2021-18:09.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/forward_decl/c_student.h"
#include "cxx/forward_decl/student.hpp"
#include "cxx/forward_decl/teacher.hpp"

using namespace iegen::example;

void release_Student(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::Student>*>(cself);
}

void* _Nonnull create_Student(char* _Nonnull st_name){
    auto c_to_cxx_st_name = std::string(st_name);
    free(st_name);
    auto this_object = new iegen::example::Student(c_to_cxx_st_name);
    return new std::shared_ptr<iegen::example::Student>(this_object);
}

void* _Nonnull create_Student_1(CDataArray teachers){
    std::vector<Teacher *> c_to_cxx_teachers;

    auto data_teachers = reinterpret_cast<void**>(teachers.data);

    for (size_t _i_teachers = 0; _i_teachers < teachers.size; ++_i_teachers) {
        auto& value_teachers = data_teachers[_i_teachers];
        
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto c_to_cxx_value_teachers = dynamic_cast<iegen::example::Teacher*>(static_cast<iegen::example::Teacher*>(value_teachers));
        c_to_cxx_teachers.emplace_back(c_to_cxx_value_teachers);
    }
    auto this_object = new iegen::example::Student(c_to_cxx_teachers);
    return new std::shared_ptr<iegen::example::Student>(this_object);
}

void _func_Student_addTeacher(void* _Nonnull cself, void* _Nonnull t, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_t = dynamic_cast<iegen::example::Teacher*>(static_cast<iegen::example::Teacher*>(t));
  
    
    std::shared_ptr<iegen::example::Student> c_to_cxx_cself;
    c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Student>(*static_cast<std::shared_ptr<iegen::example::Student>*>(cself));
    try {
        c_to_cxx_cself->addTeacher(c_to_cxx_t);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CDataArray _func_Student_teachers(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Student> c_to_cxx_cself;
    c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Student>(*static_cast<std::shared_ptr<iegen::example::Student>*>(cself));
    try {
        const auto& result = c_to_cxx_cself->teachers();
        auto _data_cxx_to_c_result = new void* [result.size()];
        CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            auto value_ptr_value_result = const_cast<iegen::example::Teacher*>(value_result);
            auto cxx_to_c_value_result = static_cast<iegen::example::Teacher*>(value_ptr_value_result);
            _data_cxx_to_c_result[_i_result] = cxx_to_c_value_result;
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
    CDataArray result;
    return result;
}
char* _Nonnull _prop_get_Student_name(void* _Nonnull cself){
    std::shared_ptr<iegen::example::Student> c_to_cxx_cself;
    c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Student>(*static_cast<std::shared_ptr<iegen::example::Student>*>(cself));
    auto result = c_to_cxx_cself->name;
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}
void _prop_set_Student_name(void* _Nonnull cself, char* _Nonnull name){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Student>(
              *static_cast<std::shared_ptr<iegen::example::Student>*>(cself)
              );
    auto c_to_cxx_name = std::string(name);
    free(name);
    c_to_cxx_cself->name = c_to_cxx_name;
}
