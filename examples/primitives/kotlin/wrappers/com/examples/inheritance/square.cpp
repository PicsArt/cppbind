#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/square.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Square_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Square_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Square, iegen::example::Parallelogram>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Square_jConstructor(JNIEnv* env, jobject obj, jdouble side){
  return iegen::handleNativeCrash(env, [&] {
      
      auto this_object = new iegen::example::Square(side);
      return iegen::UnsafeRefAsLong<iegen::example::Square, iegen::example::Parallelogram>(this_object);
      }
  );
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_Square_jArea(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Square, iegen::example::Parallelogram>(id);
        auto result = this_object->area();
        
        return result;
        }
    );
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_Square_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Square, iegen::example::Parallelogram>(id);
        
        auto result = this_object->perimeter();

        return result;
      }
    );
}