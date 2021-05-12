#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rhombus.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rhombus_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rhombus_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rhombus, iegen::example::Parallelogram>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Rhombus_jConstructor(JNIEnv* env, jobject obj, jdouble diagonal1, jdouble diagonal2){
  return iegen::handleNativeCrash(env, [&] {
      
      
      auto this_object = new iegen::example::Rhombus(diagonal1, diagonal2);
      return iegen::UnsafeRefAsLong<iegen::example::Rhombus, iegen::example::Parallelogram>(this_object);
      }
  );
}