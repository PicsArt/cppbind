/*
 * This file was generated by iegen on 06/01/2021-18:53.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/root.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_simple_Root_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_simple_Root_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Root* this_object = reinterpret_cast<iegen::example::Root*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_simple_Root_jConstructor(JNIEnv* env, jobject obj, jstring _path){
    jstring jjni_to_cxx__pathStr = (jstring)_path;
    auto jni_to_cxx__path_cstr = env->GetStringUTFChars(jjni_to_cxx__pathStr, 0);
    const std::string & jni_to_cxx__path = jni_to_cxx__path_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx__pathStr, jni_to_cxx__path_cstr);
    iegen::example::Root* baseptr = new iegen::example::Root(jni_to_cxx__path);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jstring Java_com_examples_simple_Root_jPath(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Root* this_object = reinterpret_cast<iegen::example::Root*>(id);
    auto result = this_object->path;
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}