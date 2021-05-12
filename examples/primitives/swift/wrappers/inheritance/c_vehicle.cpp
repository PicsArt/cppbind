#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_vehicle.h"
#include "cxx/inheritance/vehicle.hpp"


using namespace iegen::example;
void release_Vehicle(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Vehicle*>(static_cast<iegen::example::Vehicle*>(cself));
}
void* _Nonnull create_Vehicle(int numberOfSeats){
    
    auto this_object = new iegen::example::Vehicle(numberOfSeats);
    return static_cast<iegen::example::Vehicle*>(this_object);
}
int _prop_get_Vehicle_numberOfSeats(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Vehicle*>(static_cast<iegen::example::Vehicle*>(cself));
    auto result = c_to_cxx_cself->numberOfSeats();
    
    return result;
}