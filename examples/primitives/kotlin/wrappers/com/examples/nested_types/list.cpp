/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/19/2022-05:52.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/nested_types/list.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_00024Item_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_00024Item_00024Value_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item::Value*>(id);
    delete jnitocxxid;
}
extern "C" JNIEXPORT jint Java_com_examples_nested_1types_List_00024Item_00024Value_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item::Value*>(id);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_00024Item_00024Value_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item::Value*>(id);
    
    
    jnitocxxid->value = value;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_List_00024Item_00024Value_jConstructor(JNIEnv* env, jobject obj, jint _value){
    
    try {
        iegen::example::List::Item::Value* baseptr = new iegen::example::List::Item::Value(_value);
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
extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_List_00024Item_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item*>(id);
    const auto& result = jnitocxxid->value;
    
    iegen::example::List::Item::Value* cxxtojniresult_baseptr = const_cast<iegen::example::List::Item::Value*>(result);
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cxxtojniresult_baseptr);
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_00024Item_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jobjectid value){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List::Item*>(id);
    
    
    auto jnitocxxvalue = reinterpret_cast<iegen::example::List::Item::Value*>(value);
    jnitocxxid->value = jnitocxxvalue;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_List_00024Item_jConstructor(JNIEnv* env, jobject obj, jobjectid v){
    
    auto jnitocxxv = reinterpret_cast<iegen::example::List::Item::Value*>(v);
    try {
        iegen::example::List::Item* baseptr = new iegen::example::List::Item(jnitocxxv);
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

extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_List_jConstructor(JNIEnv* env, jobject obj){
    try {
        iegen::example::List* baseptr = new iegen::example::List();
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


extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_jPush_1back(JNIEnv* env, jobject obj, jobjectid id, jobjectid item){
    

    auto jnitocxxitem = reinterpret_cast<iegen::example::List::Item*>(item);

    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::List*>(id);
    
    try {
        jnitocxxid->push_back(jnitocxxitem);
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


extern "C" JNIEXPORT void Java_com_examples_nested_1types_List_jPop_1back(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::List*>(id);
    
    try {
        jnitocxxid->pop_back();
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

extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_List_jBack(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::List*>(id);
    try {
        const auto& result = jnitocxxid->back();
        
        iegen::example::List::Item* cxxtojniresult_baseptr = const_cast<iegen::example::List::Item*>(result);
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