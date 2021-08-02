/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/29/2021-08:47.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/forward_decl/teacher.hpp"
#include "cxx/forward_decl/student.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_forward_1decl_teacher_Teacher_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_forward_1decl_teacher_Teacher_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Teacher* this_object = reinterpret_cast<iegen::example::Teacher*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_forward_1decl_teacher_Teacher_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::Teacher* baseptr = new iegen::example::Teacher();
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT void Java_com_examples_forward_1decl_teacher_Teacher_jAddstudent(JNIEnv* env, jobject obj, jobjectid id, jobjectid s){
    

    std::shared_ptr<iegen::example::Student> jni_to_cxx_s;
    jni_to_cxx_s = *reinterpret_cast<std::shared_ptr<iegen::example::Student>*>(s);

    validateID(id);
    iegen::example::Teacher* this_object = reinterpret_cast<iegen::example::Teacher*>(id);
    void* err_ptr = nullptr;

    try {
      this_object->addStudent(jni_to_cxx_s);
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


extern "C" JNIEXPORT jobjectidArray Java_com_examples_forward_1decl_teacher_Teacher_jStudents(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Teacher* this_object = reinterpret_cast<iegen::example::Teacher*>(id);
    void* err_ptr = nullptr;

    try {
      auto result = this_object->students();
      
    jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
    size_t index_result = 0;
    for (auto& value_result : result) {
        
        jobjectid cxx_to_jni_value_result;
        cxx_to_jni_value_result = reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Student>(value_result));
        env->SetLongArrayRegion(cxx_to_jni_result, index_result, 1, &cxx_to_jni_value_result);
        ++index_result ;
    }
      return cxx_to_jni_result;
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

    jobjectidArray result;
    return result;
}