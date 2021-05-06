#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/project.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_simple_Project_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_simple_Project_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_simple_Project_jConstructor(JNIEnv* env, jobject obj, jstring title){
    jstring jjni_to_cxx_titleStr = (jstring)title;
    auto jni_to_cxx_title_cstr = env->GetStringUTFChars(jjni_to_cxx_titleStr, 0);
    const std::string & jni_to_cxx_title = jni_to_cxx_title_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_titleStr, jni_to_cxx_title_cstr);
    iegen::example::Project* baseptr = new iegen::example::Project(jni_to_cxx_title);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jstring Java_com_examples_simple_Project_jTitle(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    auto result = this_object->title();
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT void Java_com_examples_simple_Project_jAddtask(JNIEnv* env, jobject obj, jobjectid id, jobjectid task){
    

    auto jni_to_cxx_task =  reinterpret_cast<iegen::example::Task*>(task);

    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    
    this_object->addTask(jni_to_cxx_task);
}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_simple_Project_jTasks(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    
    auto result = this_object->tasks();

    jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
    size_t index = 0;
    for (auto& value : result) {
        

        iegen::example::Task* cxx_to_jni_value_baseptr = value;
        jobjectid cxx_to_jni_value = reinterpret_cast<jlong>(cxx_to_jni_value_baseptr);
        env->SetLongArrayRegion(cxx_to_jni_result, index, 1, &cxx_to_jni_value);
        ++index;
    }
    return cxx_to_jni_result;
}