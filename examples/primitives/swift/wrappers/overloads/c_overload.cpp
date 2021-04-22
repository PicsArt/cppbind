#include <string.h>
#include <memory>
#include "swift/wrappers/overloads/c_overload.h"
#include "cxx/overloads/overload.hpp"

void release_OverloadedFunctions(void* _Nonnull cself){
        delete static_cast<std::shared_ptr<iegen::example::OverloadedFunctions>*>(cself);
}
void* _Nonnull create_OverloadedFunctions(){
    auto this_object = new iegen::example::OverloadedFunctions();
    return new std::shared_ptr<iegen::example::OverloadedFunctions>(this_object);
}
char* _Nonnull _func_OverloadedFunctions_concatenate(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second){
    auto c_to_cxx_first = std::string(first);
    free(first);
  
    auto c_to_cxx_second = std::string(second);
    free(second);
  
        auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::OverloadedFunctions>(
                  *static_cast<std::shared_ptr<iegen::example::OverloadedFunctions>*>(cself)
                  );
    const auto& result = c_to_cxx_cself->concatenate(c_to_cxx_first, c_to_cxx_second);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
char* _Nonnull _func_OverloadedFunctions_concatenate_1(void* _Nonnull cself , char* _Nonnull first, char* _Nonnull second, char* _Nonnull third){
    auto c_to_cxx_first = std::string(first);
    free(first);
  
    auto c_to_cxx_second = std::string(second);
    free(second);
  
    auto c_to_cxx_third = std::string(third);
    free(third);
  
        auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::OverloadedFunctions>(
                  *static_cast<std::shared_ptr<iegen::example::OverloadedFunctions>*>(cself)
                  );
    const auto& result = c_to_cxx_cself->concatenate(c_to_cxx_first, c_to_cxx_second, c_to_cxx_third);
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}