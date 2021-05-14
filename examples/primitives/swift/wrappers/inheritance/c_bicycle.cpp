#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_bicycle.h"
#include "cxx/inheritance/bicycle.hpp"


using namespace iegen::example;
void release_Bicycle(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::Vehicle>*>(cself);
}
void* _Nonnull create_Bicycle(int numberOfSeats){
    
    auto this_object = new iegen::example::Bicycle(numberOfSeats);
    return new std::shared_ptr<iegen::example::Vehicle>(this_object);
}