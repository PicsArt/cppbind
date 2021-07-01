/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 06/28/2021-15:50.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_bicycle.h"
#include "cxx/inheritance/bicycle.hpp"
#include "cxx/inheritance/vehicle.hpp"


using namespace iegen::example;
void release_Bicycle(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::Bicycle*>(static_cast<iegen::example::Vehicle*>(cself));
}
void* _Nonnull create_Bicycle(int numberOfSeats){
    
    auto this_object = new iegen::example::Bicycle(numberOfSeats);
    return static_cast<iegen::example::Vehicle*>(this_object);
}