/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/16/2021-14:18.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/overloads/utils.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_overloads_Utils_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::Utils>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::Utils>*>(id);
    delete &jni_to_cxx_id;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_overloads_Utils_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::Utils* obj_ptr = new iegen::example::Utils();
    auto this_object = std::shared_ptr<iegen::example::Utils>(obj_ptr);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Utils>(this_object));
}


extern "C" JNIEXPORT jint Java_com_examples_overloads_Utils_jSum(JNIEnv* env, jobject obj, jint first, jint second){
    




    
    try {
        auto result = iegen::example::Utils::sum(first, second);
        
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

    jint result;
    return result;
}


extern "C" JNIEXPORT jfloat Java_com_examples_overloads_Utils_jSum_11(JNIEnv* env, jobject obj, jfloat first, jfloat second){
    




    
    try {
        auto result = iegen::example::Utils::sum(first, second);
        
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

    jfloat result;
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second){
    
    jstring jjni_to_cxx_firstStr = (jstring)first;
    auto jni_to_cxx_first_cstr = env->GetStringUTFChars(jjni_to_cxx_firstStr, 0);
    std::string jni_to_cxx_first = jni_to_cxx_first_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_firstStr, jni_to_cxx_first_cstr);

    jstring jjni_to_cxx_secondStr = (jstring)second;
    auto jni_to_cxx_second_cstr = env->GetStringUTFChars(jjni_to_cxx_secondStr, 0);
    std::string jni_to_cxx_second = jni_to_cxx_second_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_secondStr, jni_to_cxx_second_cstr);

    validateID(id);
    std::shared_ptr<iegen::example::Utils>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::Utils>*>(id);
    
    try {
        auto result = jni_to_cxx_id->concatenate(jni_to_cxx_first, jni_to_cxx_second);
        jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
        return cxx_to_jni_result;
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

    jstring result;
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate_11(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second, jstring third){
    
    jstring jjni_to_cxx_firstStr = (jstring)first;
    auto jni_to_cxx_first_cstr = env->GetStringUTFChars(jjni_to_cxx_firstStr, 0);
    std::string jni_to_cxx_first = jni_to_cxx_first_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_firstStr, jni_to_cxx_first_cstr);

    jstring jjni_to_cxx_secondStr = (jstring)second;
    auto jni_to_cxx_second_cstr = env->GetStringUTFChars(jjni_to_cxx_secondStr, 0);
    std::string jni_to_cxx_second = jni_to_cxx_second_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_secondStr, jni_to_cxx_second_cstr);

    jstring jjni_to_cxx_thirdStr = (jstring)third;
    auto jni_to_cxx_third_cstr = env->GetStringUTFChars(jjni_to_cxx_thirdStr, 0);
    std::string jni_to_cxx_third = jni_to_cxx_third_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_thirdStr, jni_to_cxx_third_cstr);

    validateID(id);
    std::shared_ptr<iegen::example::Utils>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::Utils>*>(id);
    
    try {
        auto result = jni_to_cxx_id->concatenate(jni_to_cxx_first, jni_to_cxx_second, jni_to_cxx_third);
        jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
        return cxx_to_jni_result;
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

    jstring result;
    return result;
}