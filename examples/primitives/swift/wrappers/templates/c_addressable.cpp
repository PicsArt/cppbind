#include <string.h>
#include <memory>
#include "swift/wrappers/templates/c_addressable.h"
#include "cxx/templates/addressable.hpp"
#include "cxx/classes/root.hpp"

using namespace iegen::example;
void release_AddressableRoot(void* _Nonnull cself){
        delete static_cast<std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>*>(cself);
}
void* _Nonnull create_AddressableRoot(void* _Nonnull parent, char* _Nonnull name){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto& c_to_cxx_parent = *dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(parent));
    auto c_to_cxx_name = std::string(name);
    free(name);
    auto this_object = new iegen::example::Addressable<iegen::example::Root>(c_to_cxx_parent, c_to_cxx_name);
    return new std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>(this_object);
}
char* _Nonnull _func_AddressableRoot_absPath(void* _Nonnull cself ){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Addressable<iegen::example::Root>>(
              *static_cast<std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>*>(cself)
              );
    const auto& result = c_to_cxx_cself->absPath();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}