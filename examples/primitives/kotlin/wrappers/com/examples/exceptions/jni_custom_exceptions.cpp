/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/18/2022-06:17.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/exceptions/exceptions.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION = "cppbind::example::SimpleBaseException";
const char* CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION = "cppbind::example::SimpleChildException";


extern "C" JNIEXPORT void Java_com_examples_exceptions_SimpleBaseException_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::SimpleBaseException>::value, "cppbind::example::SimpleBaseException type must have virtual destructor");
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION) == 0)
        delete static_cast<cppbind::example::SimpleBaseException*>(cppbind_obj_id_ptr);
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION) == 0)
        delete static_cast<cppbind::example::SimpleChildException*>(cppbind_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

cppbind::example::SimpleBaseException* recover_obj_from_CppbindExample_SimpleBaseException(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION) == 0)
            return static_cast<cppbind::example::SimpleBaseException*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION) == 0)
            return static_cast<cppbind::example::SimpleChildException*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jlong Java_com_examples_exceptions_SimpleBaseException_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::SimpleBaseException*>(cppbind_obj_id_ptr));
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::SimpleChildException*>(cppbind_obj_id_ptr));
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_SimpleBaseException_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint err_num, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::SimpleBaseException* this_object = new cppbind::example::SimpleBaseException(err_num);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION), this_object});
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


extern "C" JNIEXPORT jint Java_com_examples_exceptions_SimpleBaseException_jErrnum([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    cppbind::example::SimpleBaseException* jnitocxxid = recover_obj_from_CppbindExample_SimpleBaseException(id);
    
    try {
        decltype(auto) result = jnitocxxid->errNum();
        
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


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_SimpleChildException_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint err_num, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::SimpleChildException* this_object = new cppbind::example::SimpleChildException(err_num);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION), this_object});
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


extern "C" JNIEXPORT jint Java_com_examples_exceptions_SimpleChildException_jErrnum([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::SimpleChildException*>(cppbind_obj_id_ptr);
    
    try {
        decltype(auto) result = jnitocxxid->errNum();
        
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

extern "C" JNIEXPORT jstring Java_com_examples_exceptions_Custom_1exceptionsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
