/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:12.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_usage.h"
#include "cxx/inheritance/usage.hpp"
#include "cxx/inheritance/parallelogram.hpp"
#include "cxx/inheritance/vehicle.hpp"
#include "cxx/inheritance/bicycle.hpp"

using namespace iegen::example;

void release_GeometricFigure(void* _Nonnull cself) {
    delete static_cast<iegen::example::GeometricFigure*>(cself);
}

void* _Nonnull create_GeometricFigure(void* _Nonnull p, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_p = static_cast<iegen::example::Parallelogram*>(p);
    try {
        auto this_object = new iegen::example::GeometricFigure(c_to_cxx_p);
        return this_object;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

void* _Nonnull _prop_get_GeometricFigure_parallelogram(void* _Nonnull cself){
    auto c_to_cxx_cself = static_cast<iegen::example::GeometricFigure*>(cself);
    const auto& result = c_to_cxx_cself->parallelogram();
    
    auto cxx_to_c_result = const_cast<iegen::example::Parallelogram*>(result);
    return cxx_to_c_result;
}

void _prop_set_GeometricFigure_parallelogram(void* _Nonnull cself, void* _Nonnull p){
    
    auto c_to_cxx_cself = static_cast<iegen::example::GeometricFigure*>(cself);
    
    auto c_to_cxx_p = static_cast<iegen::example::Parallelogram*>(p);
    c_to_cxx_cself->setParallelogram(c_to_cxx_p);
}

void release_MyVehicle(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::MyVehicle>*>(cself);
}

void* _Nonnull create_MyVehicle(void* _Nonnull v, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_v;
    c_to_cxx_v = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(v);
    try {
        auto this_object = new iegen::example::MyVehicle(c_to_cxx_v);
        return new std::shared_ptr<iegen::example::MyVehicle>(this_object);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

void* _Nonnull _prop_get_MyVehicle_vehicle(void* _Nonnull cself){
    std::shared_ptr<iegen::example::MyVehicle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::MyVehicle>*>(cself);
    const auto& result = c_to_cxx_cself->vehicle();
    
    void* cxx_to_c_result;
    cxx_to_c_result = reinterpret_cast<void*>(new std::shared_ptr<iegen::example::Vehicle>(result));
    return cxx_to_c_result;
}

void _prop_set_MyVehicle_vehicle(void* _Nonnull cself, void* _Nonnull v){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::MyVehicle>(
              *static_cast<std::shared_ptr<iegen::example::MyVehicle>*>(cself)
              );
    
    std::shared_ptr<iegen::example::Vehicle> c_to_cxx_v;
    c_to_cxx_v = *static_cast<std::shared_ptr<iegen::example::Vehicle>*>(v);
    c_to_cxx_cself->setVehicle(c_to_cxx_v);
}

void release_MyBicycle(void* _Nonnull cself) {
    delete static_cast<std::shared_ptr<iegen::example::MyBicycle>*>(cself);
}

void* _Nonnull create_MyBicycle(void* _Nonnull b, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Bicycle> c_to_cxx_b;
    c_to_cxx_b = std::dynamic_pointer_cast<iegen::example::Bicycle>(*static_cast<std::shared_ptr<iegen::example::Vehicle>*>(b));
    try {
        auto this_object = new iegen::example::MyBicycle(c_to_cxx_b);
        return new std::shared_ptr<iegen::example::MyBicycle>(this_object);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

void* _Nonnull _prop_get_MyBicycle_bicycle(void* _Nonnull cself){
    std::shared_ptr<iegen::example::MyBicycle> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<iegen::example::MyBicycle>*>(cself);
    const auto& result = c_to_cxx_cself->bicycle();
    
    void* cxx_to_c_result;
    cxx_to_c_result = reinterpret_cast<void*>(new std::shared_ptr<const iegen::example::Vehicle>(std::static_pointer_cast<const iegen::example::Vehicle>(result)));
    return cxx_to_c_result;
}

void _prop_set_MyBicycle_bicycle(void* _Nonnull cself, void* _Nonnull b){
    auto c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::MyBicycle>(
              *static_cast<std::shared_ptr<iegen::example::MyBicycle>*>(cself)
              );
    
    std::shared_ptr<const iegen::example::Bicycle> c_to_cxx_b;
    c_to_cxx_b = std::dynamic_pointer_cast<const iegen::example::Bicycle>(*static_cast<std::shared_ptr<const iegen::example::Vehicle>*>(b));
    c_to_cxx_cself->setBicycle(c_to_cxx_b);
}
