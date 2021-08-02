/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/30/2021-08:58.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/exceptions/exceptions.hpp"

using namespace iegen::exceptions;


extern "C" JNIEXPORT void Java_com_examples_exceptions_NoThrowExc_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_exceptions_NoThrowExc_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::exceptions::NoThrowExc* this_object = reinterpret_cast<iegen::exceptions::NoThrowExc*>(id);
    delete this_object;
}


extern "C" JNIEXPORT void Java_com_examples_exceptions_NoThrowExc_jNoop(JNIEnv* env, jobject obj){
    
    void* err_ptr = nullptr;

    try {
      iegen::exceptions::NoThrowExc::noop();
      return;
    }
    catch (const std::exception& e) {
          err_ptr = new std::exception(e);
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
          jclass handlerCls = env->FindClass("exceptionUtils/ExceptionHandler");
          jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
          env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Excepiton"));
    }


}