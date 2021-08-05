/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 08/04/2021-08:55.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/extra/object.hpp"

using namespace iegen;


extern "C" JNIEXPORT void Java_com_examples_extra_Object_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_extra_Object_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    delete &this_object;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jTostring(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->toString();
      jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
      return cxx_to_jni_result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jstring result;
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jClassname(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->className();
      jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
      return cxx_to_jni_result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jstring result;
    return result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_extra_Object_jEquals(JNIEnv* env, jobject obj, jobjectid id, jobjectid other){
    

    std::shared_ptr<iegen::Object> jni_to_cxx_other;
    jni_to_cxx_other = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(other);

    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->equals(jni_to_cxx_other);
      
      return result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jboolean result;
    return result;
}


extern "C" JNIEXPORT jlong Java_com_examples_extra_Object_jHash(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->hash();
      
      return result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jlong result;
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jDebuginfo(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->debugInfo();
      jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
      return cxx_to_jni_result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jstring result;
    return result;
}


extern "C" JNIEXPORT jlong Java_com_examples_extra_Object_jBytescount(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->bytesCount();
      
      return result;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jlong result;
    return result;
}