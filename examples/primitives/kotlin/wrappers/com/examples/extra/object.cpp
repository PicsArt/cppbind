#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/base/object.hpp"

using namespace iegen;
extern "C" JNIEXPORT void Java_com_examples_extra_Object_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_extra_Object_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    delete &this_object;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jTostring(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->toString();
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jClassname(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->className();
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_extra_Object_jEquals(JNIEnv* env, jobject obj, jobjectid id, jobjectid other){
    

    std::shared_ptr<Object> jni_to_cxx_other = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(other);

    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->equals(jni_to_cxx_other);

    return result;
}


extern "C" JNIEXPORT jlong Java_com_examples_extra_Object_jHash(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->hash();

    return result;
}


extern "C" JNIEXPORT jstring Java_com_examples_extra_Object_jDebuginfo(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->debugInfo();
    jstring cxx_to_jni_result = env->NewStringUTF(result.c_str());
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jlong Java_com_examples_extra_Object_jBytescount(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::Object>*>(id);
    
    auto result = this_object->bytesCount();

    return result;
}