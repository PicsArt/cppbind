/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/14/2022-14:03.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/globs/utils.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"



extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMul(JNIEnv* env, jclass cls, jint first, jint second){
    
    
    try {
        const auto& result = ::mul(first, second);
        
        return result;
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

    jint result {};
    return result;
}

extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMulThree(JNIEnv* env, jclass cls, jint first, jint second, jint third){
    
    
    try {
        const auto& result = ::mul(first, second, third);
        
        return result;
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

    jint result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jConcat(JNIEnv* env, jclass cls, jstring str1, jstring str2){
    
    jstring jjnitocxxstr1Str = (jstring)str1;
    auto jnitocxxstr1_cstr = env->GetStringUTFChars(jjnitocxxstr1Str, 0);
    std::string jnitocxxstr1 = jnitocxxstr1_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr1Str, jnitocxxstr1_cstr);
    jstring jjnitocxxstr2Str = (jstring)str2;
    auto jnitocxxstr2_cstr = env->GetStringUTFChars(jjnitocxxstr2Str, 0);
    std::string jnitocxxstr2 = jnitocxxstr2_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr2Str, jnitocxxstr2_cstr);
    
    try {
        const auto& result = ::concat(jnitocxxstr1, jnitocxxstr2);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jConcat_11(JNIEnv* env, jclass cls, jstring str1, jstring str2, jstring str3){
    
    jstring jjnitocxxstr1Str = (jstring)str1;
    auto jnitocxxstr1_cstr = env->GetStringUTFChars(jjnitocxxstr1Str, 0);
    std::string jnitocxxstr1 = jnitocxxstr1_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr1Str, jnitocxxstr1_cstr);
    jstring jjnitocxxstr2Str = (jstring)str2;
    auto jnitocxxstr2_cstr = env->GetStringUTFChars(jjnitocxxstr2Str, 0);
    std::string jnitocxxstr2 = jnitocxxstr2_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr2Str, jnitocxxstr2_cstr);
    jstring jjnitocxxstr3Str = (jstring)str3;
    auto jnitocxxstr3_cstr = env->GetStringUTFChars(jjnitocxxstr3Str, 0);
    std::string jnitocxxstr3 = jnitocxxstr3_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr3Str, jnitocxxstr3_cstr);
    
    try {
        const auto& result = ::concat(jnitocxxstr1, jnitocxxstr2, jnitocxxstr3);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMaxInt(JNIEnv* env, jclass cls, jint a, jint b){
    
    
    try {
        const auto& result = ::max<int>(a, b);
        
        return result;
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

    jint result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jMaxString(JNIEnv* env, jclass cls, jstring a, jstring b){
    
    jstring jjnitocxxaStr = (jstring)a;
    auto jnitocxxa_cstr = env->GetStringUTFChars(jjnitocxxaStr, 0);
    std::string jnitocxxa = jnitocxxa_cstr;
    env->ReleaseStringUTFChars(jjnitocxxaStr, jnitocxxa_cstr);
    jstring jjnitocxxbStr = (jstring)b;
    auto jnitocxxb_cstr = env->GetStringUTFChars(jjnitocxxbStr, 0);
    std::string jnitocxxb = jnitocxxb_cstr;
    env->ReleaseStringUTFChars(jjnitocxxbStr, jnitocxxb_cstr);
    
    try {
        const auto& result = ::max<std::string>(jnitocxxa, jnitocxxb);
        jstring cxxtojniresult = env->NewStringUTF(result.data());
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

    jstring result {};
    return result;
}

extern "C" JNIEXPORT jobject Java_com_examples_globs_UtilsKt_jMakepairProjectProject(JNIEnv* env, jclass cls, jobjectid a, jobjectid b){
    

    auto iegen_obj_a = reinterpret_cast<IEGenCObject*>(a);
    auto iegen_obj_a_ptr = iegen_obj_a ? iegen_obj_a->ptr : nullptr;
    auto jnitocxxa = static_cast<iegen::example::Project*>(iegen_obj_a_ptr);

    auto iegen_obj_b = reinterpret_cast<IEGenCObject*>(b);
    auto iegen_obj_b_ptr = iegen_obj_b ? iegen_obj_b->ptr : nullptr;
    auto jnitocxxb = static_cast<iegen::example::Project*>(iegen_obj_b_ptr);
    
    try {
        const auto& result = iegen::example::makePair<iegen::example::Project, iegen::example::Project>(jnitocxxa, jnitocxxb);
        auto first_result = result.first;
        auto second_result = result.second;
        iegen::example::Project* cxxtojnifirst_result_ptr = const_cast<iegen::example::Project*>(first_result);
        char* type_first_result = strdup("iegen::example::Project");
        IEGenCObject* iegen_obj_cxxtojnifirst_result = new IEGenCObject {type_first_result, cxxtojnifirst_result_ptr};
        jobjectid cxxtojnifirst_result = reinterpret_cast<jlong>(iegen_obj_cxxtojnifirst_result);
        iegen::example::Project* cxxtojnisecond_result_ptr = const_cast<iegen::example::Project*>(second_result);
        char* type_second_result = strdup("iegen::example::Project");
        IEGenCObject* iegen_obj_cxxtojnisecond_result = new IEGenCObject {type_second_result, cxxtojnisecond_result_ptr};
        jobjectid cxxtojnisecond_result = reinterpret_cast<jlong>(iegen_obj_cxxtojnisecond_result);
        jobject first_result_obj = iegen::longToObject(env, cxxtojnifirst_result);
        jobject second_result_obj = iegen::longToObject(env, cxxtojnisecond_result);
        jobject cxxtojniresult = iegen::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT jobject Java_com_examples_globs_UtilsKt_jMakepairRootProject(JNIEnv* env, jclass cls, jobjectid a, jobjectid b){
    

    auto iegen_obj_a = reinterpret_cast<IEGenCObject*>(a);
    auto iegen_obj_a_ptr = iegen_obj_a ? iegen_obj_a->ptr : nullptr;
    auto jnitocxxa = static_cast<iegen::example::Root*>(iegen_obj_a_ptr);

    auto iegen_obj_b = reinterpret_cast<IEGenCObject*>(b);
    auto iegen_obj_b_ptr = iegen_obj_b ? iegen_obj_b->ptr : nullptr;
    auto jnitocxxb = static_cast<iegen::example::Project*>(iegen_obj_b_ptr);
    
    try {
        const auto& result = iegen::example::makePair<iegen::example::Root, iegen::example::Project>(jnitocxxa, jnitocxxb);
        auto first_result = result.first;
        auto second_result = result.second;
        iegen::example::Root* cxxtojnifirst_result_ptr = const_cast<iegen::example::Root*>(first_result);
        char* type_first_result = strdup("iegen::example::Root");
        IEGenCObject* iegen_obj_cxxtojnifirst_result = new IEGenCObject {type_first_result, cxxtojnifirst_result_ptr};
        jobjectid cxxtojnifirst_result = reinterpret_cast<jlong>(iegen_obj_cxxtojnifirst_result);
        iegen::example::Project* cxxtojnisecond_result_ptr = const_cast<iegen::example::Project*>(second_result);
        char* type_second_result = strdup("iegen::example::Project");
        IEGenCObject* iegen_obj_cxxtojnisecond_result = new IEGenCObject {type_second_result, cxxtojnisecond_result_ptr};
        jobjectid cxxtojnisecond_result = reinterpret_cast<jlong>(iegen_obj_cxxtojnisecond_result);
        jobject first_result_obj = iegen::longToObject(env, cxxtojnifirst_result);
        jobject second_result_obj = iegen::longToObject(env, cxxtojnisecond_result);
        jobject cxxtojniresult = iegen::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_globs_UtilsKt_jOptionalfdptr(JNIEnv* env, jclass cls, jobjectid project){
    

    auto iegen_obj_project = reinterpret_cast<IEGenCObject*>(project);
    auto iegen_obj_project_ptr = iegen_obj_project ? iegen_obj_project->ptr : nullptr;
    auto jnitocxxproject = static_cast<iegen::example::Project*>(iegen_obj_project_ptr);
    
    try {
        const auto& result = ::optionalFDPtr(jnitocxxproject);
        iegen::example::Project* cxxtojniresult_ptr = const_cast<iegen::example::Project*>(result);
        char* type_result = strdup("iegen::example::Project");
        IEGenCObject* iegen_obj_cxxtojniresult = nullptr;
        if (result) {
            iegen_obj_cxxtojniresult = new IEGenCObject {type_result, cxxtojniresult_ptr};
        }
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(iegen_obj_cxxtojniresult);
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

    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_globs_UtilsKt_jDonothing(JNIEnv* env, jclass cls){
    
    
    try {
        ::doNothing();
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

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<IEGenCObject*>(id)->type);
}
