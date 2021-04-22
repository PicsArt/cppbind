#include <string.h>
#include <memory>
#include "swift/wrappers/operators/c_counter.h"
#include "cxx/operators/counter.hpp"

void release_Counter(void* _Nonnull cself){
        delete dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
}
void* _Nonnull create_Counter(int count){
    
    auto this_object = new iegen::example::Counter(count);
    return static_cast<iegen::example::Counter*>(this_object);
}
int _prop_get_Counter_count(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
    auto result = c_to_cxx_cself->count();
    
    return result;
}
void* _Nonnull _func_Counter_operator_add_(void* _Nonnull cself , void* _Nonnull counter){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_counter = *dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(counter));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
    const auto& result = c_to_cxx_cself->operator+(c_to_cxx_counter);
    auto value_ptr_result = const_cast<iegen::example::Counter*>( new iegen::example::Counter(result) );
    auto cxx_to_c_result = static_cast<iegen::example::Counter*>(value_ptr_result);
    return cxx_to_c_result;
}
int _func_Counter_compareTo(void* _Nonnull cself , void* _Nonnull counter){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_counter = *dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(counter));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
    const auto& result = c_to_cxx_cself->compareTo(c_to_cxx_counter);
    
    return result;
}
bool _func_Counter_operator_gt_(void* _Nonnull cself , void* _Nonnull counter){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_counter = *dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(counter));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
    const auto& result = c_to_cxx_cself->operator>(c_to_cxx_counter);
    
    return result;
}
void* _Nonnull _func_Counter_operator_iadd_(void* _Nonnull cself , void* _Nonnull counter){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_counter = *dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(counter));
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Counter*>(static_cast<iegen::example::Counter*>(cself));
    const auto& result = c_to_cxx_cself->operator+=(c_to_cxx_counter);
    auto value_ptr_result = const_cast<iegen::example::Counter*>( &result );
    auto cxx_to_c_result = static_cast<iegen::example::Counter*>(value_ptr_result);
    return cxx_to_c_result;
}