/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/17/2022-09:29.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/misc/c_swift_size_buffer.h"
#include "cxx/misc/size_buffer.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SIZEUSAGE = "cppbind::example::SizeUsage";

using namespace cppbind::example;

void release_CppbindExample_SizeUsage(CppBindCObject cself, bool owner) {
    if (owner) {
        delete static_cast<cppbind::example::SizeUsage*>(cself.ptr);
    }
    free(cself.type);
}

CppBindSizeF _func_CppbindExample_SizeUsage_multiplyBy(CppBindSizeF size, int n, CppBindCObject* _Nonnull cppbind_err) {
    auto& first_tmp_size = size.first;
    auto& second_tmp_size = size.second;
    SizeF ctocxxsize { first_tmp_size, second_tmp_size };


    try {
        const auto& result = cppbind::example::SizeUsage::multiplyBy(ctocxxsize, n);
        auto _first_data_cxxtocresult = result.width;
        auto _second_data_cxxtocresult = result.height;
        CppBindSizeF cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindSizeF result {};
    return result;
}

CppBindSizeF _func_CppbindExample_SizeUsage_doubleSizeF_1(CppBindCObject* _Nonnull cppbind_err) {
    try {
        const auto& result = cppbind::example::SizeUsage::doubleSizeF();
        auto _first_data_cxxtocresult = result.width;
        auto _second_data_cxxtocresult = result.height;
        CppBindSizeF cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindSizeF result {};
    return result;
}

CppBindSizeF _func_CppbindExample_SizeUsage_doubleSizeF(CppBindSizeF resolution, CppBindCObject* _Nonnull cppbind_err) {
    auto& first_tmp_resolution = resolution.first;
    auto& second_tmp_resolution = resolution.second;
    const SizeF & ctocxxresolution { first_tmp_resolution, second_tmp_resolution };

    try {
        const auto& result = cppbind::example::SizeUsage::doubleSizeF(ctocxxresolution);
        auto _first_data_cxxtocresult = result.width;
        auto _second_data_cxxtocresult = result.height;
        CppBindSizeF cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindSizeF result {};
    return result;
}

