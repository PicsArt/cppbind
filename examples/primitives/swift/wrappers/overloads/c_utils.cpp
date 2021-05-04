#include <string.h>
#include <memory>
#include "swift/wrappers/overloads/c_utils.h"
#include "cxx/overloads/utils.hpp"


using namespace iegen::example;
void release_Utils(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::Utils>*>(cself);
}
void* _Nonnull create_Utils(){
    auto this_object = new iegen::example::Utils();
    return new std::shared_ptr<iegen::example::Utils>(this_object);
}
int _func_Utils_sum(int first, int second){
    
  
    
  
    const auto& result = iegen::example::Utils::sum(first, second);
    
    return result;
}
float _func_Utils_sum_1(float first, float second){
    
  
    
  
    const auto& result = iegen::example::Utils::sum(first, second);
    
    return result;
}
char* _Nonnull _func_Utils_concatenate(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second){
    auto c_to_cxx_first = std::string(first);
    free(first);
  
    auto c_to_cxx_second = std::string(second);
    free(second);
  
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Utils>(
              *static_cast<std::shared_ptr<iegen::example::Utils>*>(cself)
              );
    const auto& result = c_to_cxx_cself->concatenate(c_to_cxx_first, c_to_cxx_second);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
char* _Nonnull _func_Utils_concatenate_1(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second, char* _Nonnull third){
    auto c_to_cxx_first = std::string(first);
    free(first);
  
    auto c_to_cxx_second = std::string(second);
    free(second);
  
    auto c_to_cxx_third = std::string(third);
    free(third);
  
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Utils>(
              *static_cast<std::shared_ptr<iegen::example::Utils>*>(cself)
              );
    const auto& result = c_to_cxx_cself->concatenate(c_to_cxx_first, c_to_cxx_second, c_to_cxx_third);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}