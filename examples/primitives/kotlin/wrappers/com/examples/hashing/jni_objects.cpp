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
#include "cxx/hashing/objects.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;

const char* CPPBIND_CPPBIND_EXAMPLE_OBJECT1 = "cppbind::example::Object1";
const char* CPPBIND_CPPBIND_EXAMPLE_OBJECT2 = "cppbind::example::Object2";
const char* CPPBIND_CPPBIND_EXAMPLE_OBJECT3 = "cppbind::example::Object3";
const char* CPPBIND_CPPBIND_EXAMPLE_OBJECT4 = "cppbind::example::Object4";
const char* CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT1 = "cppbind::example::ExtendedObject1";
const char* CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT2 = "cppbind::example::ExtendedObject2";
const char* CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT3 = "cppbind::example::ExtendedObject3";
const char* CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT4 = "cppbind::example::ExtendedObject4";


extern "C" JNIEXPORT void Java_com_examples_hashing_Object1_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::Object1>::value, "cppbind::example::Object1 type must have virtual destructor");
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT1) == 0)
        delete static_cast<cppbind::example::Object1*>(cppbind_obj_id_ptr);
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT1) == 0)
        delete static_cast<cppbind::example::ExtendedObject1*>(cppbind_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

cppbind::example::Object1* recover_obj_from_CppbindExample_Object1(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT1) == 0)
            return static_cast<cppbind::example::Object1*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT1) == 0)
            return static_cast<cppbind::example::ExtendedObject1*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object1_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT1) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::Object1*>(cppbind_obj_id_ptr));
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT1) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::ExtendedObject1*>(cppbind_obj_id_ptr));
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
}

extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_Object1_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint value, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::Object1* this_object = new cppbind::example::Object1(value);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_OBJECT1), this_object});
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

extern "C" JNIEXPORT jint Java_com_examples_hashing_Object1_jValue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    cppbind::example::Object1* jnitocxxid = recover_obj_from_CppbindExample_Object1(id);
    try {
        decltype(auto) result = jnitocxxid->value();
        
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


extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object1_jHash([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    cppbind::example::Object1* jnitocxxid = recover_obj_from_CppbindExample_Object1(id);
    
    try {
        decltype(auto) result = jnitocxxid->hash();
        jlong cxxtojniresult = result;
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

    jlong result {};
    return result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_hashing_Object1_jEquals([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jobjectid other, ...){
    using namespace cppbind::example;
    

    cppbind::example::Object1* jnitocxxother = recover_obj_from_CppbindExample_Object1(other);

    validateID(id);
    cppbind::example::Object1* jnitocxxid = recover_obj_from_CppbindExample_Object1(id);
    
    try {
        decltype(auto) result = jnitocxxid->equals(jnitocxxother);
        jboolean cxxtojniresult = result;
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

    jboolean result {};
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_hashing_Object1_jTostring([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    cppbind::example::Object1* jnitocxxid = recover_obj_from_CppbindExample_Object1(id);
    
    try {
        decltype(auto) result = jnitocxxid->toString();
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

extern "C" JNIEXPORT void Java_com_examples_hashing_Object2_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    static_assert(std::has_virtual_destructor<cppbind::example::Object2>::value, "cppbind::example::Object2 type must have virtual destructor");
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT2) == 0)
        delete static_cast<cppbind::example::Object2*>(cppbind_obj_id_ptr);
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT2) == 0)
        delete static_cast<cppbind::example::ExtendedObject2*>(cppbind_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

cppbind::example::Object2* recover_obj_from_CppbindExample_Object2(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT2) == 0)
            return static_cast<cppbind::example::Object2*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT2) == 0)
            return static_cast<cppbind::example::ExtendedObject2*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object2_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT2) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::Object2*>(cppbind_obj_id_ptr));
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT2) == 0)
        return reinterpret_cast<jlong>(static_cast<cppbind::example::ExtendedObject2*>(cppbind_obj_id_ptr));
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
}

extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_Object2_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    try {
        cppbind::example::Object2* this_object = new cppbind::example::Object2();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_OBJECT2), this_object});
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

extern "C" JNIEXPORT void Java_com_examples_hashing_Object3_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT3) == 0)
        delete static_cast<std::shared_ptr<cppbind::example::Object3>*>(cppbind_obj_id_ptr);
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT3) == 0)
        delete static_cast<std::shared_ptr<cppbind::example::ExtendedObject3>*>(cppbind_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

std::shared_ptr<cppbind::example::Object3> recover_obj_from_CppbindExample_Object3(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT3) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::Object3>*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT3) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ExtendedObject3>*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object3_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT3) == 0)
        return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::Object3>*>(cppbind_obj_id_ptr)->get());
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT3) == 0)
        return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::ExtendedObject3>*>(cppbind_obj_id_ptr)->get());
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
}

extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_Object3_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint value, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::Object3* this_object = new cppbind::example::Object3(value);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_OBJECT3), new std::shared_ptr<cppbind::example::Object3>(this_object)});
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

extern "C" JNIEXPORT jint Java_com_examples_hashing_Object3_jValue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    std::shared_ptr<cppbind::example::Object3> jnitocxxid;
    jnitocxxid = recover_obj_from_CppbindExample_Object3(id);
    try {
        decltype(auto) result = jnitocxxid->value();
        
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


extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object3_jHash([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    std::shared_ptr<cppbind::example::Object3> jnitocxxid;
    jnitocxxid = recover_obj_from_CppbindExample_Object3(id);
    
    try {
        decltype(auto) result = jnitocxxid->hash();
        jlong cxxtojniresult = result;
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

    jlong result {};
    return result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_hashing_Object3_jEquals([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jobjectid other, ...){
    using namespace cppbind::example;
    

    std::shared_ptr<cppbind::example::Object3> jnitocxxother;
    jnitocxxother = recover_obj_from_CppbindExample_Object3(other);

    validateID(id);
    std::shared_ptr<cppbind::example::Object3> jnitocxxid;
    jnitocxxid = recover_obj_from_CppbindExample_Object3(id);
    
    try {
        decltype(auto) result = jnitocxxid->equals(jnitocxxother);
        jboolean cxxtojniresult = result;
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

    jboolean result {};
    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_hashing_Object3_jTostring([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    std::shared_ptr<cppbind::example::Object3> jnitocxxid;
    jnitocxxid = recover_obj_from_CppbindExample_Object3(id);
    
    try {
        decltype(auto) result = jnitocxxid->toString();
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

extern "C" JNIEXPORT void Java_com_examples_hashing_Object4_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT4) == 0)
        delete static_cast<std::shared_ptr<cppbind::example::Object4>*>(cppbind_obj_id_ptr);
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT4) == 0)
        delete static_cast<std::shared_ptr<cppbind::example::ExtendedObject4>*>(cppbind_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

std::shared_ptr<cppbind::example::Object4> recover_obj_from_CppbindExample_Object4(jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    if (cppbind_obj_id_ptr) {
        if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT4) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::Object4>*>(cppbind_obj_id_ptr);
        else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT4) == 0)
            return *static_cast<std::shared_ptr<cppbind::example::ExtendedObject4>*>(cppbind_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jlong Java_com_examples_hashing_Object4_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_OBJECT4) == 0)
        return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::Object4>*>(cppbind_obj_id_ptr)->get());
    else if (strcmp(cppbind_obj_id->type, CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT4) == 0)
        return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::ExtendedObject4>*>(cppbind_obj_id_ptr)->get());
    else {
        std::cerr << "Unexpected object type: " << cppbind_obj_id->type << std::endl;
        exit(1);
    }
}

extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_Object4_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    try {
        cppbind::example::Object4* this_object = new cppbind::example::Object4();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_OBJECT4), new std::shared_ptr<cppbind::example::Object4>(this_object)});
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


extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_ExtendedObject1_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint value, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::ExtendedObject1* this_object = new cppbind::example::ExtendedObject1(value);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT1), this_object});
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


extern "C" JNIEXPORT jlong Java_com_examples_hashing_ExtendedObject1_jHash([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    
    validateID(id);
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::example::ExtendedObject1*>(cppbind_obj_id_ptr);
    
    try {
        decltype(auto) result = jnitocxxid->hash();
        jlong cxxtojniresult = result;
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

    jlong result {};
    return result;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_ExtendedObject2_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    try {
        cppbind::example::ExtendedObject2* this_object = new cppbind::example::ExtendedObject2();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT2), this_object});
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


extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_ExtendedObject3_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint value, ...){
    using namespace cppbind::example;
    
    try {
        cppbind::example::ExtendedObject3* this_object = new cppbind::example::ExtendedObject3(value);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT3), new std::shared_ptr<cppbind::example::ExtendedObject3>(this_object)});
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


extern "C" JNIEXPORT jobjectid Java_com_examples_hashing_ExtendedObject4_jConstructor([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    try {
        cppbind::example::ExtendedObject4* this_object = new cppbind::example::ExtendedObject4();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_EXTENDEDOBJECT4), new std::shared_ptr<cppbind::example::ExtendedObject4>(this_object)});
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

extern "C" JNIEXPORT jstring Java_com_examples_hashing_ObjectsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
