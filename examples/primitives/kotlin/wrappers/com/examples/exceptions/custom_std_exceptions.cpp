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
#include "cxx/exceptions/exceptions.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_SystemError_jConstructor(JNIEnv* env, jobject obj, jstring message){
    jstring jjnitocxxmessageStr = (jstring)message;
    auto jnitocxxmessage_cstr = env->GetStringUTFChars(jjnitocxxmessageStr, 0);
    std::string jnitocxxmessage = jnitocxxmessage_cstr;
    env->ReleaseStringUTFChars(jjnitocxxmessageStr, jnitocxxmessage_cstr);
    try {
        std::exception* baseptr = new iegen::example::SystemError(jnitocxxmessage);
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


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_SystemError_jWhat(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto base_id = reinterpret_cast<std::exception*>(id);
    auto jnitocxxid = dynamic_cast<iegen::example::SystemError*>(base_id);
    
    try {
        const auto& result = jnitocxxid->what();
        jstring cxxtojniresult = env->NewStringUTF(result);
        return cxxtojniresult;
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

    jstring result;
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_FileError_jConstructor(JNIEnv* env, jobject obj, jstring message){
    jstring jjnitocxxmessageStr = (jstring)message;
    auto jnitocxxmessage_cstr = env->GetStringUTFChars(jjnitocxxmessageStr, 0);
    std::string jnitocxxmessage = jnitocxxmessage_cstr;
    env->ReleaseStringUTFChars(jjnitocxxmessageStr, jnitocxxmessage_cstr);
    try {
        std::exception* baseptr = new iegen::example::FileError(jnitocxxmessage);
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


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_FileError_jWhat(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto base_id = reinterpret_cast<std::exception*>(id);
    auto jnitocxxid = dynamic_cast<iegen::example::FileError*>(base_id);
    
    try {
        const auto& result = jnitocxxid->what();
        jstring cxxtojniresult = env->NewStringUTF(result);
        return cxxtojniresult;
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

    jstring result;
    return result;
}
