/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/20/2022-08:00.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/typedefs/queue_int_shared.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHARED = "cppbind::example::QueueIntShared";
const char* CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHAREDUSAGE = "cppbind::example::QueueIntSharedUsage";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueIntShared_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_typedefs_QueueIntShared_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_id_ptr)->get());
}

extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntShared_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::example::QueueIntShared* obj_ptr = new cppbind::example::QueueIntShared();
        auto this_object = std::shared_ptr<cppbind::example::QueueIntShared>(obj_ptr);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHARED), new std::shared_ptr<cppbind::example::QueueIntShared>(this_object)});
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


extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueIntShared_jPush_1back([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint element, ...){
    


    validateID(id);
    std::shared_ptr<cppbind::example::QueueIntShared> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->push_back(element);
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


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntShared_jGet_1size([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    std::shared_ptr<cppbind::example::QueueIntShared> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->get_size();
        
        return result;
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

    jint result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueIntSharedUsage_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::QueueIntSharedUsage*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_typedefs_QueueIntSharedUsage_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::QueueIntSharedUsage*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntSharedUsage_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    
    std::shared_ptr<cppbind::example::QueueIntShared> jnitocxxq;
    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    jnitocxxq = *static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_q_ptr);
    try {
        cppbind::example::QueueIntSharedUsage* ptr = new cppbind::example::QueueIntSharedUsage(jnitocxxq);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHAREDUSAGE), ptr});
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


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntSharedUsage_jGetsize([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    std::shared_ptr<cppbind::example::QueueIntShared> jnitocxxq;
    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    jnitocxxq = *static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntSharedUsage::getSize(jnitocxxq);
        
        return result;
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

    jint result {};
    return result;
}


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntSharedUsage_jGetlastelement([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    std::shared_ptr<cppbind::example::QueueIntShared> jnitocxxq;
    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    jnitocxxq = *static_cast<std::shared_ptr<cppbind::example::QueueIntShared>*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntSharedUsage::getLastElement(jnitocxxq);
        
        return result;
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

    jint result {};
    return result;
}


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntSharedUsage_jGetfirstelement([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    std::shared_ptr<const cppbind::example::QueueIntShared> jnitocxxq;
    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    jnitocxxq = *static_cast<std::shared_ptr<const cppbind::example::QueueIntShared>*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntSharedUsage::getFirstElement(jnitocxxq);
        
        return result;
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

    jint result {};
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntSharedUsage_jGetinvqueue([[maybe_unused]] JNIEnv* env, jobject, jintArray v, ...){
    

    std::vector<int> jnitocxxv;
    auto _jnitocxxv = cppbind::getIntArray(env, v);
    for (auto& value__jnitocxxv : _jnitocxxv) {
        
        jnitocxxv.emplace_back(value__jnitocxxv);
    }

    
    try {
        const auto& result = cppbind::example::QueueIntSharedUsage::getInvQueue(jnitocxxv);
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHARED);
        void* cxxtojniresult_ptr = nullptr;
        CppBindCObject* cppbind_obj_cxxtojniresult = nullptr;
        cxxtojniresult_ptr = new std::shared_ptr<cppbind::example::QueueIntShared>(result);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntSharedUsage_jGetsavedqueue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueIntSharedUsage*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->getSavedQueue();
        
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHARED);
        void* cxxtojniresult_ptr = nullptr;
        CppBindCObject* cppbind_obj_cxxtojniresult = nullptr;
        cxxtojniresult_ptr = new std::shared_ptr<cppbind::example::QueueIntShared>(result);
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
extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntSharedUsage_jSaved_1queue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueIntSharedUsage*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->saved_queue;
    
    char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTSHARED);
    void* cxxtojniresult_ptr = nullptr;
    CppBindCObject* cppbind_obj_cxxtojniresult = nullptr;
    cxxtojniresult_ptr = new std::shared_ptr<cppbind::example::QueueIntShared>(result);
    cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
    return cxxtojniresult;
}

extern "C" JNIEXPORT jstring Java_com_examples_typedefs_Queue_1int_1sharedKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
