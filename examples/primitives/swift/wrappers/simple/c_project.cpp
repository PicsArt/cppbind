#include <string.h>
#include <memory>
#include "swift/wrappers/simple/c_project.h"
#include "cxx/simple/project.hpp"


using namespace iegen::example;
void release_Project(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(cself));
}
void* _Nonnull create_Project(char* _Nonnull title){
    auto c_to_cxx_title = std::string(title);
    free(title);
    auto this_object = new iegen::example::Project(c_to_cxx_title);
    return static_cast<iegen::example::Project*>(this_object);
}
char* _Nonnull _prop_get_Project_title(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(cself));
    auto result = c_to_cxx_cself->title();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
void _func_Project_addTask(void* _Nonnull cself , void* _Nonnull task, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Task> c_to_cxx_task;
    auto baseptr = *reinterpret_cast<std::shared_ptr<iegen::example::Task>*>(task);
    c_to_cxx_task = std::dynamic_pointer_cast<iegen::example::Task>(baseptr);
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(cself));
    try {
      c_to_cxx_cself->addTask(c_to_cxx_task);
    }
    catch (const std::exception& e) {
        err->is_err = true;
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->is_err = true;
    }
}
CDataArray _func_Project_tasks(void* _Nonnull cself , ErrorObj* _Nonnull err){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(cself));
    try {
      const auto& result = c_to_cxx_cself->tasks();
      auto _data_cxx_to_c_result = new void* _Nonnull [result.size()];
    CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
    for (int _i = 0; _i < result.size(); ++_i) {
      auto& value_result = result[_i];
      
        void* _Nonnull cxx_to_c_value_result;
        std::shared_ptr<iegen::example::Task> baseptr = std::static_pointer_cast<iegen::example::Task>(value_result);
        cxx_to_c_value_result = reinterpret_cast<void* _Nonnull>(new std::shared_ptr<iegen::example::Task>(baseptr));
      _data_cxx_to_c_result[_i] = cxx_to_c_value_result;
    }
      return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->is_err = true;
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->is_err = true;
    }
    CDataArray result;
    return result;
}