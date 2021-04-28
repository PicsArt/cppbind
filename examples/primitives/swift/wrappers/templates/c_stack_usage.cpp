#include <string.h>
#include <memory>
#include "swift/wrappers/templates/c_stack_usage.h"
#include "cxx/templates/stack_usage.hpp"
#include "cxx/classes/project.hpp"

using namespace iegen::example;
void release_StackUsage(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::StackUsage*>(static_cast<iegen::example::StackUsage*>(cself));
}
void* _Nonnull create_StackUsage(){
    auto this_object = new iegen::example::StackUsage();
    return static_cast<iegen::example::StackUsage*>(this_object);
}
void* _Nonnull _func_StackUsage_firstItemOfSpecialized(void* _Nonnull cself , void* _Nonnull p){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_p = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(p));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::StackUsage*>(static_cast<iegen::example::StackUsage*>(cself));
    const auto& result = c_to_cxx_cself->firstItemOfSpecialized(c_to_cxx_p);
    auto value_ptr_result = const_cast<iegen::example::Project*>(result);
    auto cxx_to_c_result = static_cast<iegen::example::Project*>(value_ptr_result);
    return cxx_to_c_result;
}
void* _Nonnull _func_StackUsage_firstItemOfTemplateProject(void* _Nonnull cself , void* _Nonnull arg0){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_arg0 = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(arg0));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::StackUsage*>(static_cast<iegen::example::StackUsage*>(cself));
    const auto& result = c_to_cxx_cself->firstItemOfTemplate(c_to_cxx_arg0);
    auto value_ptr_result = const_cast<iegen::example::Project*>(result);
    auto cxx_to_c_result = static_cast<iegen::example::Project*>(value_ptr_result);
    return cxx_to_c_result;
}