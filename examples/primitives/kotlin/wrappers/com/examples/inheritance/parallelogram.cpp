#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/parallelogram.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Parallelogram_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Parallelogram_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Parallelogram, iegen::example::Parallelogram>(id);
        delete this_object;
    });
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_ParallelogramHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Parallelogram, iegen::example::Parallelogram>(id);
        auto result = this_object->area();
        
        return result;
        }
    );
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_ParallelogramHelper_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Parallelogram, iegen::example::Parallelogram>(id);
        
        auto result = this_object->perimeter();

        return result;
      }
    );
}