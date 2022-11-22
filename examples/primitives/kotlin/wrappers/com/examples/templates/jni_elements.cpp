/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/12/2022-10:50.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/templates/elements.hpp"
#include <vector>


extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_ELEMENTSINT = "cppbind::example::elements<std::vector<int>, int, int>";
const char* CPPBIND_CPPBIND_EXAMPLE_ELEMENTSSTRING = "cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>";
const char* CPPBIND_CPPBIND_EXAMPLE_ELEMENTSEMPTY = "cppbind::example::elements<std::vector<double>>";


extern "C" JNIEXPORT void Java_com_examples_templates_ElementsInt_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::elements<std::vector<int>, int, int>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_ElementsInt_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::elements<std::vector<int>, int, int>*>(cppbind_obj_id_ptr));
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_ElementsInt_jCreate([[maybe_unused]] JNIEnv* env, jobject, jint ts1, jint ts2, ...){
    using namespace cppbind::example;
    




    
    try {
        decltype(auto) result = cppbind::example::elements<std::vector<int>, int, int>::create(ts1, ts2);
        cppbind::example::elements<std::vector<int>, int, int>* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ELEMENTSINT);
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

extern "C" JNIEXPORT jintArray Java_com_examples_templates_ElementsInt_jHolder([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::elements<std::vector<int>, int, int>*>(cppbind_obj_id_ptr);
    try {
        decltype(auto) result = jnitocxxid->holder();
        
        jintArray cxxtojniresult = env->NewIntArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            
            env->SetIntArrayRegion(cxxtojniresult, index_result, 1, &value_result);
            ++index_result ;
        }
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

    jintArray result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_templates_ElementsString_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_ElementsString_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>*>(cppbind_obj_id_ptr));
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_ElementsString_jCreate([[maybe_unused]] JNIEnv* env, jobject, jstring ts1, jstring ts2, jstring ts3, ...){
    using namespace cppbind::example;
    
    jstring jjnitocxxts1Str = static_cast<jstring>(ts1);
    auto jnitocxxts1_cstr = env->GetStringUTFChars(jjnitocxxts1Str, 0);
    std::string jnitocxxts1 = jnitocxxts1_cstr;
    env->ReleaseStringUTFChars(jjnitocxxts1Str, jnitocxxts1_cstr);

    jstring jjnitocxxts2Str = static_cast<jstring>(ts2);
    auto jnitocxxts2_cstr = env->GetStringUTFChars(jjnitocxxts2Str, 0);
    std::string jnitocxxts2 = jnitocxxts2_cstr;
    env->ReleaseStringUTFChars(jjnitocxxts2Str, jnitocxxts2_cstr);

    jstring jjnitocxxts3Str = static_cast<jstring>(ts3);
    auto jnitocxxts3_cstr = env->GetStringUTFChars(jjnitocxxts3Str, 0);
    std::string jnitocxxts3 = jnitocxxts3_cstr;
    env->ReleaseStringUTFChars(jjnitocxxts3Str, jnitocxxts3_cstr);

    
    try {
        decltype(auto) result = cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>::create(jnitocxxts1, jnitocxxts2, jnitocxxts3);
        cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ELEMENTSSTRING);
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

extern "C" JNIEXPORT jobjectArray Java_com_examples_templates_ElementsString_jHolder([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::elements<std::vector<std::string>, std::string, std::string, std::string>*>(cppbind_obj_id_ptr);
    try {
        decltype(auto) result = jnitocxxid->holder();
        
        jobjectArray cxxtojniresult = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        size_t index_result = 0;
        for (auto& value_result : result) {
            jstring cxxtojnivalue_result = env->NewStringUTF(value_result.data());
            env->SetObjectArrayElement(cxxtojniresult, index_result, cxxtojnivalue_result);
            ++index_result ;
        }
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

    jobjectArray result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_templates_ElementsEmpty_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::elements<std::vector<double>>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_ElementsEmpty_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::elements<std::vector<double>>*>(cppbind_obj_id_ptr));
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_ElementsEmpty_jCreate([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    
    
    try {
        decltype(auto) result = cppbind::example::elements<std::vector<double>>::create();
        cppbind::example::elements<std::vector<double>>* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ELEMENTSEMPTY);
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

extern "C" JNIEXPORT jdoubleArray Java_com_examples_templates_ElementsEmpty_jHolder([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::elements<std::vector<double>>*>(cppbind_obj_id_ptr);
    try {
        decltype(auto) result = jnitocxxid->holder();
        
        jdoubleArray cxxtojniresult = env->NewDoubleArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            
            env->SetDoubleArrayRegion(cxxtojniresult, index_result, 1, &value_result);
            ++index_result ;
        }
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

    jdoubleArray result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_templates_ElementsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
