/*
 * This file was generated by iegen on 05/18/2021-13:34.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rectangle.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rectangle_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rectangle_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Rectangle* this_object = dynamic_cast<iegen::example::Rectangle*>(baseptr);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Rectangle_jConstructor(JNIEnv* env, jobject obj, jdouble length, jdouble width){
    
    
    iegen::example::Parallelogram* baseptr = new iegen::example::Rectangle(length, width);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Rectangle* this_object = dynamic_cast<iegen::example::Rectangle*>(baseptr);
    auto result = this_object->area();
    
    return result;
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Rectangle* this_object = dynamic_cast<iegen::example::Rectangle*>(baseptr);
    
    auto result = this_object->perimeter();

    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jLength(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Rectangle* this_object = dynamic_cast<iegen::example::Rectangle*>(baseptr);
    auto result = this_object->length();
    
    return result;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jWidth(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Rectangle* this_object = dynamic_cast<iegen::example::Rectangle*>(baseptr);
    auto result = this_object->width();
    
    return result;
}