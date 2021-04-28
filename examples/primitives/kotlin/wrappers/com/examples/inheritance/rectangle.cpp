#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rectangle.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rectangle_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_inheritance_Rectangle_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rectangle, iegen::example::Parallelogram>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_Rectangle_jConstructor(JNIEnv* env, jobject obj, jdouble length, jdouble width){
  return iegen::handleNativeCrash(env, [&] {
      
      
      auto this_object = new iegen::example::Rectangle(length, width);
      return iegen::UnsafeRefAsLong<iegen::example::Rectangle, iegen::example::Parallelogram>(this_object);
      }
  );
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jArea(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rectangle, iegen::example::Parallelogram>(id);
        auto result = this_object->area();
        
        return result;
        }
    );
}


extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jPerimeter(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rectangle, iegen::example::Parallelogram>(id);
        
        auto result = this_object->perimeter();

        return result;
      }
    );
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jLength(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rectangle, iegen::example::Parallelogram>(id);
        auto result = this_object->length();
        
        return result;
        }
    );
}

extern "C" JNIEXPORT jdouble Java_com_examples_inheritance_RectangleHelper_jWidth(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Rectangle, iegen::example::Parallelogram>(id);
        auto result = this_object->width();
        
        return result;
        }
    );
}