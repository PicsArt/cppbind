/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/25/2021-10:49.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/usage.hpp"
#include "cxx/inheritance/parallelogram.hpp"
#include "cxx/inheritance/vehicle.hpp"
#include "cxx/inheritance/bicycle.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_inheritance_GeometricFigure_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::GeometricFigure*>(id);
    delete jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_GeometricFigure_jConstructor(JNIEnv* env, jobject obj, jobjectid p){
    
    auto jni_to_cxx_p = reinterpret_cast<iegen::example::Parallelogram*>(p);
    try {
        iegen::example::GeometricFigure* baseptr = new iegen::example::GeometricFigure(jni_to_cxx_p);
        return reinterpret_cast<jlong>(baseptr);
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
    jobjectid result;
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_GeometricFigure_jParallelogram(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::GeometricFigure*>(id);
    try {
        const auto& result = jni_to_cxx_id->parallelogram();
        
        iegen::example::Parallelogram* cxx_to_jni_result_baseptr = const_cast<iegen::example::Parallelogram*>(result);
        jobjectid cxx_to_jni_result = reinterpret_cast<jlong>(cxx_to_jni_result_baseptr);
        return cxx_to_jni_result;
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_inheritance_GeometricFigure_jSetparallelogram(JNIEnv* env, jobject obj, jobjectid id, jobjectid p){
    validateID(id);
    
    auto jni_to_cxx_id = reinterpret_cast<iegen::example::GeometricFigure*>(id);
    
    auto jni_to_cxx_p = reinterpret_cast<iegen::example::Parallelogram*>(p);
    try {
       jni_to_cxx_id->setParallelogram(jni_to_cxx_p);
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


extern "C" JNIEXPORT void Java_com_examples_inheritance_MyVehicle_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::MyVehicle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyVehicle>*>(id);
    delete &jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_MyVehicle_jConstructor(JNIEnv* env, jobject obj, jobjectid v){
    
    std::shared_ptr<iegen::example::Vehicle>& jni_to_cxx_v = *reinterpret_cast<std::shared_ptr<iegen::example::Vehicle>*>(v);
    try {
        iegen::example::MyVehicle* obj_ptr = new iegen::example::MyVehicle(jni_to_cxx_v);
        auto this_object = std::shared_ptr<iegen::example::MyVehicle>(obj_ptr);
        return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::MyVehicle>(this_object));
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
    jobjectid result;
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_MyVehicle_jVehicle(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::MyVehicle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyVehicle>*>(id);
    try {
        const auto& result = jni_to_cxx_id->vehicle();
        
        jobjectid cxx_to_jni_result;
        cxx_to_jni_result = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Vehicle>(result));
        return cxx_to_jni_result;
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_inheritance_MyVehicle_jSetvehicle(JNIEnv* env, jobject obj, jobjectid id, jobjectid v){
    validateID(id);
    
    std::shared_ptr<iegen::example::MyVehicle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyVehicle>*>(id);
    
    std::shared_ptr<iegen::example::Vehicle>& jni_to_cxx_v = *reinterpret_cast<std::shared_ptr<iegen::example::Vehicle>*>(v);
    try {
       jni_to_cxx_id->setVehicle(jni_to_cxx_v);
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


extern "C" JNIEXPORT void Java_com_examples_inheritance_MyBicycle_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    std::shared_ptr<iegen::example::MyBicycle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyBicycle>*>(id);
    delete &jni_to_cxx_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_MyBicycle_jConstructor(JNIEnv* env, jobject obj, jobjectid b){
    
    std::shared_ptr<iegen::example::Bicycle> jni_to_cxx_b = std::dynamic_pointer_cast<iegen::example::Bicycle>(*reinterpret_cast<std::shared_ptr<iegen::example::Vehicle>*>(b));
    try {
        iegen::example::MyBicycle* obj_ptr = new iegen::example::MyBicycle(jni_to_cxx_b);
        auto this_object = std::shared_ptr<iegen::example::MyBicycle>(obj_ptr);
        return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::MyBicycle>(this_object));
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
    jobjectid result;
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_MyBicycle_jBicycle(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::MyBicycle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyBicycle>*>(id);
    try {
        const auto& result = jni_to_cxx_id->bicycle();
        
        jobjectid cxx_to_jni_result;
        cxx_to_jni_result = reinterpret_cast<jlong>(new std::shared_ptr<const iegen::example::Vehicle>(std::static_pointer_cast<const iegen::example::Vehicle>(result)));
        return cxx_to_jni_result;
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

    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_inheritance_MyBicycle_jSetbicycle(JNIEnv* env, jobject obj, jobjectid id, jobjectid b){
    validateID(id);
    
    std::shared_ptr<iegen::example::MyBicycle>& jni_to_cxx_id = *reinterpret_cast<std::shared_ptr<iegen::example::MyBicycle>*>(id);
    
    std::shared_ptr<const iegen::example::Bicycle> jni_to_cxx_b = std::dynamic_pointer_cast<const iegen::example::Bicycle>(*reinterpret_cast<std::shared_ptr<const iegen::example::Vehicle>*>(b));
    try {
       jni_to_cxx_id->setBicycle(jni_to_cxx_b);
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
