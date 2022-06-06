/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/02/2022-09:35.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/rv_policies/keep_alive_policy.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_CHILD1 = "cppbind::example::Child1";
const char* CPPBIND_CPPBIND_EXAMPLE_ICHILD3 = "cppbind::example::Child3";
const char* CPPBIND_CPPBIND_EXAMPLE_CHILD2 = "cppbind::example::Child2";
const char* CPPBIND_CPPBIND_EXAMPLE_PARENT1 = "cppbind::example::Parent1";
const char* CPPBIND_CPPBIND_EXAMPLE_PARENT2 = "cppbind::example::Parent2";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Child1_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Child1*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_rv_1policies_Child1_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Child1*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Child1_jConstructor(JNIEnv* env, jobject obj, jstring name, ...){
    jstring jjnitocxxnameStr = static_cast<jstring>(name);
    auto jnitocxxname_cstr = env->GetStringUTFChars(jjnitocxxnameStr, 0);
    std::string jnitocxxname = jnitocxxname_cstr;
    env->ReleaseStringUTFChars(jjnitocxxnameStr, jnitocxxname_cstr);
    try {
        cppbind::example::Child1* ptr = new cppbind::example::Child1(jnitocxxname);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD1), ptr});
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

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_Child1_jName(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Child1*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->name();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Child3Impl_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Child3*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_rv_1policies_Child3Impl_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Child3*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Child3Impl_jConstructor(JNIEnv* env, jobject obj, jstring name, ...){
    jstring jjnitocxxnameStr = static_cast<jstring>(name);
    auto jnitocxxname_cstr = env->GetStringUTFChars(jjnitocxxnameStr, 0);
    std::string jnitocxxname = jnitocxxname_cstr;
    env->ReleaseStringUTFChars(jjnitocxxnameStr, jnitocxxname_cstr);
    try {
        cppbind::example::Child3* ptr = new cppbind::example::Child3(jnitocxxname);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_ICHILD3), ptr});
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

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_IChild3Helper_jName(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Child3*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->name();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Child2_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_rv_1policies_Child2_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_id_ptr)->get());
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Child2_jConstructor(JNIEnv* env, jobject obj, jstring name, ...){
    jstring jjnitocxxnameStr = static_cast<jstring>(name);
    auto jnitocxxname_cstr = env->GetStringUTFChars(jjnitocxxnameStr, 0);
    std::string jnitocxxname = jnitocxxname_cstr;
    env->ReleaseStringUTFChars(jjnitocxxnameStr, jnitocxxname_cstr);
    try {
        cppbind::example::Child2* obj_ptr = new cppbind::example::Child2(jnitocxxname);
        auto this_object = std::shared_ptr<cppbind::example::Child2>(obj_ptr);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD2), new std::shared_ptr<cppbind::example::Child2>(this_object)});
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

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_Child2_jName(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<cppbind::example::Child2> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->name();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent1_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_rv_1policies_Parent1_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Parent1_jConstructor(JNIEnv* env, jobject obj, jstring name, jobjectid child1, jobjectid child2, jobjectid _child3, ...){
    jstring jjnitocxxnameStr = static_cast<jstring>(name);
    auto jnitocxxname_cstr = env->GetStringUTFChars(jjnitocxxnameStr, 0);
    std::string jnitocxxname = jnitocxxname_cstr;
    env->ReleaseStringUTFChars(jjnitocxxnameStr, jnitocxxname_cstr);
    
    auto cppbind_obj_child1 = reinterpret_cast<CppBindCObject*>(child1);
    auto cppbind_obj_child1_ptr = cppbind_obj_child1 ? cppbind_obj_child1->ptr : nullptr;
    auto jnitocxxchild1 = static_cast<cppbind::example::Child1*>(cppbind_obj_child1_ptr);
    
    std::shared_ptr<cppbind::example::Child2> jnitocxxchild2;
    auto cppbind_obj_child2 = reinterpret_cast<CppBindCObject*>(child2);
    auto cppbind_obj_child2_ptr = cppbind_obj_child2 ? cppbind_obj_child2->ptr : nullptr;
    jnitocxxchild2 = *static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_child2_ptr);
    
    auto cppbind_obj__child3 = reinterpret_cast<CppBindCObject*>(_child3);
    auto cppbind_obj__child3_ptr = cppbind_obj__child3 ? cppbind_obj__child3->ptr : nullptr;
    auto jnitocxx_child3 = static_cast<cppbind::example::Child3*>(cppbind_obj__child3_ptr);
    try {
        cppbind::example::Parent1* ptr = new cppbind::example::Parent1(jnitocxxname, jnitocxxchild1, jnitocxxchild2, jnitocxx_child3);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_PARENT1), ptr});
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

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_Parent1_jName(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->name();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Parent1_jChild1(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->child1();
        cppbind::example::Child1* cxxtojniresult_ptr = const_cast<cppbind::example::Child1*>(result);
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD1);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
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

extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent1_jSetchild1(JNIEnv* env, jobject obj, jobjectid id, jobjectid child1, ...){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    
    auto cppbind_obj_child1 = reinterpret_cast<CppBindCObject*>(child1);
    auto cppbind_obj_child1_ptr = cppbind_obj_child1 ? cppbind_obj_child1->ptr : nullptr;
    auto jnitocxxchild1 = static_cast<cppbind::example::Child1*>(cppbind_obj_child1_ptr);
    try {
       jnitocxxid->setChild1(jnitocxxchild1);
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
}


extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Parent1_jChild2(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->child2();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD2);
        void* cxxtojniresult_ptr = nullptr;
        CppBindCObject* cppbind_obj_cxxtojniresult = nullptr;
        cxxtojniresult_ptr = new std::shared_ptr<cppbind::example::Child2>(result);
        cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
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
extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Parent1_jChild3(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->child3;
    cppbind::example::Child3* cxxtojniresult_ptr = const_cast<cppbind::example::Child3*>(result);
    char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ICHILD3);
    CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent1_jSetchild3(JNIEnv* env, jobject obj, jobjectid id, jobjectid value, ...){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent1*>(cppbind_obj_id_ptr);
    
    
    auto cppbind_obj_value = reinterpret_cast<CppBindCObject*>(value);
    auto cppbind_obj_value_ptr = cppbind_obj_value ? cppbind_obj_value->ptr : nullptr;
    auto jnitocxxvalue = static_cast<cppbind::example::Child3*>(cppbind_obj_value_ptr);
    jnitocxxid->child3 = jnitocxxvalue;
}


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent2_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_rv_1policies_Parent2_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_rv_1policies_Parent2_jConstructor(JNIEnv* env, jobject obj, jstring name, ...){
    jstring jjnitocxxnameStr = static_cast<jstring>(name);
    auto jnitocxxname_cstr = env->GetStringUTFChars(jjnitocxxnameStr, 0);
    std::string jnitocxxname = jnitocxxname_cstr;
    env->ReleaseStringUTFChars(jjnitocxxnameStr, jnitocxxname_cstr);
    try {
        cppbind::example::Parent2* ptr = new cppbind::example::Parent2(jnitocxxname);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_PARENT2), ptr});
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

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_Parent2_jName(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->name();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jobjectidArray Java_com_examples_rv_1policies_Parent2_jChildren1(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->children1();
        
        jobjectidArray cxxtojniresult = env->NewLongArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            cppbind::example::Child1* cxxtojnivalue_result_ptr = const_cast<cppbind::example::Child1*>(value_result);
            char* type_value_result = strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD1);
            CppBindCObject* cppbind_obj_cxxtojnivalue_result = new CppBindCObject {type_value_result, cxxtojnivalue_result_ptr};
            jobjectid cxxtojnivalue_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnivalue_result);
            env->SetLongArrayRegion(cxxtojniresult, index_result, 1, &cxxtojnivalue_result);
            ++index_result ;
        }
        return cxxtojniresult;
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

    jobjectidArray result {};
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent2_jAddchild1(JNIEnv* env, jobject obj, jobjectid id, jobjectid c, ...){
    

    auto cppbind_obj_c = reinterpret_cast<CppBindCObject*>(c);
    auto cppbind_obj_c_ptr = cppbind_obj_c ? cppbind_obj_c->ptr : nullptr;
    auto jnitocxxc = static_cast<cppbind::example::Child1*>(cppbind_obj_c_ptr);

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->addChild1(jnitocxxc);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent2_jAddchildren1(JNIEnv* env, jobject obj, jobjectid id, jobjectidArray c, ...){
    

    std::vector<Child1 *> jnitocxxc;
    auto _jnitocxxc = cppbind::getLongArray(env, c);
    for (auto& value__jnitocxxc : _jnitocxxc) {
        
        auto cppbind_obj_value__jnitocxxc = reinterpret_cast<CppBindCObject*>(value__jnitocxxc);
        auto cppbind_obj_value__jnitocxxc_ptr = cppbind_obj_value__jnitocxxc ? cppbind_obj_value__jnitocxxc->ptr : nullptr;
        auto jnitocxxvalue__jnitocxxc = static_cast<cppbind::example::Child1*>(cppbind_obj_value__jnitocxxc_ptr);
        jnitocxxc.emplace_back(jnitocxxvalue__jnitocxxc);
    }

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->addChildren1(jnitocxxc);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent2_jAddchild2(JNIEnv* env, jobject obj, jobjectid id, jobjectid c, ...){
    

    std::shared_ptr<cppbind::example::Child2> jnitocxxc;
    auto cppbind_obj_c = reinterpret_cast<CppBindCObject*>(c);
    auto cppbind_obj_c_ptr = cppbind_obj_c ? cppbind_obj_c->ptr : nullptr;
    jnitocxxc = *static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_c_ptr);

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->addChild2(jnitocxxc);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_rv_1policies_Parent2_jAddchildren2(JNIEnv* env, jobject obj, jobjectid id, jobjectidArray c, ...){
    

    std::vector<std::shared_ptr<Child2>> jnitocxxc;
    auto _jnitocxxc = cppbind::getLongArray(env, c);
    for (auto& value__jnitocxxc : _jnitocxxc) {
        
        std::shared_ptr<cppbind::example::Child2> jnitocxxvalue__jnitocxxc;
        auto cppbind_obj_value__jnitocxxc = reinterpret_cast<CppBindCObject*>(value__jnitocxxc);
        auto cppbind_obj_value__jnitocxxc_ptr = cppbind_obj_value__jnitocxxc ? cppbind_obj_value__jnitocxxc->ptr : nullptr;
        jnitocxxvalue__jnitocxxc = *static_cast<std::shared_ptr<cppbind::example::Child2>*>(cppbind_obj_value__jnitocxxc_ptr);
        jnitocxxc.emplace_back(jnitocxxvalue__jnitocxxc);
    }

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->addChildren2(jnitocxxc);
        return;
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


}

extern "C" JNIEXPORT jobjectidArray Java_com_examples_rv_1policies_Parent2_jChildren2(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Parent2*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->children2();
        
        jobjectidArray cxxtojniresult = env->NewLongArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            
            char* type_value_result = strdup(CPPBIND_CPPBIND_EXAMPLE_CHILD2);
            void* cxxtojnivalue_result_ptr = nullptr;
            CppBindCObject* cppbind_obj_cxxtojnivalue_result = nullptr;
            cxxtojnivalue_result_ptr = new std::shared_ptr<cppbind::example::Child2>(value_result);
            cppbind_obj_cxxtojnivalue_result = new CppBindCObject {type_value_result, cxxtojnivalue_result_ptr};
            jobjectid cxxtojnivalue_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnivalue_result);
            env->SetLongArrayRegion(cxxtojniresult, index_result, 1, &cxxtojnivalue_result);
            ++index_result ;
        }
        return cxxtojniresult;
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

    jobjectidArray result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_rv_1policies_Keep_1alive_1policyKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
