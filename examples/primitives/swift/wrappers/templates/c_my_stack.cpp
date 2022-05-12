/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:26.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/templates/c_my_stack.h"
#include "cxx/templates/stack_usage.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_MYSTACKPROJECT = "cppbind::example::MyStack<cppbind::example::Project>";
const char* CPPBIND_CPPBIND_EXAMPLE_MYSTACKTASK = "cppbind::example::MyStack<cppbind::example::Task>";

using namespace cppbind::example;

CppBindCObject create_CppbindExample_MyStackProject(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::MyStack<cppbind::example::Project>();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_MYSTACKPROJECT), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

CppBindCObject create_CppbindExample_MyStackTask(CppBindCObject* _Nonnull cppbind_err) {
    try {
        auto this_object = new cppbind::example::MyStack<cppbind::example::Task>();
        return {strdup(CPPBIND_CPPBIND_EXAMPLE_MYSTACKTASK), this_object};
    } catch (const std::exception& e) {
        cppbind_err->type = strdup(CPPBIND_STD_STDEXCEPTION);
        cppbind_err->ptr = new std::exception(e);
    } catch (...) {
        cppbind_err->type = strdup("Uncaught Exception");
    }
    CppBindCObject result {};
    return result;
}

