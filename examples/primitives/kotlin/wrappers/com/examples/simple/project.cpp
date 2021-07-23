/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/22/2021-12:29.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

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

extern "C" JNIEXPORT jstring Java_com_examples_simple_Project_jTitle(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
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


extern "C" JNIEXPORT void Java_com_examples_simple_Project_jAddtask(JNIEnv* env, jobject obj, jobjectid id, jobjectid task, jobject err_obj){
    

    auto jni_to_cxx_task =  reinterpret_cast<iegen::example::Task*>(task);

    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      this_object->addTask(jni_to_cxx_task);
      return;
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


}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_simple_Project_jTasks(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    
    validateID(id);
    iegen::example::Project* this_object = reinterpret_cast<iegen::example::Project*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = this_object->tasks();
      
    jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
    size_t index_result = 0;
    for (auto& value_result : result) {
        

        iegen::example::Task* cxx_to_jni_value_result_baseptr = value_result;
        jobjectid cxx_to_jni_value_result = reinterpret_cast<jlong>(cxx_to_jni_value_result_baseptr);
        env->SetLongArrayRegion(cxx_to_jni_result, index_result, 1, &cxx_to_jni_value_result);
        ++index_result ;
    }
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

    jobjectidArray result;
    return result;
}