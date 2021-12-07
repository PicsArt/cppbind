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
#include "swift/wrappers/inheritance/c_animal.h"
#include "cxx/inheritance/animal.hpp"

using namespace iegen::example;

void release_AnimalImpl(CObject cself){
    delete static_cast<iegen::example::Animal*>(cself.ptr);
}

CObject create_Animal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Animal();
        return {strdup("iegen::example::Animal"), this_object};
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

char* _Nonnull _func_Animal_typeName(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Animal*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->typeName();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}
void release_TerrestrialAnimalImpl(CObject cself){
    delete dynamic_cast<iegen::example::TerrestrialAnimal*>(static_cast<iegen::example::Animal*>(cself.ptr));
}

CObject create_TerrestrialAnimal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::TerrestrialAnimal();
        return {strdup("iegen::example::TerrestrialAnimal"), static_cast<iegen::example::Animal*>(this_object)};
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

char* _Nonnull _func_TerrestrialAnimal_typeName(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::TerrestrialAnimal*>(static_cast<iegen::example::Animal*>(cself.ptr));
    try {
        const auto& result = c_to_cxx_cself->typeName();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}
void release_AquaticAnimal(CObject cself) {
    delete static_cast<iegen::example::Animal*>(cself.ptr);
}

CObject create_AquaticAnimal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::AquaticAnimal();
        return {strdup("iegen::example::AquaticAnimal"), static_cast<iegen::example::Animal*>(this_object)};
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

char* _Nonnull _func_AquaticAnimal_typeName(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::AquaticAnimal*>(static_cast<iegen::example::Animal*>(cself.ptr));
    try {
        const auto& result = c_to_cxx_cself->typeName();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}
void release_Frog(CObject cself) {
    delete static_cast<iegen::example::Animal*>(cself.ptr);
}

CObject create_Frog(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Frog();
        return {strdup("iegen::example::Frog"), static_cast<iegen::example::Animal*>(this_object)};
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

char* _Nonnull _func_Frog_typeName(CObject cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Frog*>(static_cast<iegen::example::Animal*>(cself.ptr));
    try {
        const auto& result = c_to_cxx_cself->typeName();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}
void release_AnimalUsage(CObject cself) {
    delete static_cast<iegen::example::AnimalUsage*>(cself.ptr);
}

CObject create_AnimalUsage(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::AnimalUsage();
        return {strdup("iegen::example::AnimalUsage"), this_object};
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

char* _Nonnull _func_AnimalUsage_getAnimalTypeName(CObject animal, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_animal = *static_cast<iegen::example::Animal*>(animal.ptr);
  
    try {
        const auto& result = iegen::example::AnimalUsage::getAnimalTypeName(c_to_cxx_animal);
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}

char* _Nonnull _func_AnimalUsage_getAquaticAnimalTypeName(CObject animal, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto& c_to_cxx_animal = *dynamic_cast<iegen::example::AquaticAnimal*>(static_cast<iegen::example::Animal*>(animal.ptr));
  
    try {
        const auto& result = iegen::example::AnimalUsage::getAquaticAnimalTypeName(c_to_cxx_animal);
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}

CObject _func_AnimalUsage_getAnimal(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getAnimal();
        
        char* type_result = strdup("iegen::example::Animal");
        CObject cxx_to_c_result = {type_result, const_cast<iegen::example::Animal*>( &result )};
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

CObject _func_AnimalUsage_getAquaticAnimal(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getAquaticAnimal();
        
        char* type_result = strdup("iegen::example::AquaticAnimal");
        auto value_ptr_result = const_cast<iegen::example::AquaticAnimal*>( &result );
        CObject cxx_to_c_result = {type_result, static_cast<iegen::example::Animal*>(value_ptr_result)};
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

CObject _func_AnimalUsage_getFrog(CObject cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself.ptr);
    try {
        const auto& result = c_to_cxx_cself->getFrog();
        
        char* type_result = strdup("iegen::example::Frog");
        auto value_ptr_result = const_cast<iegen::example::Frog*>( &result );
        CObject cxx_to_c_result = {type_result, static_cast<iegen::example::Animal*>(value_ptr_result)};
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