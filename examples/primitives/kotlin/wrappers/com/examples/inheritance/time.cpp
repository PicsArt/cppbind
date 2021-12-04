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
#include "cxx/inheritance/time.hpp"
#include "cxx/inheritance/base.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_inheritance_TimeImpl_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::Base>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::Base>*>(id);
    delete &jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_TimeImpl_jConstructor(JNIEnv* env, jobject obj, jint h, jint m, jint s){
    
    
    
    iegen::example::Time* obj_ptr = new iegen::example::Time(h, m, s);
    auto this_object = std::shared_ptr<iegen::example::Time>(obj_ptr);
    std::shared_ptr<iegen::example::Base> baseptr = std::dynamic_pointer_cast<iegen::example::Base>(this_object);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Base>(baseptr));
}


extern "C" JNIEXPORT jstring Java_com_examples_inheritance_ITimeHelper_jValue(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    std::shared_ptr<iegen::example::Time> jni_to_cxx_id = std::dynamic_pointer_cast<iegen::example::Time>(*reinterpret_cast<std::shared_ptr<iegen::example::Base>*>(id));
    
    try {
        const auto& result = jni_to_cxx_id->value();
        jstring cxx_to_jni_result = env->NewStringUTF(result.data());
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

extern "C" JNIEXPORT jstring Java_com_examples_inheritance_ITimeHelper_jTime(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::Time> jni_to_cxx_id = std::dynamic_pointer_cast<iegen::example::Time>(*reinterpret_cast<std::shared_ptr<iegen::example::Base>*>(id));
    try {
        const auto& result = jni_to_cxx_id->time();
        jstring cxx_to_jni_result = env->NewStringUTF(result.data());
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