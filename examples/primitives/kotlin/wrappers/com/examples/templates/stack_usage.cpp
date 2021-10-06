/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/06/2021-06:14.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/stack_usage.hpp"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_templates_StackUsage_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::StackUsage*>(id);
    delete jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::StackUsage* baseptr = new iegen::example::StackUsage();
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jFirstitemofspecializedstack(JNIEnv* env, jobject obj, jobjectid id, jobjectid p){
    

    auto base_p = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(p);
    auto jni_to_cxx_p = dynamic_cast<iegen::example::Stack<Project>*>(base_p);

    validateID(id);
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::StackUsage*>(id);
    
    try {
        auto result = jni_to_cxx_id->firstItemOfSpecializedStack(jni_to_cxx_p);
        
        iegen::example::Project* cxx_to_jni_result_baseptr = result;
        jobjectid cxx_to_jni_result = reinterpret_cast<jlong>(cxx_to_jni_result_baseptr);
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

    jobjectid result;
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jFirstitemoftemplatestackProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0){
    

    auto jni_to_cxx_arg0 = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(arg0);

    validateID(id);
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::StackUsage*>(id);
    
    try {
        auto result = jni_to_cxx_id->firstItemOfTemplateStack<iegen::example::Project>(jni_to_cxx_arg0);
        
        iegen::example::Project* cxx_to_jni_result_baseptr = result;
        jobjectid cxx_to_jni_result = reinterpret_cast<jlong>(cxx_to_jni_result_baseptr);
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

    jobjectid result;
    return result;
}