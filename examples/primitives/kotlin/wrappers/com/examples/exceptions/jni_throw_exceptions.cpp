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
#include "cxx/exceptions/exceptions.hpp"
#include "cxx/simple/task.hpp"

extern const char* CPPBIND_STD_STDINVALIDARGUMENT;
extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_STD_STDOUTOFRANGE;
extern const char* CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR;
extern const char* CPPBIND_CPPBIND_EXAMPLE_TASK;

const char* CPPBIND_CPPBIND_EXCEPTIONS_THROWEXC = "cppbind::exceptions::ThrowExc";


extern "C" JNIEXPORT void Java_com_examples_exceptions_Throw_1exceptionsKt_jThrowexc(JNIEnv* env, jclass, jboolean do_throw, ...){
    using namespace cppbind::exceptions;
    
    
    void* err_ptr = nullptr;
    try {
        cppbind::exceptions::throwExc(do_throw);
        return;
    }catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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

extern "C" JNIEXPORT void Java_com_examples_exceptions_ThrowExc_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_exceptions_ThrowExc_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_ThrowExc_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jboolean do_throw, ...){
    using namespace cppbind::exceptions;
    
    void* err_ptr = nullptr;
    try {
        cppbind::exceptions::ThrowExc* this_object = new cppbind::exceptions::ThrowExc(do_throw);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXCEPTIONS_THROWEXC), this_object});
    }catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT jint Java_com_examples_exceptions_ThrowExc_jGetbykey([[maybe_unused]] JNIEnv* env, jobject, jmapobject m, jint key, ...){
    using namespace cppbind::exceptions;
    

    std::map<int, int> jnitocxxm;
    auto _jnitocxxm = cppbind::extract_jni_pair(env, m);
    auto tmp_key_jnitocxxm = cppbind::getIntArray(env, _jnitocxxm.first);
    auto tmp_val_jnitocxxm = cppbind::getIntArray(env, _jnitocxxm.second);
    for (size_t i = 0; i < tmp_key_jnitocxxm.size(); ++i) {
        auto ktmp_m = tmp_key_jnitocxxm[i];
        auto vtmp_m = tmp_val_jnitocxxm[i];
        
        
        jnitocxxm.insert({ ktmp_m, vtmp_m });
    }



    
    void* err_ptr = nullptr;
    try {
        decltype(auto) result = cppbind::exceptions::ThrowExc::getByKey(jnitocxxm, key);
        
        return result;
    }catch (const std::out_of_range& e) {
        err_ptr = new std::out_of_range(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdOutOfRange");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDOUTOFRANGE), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::SystemError& e) {
        err_ptr = new cppbind::example::SystemError(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SystemError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_ThrowExc_jThrowswithreturnvaluestring([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::exceptions;
    
    
    void* err_ptr = nullptr;
    try {
        decltype(auto) result = cppbind::exceptions::ThrowExc::throwsWithReturnValueString();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
    }catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_ThrowExc_jThrowswithreturnvalueptr([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::exceptions;
    
    
    void* err_ptr = nullptr;
    try {
        decltype(auto) result = cppbind::exceptions::ThrowExc::throwsWithReturnValuePtr();
        cppbind::example::Task* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TASK);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
    }catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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

extern "C" JNIEXPORT jstring Java_com_examples_exceptions_ThrowExc_jProp([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr);
    void* err_ptr = nullptr;
    try {
        decltype(auto) result = jnitocxxid->prop();
        jstring cxxtojniresult = env->NewStringUTF(result.data());
        return cxxtojniresult;
    }
    catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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

extern "C" JNIEXPORT void Java_com_examples_exceptions_ThrowExc_jSetprop([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring s, ...){
    using namespace cppbind::exceptions;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr);
    jstring jjnitocxxsStr = static_cast<jstring>(s);
    auto jnitocxxs_cstr = env->GetStringUTFChars(jjnitocxxsStr, 0);
    std::string jnitocxxs = jnitocxxs_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsStr, jnitocxxs_cstr);
    void* err_ptr = nullptr;
    try {
       jnitocxxid->setProp(jnitocxxs);
    }
    catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const std::out_of_range& e) {
        err_ptr = new std::out_of_range(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdOutOfRange");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDOUTOFRANGE), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_ThrowExc_jProp2([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr);
    try {
        decltype(auto) result = jnitocxxid->prop2();
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

extern "C" JNIEXPORT void Java_com_examples_exceptions_ThrowExc_jSetprop2([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jstring s, ...){
    using namespace cppbind::exceptions;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::ThrowExc*>(cppbind_obj_id_ptr);
    jstring jjnitocxxsStr = static_cast<jstring>(s);
    auto jnitocxxs_cstr = env->GetStringUTFChars(jjnitocxxsStr, 0);
    std::string jnitocxxs = jnitocxxs_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsStr, jnitocxxs_cstr);
    void* err_ptr = nullptr;
    try {
       jnitocxxid->setProp2(jnitocxxs);
    }
    catch (const std::invalid_argument& e) {
        err_ptr = new std::invalid_argument(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdInvalidArgument");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDINVALIDARGUMENT), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const std::out_of_range& e) {
        err_ptr = new std::out_of_range(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdOutOfRange");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDOUTOFRANGE), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT jstring Java_com_examples_exceptions_Throw_1exceptionsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
