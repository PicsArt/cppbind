/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/23/2021-09:22.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/task.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_simple_Task_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_simple_Task_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Task* this_object = reinterpret_cast<iegen::example::Task*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_simple_Task_jConstructor(JNIEnv* env, jobject obj, jstring title){
    jstring jjni_to_cxx_titleStr = (jstring)title;
    auto jni_to_cxx_title_cstr = env->GetStringUTFChars(jjni_to_cxx_titleStr, 0);
    const std::string & jni_to_cxx_title = jni_to_cxx_title_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_titleStr, jni_to_cxx_title_cstr);
    iegen::example::Task* baseptr = new iegen::example::Task(jni_to_cxx_title);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jstring Java_com_examples_simple_Task_jTitle(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    validateID(id);
    iegen::example::Task* this_object = reinterpret_cast<iegen::example::Task*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;
    try {
        auto result = this_object->title();
        jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
        return cxx_to_jni_result;
    }
    
    catch (const std::exception& e) {
        err_type_id = 1;
        err_ptr = new std::exception(e);
    }
    catch (...) {
        err_type_id = -1;
    }

    jclass err_cls = env->GetObjectClass(err_obj);
    jfieldID typeId_field_id = env->GetFieldID(err_cls, "typeId", "I");
    jfieldID ptrId_field_id = env->GetFieldID(err_cls, "ptrId", "J");
    env->SetIntField(err_obj, typeId_field_id, err_type_id);
    env->SetLongField(err_obj, ptrId_field_id, reinterpret_cast<jobjectid>(err_ptr));

    jstring result;
    return result;
}