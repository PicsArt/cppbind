/*
 * This file was generated by iegen on 05/18/2021-20:18.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/enums/c_frame.h"
#include "cxx/enums/frame.hpp"


using namespace iegen::example;
void release_Frame(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Frame*>(static_cast<iegen::example::Frame*>(cself));
}
void* _Nonnull create_Frame(){
    auto this_object = new iegen::example::Frame();
    return static_cast<iegen::example::Frame*>(this_object);
}
unsigned int _prop_get_Frame_backgroundColor(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Frame*>(static_cast<iegen::example::Frame*>(cself));
    auto result = c_to_cxx_cself->backgroundColor;
    unsigned int cxx_to_c_result = (unsigned int)result;
    return cxx_to_c_result;
}
void _prop_set_Frame_backgroundColor(void* _Nonnull cself, unsigned int backgroundColor){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Frame*>(static_cast<iegen::example::Frame*>(cself));
    auto c_to_cxx_backgroundColor = (iegen::example::Color)backgroundColor;
    c_to_cxx_cself->backgroundColor = c_to_cxx_backgroundColor;
}