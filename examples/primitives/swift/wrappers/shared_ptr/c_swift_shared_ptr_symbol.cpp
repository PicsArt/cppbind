/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/22/2022-09:36.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/shared_ptr/c_swift_shared_ptr_symbol.h"
#include "cxx/shared_ptr/shared_ptr_symbol.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SIGNSHARED = "cppbind::example::SignShared";
const char* CPPBIND_CPPBIND_EXAMPLE_TEXTSHARED = "cppbind::example::TextShared";
const char* CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED = "cppbind::example::DigitShared";
const char* CPPBIND_CPPBIND_EXAMPLE_SYMBOLUSAGESHARED = "cppbind::example::SymbolUsageShared";

void release_CppbindExample_SignSharedImpl(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_SIGNSHARED) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::SignShared>*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

std::shared_ptr<cppbind::example::SignShared> recover_obj_from_CppbindExample_SignShared(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_SIGNSHARED) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::SignShared>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_SignShared(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::SignShared();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_SIGNSHARED), new std::shared_ptr<cppbind::example::SignShared>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_SignShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::SignShared> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_SignShared(cself);
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

void release_CppbindExample_TextShared(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_TEXTSHARED) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::TextShared>*>(cself.ptr);
        else if (strcmp(cself.type, CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED) == 0)
            delete static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(cself.ptr);
        else {
            std::cerr << "Unexpected object type: " << cself.type << std::endl;
            exit(1);
        }
    }
    free(cself.type);
}

std::shared_ptr<cppbind::example::TextShared> recover_obj_from_CppbindExample_TextShared(CppBindCObject cppbindObj) {
    if (cppbindObj.ptr) {
        if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_TEXTSHARED) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::TextShared>*>(cppbindObj.ptr);
        else if (strcmp(cppbindObj.type, CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(cppbindObj.ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbindObj.type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

CppBindCObject create_CppbindExample_TextShared(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::TextShared();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_TEXTSHARED), new std::shared_ptr<cppbind::example::TextShared>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_TextShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::TextShared> ctocxxcself;
    ctocxxcself = recover_obj_from_CppbindExample_TextShared(cself);
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

CppBindCObject create_CppbindExample_DigitShared(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::DigitShared();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_DIGITSHARED), new std::shared_ptr<cppbind::example::DigitShared>(this_object)};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_DigitShared_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    std::shared_ptr<cppbind::example::DigitShared> ctocxxcself;
    ctocxxcself = *static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(cself.ptr);
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

void release_CppbindExample_SymbolUsageShared(CppBindCObject cself, bool owner) {
    using namespace cppbind::example;
    if (owner) {
        delete static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    }
    free(cself.type);
}

CppBindCObject create_CppbindExample_SymbolUsageShared(CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    try {
        auto this_object = new cppbind::example::SymbolUsageShared();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_SYMBOLUSAGESHARED), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_SymbolUsageShared1(CppBindCObject d, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::DigitShared> ctocxxd;
    ctocxxd = *static_cast<std::shared_ptr<cppbind::example::DigitShared>*>(d.ptr);
    try {
        auto this_object = new cppbind::example::SymbolUsageShared(ctocxxd);
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_SYMBOLUSAGESHARED), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

char* _Nonnull _func_CppbindExample_SymbolUsageShared_getTextType(CppBindCObject cself, CppBindCObject t, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::TextShared> ctocxxt;
    ctocxxt = recover_obj_from_CppbindExample_TextShared(t);

    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getTextType(ctocxxt);
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

char* _Nonnull _func_CppbindExample_SymbolUsageShared_getSignType(CppBindCObject cself, CppBindCObject s, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::SignShared> ctocxxs;
    ctocxxs = recover_obj_from_CppbindExample_SignShared(s);

    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getSignType(ctocxxs);
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

int _func_CppbindExample_SymbolUsageShared_getTextId(CppBindCObject cself, CppBindCObject t, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::TextShared> ctocxxt;
    ctocxxt = recover_obj_from_CppbindExample_TextShared(t);

    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getTextId(ctocxxt);
        
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

int _func_CppbindExample_SymbolUsageShared_getSignId(CppBindCObject cself, CppBindCObject s, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    
    std::shared_ptr<cppbind::example::SignShared> ctocxxs;
    ctocxxs = recover_obj_from_CppbindExample_SignShared(s);

    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getSignId(ctocxxs);
        
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

CppBindCObject _func_CppbindExample_SymbolUsageShared_getTextPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getTextPtr();
        
        char* type_result = nullptr;
        void* cxxtocresult_ptr = nullptr;

        auto& arg_pointee_result = *result.get();
        const char * name_result = typeid(arg_pointee_result).name();
        int status = 0;
        char* demangled_result = abi::__cxa_demangle(name_result, NULL, NULL, &status);
        if (status == 0) {
            type_result = demangled_result;
        } else {
            type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TEXTSHARED);
        }
        cxxtocresult_ptr = new std::shared_ptr<void>(std::dynamic_pointer_cast<void>(result));
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

CppBindCObject _func_CppbindExample_SymbolUsageShared_getSignPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err) {
    using namespace cppbind::example;
    auto ctocxxcself = static_cast<cppbind::example::SymbolUsageShared*>(cself.ptr);
    try {
        decltype(auto) result = ctocxxcself->getSignPtr();
        
        char* type_result = nullptr;
        void* cxxtocresult_ptr = nullptr;

        auto& arg_pointee_result = *result.get();
        const char * name_result = typeid(arg_pointee_result).name();
        int status = 0;
        char* demangled_result = abi::__cxa_demangle(name_result, NULL, NULL, &status);
        if (status == 0) {
            type_result = demangled_result;
        } else {
            type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_SIGNSHARED);
        }
        cxxtocresult_ptr = new std::shared_ptr<void>(std::dynamic_pointer_cast<void>(result));
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

