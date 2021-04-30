#include <string.h>
#include <memory>
#include "swift/wrappers/extra/c_object.h"
#include "cxx/base/object.hpp"


using namespace iegen;
void release_Object(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::Object>*>(cself);
}
char* _Nonnull _func_Object_toString(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->toString();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
char* _Nonnull _func_Object_className(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->className();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
bool _func_Object_equals(void* _Nonnull cself , void* _Nonnull other){
    
    std::shared_ptr<iegen::Object> c_to_cxx_other;
    auto baseptr = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(other);
    c_to_cxx_other = std::dynamic_pointer_cast<iegen::Object>(baseptr);
  
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->equals(c_to_cxx_other);
    
    return result;
}
unsigned long _func_Object_hash(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->hash();
    
    return result;
}
char* _Nonnull _func_Object_debugInfo(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->debugInfo();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
unsigned long _func_Object_bytesCount(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::Object>(
              *static_cast<std::shared_ptr<iegen::Object>*>(cself)
              );
    const auto& result = c_to_cxx_cself->bytesCount();
    
    return result;
}