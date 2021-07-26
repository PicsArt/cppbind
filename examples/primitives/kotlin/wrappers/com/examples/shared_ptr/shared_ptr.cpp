/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 07/23/2021-09:57.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/shared_ptr/shared_ptr.hpp"

using namespace Example;


extern "C" JNIEXPORT void Java_com_examples_shared_1ptr_Car_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_shared_1ptr_Car_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<Example::Car>*>(id);
    delete &this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_shared_1ptr_Car_jConstructor(JNIEnv* env, jobject obj, jint cost){
    
    Example::Car* obj_ptr = new Example::Car(cost);
    auto this_object = std::shared_ptr<Example::Car>(obj_ptr);
    return reinterpret_cast<jlong>(new std::shared_ptr<Example::Car>(this_object));
}

extern "C" JNIEXPORT jint Java_com_examples_shared_1ptr_Car_jCost(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<Example::Car>*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;
    try {
      auto result = this_object->cost();
      
      return result;
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

    jint result;
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_shared_1ptr_Car_jSetcostwithcarsharedptr(JNIEnv* env, jobject obj, jobjectid id, jobjectid sp, jobject err_obj){
    

    std::shared_ptr<Example::Car> jni_to_cxx_sp;
    jni_to_cxx_sp = *reinterpret_cast<std::shared_ptr<Example::Car>*>(sp);

    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<Example::Car>*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      this_object->setCostWithCarSharedPtr(jni_to_cxx_sp);
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


extern "C" JNIEXPORT jobjectid Java_com_examples_shared_1ptr_Car_jGetnewcarsharedptr(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<Example::Car>*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = this_object->getNewCarSharedPtr();
      
    jobjectid cxx_to_jni_result;
    cxx_to_jni_result = reinterpret_cast<jlong>(new std::shared_ptr<Example::Car>(result));
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

    jobjectid result;
    return result;
}