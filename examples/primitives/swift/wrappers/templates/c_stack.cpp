#include <string.h>
#include <memory>
#include "swift/wrappers/templates/c_stack.h"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"


using namespace iegen::example;
void release_StackProject(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(cself));
}
void* _Nonnull create_StackProject(){
    auto this_object = new iegen::example::Stack<iegen::example::Project>();
    return static_cast<iegen::example::Stack<iegen::example::Project>*>(this_object);
}
void* _Nonnull create_StackProject_1(void* _Nonnull st){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto& c_to_cxx_st = *dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(st));
    auto this_object = new iegen::example::Stack<iegen::example::Project>(c_to_cxx_st);
    return static_cast<iegen::example::Stack<iegen::example::Project>*>(this_object);
}
void _func_StackProject_push(void* _Nonnull cself , void* _Nonnull item){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_item = dynamic_cast<iegen::example::Project*>(static_cast<iegen::example::Project*>(item));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(cself));
  c_to_cxx_cself->push(c_to_cxx_item);
}
void _func_StackProject_pop(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(cself));
  c_to_cxx_cself->pop();
}
void* _Nonnull _func_StackProject_top(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(cself));
    const auto& result = c_to_cxx_cself->top();
    auto value_ptr_result = const_cast<iegen::example::Project*>(result);
    auto cxx_to_c_result = static_cast<iegen::example::Project*>(value_ptr_result);
    return cxx_to_c_result;
}
bool _func_StackProject_empty(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Project>*>(static_cast<iegen::example::Stack<iegen::example::Project>*>(cself));
    const auto& result = c_to_cxx_cself->empty();
    
    return result;
}

using namespace iegen::example;
void release_StackRoot(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Stack<iegen::example::Root>*>(static_cast<iegen::example::Stack<iegen::example::Root>*>(cself));
}
void* _Nonnull create_StackRoot(){
    auto this_object = new iegen::example::Stack<iegen::example::Root>();
    return static_cast<iegen::example::Stack<iegen::example::Root>*>(this_object);
}
void* _Nonnull create_StackRoot_1(void* _Nonnull st){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto& c_to_cxx_st = *dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(st));
    auto this_object = new iegen::example::Stack<iegen::example::Root>(c_to_cxx_st);
    return static_cast<iegen::example::Stack<iegen::example::Root>*>(this_object);
}
void _func_StackRoot_push(void* _Nonnull cself , void* _Nonnull item){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_item = dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(item));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Root>*>(static_cast<iegen::example::Stack<iegen::example::Root>*>(cself));
  c_to_cxx_cself->push(c_to_cxx_item);
}
void _func_StackRoot_pop(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Root>*>(static_cast<iegen::example::Stack<iegen::example::Root>*>(cself));
  c_to_cxx_cself->pop();
}
void* _Nonnull _func_StackRoot_top(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Root>*>(static_cast<iegen::example::Stack<iegen::example::Root>*>(cself));
    const auto& result = c_to_cxx_cself->top();
    auto value_ptr_result = const_cast<iegen::example::Root*>(result);
    auto cxx_to_c_result = static_cast<iegen::example::Root*>(value_ptr_result);
    return cxx_to_c_result;
}
bool _func_StackRoot_empty(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Stack<iegen::example::Root>*>(static_cast<iegen::example::Stack<iegen::example::Root>*>(cself));
    const auto& result = c_to_cxx_cself->empty();
    
    return result;
}