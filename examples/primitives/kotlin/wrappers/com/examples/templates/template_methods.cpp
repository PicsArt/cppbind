#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/template_methods.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_TemplateMethods_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_templates_TemplateMethods_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::TemplateMethods* this_object = reinterpret_cast<iegen::example::TemplateMethods*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_TemplateMethods_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::TemplateMethods* baseptr = new iegen::example::TemplateMethods();
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT jint Java_com_examples_templates_TemplateMethods_jMaxInt(JNIEnv* env, jobject obj, jobjectid id, jint arg0, jint arg1){
    




    validateID(id);
    iegen::example::TemplateMethods* this_object = reinterpret_cast<iegen::example::TemplateMethods*>(id);
    
    auto result = this_object->max<int>(arg0, arg1);

    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_templates_TemplateMethods_jMaxString(JNIEnv* env, jobject obj, jobjectid id, jstring arg0, jstring arg1){
    
    jstring jjni_to_cxx_arg0Str = (jstring)arg0;
    auto jni_to_cxx_arg0_cstr = env->GetStringUTFChars(jjni_to_cxx_arg0Str, 0);
    const std::string & jni_to_cxx_arg0 = jni_to_cxx_arg0_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_arg0Str, jni_to_cxx_arg0_cstr);

    jstring jjni_to_cxx_arg1Str = (jstring)arg1;
    auto jni_to_cxx_arg1_cstr = env->GetStringUTFChars(jjni_to_cxx_arg1Str, 0);
    const std::string & jni_to_cxx_arg1 = jni_to_cxx_arg1_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_arg1Str, jni_to_cxx_arg1_cstr);

    validateID(id);
    iegen::example::TemplateMethods* this_object = reinterpret_cast<iegen::example::TemplateMethods*>(id);
    
    auto result = this_object->max<std::string>(jni_to_cxx_arg0, jni_to_cxx_arg1);
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jobject Java_com_examples_templates_TemplateMethods_jMakepairProjectProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0, jobjectid arg1){
    

    auto jni_to_cxx_arg0 =  reinterpret_cast<iegen::example::Project*>(arg0);


    auto jni_to_cxx_arg1 =  reinterpret_cast<iegen::example::Project*>(arg1);

    validateID(id);
    iegen::example::TemplateMethods* this_object = reinterpret_cast<iegen::example::TemplateMethods*>(id);
    
    auto result = this_object->makePair<iegen::example::Project, iegen::example::Project>(jni_to_cxx_arg0, jni_to_cxx_arg1);
    auto first = result.first;
    auto second = result.second;


    iegen::example::Project* cxx_to_jni_first_baseptr = first;
    jobjectid cxx_to_jni_first = reinterpret_cast<jlong>(cxx_to_jni_first_baseptr);


    iegen::example::Project* cxx_to_jni_second_baseptr = second;
    jobjectid cxx_to_jni_second = reinterpret_cast<jlong>(cxx_to_jni_second_baseptr);
    jobject result_first = iegen::longToObject(env, cxx_to_jni_first);
    jobject result_second = iegen::longToObject(env, cxx_to_jni_second);
    jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, result_first, result_second);
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jobject Java_com_examples_templates_TemplateMethods_jMakepairTaskProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0, jobjectid arg1){
    

    auto jni_to_cxx_arg0 =  reinterpret_cast<iegen::example::Task*>(arg0);


    auto jni_to_cxx_arg1 =  reinterpret_cast<iegen::example::Project*>(arg1);

    validateID(id);
    iegen::example::TemplateMethods* this_object = reinterpret_cast<iegen::example::TemplateMethods*>(id);
    
    auto result = this_object->makePair<iegen::example::Task, iegen::example::Project>(jni_to_cxx_arg0, jni_to_cxx_arg1);
    auto first = result.first;
    auto second = result.second;


    iegen::example::Task* cxx_to_jni_first_baseptr = first;
    jobjectid cxx_to_jni_first = reinterpret_cast<jlong>(cxx_to_jni_first_baseptr);


    iegen::example::Project* cxx_to_jni_second_baseptr = second;
    jobjectid cxx_to_jni_second = reinterpret_cast<jlong>(cxx_to_jni_second_baseptr);
    jobject result_first = iegen::longToObject(env, cxx_to_jni_first);
    jobject result_second = iegen::longToObject(env, cxx_to_jni_second);
    jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, result_first, result_second);
    return cxx_to_jni_result;
}