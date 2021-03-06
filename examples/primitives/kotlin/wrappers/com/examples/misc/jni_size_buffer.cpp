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
#include "cxx/misc/size_buffer.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SIZEUSAGE = "cppbind::example::SizeUsage";
const char* CPPBIND_CPPBIND_EXAMPLE_BUFFERUSAGE = "cppbind::example::BufferUsage";

using namespace cppbind::example;


extern "C" JNIEXPORT void Java_com_examples_misc_SizeUsage_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::SizeUsage*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_misc_SizeUsage_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::SizeUsage*>(cppbind_obj_id_ptr));
}


extern "C" JNIEXPORT jfloatArray Java_com_examples_misc_SizeUsage_jMultiplyby([[maybe_unused]] JNIEnv* env, jobject, jfloatArray size, jint n, ...){
    
    jfloat *elems = env->GetFloatArrayElements(size, 0);
    jfloat width_size = elems[0];
    jfloat height_size = elems[1];
    env->ReleaseFloatArrayElements(size, elems, 0);
    SizeF jnitocxxsize = SizeF(width_size, height_size);



    
    try {
        const auto& result = cppbind::example::SizeUsage::multiplyBy(jnitocxxsize, n);
        jfloat width_result = result.width;
        jfloat height_result = result.height;
        jfloatArray cxxtojniresult = env->NewFloatArray(2);
        jfloat carray[] = {width_result, height_result};
        env->SetFloatArrayRegion(cxxtojniresult, 0 , 2, carray);
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

    jfloatArray result {};
    return result;
}


extern "C" JNIEXPORT jfloatArray Java_com_examples_misc_SizeUsage_jDoublesizef_11([[maybe_unused]] JNIEnv* env, jobject){
    
    
    try {
        const auto& result = cppbind::example::SizeUsage::doubleSizeF();
        jfloat width_result = result.width;
        jfloat height_result = result.height;
        jfloatArray cxxtojniresult = env->NewFloatArray(2);
        jfloat carray[] = {width_result, height_result};
        env->SetFloatArrayRegion(cxxtojniresult, 0 , 2, carray);
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

    jfloatArray result {};
    return result;
}



extern "C" JNIEXPORT jfloatArray Java_com_examples_misc_SizeUsage_jDoublesizef([[maybe_unused]] JNIEnv* env, jobject, jfloatArray resolution, ...){
    
    jfloat *elems = env->GetFloatArrayElements(resolution, 0);
    jfloat width_resolution = elems[0];
    jfloat height_resolution = elems[1];
    env->ReleaseFloatArrayElements(resolution, elems, 0);
    const SizeF & jnitocxxresolution = SizeF(width_resolution, height_resolution);

    
    try {
        const auto& result = cppbind::example::SizeUsage::doubleSizeF(jnitocxxresolution);
        jfloat width_result = result.width;
        jfloat height_result = result.height;
        jfloatArray cxxtojniresult = env->NewFloatArray(2);
        jfloat carray[] = {width_result, height_result};
        env->SetFloatArrayRegion(cxxtojniresult, 0 , 2, carray);
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

    jfloatArray result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_misc_BufferUsage_jFinalize(JNIEnv*, jobject, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::example::BufferUsage*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_misc_BufferUsage_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::example::BufferUsage*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_misc_BufferUsage_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    try {
        cppbind::example::BufferUsage* ptr = new cppbind::example::BufferUsage();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_BUFFERUSAGE), ptr});
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


extern "C" JNIEXPORT jstring Java_com_examples_misc_BufferUsage_jUsage1([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jobjectid b, ...){
    
    auto& jnitocxxb = *reinterpret_cast<cppbind::example::Buffer<int>*>(b);

    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::BufferUsage*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->usage1(jnitocxxb);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_misc_BufferUsage_jUsage2([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::BufferUsage*>(cppbind_obj_id_ptr);
    
    try {
        const auto& result = jnitocxxid->usage2();
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(result);
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

extern "C" JNIEXPORT jstring Java_com_examples_misc_Size_1bufferKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
