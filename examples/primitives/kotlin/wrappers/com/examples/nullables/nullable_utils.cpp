/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 05/04/2022-08:43.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/nullables/nullable_utils.hpp"

extern const char* IEGEN_STD_STDEXCEPTION;

const char* IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERINT = "iegen::example::nullable::NumberInt";
const char* IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE = "iegen::example::nullable::NumberDouble";
const char* IEGEN_IEGEN_EXAMPLE_NULLABLE_UTILS = "iegen::example::nullable::Utils";

using namespace iegen::example::nullable;


extern "C" JNIEXPORT void Java_com_examples_nullables_NumberInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(iegen_obj_id_ptr);
    free(iegen_obj_id->type);
    delete iegen_obj_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_NumberInt_jConstructor(JNIEnv* env, jobject obj, jint val_){
    
    try {
        iegen::example::nullable::NumberInt* obj_ptr = new iegen::example::nullable::NumberInt(val_);
        auto this_object = std::shared_ptr<iegen::example::nullable::NumberInt>(obj_ptr);
        return reinterpret_cast<jlong>(new IEGenCObject {strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERINT), new std::shared_ptr<iegen::example::nullable::NumberInt>(this_object)});
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
extern "C" JNIEXPORT jint Java_com_examples_nullables_NumberInt_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(iegen_obj_id_ptr);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_NumberDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    delete static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_id_ptr);
    free(iegen_obj_id->type);
    delete iegen_obj_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_NumberDouble_jConstructor(JNIEnv* env, jobject obj, jdouble val_){
    
    try {
        iegen::example::nullable::NumberDouble* ptr = new iegen::example::nullable::NumberDouble(val_);
        return reinterpret_cast<jlong>(new IEGenCObject {strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE), ptr});
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
extern "C" JNIEXPORT jdouble Java_com_examples_nullables_NumberDouble_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_id_ptr);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    free(iegen_obj_id->type);
    delete iegen_obj_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jConstructor(JNIEnv* env, jobject obj, jobjectid num){
    
    auto iegen_obj_num = reinterpret_cast<IEGenCObject*>(num);
    auto iegen_obj_num_ptr = iegen_obj_num ? iegen_obj_num->ptr : nullptr;
    auto jnitocxxnum = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_num_ptr);
    try {
        iegen::example::nullable::Utils* obj_ptr = new iegen::example::nullable::Utils(jnitocxxnum);
        auto this_object = std::shared_ptr<iegen::example::nullable::Utils>(obj_ptr);
        return reinterpret_cast<jlong>(new IEGenCObject {strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_UTILS), new std::shared_ptr<iegen::example::nullable::Utils>(this_object)});
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


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jMax(JNIEnv* env, jobject obj, jobjectid first, jobjectid second){
    

    auto iegen_obj_first = reinterpret_cast<IEGenCObject*>(first);
    auto iegen_obj_first_ptr = iegen_obj_first ? iegen_obj_first->ptr : nullptr;
    auto jnitocxxfirst = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_first_ptr);


    auto iegen_obj_second = reinterpret_cast<IEGenCObject*>(second);
    auto iegen_obj_second_ptr = iegen_obj_second ? iegen_obj_second->ptr : nullptr;
    auto jnitocxxsecond = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_second_ptr);

    
    try {
        const auto& result = iegen::example::nullable::Utils::max(jnitocxxfirst, jnitocxxsecond);
        iegen::example::nullable::NumberDouble* cxxtojniresult_ptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jMax_11(JNIEnv* env, jobject obj, jobjectid first, jobjectid second){
    

    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxfirst = nullptr;
    if (first) {
        auto iegen_obj_first = reinterpret_cast<IEGenCObject*>(first);
        auto iegen_obj_first_ptr = iegen_obj_first ? iegen_obj_first->ptr : nullptr;
        jnitocxxfirst = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(iegen_obj_first_ptr);
    }


    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxsecond = nullptr;
    if (second) {
        auto iegen_obj_second = reinterpret_cast<IEGenCObject*>(second);
        auto iegen_obj_second_ptr = iegen_obj_second ? iegen_obj_second->ptr : nullptr;
        jnitocxxsecond = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(iegen_obj_second_ptr);
    }

    
    try {
        const auto& result = iegen::example::nullable::Utils::max(jnitocxxfirst, jnitocxxsecond);
        
        char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERINT);
        void* cxxtojniresult_ptr = nullptr;
        IEGenCObject* iegen_obj_cxxtojniresult = nullptr;
        if (result) {
            cxxtojniresult_ptr = new std::shared_ptr<iegen::example::nullable::NumberInt>(result);
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


extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jChecknonnullarg(JNIEnv* env, jobject obj, jobjectid number){
    

    auto iegen_obj_number = reinterpret_cast<IEGenCObject*>(number);
    auto iegen_obj_number_ptr = iegen_obj_number ? iegen_obj_number->ptr : nullptr;
    auto jnitocxxnumber = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_number_ptr);

    
    try {
        iegen::example::nullable::Utils::checkNonnullArg(jnitocxxnumber);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jChecknonnullreturn(JNIEnv* env, jobject obj){
    
    
    try {
        const auto& result = iegen::example::nullable::Utils::checkNonnullReturn();
        iegen::example::nullable::NumberDouble* cxxtojniresult_ptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE);
        IEGenCObject* iegen_obj_cxxtojniresult = new IEGenCObject {type_result, cxxtojniresult_ptr};
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

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNullable(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->nullable();
        iegen::example::nullable::NumberDouble* cxxtojniresult_ptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE);
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

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnullable(JNIEnv* env, jobject obj, jobjectid id, jobjectid num){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    
    auto iegen_obj_num = reinterpret_cast<IEGenCObject*>(num);
    auto iegen_obj_num_ptr = iegen_obj_num ? iegen_obj_num->ptr : nullptr;
    auto jnitocxxnum = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_num_ptr);
    try {
       jnitocxxid->setNullable(jnitocxxnum);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNonnull(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->nonNull();
        iegen::example::nullable::NumberDouble* cxxtojniresult_ptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
        char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE);
        IEGenCObject* iegen_obj_cxxtojniresult = new IEGenCObject {type_result, cxxtojniresult_ptr};
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

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnonnull(JNIEnv* env, jobject obj, jobjectid id, jobjectid num){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    
    auto iegen_obj_num = reinterpret_cast<IEGenCObject*>(num);
    auto iegen_obj_num_ptr = iegen_obj_num ? iegen_obj_num->ptr : nullptr;
    auto jnitocxxnum = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_num_ptr);
    try {
       jnitocxxid->setNonNull(jnitocxxnum);
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

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNumdouble(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    const auto& result = jnitocxxid->numDouble;
    iegen::example::nullable::NumberDouble* cxxtojniresult_ptr = const_cast<iegen::example::nullable::NumberDouble*>(result);
    char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERDOUBLE);
    IEGenCObject* iegen_obj_cxxtojniresult = nullptr;
    if (result) {
        iegen_obj_cxxtojniresult = new IEGenCObject {type_result, cxxtojniresult_ptr};
    }
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(iegen_obj_cxxtojniresult);
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnumdouble(JNIEnv* env, jobject obj, jobjectid id, jobjectid value){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    
    
    auto iegen_obj_value = reinterpret_cast<IEGenCObject*>(value);
    auto iegen_obj_value_ptr = iegen_obj_value ? iegen_obj_value->ptr : nullptr;
    auto jnitocxxvalue = static_cast<iegen::example::nullable::NumberDouble*>(iegen_obj_value_ptr);
    jnitocxxid->numDouble = jnitocxxvalue;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_nullables_Utils_jNumint(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    const auto& result = jnitocxxid->numInt;
    
    char* type_result = strdup(IEGEN_IEGEN_EXAMPLE_NULLABLE_NUMBERINT);
    void* cxxtojniresult_ptr = nullptr;
    IEGenCObject* iegen_obj_cxxtojniresult = nullptr;
    cxxtojniresult_ptr = new std::shared_ptr<iegen::example::nullable::NumberInt>(result);
    iegen_obj_cxxtojniresult = new IEGenCObject {type_result, cxxtojniresult_ptr};
    jobjectid cxxtojniresult = reinterpret_cast<jlong>(iegen_obj_cxxtojniresult);
    return cxxtojniresult;
}

extern "C" JNIEXPORT void Java_com_examples_nullables_Utils_jSetnumint(JNIEnv* env, jobject obj, jobjectid id, jobjectid value){
    validateID(id);
    
    std::shared_ptr<iegen::example::nullable::Utils> jnitocxxid;
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<iegen::example::nullable::Utils>*>(iegen_obj_id_ptr);
    
    
    std::shared_ptr<iegen::example::nullable::NumberInt> jnitocxxvalue;
    auto iegen_obj_value = reinterpret_cast<IEGenCObject*>(value);
    auto iegen_obj_value_ptr = iegen_obj_value ? iegen_obj_value->ptr : nullptr;
    jnitocxxvalue = *static_cast<std::shared_ptr<iegen::example::nullable::NumberInt>*>(iegen_obj_value_ptr);
    jnitocxxid->numInt = jnitocxxvalue;
}


extern "C" JNIEXPORT jstring Java_com_examples_nullables_Nullable_1utilsKt_jReversestring(JNIEnv* env, jclass cls, jstring s){
    
    auto deleter = [&env, &s](const char * ptr) {
        env->ReleaseStringUTFChars(s, ptr);
    };
    std::unique_ptr<const char, decltype(deleter)> jnitocxxs_unique_ptr(
                                                                  s ? env->GetStringUTFChars(s, NULL) : nullptr,
                                                                  deleter);
    const char * jnitocxxs = jnitocxxs_unique_ptr.get();
    
    try {
        const auto& result = iegen::example::nullable::reverseString(jnitocxxs);
        jstring cxxtojniresult = env->NewStringUTF(result);
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

extern "C" JNIEXPORT jstring Java_com_examples_nullables_Nullable_1utilsKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<IEGenCObject*>(id)->type);
}
