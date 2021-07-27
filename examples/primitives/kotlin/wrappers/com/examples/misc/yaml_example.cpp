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
#include "cxx/misc/yaml_example.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_misc_WithExternalAPIComments_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_misc_WithExternalAPIComments_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::WithExternalAPIComments* this_object = reinterpret_cast<iegen::example::WithExternalAPIComments*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_misc_WithExternalAPIComments_jConstructor(JNIEnv* env, jobject obj, jstring s){
    jstring jjni_to_cxx_sStr = (jstring)s;
    auto jni_to_cxx_s_cstr = env->GetStringUTFChars(jjni_to_cxx_sStr, 0);
    std::string jni_to_cxx_s = jni_to_cxx_s_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_sStr, jni_to_cxx_s_cstr);
    iegen::example::WithExternalAPIComments* baseptr = new iegen::example::WithExternalAPIComments(jni_to_cxx_s);
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT jint Java_com_examples_misc_WithExternalAPIComments_jRetint(JNIEnv* env, jobject obj, jint n, jobject err_obj){
    


    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = iegen::example::WithExternalAPIComments::retInt(n);
      
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

extern "C" JNIEXPORT jstring Java_com_examples_misc_WithExternalAPIComments_jStr(JNIEnv* env, jobject obj, jobjectid id, jobject err_obj){
    validateID(id);
    iegen::example::WithExternalAPIComments* this_object = reinterpret_cast<iegen::example::WithExternalAPIComments*>(id);
    int err_type_id = 0;
    void* err_ptr = nullptr;
    try {
        auto result = this_object->str();
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

extern "C" JNIEXPORT void Java_com_examples_misc_WithExternalAPIComments_jSetstr(JNIEnv* env, jobject obj, jobjectid id, jstring s, jobject err_obj){
    validateID(id);
    iegen::example::WithExternalAPIComments* this_object = reinterpret_cast<iegen::example::WithExternalAPIComments*>(id);jstring jjni_to_cxx_sStr = (jstring)s;
    auto jni_to_cxx_s_cstr = env->GetStringUTFChars(jjni_to_cxx_sStr, 0);
    const std::string & jni_to_cxx_s = jni_to_cxx_s_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_sStr, jni_to_cxx_s_cstr);
    int err_type_id = 0;
    void* err_ptr = nullptr;
    try {
        this_object->setStr(jni_to_cxx_s);
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



extern "C" JNIEXPORT jint Java_com_examples_misc_WithExternalAPIComments_jMaxInt(JNIEnv* env, jobject obj, jint arg0, jint arg1, jobject err_obj){
    




    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = iegen::example::WithExternalAPIComments::max<int>(arg0, arg1);
      
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


extern "C" JNIEXPORT jstring Java_com_examples_misc_WithExternalAPIComments_jMaxString(JNIEnv* env, jobject obj, jstring arg0, jstring arg1, jobject err_obj){
    
    jstring jjni_to_cxx_arg0Str = (jstring)arg0;
    auto jni_to_cxx_arg0_cstr = env->GetStringUTFChars(jjni_to_cxx_arg0Str, 0);
    const std::string & jni_to_cxx_arg0 = jni_to_cxx_arg0_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_arg0Str, jni_to_cxx_arg0_cstr);

    jstring jjni_to_cxx_arg1Str = (jstring)arg1;
    auto jni_to_cxx_arg1_cstr = env->GetStringUTFChars(jjni_to_cxx_arg1Str, 0);
    const std::string & jni_to_cxx_arg1 = jni_to_cxx_arg1_cstr;
    env->ReleaseStringUTFChars(jjni_to_cxx_arg1Str, jni_to_cxx_arg1_cstr);

    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = iegen::example::WithExternalAPIComments::max<std::string>(jni_to_cxx_arg0, jni_to_cxx_arg1);
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

extern "C" JNIEXPORT void Java_com_examples_misc_AdderInt_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_misc_AdderInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Adder<int>* this_object = reinterpret_cast<iegen::example::Adder<int>*>(id);
    delete this_object;
}


extern "C" JNIEXPORT jint Java_com_examples_misc_AdderInt_jAdd(JNIEnv* env, jobject obj, jint a, jint b, jobject err_obj){
    




    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = iegen::example::Adder<int>::add(a, b);
      
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

extern "C" JNIEXPORT void Java_com_examples_misc_AdderDouble_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_misc_AdderDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Adder<double>* this_object = reinterpret_cast<iegen::example::Adder<double>*>(id);
    delete this_object;
}


extern "C" JNIEXPORT jdouble Java_com_examples_misc_AdderDouble_jAdd(JNIEnv* env, jobject obj, jdouble a, jdouble b, jobject err_obj){
    




    int err_type_id = 0;
    void* err_ptr = nullptr;

    try {
      auto result = iegen::example::Adder<double>::add(a, b);
      
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

    jdouble result;
    return result;
}