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
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"
#include "cxx/enums/color.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_PROJECT;
extern const char* CPPBIND_CPPBIND_EXAMPLE_ROOT;


extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMul(JNIEnv* env, jclass, jint first, jint second, ...){
    
    
    try {
        decltype(auto) result = ::mul(first, second);
        
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

extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMulThree(JNIEnv* env, jclass, jint first, jint second, jint third, ...){
    
    
    try {
        decltype(auto) result = ::mul(first, second, third);
        
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

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jConcat(JNIEnv* env, jclass, jstring str1, jstring str2, ...){
    
    jstring jjnitocxxstr1Str = static_cast<jstring>(str1);
    auto jnitocxxstr1_cstr = env->GetStringUTFChars(jjnitocxxstr1Str, 0);
    std::string jnitocxxstr1 = jnitocxxstr1_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr1Str, jnitocxxstr1_cstr);
    jstring jjnitocxxstr2Str = static_cast<jstring>(str2);
    auto jnitocxxstr2_cstr = env->GetStringUTFChars(jjnitocxxstr2Str, 0);
    std::string jnitocxxstr2 = jnitocxxstr2_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr2Str, jnitocxxstr2_cstr);
    
    try {
        decltype(auto) result = ::concat(jnitocxxstr1, jnitocxxstr2);
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

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jConcat1(JNIEnv* env, jclass, jstring str1, jstring str2, jstring str3, ...){
    
    jstring jjnitocxxstr1Str = static_cast<jstring>(str1);
    auto jnitocxxstr1_cstr = env->GetStringUTFChars(jjnitocxxstr1Str, 0);
    std::string jnitocxxstr1 = jnitocxxstr1_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr1Str, jnitocxxstr1_cstr);
    jstring jjnitocxxstr2Str = static_cast<jstring>(str2);
    auto jnitocxxstr2_cstr = env->GetStringUTFChars(jjnitocxxstr2Str, 0);
    std::string jnitocxxstr2 = jnitocxxstr2_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr2Str, jnitocxxstr2_cstr);
    jstring jjnitocxxstr3Str = static_cast<jstring>(str3);
    auto jnitocxxstr3_cstr = env->GetStringUTFChars(jjnitocxxstr3Str, 0);
    std::string jnitocxxstr3 = jnitocxxstr3_cstr;
    env->ReleaseStringUTFChars(jjnitocxxstr3Str, jnitocxxstr3_cstr);
    
    try {
        decltype(auto) result = ::concat(jnitocxxstr1, jnitocxxstr2, jnitocxxstr3);
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

extern "C" JNIEXPORT jint Java_com_examples_globs_UtilsKt_jMaxInt(JNIEnv* env, jclass, jint a, jint b, ...){
    
    
    try {
        decltype(auto) result = ::max<int>(a, b);
        
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

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jMaxString(JNIEnv* env, jclass, jstring a, jstring b, ...){
    
    jstring jjnitocxxaStr = static_cast<jstring>(a);
    auto jnitocxxa_cstr = env->GetStringUTFChars(jjnitocxxaStr, 0);
    std::string jnitocxxa = jnitocxxa_cstr;
    env->ReleaseStringUTFChars(jjnitocxxaStr, jnitocxxa_cstr);
    jstring jjnitocxxbStr = static_cast<jstring>(b);
    auto jnitocxxb_cstr = env->GetStringUTFChars(jjnitocxxbStr, 0);
    std::string jnitocxxb = jnitocxxb_cstr;
    env->ReleaseStringUTFChars(jjnitocxxbStr, jnitocxxb_cstr);
    
    try {
        decltype(auto) result = ::max<std::string>(jnitocxxa, jnitocxxb);
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

extern "C" JNIEXPORT jobject Java_com_examples_globs_UtilsKt_jMakepairProjectProject(JNIEnv* env, jclass, jobjectid a, jobjectid b, ...){
    using namespace cppbind::example;
    

    auto cppbind_obj_a = reinterpret_cast<CppBindCObject*>(a);
    auto cppbind_obj_a_ptr = cppbind_obj_a ? cppbind_obj_a->ptr : nullptr;
    auto jnitocxxa = static_cast<cppbind::example::Project*>(cppbind_obj_a_ptr);

    auto cppbind_obj_b = reinterpret_cast<CppBindCObject*>(b);
    auto cppbind_obj_b_ptr = cppbind_obj_b ? cppbind_obj_b->ptr : nullptr;
    auto jnitocxxb = static_cast<cppbind::example::Project*>(cppbind_obj_b_ptr);
    
    try {
        decltype(auto) result = cppbind::example::makePair<cppbind::example::Project, cppbind::example::Project>(jnitocxxa, jnitocxxb);
        auto first_result = result.first;
        auto second_result = result.second;
        cppbind::example::Project* cxxtojnifirst_result_ptr = first_result;
        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        CppBindCObject* cppbind_obj_cxxtojnifirst_result = new CppBindCObject {type_first_result, cxxtojnifirst_result_ptr};
        jobjectid cxxtojnifirst_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnifirst_result);
        cppbind::example::Project* cxxtojnisecond_result_ptr = second_result;
        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        CppBindCObject* cppbind_obj_cxxtojnisecond_result = new CppBindCObject {type_second_result, cxxtojnisecond_result_ptr};
        jobjectid cxxtojnisecond_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnisecond_result);
        jobject first_result_obj = cppbind::longToObject(env, cxxtojnifirst_result);
        jobject second_result_obj = cppbind::longToObject(env, cxxtojnisecond_result);
        jobject cxxtojniresult = cppbind::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT jobject Java_com_examples_globs_UtilsKt_jMakepairRootProject(JNIEnv* env, jclass, jobjectid a, jobjectid b, ...){
    using namespace cppbind::example;
    

    auto cppbind_obj_a = reinterpret_cast<CppBindCObject*>(a);
    auto cppbind_obj_a_ptr = cppbind_obj_a ? cppbind_obj_a->ptr : nullptr;
    auto jnitocxxa = static_cast<cppbind::example::Root*>(cppbind_obj_a_ptr);

    auto cppbind_obj_b = reinterpret_cast<CppBindCObject*>(b);
    auto cppbind_obj_b_ptr = cppbind_obj_b ? cppbind_obj_b->ptr : nullptr;
    auto jnitocxxb = static_cast<cppbind::example::Project*>(cppbind_obj_b_ptr);
    
    try {
        decltype(auto) result = cppbind::example::makePair<cppbind::example::Root, cppbind::example::Project>(jnitocxxa, jnitocxxb);
        auto first_result = result.first;
        auto second_result = result.second;
        cppbind::example::Root* cxxtojnifirst_result_ptr = first_result;
        char* type_first_result = strdup(CPPBIND_CPPBIND_EXAMPLE_ROOT);
        CppBindCObject* cppbind_obj_cxxtojnifirst_result = new CppBindCObject {type_first_result, cxxtojnifirst_result_ptr};
        jobjectid cxxtojnifirst_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnifirst_result);
        cppbind::example::Project* cxxtojnisecond_result_ptr = second_result;
        char* type_second_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        CppBindCObject* cppbind_obj_cxxtojnisecond_result = new CppBindCObject {type_second_result, cxxtojnisecond_result_ptr};
        jobjectid cxxtojnisecond_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnisecond_result);
        jobject first_result_obj = cppbind::longToObject(env, cxxtojnifirst_result);
        jobject second_result_obj = cppbind::longToObject(env, cxxtojnisecond_result);
        jobject cxxtojniresult = cppbind::make_jni_object_pair(env, first_result_obj, second_result_obj);
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

    jobject result {};
    return result;
}

extern "C" JNIEXPORT jintArray Java_com_examples_globs_UtilsKt_jGetvectorcolor(JNIEnv* env, jclass, jintArray c, ...){
    using namespace cppbind::example;
    

    std::vector<Color> jnitocxxc;
    auto _jnitocxxc = cppbind::getIntArray(env, c);
    for (auto& value__jnitocxxc : _jnitocxxc) {
        auto jnitocxxvalue__jnitocxxc = static_cast<cppbind::example::Color>(value__jnitocxxc);
        jnitocxxc.emplace_back(jnitocxxvalue__jnitocxxc);
    }
    
    try {
        decltype(auto) result = cppbind::example::getVectorColor(jnitocxxc);
        
        jintArray cxxtojniresult = env->NewIntArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            jint cxxtojnivalue_result = static_cast<jint>(value_result);
            env->SetIntArrayRegion(cxxtojniresult, index_result, 1, &cxxtojnivalue_result);
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

extern "C" JNIEXPORT jobjectid Java_com_examples_globs_UtilsKt_jOptionalfdptr(JNIEnv* env, jclass, jobjectid project, ...){
    

    auto cppbind_obj_project = reinterpret_cast<CppBindCObject*>(project);
    auto cppbind_obj_project_ptr = cppbind_obj_project ? cppbind_obj_project->ptr : nullptr;
    auto jnitocxxproject = static_cast<cppbind::example::Project*>(cppbind_obj_project_ptr);
    
    try {
        decltype(auto) result = ::optionalFDPtr(jnitocxxproject);
        cppbind::example::Project* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_PROJECT);
        CppBindCObject* cppbind_obj_cxxtojniresult = nullptr;
        if (result) {
            cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        }
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

extern "C" JNIEXPORT void Java_com_examples_globs_UtilsKt_jDonothing(JNIEnv* env, jclass){
    
    
    try {
        ::doNothing();
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

extern "C" JNIEXPORT jstring Java_com_examples_globs_UtilsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
