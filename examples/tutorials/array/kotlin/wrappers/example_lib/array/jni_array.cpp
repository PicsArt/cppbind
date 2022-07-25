/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/18/2022-09:06.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/array.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_STD_STDOUTOFRANGE;

const char* CPPBIND_CPPBIND_ARRAY = "cppbind::Array";

using namespace cppbind;


extern "C" JNIEXPORT void Java_example_1lib_array_Array_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_example_1lib_array_Array_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::Array*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_example_1lib_array_Array_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::Array* ptr = new cppbind::Array();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_ARRAY), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT jint Java_example_1lib_array_Array_jFront([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->front();
        
        return result;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}


extern "C" JNIEXPORT jint Java_example_1lib_array_Array_jBack([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->back();
        
        return result;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}


extern "C" JNIEXPORT void Java_example_1lib_array_Array_jPush_1back([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint element, ...){
    


    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->push_back(element);
        return;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }


}

extern "C" JNIEXPORT jint Java_example_1lib_array_Array_jSize([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->size();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}

extern "C" JNIEXPORT jboolean Java_example_1lib_array_Array_jEmpty([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->empty();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jboolean result {};
    return result;
}


extern "C" JNIEXPORT jint Java_example_1lib_array_Array_jGet([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint i, ...){
    


    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->operator[](i);
        
        return result;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}


extern "C" JNIEXPORT void Java_example_1lib_array_Array_jSet([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint i, jint value, ...){
    


    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->operator[](i) = value;
        return;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }


}


extern "C" JNIEXPORT jint Java_example_1lib_array_Array_jAt([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint i, ...){
    


    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::Array*>(cppbind_obj_id_ptr);
    
    void* err_ptr = nullptr;
    try {
        const auto& result = jnitocxxid->at(i);
        
        return result;
    }catch (const std::out_of_range& e) {
        err_ptr = new std::out_of_range(e);
        jclass excCls = env->FindClass("example_lib/cppbind/exception_helpers/StdOutOfRange");
        jclass cppbindObjClass = env->FindClass("example_lib/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDOUTOFRANGE), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lexample_lib/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("example_lib/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_example_1lib_array_ArrayKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
