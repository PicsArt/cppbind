/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:29.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/nested_types/template_list.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_TEMPLATELISTINT = "cppbind::example::TemplateList<int>";
const char* CPPBIND_TEMPLATELISTINT_ITEM = "cppbind::example::TemplateList<int>::Item";
const char* CPPBIND_CPPBIND_EXAMPLE_TEMPLATELISTDOUBLE = "cppbind::example::TemplateList<double>";
const char* CPPBIND_TEMPLATELISTDOUBLE_ITEM = "cppbind::example::TemplateList<double>::Item";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::TemplateList<int>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListInt_00024Item_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::TemplateList<int>::Item*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}
extern "C" JNIEXPORT jint Java_com_examples_nested_1types_TemplateListInt_00024Item_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::TemplateList<int>::Item*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListInt_00024Item_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::TemplateList<int>::Item*>(cppbind_obj_id_ptr);
    
    
    jnitocxxid->value = value;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_TemplateListInt_00024Item_jConstructor(JNIEnv* env, jobject obj, jint v){
    
    try {
        cppbind::example::TemplateList<int>::Item* ptr = new cppbind::example::TemplateList<int>::Item(v);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_TEMPLATELISTINT_ITEM), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_TemplateListInt_jConstructor(JNIEnv* env, jobject obj){
    try {
        cppbind::example::TemplateList<int>* ptr = new cppbind::example::TemplateList<int>();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_TEMPLATELISTINT), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::TemplateList<double>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListDouble_00024Item_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::TemplateList<double>::Item*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}
extern "C" JNIEXPORT jdouble Java_com_examples_nested_1types_TemplateListDouble_00024Item_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::TemplateList<double>::Item*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nested_1types_TemplateListDouble_00024Item_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jdouble value){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::TemplateList<double>::Item*>(cppbind_obj_id_ptr);
    
    
    jnitocxxid->value = value;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_TemplateListDouble_00024Item_jConstructor(JNIEnv* env, jobject obj, jdouble v){
    
    try {
        cppbind::example::TemplateList<double>::Item* ptr = new cppbind::example::TemplateList<double>::Item(v);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_TEMPLATELISTDOUBLE_ITEM), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nested_1types_TemplateListDouble_jConstructor(JNIEnv* env, jobject obj){
    try {
        cppbind::example::TemplateList<double>* ptr = new cppbind::example::TemplateList<double>();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_TEMPLATELISTDOUBLE), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_nested_1types_Template_1listKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
