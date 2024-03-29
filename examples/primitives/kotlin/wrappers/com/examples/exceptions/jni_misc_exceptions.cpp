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

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_STD_STDOUTOFRANGE;
extern const char* CPPBIND_STD_STDRUNTIMEERROR;
extern const char* CPPBIND_CPPBIND_EXAMPLE_FILEERROR;
extern const char* CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR;
extern const char* CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION;

const char* CPPBIND_CPPBIND_EXCEPTIONS_INTEGER = "cppbind::exceptions::Integer";
const char* CPPBIND_CPPBIND_EXCEPTIONS_MISCEXC = "cppbind::exceptions::MiscExc";


extern "C" JNIEXPORT void Java_com_examples_exceptions_Integer_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::exceptions::Integer*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_exceptions_Integer_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::exceptions::Integer*>(cppbind_obj_id_ptr));
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_Integer_jConstructor([[maybe_unused]] JNIEnv* env, jobject, jint n, ...){
    using namespace cppbind::exceptions;
    
    try {
        cppbind::exceptions::Integer* this_object = new cppbind::exceptions::Integer(n);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXCEPTIONS_INTEGER), this_object});
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

extern "C" JNIEXPORT jint Java_com_examples_exceptions_Integer_jValue([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::Integer*>(cppbind_obj_id_ptr);
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

extern "C" JNIEXPORT void Java_com_examples_exceptions_MiscExc_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::exceptions;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::exceptions::MiscExc*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_exceptions_MiscExc_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<cppbind::exceptions::MiscExc*>(cppbind_obj_id_ptr));
}


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_MiscExc_jReturninteger([[maybe_unused]] JNIEnv* env, jobject, jboolean do_throw, ...){
    using namespace cppbind::exceptions;
    


    
    void* err_ptr = nullptr;
    try {
        decltype(auto) result = cppbind::exceptions::MiscExc::returnInteger(do_throw);
        cppbind::exceptions::Integer* cxxtojniresult_ptr = result;
        char* type_result = strdup(CPPBIND_CPPBIND_EXCEPTIONS_INTEGER);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
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

    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_exceptions_MiscExc_jRaiseerrorbytype([[maybe_unused]] JNIEnv* env, jobject, jstring err_type, ...){
    using namespace cppbind::exceptions;
    
    jstring jjnitocxxerr_typeStr = static_cast<jstring>(err_type);
    auto jnitocxxerr_type_cstr = env->GetStringUTFChars(jjnitocxxerr_typeStr, 0);
    std::string jnitocxxerr_type = jnitocxxerr_type_cstr;
    env->ReleaseStringUTFChars(jjnitocxxerr_typeStr, jnitocxxerr_type_cstr);

    
    void* err_ptr = nullptr;
    try {
        cppbind::exceptions::MiscExc::raiseErrorByType(jnitocxxerr_type);
        return;
    }catch (const std::runtime_error& e) {
        err_ptr = new std::runtime_error(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdRuntimeError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDRUNTIMEERROR), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::FileError& e) {
        err_ptr = new cppbind::example::FileError(e);
        jclass excCls = env->FindClass("com/examples/exceptions/FileError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_FILEERROR), err_ptr}), true);
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
    }catch (const cppbind::example::SimpleChildException& e) {
        err_ptr = new cppbind::example::SimpleChildException(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SimpleChildException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::SimpleBaseException& e) {
        err_ptr = new cppbind::example::SimpleBaseException(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SimpleBaseException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const std::exception& e) {
        err_ptr = new std::exception(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exceptions/StdException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }


}

extern "C" JNIEXPORT jstring Java_com_examples_exceptions_Misc_1exceptionsKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
