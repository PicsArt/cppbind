#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/bicycle.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Bicycle_jConstructor(JNIEnv* env, jobject obj, jint numberOfSeats){
    
    iegen::example::Vehicle* baseptr = new iegen::example::Bicycle(numberOfSeats);
    return reinterpret_cast<jlong>(baseptr);
}