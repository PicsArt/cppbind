/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/20/2022-08:00.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/exceptions/exceptions.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR = "cppbind::example::SystemError";
const char* CPPBIND_CPPBIND_EXAMPLE_FILEERROR = "cppbind::example::FileError";

using namespace cppbind::example;



cppbind::example::SystemError* recover_obj_from_CppbindExample_SystemError(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR) == 0)
            return static_cast<cppbind::example::SystemError*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_FILEERROR) == 0)
            return static_cast<cppbind::example::FileError*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_SystemError_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jstring message, ...){
    jstring jjnitocxxmessageStr = static_cast<jstring>(message);
    auto jnitocxxmessage_cstr = env->GetStringUTFChars(jjnitocxxmessageStr, 0);
    std::string jnitocxxmessage = jnitocxxmessage_cstr;
    env->ReleaseStringUTFChars(jjnitocxxmessageStr, jnitocxxmessage_cstr);
    try {
        cppbind::example::SystemError* ptr = new cppbind::example::SystemError(jnitocxxmessage);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_SystemError_jWhat([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    cppbind::example::SystemError* jnitocxxid = recover_obj_from_CppbindExample_SystemError(id);
    
    try {
        const auto& result = jnitocxxid->what();
        jstring cxxtojniresult = env->NewStringUTF(result);
        return cxxtojniresult;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jstring result {};
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_FileError_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jstring message, ...){
    jstring jjnitocxxmessageStr = static_cast<jstring>(message);
    auto jnitocxxmessage_cstr = env->GetStringUTFChars(jjnitocxxmessageStr, 0);
    std::string jnitocxxmessage = jnitocxxmessage_cstr;
    env->ReleaseStringUTFChars(jjnitocxxmessageStr, jnitocxxmessage_cstr);
    try {
        cppbind::example::FileError* ptr = new cppbind::example::FileError(jnitocxxmessage);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_FILEERROR), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_FileError_jWhat([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::FileError*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->what();
        jstring cxxtojniresult = env->NewStringUTF(result);
        return cxxtojniresult;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_exceptions_Custom_1std_1exceptionsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
