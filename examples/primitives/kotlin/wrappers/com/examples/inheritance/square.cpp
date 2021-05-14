#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/square.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Square_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Square_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Square* this_object = dynamic_cast<iegen::example::Square*>(baseptr);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Square_jConstructor(JNIEnv* env, jobject obj, jdouble side){
    
    iegen::example::Parallelogram* baseptr = new iegen::example::Square(side);
    return reinterpret_cast<jlong>(baseptr);
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_Square_jArea(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Square* this_object = dynamic_cast<iegen::example::Square*>(baseptr);
    auto result = this_object->area();
    
    return result;
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_Square_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Parallelogram* baseptr = reinterpret_cast<iegen::example::Parallelogram*>(id);
    iegen::example::Square* this_object = dynamic_cast<iegen::example::Square*>(baseptr);
    
    auto result = this_object->perimeter();

    return result;
}