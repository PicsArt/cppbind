#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/parallelogram.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Parallelogram_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Parallelogram_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Parallelogram* this_object = reinterpret_cast<iegen::example::Parallelogram*>(id);
    delete this_object;
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_ParallelogramHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    iegen::example::Parallelogram* this_object = reinterpret_cast<iegen::example::Parallelogram*>(id);
    auto result = this_object->area();
    
    return result;
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_ParallelogramHelper_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Parallelogram* this_object = reinterpret_cast<iegen::example::Parallelogram*>(id);
    
    auto result = this_object->perimeter();

    return result;
}