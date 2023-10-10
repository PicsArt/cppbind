/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/26/2022-08:39.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/templates/tuple.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_INTSTUPLE = "cppbind::example::IntsTuple";
const char* CPPBIND_CPPBIND_EXAMPLE_MYTUPLEDOUBLE = "cppbind::example::MyTuple<double>";
const char* CPPBIND_CPPBIND_EXAMPLE_MYTUPLEINT = "cppbind::example::MyTuple<int>";

cppbind::example::tuple<int, double>* recover_obj_from_CppbindExample_TupleDoubleInt(jobjectid);
cppbind::example::tuple<int, int>* recover_obj_from_CppbindExample_TupleTwoInt(jobjectid);



extern "C" JNIEXPORT jobjectid Java_com_examples_templates_IntsTuple_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint a, jint b, jint c, ...){
    using namespace cppbind::example;
    
    
    
    try {
        cppbind::example::IntsTuple* this_object = new cppbind::example::IntsTuple(a, b, c);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_INTSTUPLE), this_object});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_MyTupleDouble_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jdouble a, jdouble b, ...){
    using namespace cppbind::example;
    
    
    try {
        cppbind::example::MyTuple<double>* this_object = new cppbind::example::MyTuple<double>(a, b);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_MYTUPLEDOUBLE), this_object});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_MyTupleInt_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint a, jint b, ...){
    using namespace cppbind::example;
    
    
    try {
        cppbind::example::MyTuple<int>* this_object = new cppbind::example::MyTuple<int>(a, b);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_MYTUPLEINT), this_object});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jint Java_com_examples_templates_Tuple_1usageKt_jGettuplefirstelementIntDouble(JNIEnv* env, jclass, jobjectid t1, ...){
    using namespace cppbind::example;
    

    cppbind::example::tuple<int, double>* jnitocxxt1_ptr = recover_obj_from_CppbindExample_TupleDoubleInt(t1);
    auto& jnitocxxt1 = *jnitocxxt1_ptr;
    
    try {
        decltype(auto) result = cppbind::example::getTupleFirstElement<int, double>(jnitocxxt1);
        
        return result;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}

extern "C" JNIEXPORT jint Java_com_examples_templates_Tuple_1usageKt_jGettuplefirstelementIntInt(JNIEnv* env, jclass, jobjectid t1, ...){
    using namespace cppbind::example;
    

    cppbind::example::tuple<int, int>* jnitocxxt1_ptr = recover_obj_from_CppbindExample_TupleTwoInt(t1);
    auto& jnitocxxt1 = *jnitocxxt1_ptr;
    
    try {
        decltype(auto) result = cppbind::example::getTupleFirstElement<int, int>(jnitocxxt1);
        
        return result;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jint result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_templates_Tuple_1usageKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}