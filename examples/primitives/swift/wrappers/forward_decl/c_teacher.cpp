#include <string.h>
#include <memory>
#include "swift/wrappers/forward_decl/c_teacher.h"
#include "cxx/forward_decl/teacher.hpp"
#include "cxx/forward_decl/student.hpp"


using namespace iegen::example;
void release_Teacher(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Teacher*>(static_cast<iegen::example::Teacher*>(cself));
}
void* _Nonnull create_Teacher(){
    auto this_object = new iegen::example::Teacher();
    return static_cast<iegen::example::Teacher*>(this_object);
}
void _func_Teacher_addStudent(void* _Nonnull cself , void* _Nonnull s){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_s = dynamic_cast<iegen::example::Student*>(static_cast<iegen::example::Student*>(s));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Teacher*>(static_cast<iegen::example::Teacher*>(cself));
  c_to_cxx_cself->addStudent(c_to_cxx_s);
}
CDataArray _func_Teacher_students(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Teacher*>(static_cast<iegen::example::Teacher*>(cself));
    const auto& result = c_to_cxx_cself->students();
    auto _data_cxx_to_c_result = new void* _Nonnull [result.size()];
    CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
    for (int _i = 0; _i < result.size(); ++_i) {
      auto& value_result = result[_i];
      auto value_ptr_value_result = const_cast<iegen::example::Student*>(value_result);
        auto cxx_to_c_value_result = static_cast<iegen::example::Student*>(value_ptr_value_result);
      _data_cxx_to_c_result[_i] = cxx_to_c_value_result;
    }
    return cxx_to_c_result;
}