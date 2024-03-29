/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/13/2022-14:16.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/shared_ptr/c_swift_shared_ptr.h"
#include "swift/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/shared_ptr/shared_ptr.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_EXAMPLE_CAR = "Example::Car";
const char* CPPBIND_EXAMPLE_CARUSAGE = "Example::CarUsage";

void release_Example_Car(CppBindCObject cself, bool owner) {
    using namespace Example;
    if (owner) {
        delete static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_Example_Car(int cost, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    try {
        auto this_object = new Example::Car(cost);
        return {strdup(CPPBIND_EXAMPLE_CAR), new std::shared_ptr<Example::Car>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

int _prop_get_Example_Car_cost(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->cost();
        
        return result;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

void _func_Example_Car_setCostWithCarSharedPtr(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxsp;
    ctocxxsp = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        ctocxxcself->setCostWithCarSharedPtr(ctocxxsp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_Example_Car_setCostWithCar(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxsp_shared_ptr;
    ctocxxsp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto& ctocxxsp = *ctocxxsp_shared_ptr.get();

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        ctocxxcself->setCostWithCar(ctocxxsp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_Example_Car_setCostWithCarConstSharedPtr(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<const Example::Car> ctocxxsp;
    ctocxxsp = *static_cast<std::shared_ptr<const Example::Car>*>(sp.ptr);

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        ctocxxcself->setCostWithCarConstSharedPtr(ctocxxsp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_Example_Car_makeConstSharedPtr(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxsp;
    ctocxxsp = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->makeConstSharedPtr(ctocxxsp);
        
        char* type_result = nullptr;
        void* cxxtocresult_ptr = nullptr;
        cxxtocresult_ptr = new std::shared_ptr<const Example::Car>(std::const_pointer_cast<Example::Car>(result));
        CppBindCObject cxxtocresult = {type_result, cxxtocresult_ptr};
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

void _func_Example_Car_setCostWithCarRef(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxsp_shared_ptr;
    ctocxxsp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto& ctocxxsp = *ctocxxsp_shared_ptr.get();

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        ctocxxcself->setCostWithCarRef(ctocxxsp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

void _func_Example_Car_setCostWithCarPtr(CppBindCObject cself, CppBindCObject sp, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxsp_shared_ptr;
    ctocxxsp_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(sp.ptr);
    auto ctocxxsp = ctocxxsp_shared_ptr.get();

    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        ctocxxcself->setCostWithCarPtr(ctocxxsp);
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
}

CppBindCObject _func_Example_Car_getNewCarSharedPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    std::shared_ptr<Example::Car> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<Example::Car>*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getNewCarSharedPtr();
        
        char* type_result = nullptr;
        void* cxxtocresult_ptr = nullptr;
        cxxtocresult_ptr = new std::shared_ptr<Example::Car>(result);
        CppBindCObject cxxtocresult = {type_result, cxxtocresult_ptr};
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

void release_Example_CarUsage(CppBindCObject cself, bool owner) {
    using namespace Example;
    if (owner) {
        delete static_cast<Example::CarUsage*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_Example_CarUsage(CppBindCObject car, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    
    std::shared_ptr<Example::Car> ctocxxcar_shared_ptr;
    ctocxxcar_shared_ptr = *static_cast<std::shared_ptr<Example::Car>*>(car.ptr);
    auto ctocxxcar = ctocxxcar_shared_ptr.get();
    try {
        auto this_object = new Example::CarUsage(ctocxxcar);
        return {strdup(CPPBIND_EXAMPLE_CARUSAGE), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject _func_Example_CarUsage_getCar(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace Example;
    auto ctocxxcself = static_cast<Example::CarUsage*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getCar();
        
        std::shared_ptr<Example::Car> result_shared_ptr = std::make_shared<Example::Car>(result);

        char* type_result_shared_ptr = nullptr;
        void* cxxtocresult_ptr = nullptr;
        cxxtocresult_ptr = new std::shared_ptr<Example::Car>(result_shared_ptr);
        CppBindCObject cxxtocresult = {type_result_shared_ptr, cxxtocresult_ptr};
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

