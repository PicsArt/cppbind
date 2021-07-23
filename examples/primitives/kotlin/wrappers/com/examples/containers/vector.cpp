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
#include "cxx/containers/vector.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_containers_VectorItem_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_containers_VectorItem_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::VectorItem* this_object = reinterpret_cast<iegen::example::VectorItem*>(id);
    delete this_object;
}

extern "C" JNIEXPORT jint Java_com_examples_containers_VectorItem_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::VectorItem* this_object = reinterpret_cast<iegen::example::VectorItem*>(id);
    auto result = this_object->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_containers_VectorItem_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    iegen::example::VectorItem* this_object = reinterpret_cast<iegen::example::VectorItem*>(id);
    
    
    this_object->value = value;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_containers_VectorItem_jConstructor(JNIEnv* env, jobject obj, jint _value){
    
    iegen::example::VectorItem* baseptr = new iegen::example::VectorItem(_value);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT void Java_com_examples_containers_VectorExamples_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_containers_VectorExamples_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_containers_VectorExamples_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::VectorExamples* baseptr = new iegen::example::VectorExamples();
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT void Java_com_examples_containers_VectorExamples_jAddintvector(JNIEnv* env, jobject obj, jobjectid id, jintArray v, jobject err_obj){
    

    std::vector<int> jni_to_cxx_v;
    auto _jni_to_cxx_v = iegen::getIntArray(env, v);
    for (auto& value__jni_to_cxx_v : _jni_to_cxx_v) {
        
        jni_to_cxx_v.emplace_back(value__jni_to_cxx_v);
    }

    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      this_object->addIntVector(jni_to_cxx_v);
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


extern "C" JNIEXPORT void Java_com_examples_containers_VectorExamples_jAddobjvector(JNIEnv* env, jobject obj, jobjectid id, jobjectidArray v, jobject err_obj){
    

    std::vector<VectorItem *> jni_to_cxx_v;
    auto _jni_to_cxx_v = iegen::getLongArray(env, v);
    for (auto& value__jni_to_cxx_v : _jni_to_cxx_v) {
        
        auto jni_to_cxx_value__jni_to_cxx_v =  reinterpret_cast<iegen::example::VectorItem*>(value__jni_to_cxx_v);
        jni_to_cxx_v.emplace_back(jni_to_cxx_value__jni_to_cxx_v);
    }

    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      this_object->addObjVector(jni_to_cxx_v);
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


extern "C" JNIEXPORT void Java_com_examples_containers_VectorExamples_jAddstringvector(JNIEnv* env, jobject obj, jobjectid id, jobjectArray v, jobject err_obj){
    

    std::vector<std::string> jni_to_cxx_v;
    auto _jni_to_cxx_v = iegen::getObjectArray(env, v);
    for (auto& value__jni_to_cxx_v : _jni_to_cxx_v) {
        jstring jjni_to_cxx_value__jni_to_cxx_vStr = (jstring)value__jni_to_cxx_v;
        auto jni_to_cxx_value__jni_to_cxx_v_cstr = env->GetStringUTFChars(jjni_to_cxx_value__jni_to_cxx_vStr, 0);
        std::string jni_to_cxx_value__jni_to_cxx_v = jni_to_cxx_value__jni_to_cxx_v_cstr;
        env->ReleaseStringUTFChars(jjni_to_cxx_value__jni_to_cxx_vStr, jni_to_cxx_value__jni_to_cxx_v_cstr);
        jni_to_cxx_v.emplace_back(jni_to_cxx_value__jni_to_cxx_v);
    }

    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      this_object->addStringVector(jni_to_cxx_v);
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


extern "C" JNIEXPORT jobjectArray Java_com_examples_containers_VectorExamples_jGetstringvector(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    
    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = this_object->getStringVector();
      
    jobjectArray cxx_to_jni_result = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
    size_t index_result = 0;
    for (auto& value_result : result) {
        jstring cxx_to_jni_value_result = env->NewStringUTF(value_result.c_str());
        env->SetObjectArrayElement(cxx_to_jni_result, index_result, cxx_to_jni_value_result);
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

    jobjectArray result;
    return result;
}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_containers_VectorExamples_jGetobjvector(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    
    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = this_object->getObjVector();
      
    jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
    size_t index_result = 0;
    for (auto& value_result : result) {
        

        iegen::example::VectorItem* cxx_to_jni_value_result_baseptr = value_result;
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


extern "C" JNIEXPORT jintArray Java_com_examples_containers_VectorExamples_jGetintvector(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    
    validateID(id);
    iegen::example::VectorExamples* this_object = reinterpret_cast<iegen::example::VectorExamples*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = this_object->getIntVector();
      
    jintArray cxx_to_jni_result = env->NewIntArray(result.size());
    size_t index_result = 0;
    for (auto& value_result : result) {
        
        env->SetIntArrayRegion(cxx_to_jni_result, index_result, 1, &value_result);
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

    jintArray result;
    return result;
}