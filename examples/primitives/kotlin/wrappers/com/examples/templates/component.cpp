#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/component.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_Component_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_Component_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::Component, iegen::example::Addressable<iegen::example::Root>>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_Component_jConstructor(JNIEnv* env, jobject obj, jobjectid parent, jstring name){
  return iegen::handleNativeCrash(env, [&] {
      
        auto& jni_to_cxx_parent = * reinterpret_cast<iegen::example::Root*>(parent);
      const std::string & jni_to_cxx_name = iegen::jni_to_string(env, name);
      auto this_object = iegen::allocateRef<iegen::example::Component>(jni_to_cxx_parent, jni_to_cxx_name);
      return iegen::AllocRefPtrAsLong<iegen::example::Component, iegen::example::Addressable<iegen::example::Root>>(this_object);
      }
  );
}