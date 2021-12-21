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
#include "cxx/templates/pair.hpp"
#include "cxx/overloads/employee.hpp"
#include "cxx/forward_decl/student.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_templates_PairEmployee_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_PairEmployee_jConstructor(JNIEnv* env, jobject obj, jstring first, jobjectid second){
    jstring jjnitocxxfirstStr = (jstring)first;
    auto jnitocxxfirst_cstr = env->GetStringUTFChars(jjnitocxxfirstStr, 0);
    std::string jnitocxxfirst = jnitocxxfirst_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirstStr, jnitocxxfirst_cstr);
    
    std::shared_ptr<iegen::example::Employee>& jnitocxxsecond = *reinterpret_cast<std::shared_ptr<iegen::example::Employee>*>(second);
    try {
        iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>* baseptr = new iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>(jnitocxxfirst, jnitocxxsecond);
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

extern "C" JNIEXPORT jstring Java_com_examples_templates_PairEmployee_jFirst(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>*>(id);
    try {
        const auto& result = jnitocxxid->first();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_PairEmployee_jSecond(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Employee>>*>(id);
    try {
        const auto& result = jnitocxxid->second();
        
        jobjectid cxxtojniresult;
        cxxtojniresult = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Employee>(result));
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

extern "C" JNIEXPORT void Java_com_examples_templates_PairStudent_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_PairStudent_jConstructor(JNIEnv* env, jobject obj, jstring first, jobjectid second){
    jstring jjnitocxxfirstStr = (jstring)first;
    auto jnitocxxfirst_cstr = env->GetStringUTFChars(jjnitocxxfirstStr, 0);
    std::string jnitocxxfirst = jnitocxxfirst_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirstStr, jnitocxxfirst_cstr);
    
    std::shared_ptr<iegen::example::Student>& jnitocxxsecond = *reinterpret_cast<std::shared_ptr<iegen::example::Student>*>(second);
    try {
        iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>* baseptr = new iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>(jnitocxxfirst, jnitocxxsecond);
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

extern "C" JNIEXPORT jstring Java_com_examples_templates_PairStudent_jFirst(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>*>(id);
    try {
        const auto& result = jnitocxxid->first();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_PairStudent_jSecond(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::Pair<std::string, std::shared_ptr<iegen::example::Student>>*>(id);
    try {
        const auto& result = jnitocxxid->second();
        
        jobjectid cxxtojniresult;
        cxxtojniresult = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Student>(result));
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