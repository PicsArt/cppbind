/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/17/2022-16:24.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_swift_animal.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/inheritance/animal.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_ANIMAL = "cppbind::example::Animal";
const char* CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL = "cppbind::example::TerrestrialAnimal";
const char* CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL = "cppbind::example::AquaticAnimal";
const char* CPPBIND_CPPBIND_EXAMPLE_FROG = "cppbind::example::Frog";
const char* CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG = "cppbind::example::LittleFrog";
const char* CPPBIND_CPPBIND_EXAMPLE_ANIMALUSAGE = "cppbind::example::AnimalUsage";
const char* CPPBIND_CPPBIND_EXAMPLE_DOG = "cppbind::example::Dog";
const char* CPPBIND_CPPBIND_EXAMPLE_BIGDOG = "cppbind::example::BigDog";
const char* CPPBIND_CPPBIND_EXAMPLE_BLACKBIGDOG = "cppbind::example::BlackBigDog";

void release_CppbindExample_AnimalImpl(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::Animal>::value, "cppbind::example::Animal type must have virtual destructor");
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_ANIMAL) == 0)
            delete static_cast<cppbind::example::Animal*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            delete static_cast<cppbind::example::LittleFrog*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            delete static_cast<cppbind::example::Frog*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL) == 0)
            delete static_cast<cppbind::example::AquaticAnimal*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL) == 0)
            delete static_cast<cppbind::example::TerrestrialAnimal*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

cppbind::example::Animal* recover_obj_from_CppbindExample_Animal(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_ANIMAL) == 0)
            return static_cast<cppbind::example::Animal*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            return static_cast<cppbind::example::LittleFrog*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            return static_cast<cppbind::example::Frog*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL) == 0)
            return static_cast<cppbind::example::AquaticAnimal*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL) == 0)
            return static_cast<cppbind::example::TerrestrialAnimal*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_Animal(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Animal();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_ANIMAL), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_Animal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::Animal* ctocxxcself = recover_obj_from_CppbindExample_Animal(cself);
    try {
        decltype(auto) result = ctocxxcself->typeName();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

bool _func_CppbindExample_Animal_isEqualTo(CppBindCObject cself, CppBindCObject a, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    cppbind::example::Animal* ctocxxa = recover_obj_from_CppbindExample_Animal(a);

    cppbind::example::Animal* ctocxxcself = recover_obj_from_CppbindExample_Animal(cself);
    try {
        decltype(auto) result = ctocxxcself->isEqualTo(ctocxxa);
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

void release_CppbindExample_TerrestrialAnimalImpl(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::TerrestrialAnimal>::value, "cppbind::example::TerrestrialAnimal type must have virtual destructor");
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL) == 0)
            delete static_cast<cppbind::example::TerrestrialAnimal*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            delete static_cast<cppbind::example::LittleFrog*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            delete static_cast<cppbind::example::Frog*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

cppbind::example::TerrestrialAnimal* recover_obj_from_CppbindExample_TerrestrialAnimal(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL) == 0)
            return static_cast<cppbind::example::TerrestrialAnimal*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            return static_cast<cppbind::example::LittleFrog*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            return static_cast<cppbind::example::Frog*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_TerrestrialAnimal(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::TerrestrialAnimal();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_TERRESTRIALANIMAL), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_TerrestrialAnimal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::TerrestrialAnimal* ctocxxcself = recover_obj_from_CppbindExample_TerrestrialAnimal(cself);
    try {
        decltype(auto) result = ctocxxcself->typeName();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

void release_CppbindExample_AquaticAnimal(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::AquaticAnimal>::value, "cppbind::example::AquaticAnimal type must have virtual destructor");
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL) == 0)
            delete static_cast<cppbind::example::AquaticAnimal*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            delete static_cast<cppbind::example::LittleFrog*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            delete static_cast<cppbind::example::Frog*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

