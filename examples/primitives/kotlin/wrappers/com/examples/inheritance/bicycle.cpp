#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/bicycle.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Bicycle_jConstructor(JNIEnv* env, jobject obj, jint numberOfSeats){
  return iegen::handleNativeCrash(env, [&] {
      
      auto this_object = new iegen::example::Bicycle(numberOfSeats);
      return iegen::UnsafeRefAsLong<iegen::example::Bicycle, iegen::example::Vehicle>(this_object);
      }
  );
}