#include <string.h>
#include <memory>
#include "swift/wrappers/classes/c_root.h"
#include "cxx/classes/root.hpp"

void release_Root(void* _Nonnull cself){
        delete dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(cself));
}
void* _Nonnull create_Root(char* _Nonnull _path){
    auto c_to_cxx__path = std::string(_path);
    free(_path);
    auto this_object = new iegen::example::Root(c_to_cxx__path);
    return static_cast<iegen::example::Root*>(this_object);
}
char* _Nonnull _prop_get_Root_path(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(cself));
    auto result = c_to_cxx_cself->path;
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}
void _prop_set_Root_path(void* _Nonnull cself, char* _Nonnull path){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Root*>(static_cast<iegen::example::Root*>(cself));
    auto c_to_cxx_path = std::string(path);
    free(path);
    c_to_cxx_cself->path = c_to_cxx_path;
}
