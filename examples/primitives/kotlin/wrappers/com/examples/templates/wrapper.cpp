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
#include "cxx/templates/wrapper.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRSTRINGS = "cppbind::example::Wrapper<std::pair<std::string, std::string>>";
const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRINTINT = "cppbind::example::Wrapper<std::pair<int, int>>";
const char* CPPBIND_CPPBIND_EXAMPLE_WRAPPERSTRING = "cppbind::example::Wrapper<std::string>";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairStrings_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_WrapperPairStrings_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_WrapperPairStrings_jConstructor(JNIEnv* env, jobject obj, jobject value, ...){
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = cppbind::extractObject(env, firstObject_value);
    auto second_value = cppbind::extractObject(env, secondObject_value);
    jstring jjnitocxxfirst_valueStr = static_cast<jstring>(first_value);
    auto jnitocxxfirst_value_cstr = env->GetStringUTFChars(jjnitocxxfirst_valueStr, 0);
    std::string jnitocxxfirst_value = jnitocxxfirst_value_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirst_valueStr, jnitocxxfirst_value_cstr);
    jstring jjnitocxxsecond_valueStr = static_cast<jstring>(second_value);
    auto jnitocxxsecond_value_cstr = env->GetStringUTFChars(jjnitocxxsecond_valueStr, 0);
    std::string jnitocxxsecond_value = jnitocxxsecond_value_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsecond_valueStr, jnitocxxsecond_value_cstr);
    std::pair<std::string, std::string> jnitocxxvalue = std::make_pair(jnitocxxfirst_value, jnitocxxsecond_value);
    try {
        cppbind::example::Wrapper<std::pair<std::string, std::string>>* ptr = new cppbind::example::Wrapper<std::pair<std::string, std::string>>(jnitocxxvalue);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRSTRINGS), ptr});
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

extern "C" JNIEXPORT jobject Java_com_examples_templates_WrapperPairStrings_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->value();
        auto first_result = result.first;
        auto second_result = result.second;
        jstring cxxtojnifirst_result = env->NewStringUTF(first_result.data());
        jstring cxxtojnisecond_result = env->NewStringUTF(second_result.data());
        jobject first_result_obj = cxxtojnifirst_result;
        jobject second_result_obj = cxxtojnisecond_result;
        jobject cxxtojniresult = cppbind::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairStrings_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jobject value, ...){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::pair<std::string, std::string>>*>(cppbind_obj_id_ptr);
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = cppbind::extractObject(env, firstObject_value);
    auto second_value = cppbind::extractObject(env, secondObject_value);
    jstring jjnitocxxfirst_valueStr = static_cast<jstring>(first_value);
    auto jnitocxxfirst_value_cstr = env->GetStringUTFChars(jjnitocxxfirst_valueStr, 0);
    std::string jnitocxxfirst_value = jnitocxxfirst_value_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirst_valueStr, jnitocxxfirst_value_cstr);
    jstring jjnitocxxsecond_valueStr = static_cast<jstring>(second_value);
    auto jnitocxxsecond_value_cstr = env->GetStringUTFChars(jjnitocxxsecond_valueStr, 0);
    std::string jnitocxxsecond_value = jnitocxxsecond_value_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsecond_valueStr, jnitocxxsecond_value_cstr);
    std::pair<std::string, std::string> jnitocxxvalue = std::make_pair(jnitocxxfirst_value, jnitocxxsecond_value);
    try {
       jnitocxxid->setValue(jnitocxxvalue);
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


extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairIntInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_WrapperPairIntInt_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_WrapperPairIntInt_jConstructor(JNIEnv* env, jobject obj, jobject value, ...){
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = cppbind::extractInt(env, firstObject_value);
    auto second_value = cppbind::extractInt(env, secondObject_value);


    std::pair<int, int> jnitocxxvalue = std::make_pair(first_value, second_value);
    try {
        cppbind::example::Wrapper<std::pair<int, int>>* ptr = new cppbind::example::Wrapper<std::pair<int, int>>(jnitocxxvalue);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERPAIRINTINT), ptr});
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

extern "C" JNIEXPORT jobject Java_com_examples_templates_WrapperPairIntInt_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->value();
        auto first_result = result.first;
        auto second_result = result.second;


        jobject first_result_obj = cppbind::intToObject(env, first_result);
        jobject second_result_obj = cppbind::intToObject(env, second_result);
        jobject cxxtojniresult = cppbind::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairIntInt_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jobject value, ...){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::pair<int, int>>*>(cppbind_obj_id_ptr);
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = cppbind::extractInt(env, firstObject_value);
    auto second_value = cppbind::extractInt(env, secondObject_value);


    std::pair<int, int> jnitocxxvalue = std::make_pair(first_value, second_value);
    try {
       jnitocxxid->setValue(jnitocxxvalue);
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


extern "C" JNIEXPORT void Java_com_examples_templates_WrapperString_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::Wrapper<std::string>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_templates_WrapperString_jGetcxxid(JNIEnv* env, jobject obj, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::Wrapper<std::string>*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_templates_WrapperString_jConstructor(JNIEnv* env, jobject obj, jstring value, ...){
    jstring jjnitocxxvalueStr = static_cast<jstring>(value);
    auto jnitocxxvalue_cstr = env->GetStringUTFChars(jjnitocxxvalueStr, 0);
    std::string jnitocxxvalue = jnitocxxvalue_cstr;
    env->ReleaseStringUTFChars(jjnitocxxvalueStr, jnitocxxvalue_cstr);
    try {
        cppbind::example::Wrapper<std::string>* ptr = new cppbind::example::Wrapper<std::string>(jnitocxxvalue);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_WRAPPERSTRING), ptr});
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

extern "C" JNIEXPORT jstring Java_com_examples_templates_WrapperString_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::string>*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->value();
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

extern "C" JNIEXPORT void Java_com_examples_templates_WrapperString_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jstring value, ...){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::Wrapper<std::string>*>(cppbind_obj_id_ptr);
    jstring jjnitocxxvalueStr = static_cast<jstring>(value);
    auto jnitocxxvalue_cstr = env->GetStringUTFChars(jjnitocxxvalueStr, 0);
    std::string jnitocxxvalue = jnitocxxvalue_cstr;
    env->ReleaseStringUTFChars(jjnitocxxvalueStr, jnitocxxvalue_cstr);
    try {
       jnitocxxid->setValue(jnitocxxvalue);
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


extern "C" JNIEXPORT jstring Java_com_examples_templates_WrapperKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
