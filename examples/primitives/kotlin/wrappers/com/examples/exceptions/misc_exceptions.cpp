/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:29.
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

using namespace cppbind::exceptions;


extern "C" JNIEXPORT void Java_com_examples_exceptions_Integer_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::exceptions::Integer*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_Integer_jConstructor(JNIEnv* env, jobject obj, jint n){
    
    try {
        cppbind::exceptions::Integer* ptr = new cppbind::exceptions::Integer(n);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXCEPTIONS_INTEGER), ptr});
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

extern "C" JNIEXPORT jint Java_com_examples_exceptions_Integer_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    auto jnitocxxid = static_cast<cppbind::exceptions::Integer*>(cppbind_obj_id_ptr);
    try {
        const auto& result = jnitocxxid->value();
        
        return result;
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

    jint result {};
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_exceptions_MiscExc_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<cppbind::exceptions::MiscExc*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_exceptions_MiscExc_jReturninteger(JNIEnv* env, jobject obj, jboolean do_throw){
    


    
    void* err_ptr = nullptr;
    try {
        const auto& result = cppbind::exceptions::MiscExc::returnInteger(do_throw);
        cppbind::exceptions::Integer* cxxtojniresult_ptr = const_cast<cppbind::exceptions::Integer*>(result);
        char* type_result = strdup(CPPBIND_CPPBIND_EXCEPTIONS_INTEGER);
        CppBindCObject* cppbind_obj_cxxtojniresult = new CppBindCObject {type_result, cxxtojniresult_ptr};
        jobjectid cxxtojniresult = reinterpret_cast<jlong>(cppbind_obj_cxxtojniresult);
        return cxxtojniresult;
    }catch (const std::out_of_range& e) {
        err_ptr = new std::out_of_range(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exception_helpers/StdOutOfRange");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDOUTOFRANGE), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
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


extern "C" JNIEXPORT void Java_com_examples_exceptions_MiscExc_jRaiseerrorbytype(JNIEnv* env, jobject obj, jstring err_type){
    
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
        jclass excCls = env->FindClass("com/examples/cppbind/exception_helpers/StdRuntimeError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDRUNTIMEERROR), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::FileError& e) {
        err_ptr = new cppbind::example::FileError(e);
        jclass excCls = env->FindClass("com/examples/exceptions/FileError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_FILEERROR), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::SystemError& e) {
        err_ptr = new cppbind::example::SystemError(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SystemError");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SYSTEMERROR), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::SimpleChildException& e) {
        err_ptr = new cppbind::example::SimpleChildException(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SimpleChildException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLECHILDEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const cppbind::example::SimpleBaseException& e) {
        err_ptr = new cppbind::example::SimpleBaseException(e);
        jclass excCls = env->FindClass("com/examples/exceptions/SimpleBaseException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SIMPLEBASEEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }catch (const std::exception& e) {
        err_ptr = new std::exception(e);
        jclass excCls = env->FindClass("com/examples/cppbind/exception_helpers/StdException");
        jclass cppbindObjClass = env->FindClass("com/examples/cppbind/alias/CppBindObject");
        jmethodID cppbindConstructor = env->GetMethodID(cppbindObjClass, "<init>", "(JZ)V");
        jobject cppbindObj = env->NewObject(cppbindObjClass, cppbindConstructor, reinterpret_cast<jobjectid>(new CppBindCObject {strdup(CPPBIND_STD_STDEXCEPTION), err_ptr}), true);
        jmethodID excConstructor = env->GetMethodID(excCls, "<init>", "(Lcom/examples/cppbind/alias/CppBindObject;)V");
        jobject excObj = env->NewObject(excCls, excConstructor, cppbindObj);
        env->Throw(jthrowable(excObj));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }


}

extern "C" JNIEXPORT jstring Java_com_examples_exceptions_Misc_1exceptionsKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
