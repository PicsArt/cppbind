#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/classes/root.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_classes_Root_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_classes_Root_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Root, iegen::example::Root>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_classes_Root_jConstructor(JNIEnv* env, jobject obj, jstring _path){
  return iegen::handleNativeCrash(env, [&] {
        const std::string & jni_to_cxx__path = iegen::jni_to_string(env, _path);
        auto this_object = new iegen::example::Root(jni_to_cxx__path);
        return iegen::UnsafeRefAsLong<iegen::example::Root, iegen::example::Root>(this_object);
        }
  );
}

extern "C" JNIEXPORT jstring Java_com_examples_classes_Root_jPath(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Root, iegen::example::Root>(id);
        auto result = this_object->path;
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
        }
    );
}