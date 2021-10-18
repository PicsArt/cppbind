/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/15/2021-18:18.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rectangle.hpp"
#include "cxx/inheritance/parallelogram.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_inheritance_RectangleImpl_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    delete jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_RectangleImpl_jConstructor(JNIEnv* env, jobject obj, jdouble length, jdouble width){
    
    
    iegen::example::Parallelogram* baseptr = new iegen::example::Rectangle(length, width);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jni_to_cxx_id = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        auto result = jni_to_cxx_id->area();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jLength(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jni_to_cxx_id = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        auto result = jni_to_cxx_id->length();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jWidth(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jni_to_cxx_id = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        auto result = jni_to_cxx_id->width();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}