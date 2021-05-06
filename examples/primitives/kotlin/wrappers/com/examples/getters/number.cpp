#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/getters/number.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<int>>*>(id);
    delete &this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberInt_jConstructor(JNIEnv* env, jobject obj, jint n){
    
    iegen::example::Number<int>* obj_ptr = new iegen::example::Number<int>(n);
    auto this_object = std::shared_ptr<iegen::example::Number<int>>(obj_ptr);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Number<int>>(this_object));
}

extern "C" JNIEXPORT jint Java_com_examples_getters_NumberInt_jNum(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<int>>*>(id);
    auto result = this_object->num;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<int>>*>(id);
    
    
    this_object->num = value;
}


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<double>>*>(id);
    delete &this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberDouble_jConstructor(JNIEnv* env, jobject obj, jdouble n){
    
    iegen::example::Number<double>* obj_ptr = new iegen::example::Number<double>(n);
    auto this_object = std::shared_ptr<iegen::example::Number<double>>(obj_ptr);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::example::Number<double>>(this_object));
}

extern "C" JNIEXPORT jdouble Java_com_examples_getters_NumberDouble_jNum(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<double>>*>(id);
    auto result = this_object->num;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jdouble value){
    validateID(id);
    auto this_object = *reinterpret_cast<std::shared_ptr<iegen::example::Number<double>>*>(id);
    
    
    this_object->num = value;
}
