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
#include "cxx/nullables/nullable_utils.hpp"

using namespace iegen::example::nullable;


extern "C" JNIEXPORT void Java_com_examples_nullables_NumberInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::nullable::NumberInt>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(id);
    delete &jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_NumberInt_jConstructor(JNIEnv* env, jobject obj, jint val_){
    
    try {
        iegen::example::nullable::NumberInt* obj_ptr = new iegen::example::nullable::NumberInt(val_);
        auto this_object = std::shared_ptr<iegen::example::nullable::NumberInt>(obj_ptr);
        return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::nullable::NumberInt>(this_object));
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
extern "C" JNIEXPORT jint Java_com_examples_nullables_NumberInt_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::NumberInt>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(id);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_NumberDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::nullable::NumberDouble*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_NumberDouble_jConstructor(JNIEnv* env, jobject obj, jdouble val_){
    
    try {
        iegen::example::nullable::NumberDouble* baseptr = new iegen::example::nullable::NumberDouble(val_);
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
extern "C" JNIEXPORT jdouble Java_com_examples_nullables_NumberDouble_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::nullable::NumberDouble*>(id);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    delete &jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jConstructor(JNIEnv* env, jobject obj, jobjectid num){
    
    auto jnitocxxnum = reinterpret_cast<iegen::example::nullable::NumberDouble*>(num);
    try {
        iegen::example::nullable::Utils* obj_ptr = new iegen::example::nullable::Utils(jnitocxxnum);
        auto this_object = std::shared_ptr<iegen::example::nullable::Utils>(obj_ptr);
        return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::nullable::Utils>(this_object));
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


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jMax(JNIEnv* env, jobject obj, jobjectid first, jobjectid second){
    

    auto jnitocxxfirst = reinterpret_cast<iegen::example::nullable::NumberDouble*>(first);


    auto jnitocxxsecond = reinterpret_cast<iegen::example::nullable::NumberDouble*>(second);

    
    try {
        const auto& result = iegen::example::nullable::Utils::max(jnitocxxfirst, jnitocxxsecond);
        
        iegen::example::nullable::NumberDouble* cxxtojniresult_baseptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
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

    jobjectid result;
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jMax_11(JNIEnv* env, jobject obj, jobjectid first, jobjectid second){
    

    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxfirst = nullptr;
    if (first) {
        jnitocxxfirst = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(first);
    }


    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxsecond = nullptr;
    if (second) {
        jnitocxxsecond = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(second);
    }

    
    try {
        const auto& result = iegen::example::nullable::Utils::max(jnitocxxfirst, jnitocxxsecond);
        
        jobjectid cxxtojniresult = 0;
        if (result) {
            cxxtojniresult = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::nullable::NumberInt>(result));
        }
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

    jobjectid result;
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jChecknonnullarg(JNIEnv* env, jobject obj, jobjectid number){
    

    auto jnitocxxnumber = reinterpret_cast<iegen::example::nullable::NumberDouble*>(number);

    
    try {
        iegen::example::nullable::Utils::checkNonnullArg(jnitocxxnumber);
        return;
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


}


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jChecknonnullreturn(JNIEnv* env, jobject obj){
    
    
    try {
        const auto& result = iegen::example::nullable::Utils::checkNonnullReturn();
        
        iegen::example::nullable::NumberDouble* cxxtojniresult_baseptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNullable(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    try {
        const auto& result = jnitocxxid->nullable();
        
        iegen::example::nullable::NumberDouble* cxxtojniresult_baseptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnullable(JNIEnv* env, jobject obj, jobjectid id, jobjectid num){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    
    auto jnitocxxnum = reinterpret_cast<iegen::example::nullable::NumberDouble*>(num);
    try {
       jnitocxxid->setNullable(jnitocxxnum);
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
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNonnull(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    try {
        const auto& result = jnitocxxid->nonNull();
        
        iegen::example::nullable::NumberDouble* cxxtojniresult_baseptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnonnull(JNIEnv* env, jobject obj, jobjectid id, jobjectid num){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    
    auto jnitocxxnum = reinterpret_cast<iegen::example::nullable::NumberDouble*>(num);
    try {
       jnitocxxid->setNonNull(jnitocxxnum);
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
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNumdouble(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    const auto& result = jnitocxxid->numDouble;
    
    iegen::example::nullable::NumberDouble* cxxtojniresult_baseptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnumdouble(JNIEnv* env, jobject obj, jobjectid id, jobjectid value){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    
    
    auto jnitocxxvalue = reinterpret_cast<iegen::example::nullable::NumberDouble*>(value);
    jnitocxxid->numDouble = jnitocxxvalue;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNumint(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    const auto& result = jnitocxxid->numInt;
    
    jobjectid cxxtojniresult;
    cxxtojniresult = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::nullable::NumberInt>(result));
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnumint(JNIEnv* env, jobject obj, jobjectid id, jobjectid value){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils>& jnitocxxid = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(id);
    
    
    std::shared_ptr<iegen::example::nullable::NumberInt>& jnitocxxvalue = *reinterpret_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(value);
    jnitocxxid->numInt = jnitocxxvalue;
}

