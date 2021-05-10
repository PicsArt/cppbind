#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/task.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_simple_Task_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_simple_Task_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Task>*>(id);
    delete &this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_simple_Task_jConstructor(JNIEnv* env, jobject obj, jstring title){
    jstring jjni_to_cxx_titleStr = (jstring)title;
    auto jni_to_cxx_title_cstr = env->GetStringUTFChars(jjni_to_cxx_titleStr, 0);
    const std::string & jni_to_cxx_title = jni_to_cxx_title_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_titleStr, jni_to_cxx_title_cstr);
    iegen::example::Task* obj_ptr = new iegen::example::Task(jni_to_cxx_title);
    auto this_object = std::shared_ptr<iegen::example::Task>(obj_ptr);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Task>(this_object));
}

extern "C" JNIEXPORT jstring Java_com_examples_simple_Task_jTitle(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Task>*>(id);
    auto result = this_object->title();
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}