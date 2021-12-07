/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-08:30.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/shared_ptr/c_shared_ptr.h"
#include "cxx/shared_ptr/shared_ptr.hpp"

using namespace Example;

void release_Car(CObject cself) {
    delete static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
}

CObject create_Car(int cost, ErrorObj* _Nonnull err){
    
    try {
        auto this_object = new Example::Car(cost);
        return {strdup("Example::Car"), new std::shared_ptr<Example::Car>(this_object)};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

int _prop_get_Car_cost(CObject cself){
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    const auto& result = c_to_cxx_cself->cost();
    
    return result;
}

void _func_Car_setCostWithCarSharedPtr(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    
    std::shared_ptr<Example::Car> c_to_cxx_sp;
    c_to_cxx_sp = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        c_to_cxx_cself->setCostWithCarSharedPtr(c_to_cxx_sp);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_Car_setCostWithCar(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    std::shared_ptr<Example::Car> c_to_cxx_sp_shared_ptr;
    c_to_cxx_sp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto& c_to_cxx_sp = *c_to_cxx_sp_shared_ptr.get();
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        c_to_cxx_cself->setCostWithCar(c_to_cxx_sp);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_Car_setCostWithCarConstSharedPtr(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    
    std::shared_ptr<const Example::Car> c_to_cxx_sp;
    c_to_cxx_sp = *static_cast<std::shared_ptr<const Example::Car>*>(sp.ptr);
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        c_to_cxx_cself->setCostWithCarConstSharedPtr(c_to_cxx_sp);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CObject _func_Car_makeConstSharedPtr(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    
    std::shared_ptr<Example::Car> c_to_cxx_sp;
    c_to_cxx_sp = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->makeConstSharedPtr(c_to_cxx_sp);
        
        char* type_result = strdup("Example::Car");
        void* cxx_to_c_result_ptr;
        cxx_to_c_result_ptr = reinterpret_cast<void*>(new std::shared_ptr<const Example::Car>(result));
        CObject cxx_to_c_result = {type_result, cxx_to_c_result_ptr};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

void _func_Car_setCostWithCarRef(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    std::shared_ptr<Example::Car> c_to_cxx_sp_shared_ptr;
    c_to_cxx_sp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto& c_to_cxx_sp = *c_to_cxx_sp_shared_ptr.get();
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        c_to_cxx_cself->setCostWithCarRef(c_to_cxx_sp);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

void _func_Car_setCostWithCarPtr(CObject cself, CObject sp, ErrorObj* _Nonnull err){
    std::shared_ptr<Example::Car> c_to_cxx_sp_shared_ptr;
    c_to_cxx_sp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto c_to_cxx_sp = c_to_cxx_sp_shared_ptr.get();
  
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        c_to_cxx_cself->setCostWithCarPtr(c_to_cxx_sp);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

CObject _func_Car_getNewCarSharedPtr(CObject cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<Example::Car> c_to_cxx_cself;
    c_to_cxx_cself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getNewCarSharedPtr();
        
        char* type_result = strdup("Example::Car");
        void* cxx_to_c_result_ptr;
        cxx_to_c_result_ptr = reinterpret_cast<void*>(new std::shared_ptr<Example::Car>(result));
        CObject cxx_to_c_result = {type_result, cxx_to_c_result_ptr};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}
void release_CarUsage(CObject cself) {
    delete static_cast<Example::CarUsage*>(cself.ptr);
}

CObject create_CarUsage(CObject car, ErrorObj* _Nonnull err){
    std::shared_ptr<Example::Car> c_to_cxx_car_shared_ptr;
    c_to_cxx_car_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(car.ptr);
    auto c_to_cxx_car = c_to_cxx_car_shared_ptr.get();
    try {
        auto this_object = new Example::CarUsage(c_to_cxx_car);
        return {strdup("Example::CarUsage"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

CObject _func_CarUsage_getCar(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<Example::CarUsage*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getCar();
        
        std::shared_ptr<Example::Car> result_shared_ptr = std::make_shared<Example::Car>(result);

        char* type_result_shared_ptr = strdup("Example::Car");
        void* cxx_to_c_result_ptr;
        cxx_to_c_result_ptr = reinterpret_cast<void*>(new std::shared_ptr<Example::Car>(result_shared_ptr));
        CObject cxx_to_c_result = {type_result_shared_ptr, cxx_to_c_result_ptr};
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}