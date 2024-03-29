/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/22/2022-09:33.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/globs/utils.h"

extern const char* CPPBIND_STD_STDEXCEPTION;


extern "C" JNIEXPORT jstring Java_com_examples_globs_custom_1args_CustomArgUtilsKt_jGreet(JNIEnv* env, jclass, jstring person, jstring hometown, ...){
    
    jstring jjnitocxxpersonStr = static_cast<jstring>(person);
    auto jnitocxxperson_cstr = env->GetStringUTFChars(jjnitocxxpersonStr, 0);
    std::string jnitocxxperson = jnitocxxperson_cstr;
    env->ReleaseStringUTFChars(jjnitocxxpersonStr, jnitocxxperson_cstr);
    jstring jjnitocxxhometownStr = static_cast<jstring>(hometown);
    auto jnitocxxhometown_cstr = env->GetStringUTFChars(jjnitocxxhometownStr, 0);
    std::string jnitocxxhometown = jnitocxxhometown_cstr;
    env->ReleaseStringUTFChars(jjnitocxxhometownStr, jnitocxxhometown_cstr);
    
    try {
        decltype(auto) result = ::greet(jnitocxxperson, jnitocxxhometown);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_globs_custom_1args_CustomArgUtilsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
