#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/vehicle.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Vehicle_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Vehicle_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Vehicle, iegen::example::Vehicle>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Vehicle_jConstructor(JNIEnv* env, jobject obj, jint numberOfSeats){
  return iegen::handleNativeCrash(env, [&] {
      
      auto this_object = new iegen::example::Vehicle(numberOfSeats);
      return iegen::UnsafeRefAsLong<iegen::example::Vehicle, iegen::example::Vehicle>(this_object);
      }
  );
}

extern "C" JNIEXPORT jint Java_com_examples_inheritance_Vehicle_jNumberofseats(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Vehicle, iegen::example::Vehicle>(id);
        auto result = this_object->numberOfSeats();
        
        return result;
        }
    );
}