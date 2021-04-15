#include "jni.h"
#include <iostream>
#include "tests/examples_tests/kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "examples/cxx/classes/task.hpp"


extern "C" JNIEXPORT void Java_com_examples_classes_Task_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_classes_Task_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Task, iegen::example::Task>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_classes_Task_jConstructor(JNIEnv* env, jobject obj, jstring title){
  return iegen::handleNativeCrash(env, [&] {
        const std::string & jni_to_cxx_title = iegen::jni_to_string(env, title);
        auto this_object = new iegen::example::Task(jni_to_cxx_title);
        return iegen::UnsafeRefAsLong<iegen::example::Task, iegen::example::Task>(this_object);
        }
  );
}

extern "C" JNIEXPORT jstring Java_com_examples_classes_Task_jTitle(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Task, iegen::example::Task>(id);
        auto result = this_object->title();
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
        }
    );
}