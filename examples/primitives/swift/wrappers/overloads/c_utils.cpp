#include <string.h>
#include <memory>
#include "swift/wrappers/overloads/c_utils.h"
#include "cxx/overloads/utils.hpp"


using namespace iegen::example;
void release_Utils(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::Utils>*>(cself);
}
int _func_Utils_sum(int first, int second){
    
  
    
  
    const auto& result = iegen::example::Utils::sum(first, second);
    
    return result;
}
float _func_Utils_sum_1(float first, float second){
    
  
    
  
    const auto& result = iegen::example::Utils::sum(first, second);
    
    return result;
}