/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/10/2022-13:26.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/optionals/c_optionals.h"
#include "cxx/optionals/optionals.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/enums/color.hpp"
#include "cxx/simple/root.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/getters/person.hpp"

using namespace iegen::example;

void release_Optionals(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Optionals*>(cself.ptr);
    }
}

IEGenCObject _func_Optionals_optionalPtrWithNullptrDefault(IEGenCObject cself, IEGenCObject task, IEGenCObject* _Nonnull err) {
    
    auto ctocxxtask = static_cast<iegen::example::Task*>(task.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalPtrWithNullptrDefault(ctocxxtask);
        
        char* type_result = strdup("iegen::example::Task");
        auto value_ptr_result = const_cast<iegen::example::Task*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

IEGenCObject _func_Optionals_optionalPtrWithNullDefault(IEGenCObject cself, IEGenCObject task, IEGenCObject* _Nonnull err) {
    
    auto ctocxxtask = static_cast<iegen::example::Task*>(task.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalPtrWithNullDefault(ctocxxtask);
        
        char* type_result = strdup("iegen::example::Task");
        auto value_ptr_result = const_cast<iegen::example::Task*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

int _func_Optionals_optionalIntWithDefault(IEGenCObject cself, int value, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalIntWithDefault(value);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    int result {};
    return result;
}

long _func_Optionals_optionalLongWithDefault(IEGenCObject cself, long value, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalLongWithDefault(value);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    long result {};
    return result;
}

double _func_Optionals_optionalDoubleWithDefault(IEGenCObject cself, double value, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalDoubleWithDefault(value);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    double result {};
    return result;
}

float _func_Optionals_optionalFloatWithDefault(IEGenCObject cself, float value, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalFloatWithDefault(value);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    float result {};
    return result;
}

bool _func_Optionals_optionalBoolWithDefault(IEGenCObject cself, bool value, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalBoolWithDefault(value);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    bool result {};
    return result;
}

char* _Nonnull _func_Optionals_optionalStringWithDefault(IEGenCObject cself, char* _Nonnull optionalStr, IEGenCObject* _Nonnull err) {
    auto ctocxxoptionalStr = std::string(optionalStr);
    free(optionalStr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalStringWithDefault(ctocxxoptionalStr);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

const char * _Nonnull _func_Optionals_optionalCharPointerWithDefault(IEGenCObject cself, const char * _Nonnull optionalStr, IEGenCObject* _Nonnull err) {
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalCharPointerWithDefault(optionalStr);
        
        return result;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    const char * result {};
    return result;
}

unsigned int _func_Optionals_optionalEnumWithDefault(IEGenCObject cself, unsigned int c, IEGenCObject* _Nonnull err) {
    auto ctocxxc = static_cast<iegen::example::Color>(c);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalEnumWithDefault(ctocxxc);
        unsigned int cxxtocresult = static_cast<unsigned int>(result);
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    unsigned int result {};
    return result;
}

IEGenCObject _func_Optionals_singleComplexDefaultValue_1(IEGenCObject cself, IEGenCObject* _Nonnull err) {
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->singleComplexDefaultValue();
        
        char* type_result = strdup("iegen::example::Task");
        auto value_ptr_result = const_cast<iegen::example::Task*>(new iegen::example::Task(result));
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

IEGenCObject _func_Optionals_singleComplexDefaultValue(IEGenCObject cself, IEGenCObject task, IEGenCObject* _Nonnull err) {
    
    auto& ctocxxtask = *static_cast<iegen::example::Task*>(task.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->singleComplexDefaultValue(ctocxxtask);
        
        char* type_result = strdup("iegen::example::Task");
        auto value_ptr_result = const_cast<iegen::example::Task*>(new iegen::example::Task(result));
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

char* _Nonnull _func_Optionals_multipleMixedDefaultValues_1(IEGenCObject cself, IEGenCObject* _Nonnull err) {
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->multipleMixedDefaultValues();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

char* _Nonnull _func_Optionals_multipleMixedDefaultValues_2(IEGenCObject cself, IEGenCObject task, int i, IEGenCObject* _Nonnull err) {
    
    auto& ctocxxtask = *static_cast<iegen::example::Task*>(task.ptr);
  
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->multipleMixedDefaultValues(ctocxxtask, i);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

char* _Nonnull _func_Optionals_multipleMixedDefaultValues(IEGenCObject cself, IEGenCObject task, int i, IEGenCObject r, IEGenCObject* _Nonnull err) {
    
    auto& ctocxxtask = *static_cast<iegen::example::Task*>(task.ptr);
  
  
    
    auto& ctocxxr = *static_cast<iegen::example::Root*>(r.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->multipleMixedDefaultValues(ctocxxtask, i, ctocxxr);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

IEGenCObject create_Optionals_1(IEGenCObject* _Nonnull err) {
    try {
        auto this_object = new iegen::example::Optionals();
        return {strdup("iegen::example::Optionals"), this_object};
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

IEGenCObject create_Optionals_2(IEGenCObject task, int i, IEGenCObject* _Nonnull err) {
    
    auto& ctocxxtask = *static_cast<iegen::example::Task*>(task.ptr);
    try {
        auto this_object = new iegen::example::Optionals(ctocxxtask, i);
        return {strdup("iegen::example::Optionals"), this_object};
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

IEGenCObject create_Optionals(IEGenCObject task, int i, IEGenCObject r, IEGenCObject* _Nonnull err) {
    
    auto& ctocxxtask = *static_cast<iegen::example::Task*>(task.ptr);
    
    auto& ctocxxr = *static_cast<iegen::example::Root*>(r.ptr);
    try {
        auto this_object = new iegen::example::Optionals(ctocxxtask, i, ctocxxr);
        return {strdup("iegen::example::Optionals"), this_object};
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

unsigned int _func_Optionals_optionalEnumWithDefaultAndFieldPrefix(IEGenCObject cself, unsigned int c, IEGenCObject* _Nonnull err) {
    auto ctocxxc = static_cast<iegen::example::ColorShade>(c);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalEnumWithDefaultAndFieldPrefix(ctocxxc);
        unsigned int cxxtocresult = static_cast<unsigned int>(result);
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    unsigned int result {};
    return result;
}

unsigned int _func_Optionals_optionalEnumWithInternalDefault(IEGenCObject cself, unsigned int c, IEGenCObject* _Nonnull err) {
    auto ctocxxc = static_cast<iegen::example::ColorShade>(c);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalEnumWithInternalDefault(ctocxxc);
        unsigned int cxxtocresult = static_cast<unsigned int>(result);
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    unsigned int result {};
    return result;
}

char* _Nonnull _func_Optionals_optionalStringViewWithDefault(IEGenCObject cself, char* _Nonnull optionalStr, IEGenCObject* _Nonnull err) {
    auto ctocxxoptionalStr = std::string(optionalStr);
    free(optionalStr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalStringViewWithDefault(ctocxxoptionalStr);
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}

IEGenCObject _func_Optionals_optionalFDPtrWithNullptrDefault(IEGenCObject cself, IEGenCObject project, IEGenCObject* _Nonnull err) {
    
    auto ctocxxproject = static_cast<iegen::example::Project*>(project.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalFDPtrWithNullptrDefault(ctocxxproject);
        
        char* type_result = strdup("iegen::example::Project");
        auto value_ptr_result = const_cast<iegen::example::Project*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

IEGenCObject _func_Optionals_optionalSharedPtrWithNullptrDefault(IEGenCObject cself, IEGenCObject person, IEGenCObject* _Nonnull err) {
    
    std::shared_ptr<iegen::example::Person> ctocxxperson = nullptr;
    if (person.ptr) {
        ctocxxperson = *static_cast<std::shared_ptr<iegen::example::Person>*>(person.ptr);
    }
  
    
    auto ctocxxcself = static_cast<iegen::example::Optionals*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->optionalSharedPtrWithNullptrDefault(ctocxxperson);
        
        char* type_result = strdup("iegen::example::Person");
        void* cxxtocresult_ptr = nullptr;
        if (result) {
            cxxtocresult_ptr = new std::shared_ptr<iegen::example::Person>(result);
        } else {
            type_result = strdup("iegen::example::Person");
        }
        IEGenCObject cxxtocresult = {type_result, cxxtocresult_ptr};
        return cxxtocresult;
    } catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    } catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    IEGenCObject result {};
    return result;
}

