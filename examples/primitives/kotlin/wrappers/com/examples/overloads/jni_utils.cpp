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
#include "cxx/overloads/utils.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_UTILS = "cppbind::example::Utils";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_overloads_Utils_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<cppbind::example::Utils>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_overloads_Utils_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::Utils>*>(cppbind_obj_id_ptr)->get());
}

extern "C" JNIEXPORT jobjectid Java_com_examples_overloads_Utils_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::example::Utils* obj_ptr = new cppbind::example::Utils();
        auto this_object = std::shared_ptr<cppbind::example::Utils>(obj_ptr);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_UTILS), new std::shared_ptr<cppbind::example::Utils>(this_object)});
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


extern "C" JNIEXPORT jint Java_com_examples_overloads_Utils_jSum([[maybe_unused]] JNIEnv* env, jobject, jint first, jint second, ...){
    




    
    try {
        const auto& result = cppbind::example::Utils::sum(first, second);
        
        return result;
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

    jint result {};
    return result;
}


extern "C" JNIEXPORT jfloat Java_com_examples_overloads_Utils_jSum_11([[maybe_unused]] JNIEnv* env, jobject, jfloat first, jfloat second, ...){
    




    
    try {
        const auto& result = cppbind::example::Utils::sum(first, second);
        
        return result;
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

    jfloat result {};
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring first, jstring second, ...){
    
    jstring jjnitocxxfirstStr = static_cast<jstring>(first);
    auto jnitocxxfirst_cstr = env->GetStringUTFChars(jjnitocxxfirstStr, 0);
    std::string jnitocxxfirst = jnitocxxfirst_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirstStr, jnitocxxfirst_cstr);

    jstring jjnitocxxsecondStr = static_cast<jstring>(second);
    auto jnitocxxsecond_cstr = env->GetStringUTFChars(jjnitocxxsecondStr, 0);
    std::string jnitocxxsecond = jnitocxxsecond_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsecondStr, jnitocxxsecond_cstr);

    validateID(id);
    std::shared_ptr<cppbind::example::Utils> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->concatenate(jnitocxxfirst, jnitocxxsecond);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate_11([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring first, jstring second, jstring third, ...){
    
    jstring jjnitocxxfirstStr = static_cast<jstring>(first);
    auto jnitocxxfirst_cstr = env->GetStringUTFChars(jjnitocxxfirstStr, 0);
    std::string jnitocxxfirst = jnitocxxfirst_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirstStr, jnitocxxfirst_cstr);

    jstring jjnitocxxsecondStr = static_cast<jstring>(second);
    auto jnitocxxsecond_cstr = env->GetStringUTFChars(jjnitocxxsecondStr, 0);
    std::string jnitocxxsecond = jnitocxxsecond_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsecondStr, jnitocxxsecond_cstr);

    jstring jjnitocxxthirdStr = static_cast<jstring>(third);
    auto jnitocxxthird_cstr = env->GetStringUTFChars(jjnitocxxthirdStr, 0);
    std::string jnitocxxthird = jnitocxxthird_cstr;
    env->ReleaseStringUTFChars(jjnitocxxthirdStr, jnitocxxthird_cstr);

    validateID(id);
    std::shared_ptr<cppbind::example::Utils> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::Utils>*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->concatenate(jnitocxxfirst, jnitocxxsecond, jnitocxxthird);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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


extern "C" JNIEXPORT jint Java_com_examples_overloads_Utils_jMinus([[maybe_unused]] JNIEnv* env, jobject, jint first, jint second, ...){
    




    
    try {
        const auto& result = cppbind::example::Utils::sub(first, second);
        
        return result;
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

    jint result {};
    return result;
}


extern "C" JNIEXPORT jfloat Java_com_examples_overloads_Utils_jMinus_11([[maybe_unused]] JNIEnv* env, jobject, jfloat first, jfloat second, ...){
    




    
    try {
        const auto& result = cppbind::example::Utils::sub(first, second);
        
        return result;
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

    jfloat result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_overloads_UtilsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
