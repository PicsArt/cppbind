/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/03/2021-15:28.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/wrapper.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairStringString_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::Wrapper<std::pair<std::string, std::string>>*>(id);
    delete jni_to_cxx_id;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_WrapperPairStringString_jConstructor(JNIEnv* env, jobject obj, jobject value){
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = iegen::extractObject(env, firstObject_value);
    auto second_value = iegen::extractObject(env, secondObject_value);
    jstring jjni_to_cxx_first_valueStr = (jstring)first_value;
    auto jni_to_cxx_first_value_cstr = env->GetStringUTFChars(jjni_to_cxx_first_valueStr, 0);
    std::string jni_to_cxx_first_value = jni_to_cxx_first_value_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_first_valueStr, jni_to_cxx_first_value_cstr);
    jstring jjni_to_cxx_second_valueStr = (jstring)second_value;
    auto jni_to_cxx_second_value_cstr = env->GetStringUTFChars(jjni_to_cxx_second_valueStr, 0);
    std::string jni_to_cxx_second_value = jni_to_cxx_second_value_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_second_valueStr, jni_to_cxx_second_value_cstr);
    std::pair<std::string, std::string> jni_to_cxx_value = std::make_pair(jni_to_cxx_first_value, jni_to_cxx_second_value);
    iegen::example::Wrapper<std::pair<std::string, std::string>>* baseptr = new iegen::example::Wrapper<std::pair<std::string, std::string>>(jni_to_cxx_value);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jobject Java_com_examples_templates_WrapperPairStringString_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::Wrapper<std::pair<std::string, std::string>>*>(id);
    try {
        auto result = jni_to_cxx_id->value();
        auto first_result = result.first;
        auto second_result = result.second;
        jstring cxx_to_jni_first_result = env->NewStringUTF(first_result.c_str());
        jstring cxx_to_jni_second_result = env->NewStringUTF(second_result.c_str());
        jobject first_result_obj = cxx_to_jni_first_result;
        jobject second_result_obj = cxx_to_jni_second_result;
        jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_templates_WrapperPairStringString_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jobject value){
    validateID(id);
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::Wrapper<std::pair<std::string, std::string>>*>(id);
    jclass pairClass_value = env->FindClass("kotlin/Pair");

    jfieldID firstID_value = env->GetFieldID(pairClass_value, "first", "Ljava/lang/Object;");
    jfieldID secondID_value = env->GetFieldID(pairClass_value, "second", "Ljava/lang/Object;");

    auto firstObject_value = env->GetObjectField(value, firstID_value);
    auto secondObject_value = env->GetObjectField(value, secondID_value);
    auto first_value = iegen::extractObject(env, firstObject_value);
    auto second_value = iegen::extractObject(env, secondObject_value);
    jstring jjni_to_cxx_first_valueStr = (jstring)first_value;
    auto jni_to_cxx_first_value_cstr = env->GetStringUTFChars(jjni_to_cxx_first_valueStr, 0);
    std::string jni_to_cxx_first_value = jni_to_cxx_first_value_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_first_valueStr, jni_to_cxx_first_value_cstr);
    jstring jjni_to_cxx_second_valueStr = (jstring)second_value;
    auto jni_to_cxx_second_value_cstr = env->GetStringUTFChars(jjni_to_cxx_second_valueStr, 0);
    std::string jni_to_cxx_second_value = jni_to_cxx_second_value_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_second_valueStr, jni_to_cxx_second_value_cstr);
    std::pair<std::string, std::string> jni_to_cxx_value = std::make_pair(jni_to_cxx_first_value, jni_to_cxx_second_value);
    try {
       jni_to_cxx_id->setValue(jni_to_cxx_value);
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
}
