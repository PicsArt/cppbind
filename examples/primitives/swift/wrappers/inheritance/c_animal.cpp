/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/25/2021-10:01.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_animal.h"
#include "cxx/inheritance/animal.hpp"

using namespace iegen::example;

void release_AnimalImpl(void* _Nonnull cself){
    delete static_cast<iegen::example::Animal*>(cself);
}

void* _Nonnull create_Animal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Animal();
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

char* _Nonnull _func_Animal_typeName(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::Animal*>(cself);
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
    char* result = nullptr;
    return result;
}
void release_TerrestrialAnimalImpl(void* _Nonnull cself){
    delete dynamic_cast<iegen::example::TerrestrialAnimal*>(static_cast<iegen::example::Animal*>(cself));
}

void* _Nonnull create_TerrestrialAnimal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::TerrestrialAnimal();
        return static_cast<iegen::example::Animal*>(this_object);
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

char* _Nonnull _func_TerrestrialAnimal_typeName(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::TerrestrialAnimal*>(static_cast<iegen::example::Animal*>(cself));
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
    char* result = nullptr;
    return result;
}
void release_AquaticAnimal(void* _Nonnull cself) {
    delete static_cast<iegen::example::Animal*>(cself);
}

void* _Nonnull create_AquaticAnimal(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::AquaticAnimal();
        return static_cast<iegen::example::Animal*>(this_object);
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

char* _Nonnull _func_AquaticAnimal_typeName(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::AquaticAnimal*>(static_cast<iegen::example::Animal*>(cself));
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
    char* result = nullptr;
    return result;
}
void release_Frog(void* _Nonnull cself) {
    delete static_cast<iegen::example::Animal*>(cself);
}

void* _Nonnull create_Frog(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::Frog();
        return static_cast<iegen::example::Animal*>(this_object);
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

char* _Nonnull _func_Frog_typeName(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Frog*>(static_cast<iegen::example::Animal*>(cself));
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
    char* result = nullptr;
    return result;
}
void release_AnimalUsage(void* _Nonnull cself) {
    delete static_cast<iegen::example::AnimalUsage*>(cself);
}

void* _Nonnull create_AnimalUsage(ErrorObj* _Nonnull err){
    try {
        auto this_object = new iegen::example::AnimalUsage();
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

char* _Nonnull _func_AnimalUsage_getAnimalTypeName(void* _Nonnull animal, ErrorObj* _Nonnull err){
    
    auto& c_to_cxx_animal = *static_cast<iegen::example::Animal*>(animal);
  
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
    char* result = nullptr;
    return result;
}

char* _Nonnull _func_AnimalUsage_getAquaticAnimalTypeName(void* _Nonnull animal, ErrorObj* _Nonnull err){
    
    // we might need to avoid dynamic_cast if there is no multiple inheritance
    auto& c_to_cxx_animal = *dynamic_cast<iegen::example::AquaticAnimal*>(static_cast<iegen::example::Animal*>(animal));
  
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
    char* result = nullptr;
    return result;
}

void* _Nonnull _func_AnimalUsage_getAnimal(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself);
    try {
        const auto& result = c_to_cxx_cself->getAnimal();
        
        auto cxx_to_c_result = const_cast<iegen::example::Animal*>( &result );
        return cxx_to_c_result;
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

void* _Nonnull _func_AnimalUsage_getAquaticAnimal(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself);
    try {
        const auto& result = c_to_cxx_cself->getAquaticAnimal();
        
        auto value_ptr_result = const_cast<iegen::example::AquaticAnimal*>( &result );
        auto cxx_to_c_result = static_cast<iegen::example::Animal*>(value_ptr_result);
        return cxx_to_c_result;
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

void* _Nonnull _func_AnimalUsage_getFrog(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<iegen::example::AnimalUsage*>(cself);
    try {
        const auto& result = c_to_cxx_cself->getFrog();
        
        auto value_ptr_result = const_cast<iegen::example::Frog*>( &result );
        auto cxx_to_c_result = static_cast<iegen::example::Animal*>(value_ptr_result);
        return cxx_to_c_result;
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