/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:28.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rectangle.hpp"
#include "cxx/inheritance/parallelogram.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_inheritance_RectangleImpl_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Parallelogram*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_RectangleImpl_jConstructor(JNIEnv* env, jobject obj, jdouble length, jdouble width){
    
    
    try {
        iegen::example::Parallelogram* baseptr = new iegen::example::Rectangle(length, width);
        return reinterpret_cast<jlong>(baseptr);
    }
    catch (const std::exception& e) {
          jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result;
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jnitocxxid = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        const auto& result = jnitocxxid->area();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jLength(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jnitocxxid = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        const auto& result = jnitocxxid->length();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_IRectangleHelper_jWidth(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto base_id = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto jnitocxxid = dynamic_cast<iegen::example::Rectangle*>(base_id);
    try {
        const auto& result = jnitocxxid->width();
        
        return result;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jdouble result;
    return result;
}
