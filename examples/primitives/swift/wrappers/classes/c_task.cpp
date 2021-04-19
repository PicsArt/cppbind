#include <string.h>
#include <memory>
#include "swift/wrappers/classes/c_task.h"
#include "cxx/classes/task.hpp"

void release_Task(void* _Nonnull cself){
        delete dynamic_cast<iegen::example::Task*>(static_cast<iegen::example::Task*>(cself));
}
void* _Nonnull create_Task(char* _Nonnull title){
    auto c_to_cxx_title = std::string(title);
    free(title);
    auto this_object = new iegen::example::Task(c_to_cxx_title);
    return static_cast<iegen::example::Task*>(this_object);
}
char* _Nonnull _prop_get_Task_title(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Task*>(static_cast<iegen::example::Task*>(cself));
    auto result = c_to_cxx_cself->title();
    auto cxx_to_c_result = strdup(result.c_str()); 
    return cxx_to_c_result;
}