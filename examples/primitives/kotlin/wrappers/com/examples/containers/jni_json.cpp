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
#include "cxx/containers/json.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_JSONEXAMPLES = "cppbind::example::JsonExamples";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_containers_JsonExamples_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_containers_JsonExamples_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_containers_JsonExamples_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::example::JsonExamples* ptr = new cppbind::example::JsonExamples();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_JSONEXAMPLES), ptr});
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


extern "C" JNIEXPORT void Java_com_examples_containers_JsonExamples_jSetjson([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring j, ...){
    
    auto jnitocxxj = nlohmann::json::parse(cppbind::jni_to_string(env, j));

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->setJson(jnitocxxj);
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


extern "C" JNIEXPORT jstring Java_com_examples_containers_JsonExamples_jGetjson([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->getJson();
        jstring cxxtojniresult = cppbind::string_to_jni(env, result.dump(4));
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


extern "C" JNIEXPORT jstring Java_com_examples_containers_JsonExamples_jGetsimplejsonexample([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->getSimpleJsonExample();
        jstring cxxtojniresult = cppbind::string_to_jni(env, result.dump(4));
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


extern "C" JNIEXPORT void Java_com_examples_containers_JsonExamples_jSetjsonmatrix([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jobjectArray jm, ...){
    

    std::vector<std::vector<nlohmann::json>> jnitocxxjm;
    auto _jnitocxxjm = cppbind::getObjectArray(env, jm);
    for (auto& value__jnitocxxjm : _jnitocxxjm) {
        
        std::vector<nlohmann::json> jnitocxxvalue__jnitocxxjm;
        auto _jnitocxxvalue__jnitocxxjm = cppbind::getObjectArray(env, value__jnitocxxjm);
        for (auto& value__jnitocxxvalue__jnitocxxjm : _jnitocxxvalue__jnitocxxjm) {
            auto jnitocxxvalue__jnitocxxvalue__jnitocxxjm = nlohmann::json::parse(cppbind::jni_to_string(env, value__jnitocxxvalue__jnitocxxjm));
            jnitocxxvalue__jnitocxxjm.emplace_back(jnitocxxvalue__jnitocxxvalue__jnitocxxjm);
        }
        jnitocxxjm.emplace_back(jnitocxxvalue__jnitocxxjm);
    }

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->setJsonMatrix(jnitocxxjm);
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


extern "C" JNIEXPORT jobjectArray Java_com_examples_containers_JsonExamples_jGetjsonmatrix([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::JsonExamples*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->getJsonMatrix();
        
        jobjectArray cxxtojniresult = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        size_t index_result = 0;
        for (auto& value_result : result) {
            
            jobjectArray cxxtojnivalue_result = env->NewObjectArray(value_result.size(), env->FindClass("java/lang/Object"), NULL);
            size_t index_value_result = 0;
            for (auto& value_value_result : value_result) {
                jstring cxxtojnivalue_value_result = cppbind::string_to_jni(env, value_value_result.dump(4));
                env->SetObjectArrayElement(cxxtojnivalue_result, index_value_result, cxxtojnivalue_value_result);
                ++index_value_result ;
            }
            env->SetObjectArrayElement(cxxtojniresult, index_result, cxxtojnivalue_result);
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

    jobjectArray result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_containers_JsonKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
