/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 11/22/2022-06:42.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_swift_bicycle.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/inheritance/bicycle.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_BICYCLE = "cppbind::example::Bicycle";
const char* CPPBIND_CPPBIND_EXAMPLE_ELECTRICBICYCLE = "cppbind::example::ElectricBicycle";
const char* CPPBIND_CPPBIND_EXAMPLE_MOUNTAINBICYCLE = "cppbind::example::MountainBicycle";
const char* CPPBIND_CPPBIND_EXAMPLE_ELECTRICCITYBICYCLE = "cppbind::example::ElectricCityBicycle";

std::shared_ptr<cppbind::example::Bicycle> recover_obj_from_CppbindExample_Bicycle(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_BICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::Bicycle>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_ELECTRICCITYBICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ElectricCityBicycle>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_ELECTRICBICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ElectricBicycle>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_MOUNTAINBICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::MountainBicycle>*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_Bicycle(int number_of_seats, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::Bicycle(number_of_seats);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_BICYCLE), new std::shared_ptr<cppbind::example::Bicycle>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_Bicycle_type(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::Bicycle> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_Bicycle(cself);
    try {
        decltype(auto) result = ctocxxcself->type();
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

std::shared_ptr<cppbind::example::ElectricBicycle> recover_obj_from_CppbindExample_ElectricBicycle(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_ELECTRICBICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ElectricBicycle>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_ELECTRICCITYBICYCLE) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ElectricCityBicycle>*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_ElectricBicycle(int number_of_seats, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::ElectricBicycle(number_of_seats);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_ELECTRICBICYCLE), new std::shared_ptr<cppbind::example::ElectricBicycle>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_ElectricBicycle_type(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::ElectricBicycle> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_ElectricBicycle(cself);
    try {
        decltype(auto) result = ctocxxcself->bicycleType();
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

CppBindCObject create_CppbindExample_MountainBicycle(int number_of_seats, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::MountainBicycle(number_of_seats);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_MOUNTAINBICYCLE), new std::shared_ptr<cppbind::example::MountainBicycle>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_MountainBicycle_type(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::MountainBicycle> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::MountainBicycle>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->type();
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

CppBindCObject create_CppbindExample_ElectricCityBicycle(int number_of_seats, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::ElectricCityBicycle(number_of_seats);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_ELECTRICCITYBICYCLE), new std::shared_ptr<cppbind::example::ElectricCityBicycle>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_ElectricCityBicycle_type(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::ElectricCityBicycle> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::ElectricCityBicycle>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->type();
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