cppbind::example::AquaticAnimal* recover_obj_from_CppbindExample_AquaticAnimal(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL) == 0)
            return static_cast<cppbind::example::AquaticAnimal*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG) == 0)
            return static_cast<cppbind::example::LittleFrog*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            return static_cast<cppbind::example::Frog*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_AquaticAnimal(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::AquaticAnimal();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_AquaticAnimal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    cppbind::example::AquaticAnimal* ctocxxcself = recover_obj_from_CppbindExample_AquaticAnimal(cself);
    try {
        decltype(auto) result = ctocxxcself->typeName();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

cppbind::example::Frog* recover_obj_from_CppbindExample_Frog(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_FROG) == 0)
            return static_cast<cppbind::example::Frog*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_Frog(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Frog();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_FROG), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_Frog_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::Frog*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->typeName();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

CppBindCObject create_CppbindExample_LittleFrog(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::LittleFrog();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_LITTLEFROG), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void release_CppbindExample_AnimalUsage(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::AnimalUsage*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_AnimalUsage(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::AnimalUsage();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_ANIMALUSAGE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_AnimalUsage1(CppBindCObject little_frog, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    auto& ctocxxlittle_frog = *static_cast<cppbind::example::LittleFrog*>(little_frog.ptr);
    try {
        auto this_object = new cppbind::example::AnimalUsage(ctocxxlittle_frog);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_ANIMALUSAGE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_AnimalUsage_getAnimalTypeName(CppBindCObject animal, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    cppbind::example::Animal* ctocxxanimal_ptr = recover_obj_from_CppbindExample_Animal(animal);
    auto& ctocxxanimal = *ctocxxanimal_ptr;

    try {
        decltype(auto) result = cppbind::example::AnimalUsage::getAnimalTypeName(ctocxxanimal);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

char* _Nonnull _func_CppbindExample_AnimalUsage_getAquaticAnimalTypeName(CppBindCObject animal, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    cppbind::example::AquaticAnimal* ctocxxanimal_ptr = recover_obj_from_CppbindExample_AquaticAnimal(animal);
    auto& ctocxxanimal = *ctocxxanimal_ptr;

    try {
        decltype(auto) result = cppbind::example::AnimalUsage::getAquaticAnimalTypeName(ctocxxanimal);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

CppBindCObject _func_CppbindExample_AnimalUsage_getAnimal(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::AnimalUsage*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getAnimal();
        
        char* type_result = nullptr;
        const char * name_result = typeid(result).name();
        int status = 0;
        char* demangled_result = abi::__cxa_demangle(name_result, NULL, NULL, &status);
        if (status == 0) {
            type_result = demangled_result;
        } else {
            type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ANIMAL);
        }
        auto value_ptr_result = const_cast<cppbind::example::Animal*>(&result);
        CppBindCObject cxxtocresult = {type_result, dynamic_cast<void*>(value_ptr_result)};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _func_CppbindExample_AnimalUsage_getAquaticAnimal(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::AnimalUsage*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getAquaticAnimal();
        
        char* type_result = nullptr;
        const char * name_result = typeid(result).name();
        int status = 0;
        char* demangled_result = abi::__cxa_demangle(name_result, NULL, NULL, &status);
        if (status == 0) {
            type_result = demangled_result;
        } else {
            type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_AQUATICANIMAL);
        }
        auto value_ptr_result = const_cast<cppbind::example::AquaticAnimal*>(&result);
        CppBindCObject cxxtocresult = {type_result, dynamic_cast<void*>(value_ptr_result)};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _func_CppbindExample_AnimalUsage_getFrog(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::AnimalUsage*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getFrog();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_FROG);
        auto value_ptr_result = const_cast<cppbind::example::Frog*>(&result);
        CppBindCObject cxxtocresult = {type_result, dynamic_cast<void*>(value_ptr_result)};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _func_CppbindExample_AnimalUsage_getLittleFrog(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::AnimalUsage*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getLittleFrog();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_FROG);
        auto value_ptr_result = const_cast<cppbind::example::Frog*>(&result);
        CppBindCObject cxxtocresult = {type_result, dynamic_cast<void*>(value_ptr_result)};
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

void release_CppbindExample_Dog(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::Dog*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_Dog(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Dog();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_DOG), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

cppbind::example::BigDog* recover_obj_from_CppbindExample_BigDog(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_BIGDOG) == 0)
            return static_cast<cppbind::example::BigDog*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_BLACKBIGDOG) == 0)
            return static_cast<cppbind::example::BlackBigDog*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_BigDog(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::BigDog();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_BIGDOG), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_BlackBigDog(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::BlackBigDog();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_BLACKBIGDOG), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

