/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/exceptions/exceptions.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_SystemError_jConstructor(JNIEnv* env, jobject obj, jstring message){
    jstring jjni_to_cxx_messageStr = (jstring)message;
    auto jni_to_cxx_message_cstr = env->GetStringUTFChars(jjni_to_cxx_messageStr, 0);
    std::string jni_to_cxx_message = jni_to_cxx_message_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_messageStr, jni_to_cxx_message_cstr);
    std::exception* baseptr = new iegen::example::SystemError(jni_to_cxx_message);
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_SystemError_jWhat(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto base_id = reinterpret_cast<std::exception*>(id);
    auto jni_to_cxx_id = dynamic_cast<iegen::example::SystemError*>(base_id);
    
    try {
        const auto& result = jni_to_cxx_id->what();
        jstring cxx_to_jni_result = env->NewStringUTF(result);
        return cxx_to_jni_result;
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
    jstring jjni_to_cxx_messageStr = (jstring)message;
    auto jni_to_cxx_message_cstr = env->GetStringUTFChars(jjni_to_cxx_messageStr, 0);
    std::string jni_to_cxx_message = jni_to_cxx_message_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_messageStr, jni_to_cxx_message_cstr);
    std::exception* baseptr = new iegen::example::FileError(jni_to_cxx_message);
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_FileError_jWhat(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto base_id = reinterpret_cast<std::exception*>(id);
    auto jni_to_cxx_id = dynamic_cast<iegen::example::FileError*>(base_id);
    
    try {
        const auto& result = jni_to_cxx_id->what();
        jstring cxx_to_jni_result = env->NewStringUTF(result);
        return cxx_to_jni_result;
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