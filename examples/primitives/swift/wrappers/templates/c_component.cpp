#include <string.h>
#include <memory>
#include "swift/wrappers/templates/c_component.h"
#include "cxx/templates/component.hpp"

void release_Component(void* _Nonnull cself){
        delete static_cast<std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>*>(cself);
}
void* _Nonnull create_Component(void* _Nonnull parent, char* _Nonnull name){
    
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_parent = *dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(parent));
    auto c_to_cxx_name = std::string(name);
    free(name);
    auto this_object = new iegen::example::Component(c_to_cxx_parent, c_to_cxx_name);
    return new std::shared_ptr<iegen::example::Addressable<iegen::example::Root>>(this_object);
}