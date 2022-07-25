/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 07/14/2022-12:49.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/typedefs/queue_int.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_QUEUEINT = "cppbind::example::QueueInt";
const char* CPPBIND_CPPBIND_EXAMPLE_QUEUEINTUSAGE = "cppbind::example::QueueIntUsage";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueInt_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::QueueInt*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_typedefs_QueueInt_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::QueueInt*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueInt_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::example::QueueInt* ptr = new cppbind::example::QueueInt();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINT), ptr});
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


extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueInt_jPush_1back([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jint element, ...){
    


    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueInt*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->push_back(element);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueInt_jPush_1back_1from_1str([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring element, ...){
    
    jstring jjnitocxxelementStr = static_cast<jstring>(element);
    auto jnitocxxelement_cstr = env->GetStringUTFChars(jjnitocxxelementStr, 0);
    std::string jnitocxxelement = jnitocxxelement_cstr;
    env->ReleaseStringUTFChars(jjnitocxxelementStr, jnitocxxelement_cstr);

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueInt*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->push_back_from_str(jnitocxxelement);
        return;
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


}


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueInt_jGet_1size([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueInt*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->get_size();
        
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

extern "C" JNIEXPORT void Java_com_examples_typedefs_QueueIntUsage_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::QueueIntUsage*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_typedefs_QueueIntUsage_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::QueueIntUsage*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntUsage_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    
    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    auto jnitocxxq = static_cast<cppbind::example::QueueInt*>(cppbind_obj_q_ptr);
    try {
        cppbind::example::QueueIntUsage* ptr = new cppbind::example::QueueIntUsage(jnitocxxq);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINTUSAGE), ptr});
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


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntUsage_jGetsize([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    auto& jnitocxxq = *static_cast<cppbind::example::ConstQueueIntType*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntUsage::getSize(jnitocxxq);
        
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


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntUsage_jGetlastelement([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    auto jnitocxxq = static_cast<cppbind::example::QueueIntType*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntUsage::getLastElement(jnitocxxq);
        
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


extern "C" JNIEXPORT jint Java_com_examples_typedefs_QueueIntUsage_jGetfirstelement([[maybe_unused]] JNIEnv* env, jobject, jobjectid q, ...){
    

    auto cppbind_obj_q = reinterpret_cast<CppBindCObject*>(q);
    auto cppbind_obj_q_ptr = cppbind_obj_q ? cppbind_obj_q->ptr : nullptr;
    auto jnitocxxq = static_cast<cppbind::example::QueueInt*>(cppbind_obj_q_ptr);

    
    try {
        const auto& result = cppbind::example::QueueIntUsage::getFirstElement(jnitocxxq);
        
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


extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntUsage_jGetinvqueue([[maybe_unused]] JNIEnv* env, jobject, jintArray v, ...){
    

    std::vector<int> jnitocxxv;
    auto _jnitocxxv = cppbind::getIntArray(env, v);
    for (auto& value__jnitocxxv : _jnitocxxv) {
        
        jnitocxxv.emplace_back(value__jnitocxxv);
    }

    
    try {
        const auto& result = cppbind::example::QueueIntUsage::getInvQueue(jnitocxxv);
        cppbind::example::QueueIntType* cxxtojniresult_ptr = const_cast<cppbind::example::QueueIntType*>(new cppbind::example::QueueIntType(result));
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINT);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
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


extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntUsage_jGetsavedqueue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueIntUsage*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->getSavedQueue();
        cppbind::example::QueueInt* cxxtojniresult_ptr = const_cast<cppbind::example::QueueInt*>(result);
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINT);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
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
extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntUsage_jEmpty_1queue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueIntUsage*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->empty_queue;
    cppbind::example::QueueIntType* cxxtojniresult_ptr = const_cast<cppbind::example::QueueIntType*>(new cppbind::example::QueueIntType(result));
    char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINT);
    CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
    return cxxtojniresult;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_typedefs_QueueIntUsage_jSaved_1queue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::QueueIntUsage*>(cppbind_obj_id_ptr);
    const auto& result = jnitocxxid->saved_queue;
    cppbind::example::QueueInt* cxxtojniresult_ptr = const_cast<cppbind::example::QueueInt*>(result);
    char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_QUEUEINT);
    CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
    return cxxtojniresult;
}

extern "C" JNIEXPORT jstring Java_com_examples_typedefs_Queue_1intKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
