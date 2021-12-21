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
#include "cxx/getters/number.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<int>*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberInt_jConstructor(JNIEnv* env, jobject obj, jint n){
    
    try {
        iegen::example::Number<int>* baseptr = new iegen::example::Number<int>(n);
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


extern "C" JNIEXPORT jint Java_com_examples_getters_NumberInt_jToint(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<int>*>(id);
    
    try {
        const auto& result = jnitocxxid->toInt();
        
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

    jint result;
    return result;
}
extern "C" JNIEXPORT jint Java_com_examples_getters_NumberInt_jNum(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<int>*>(id);
    const auto& result = jnitocxxid->num;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<int>*>(id);
    
    
    jnitocxxid->num = value;
}


extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<double>*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberDouble_jConstructor(JNIEnv* env, jobject obj, jdouble n){
    
    try {
        iegen::example::Number<double>* baseptr = new iegen::example::Number<double>(n);
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


extern "C" JNIEXPORT jint Java_com_examples_getters_NumberDouble_jToint(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<double>*>(id);
    
    try {
        const auto& result = jnitocxxid->toInt();
        
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

    jint result;
    return result;
}
extern "C" JNIEXPORT jdouble Java_com_examples_getters_NumberDouble_jNum(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<double>*>(id);
    const auto& result = jnitocxxid->num;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jdouble value){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Number<double>*>(id);
    
    
    jnitocxxid->num = value;
}

