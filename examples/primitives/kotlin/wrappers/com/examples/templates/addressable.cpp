#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/addressable.hpp"
#include "cxx/classes/root.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_AddressableRoot_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_AddressableRoot_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::Addressable<iegen::example::Root>, iegen::example::Addressable<iegen::example::Root>>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_AddressableRoot_jConstructor(JNIEnv* env, jobject obj, jobjectid parent, jstring name){
  return iegen::handleNativeCrash(env, [&] {
      
        auto& jni_to_cxx_parent = * reinterpret_cast<iegen::example::Root*>(parent);
      const std::string & jni_to_cxx_name = iegen::jni_to_string(env, name);
      auto this_object = iegen::allocateRef<iegen::example::Addressable<iegen::example::Root>>(jni_to_cxx_parent, jni_to_cxx_name);
      return iegen::AllocRefPtrAsLong<iegen::example::Addressable<iegen::example::Root>, iegen::example::Addressable<iegen::example::Root>>(this_object);
      }
  );
}


extern "C" JNIEXPORT jstring Java_com_examples_templates_AddressableHelperRoot_jAbspath(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::RefFromLong<iegen::example::Addressable<iegen::example::Root>, iegen::example::Addressable<iegen::example::Root>>(id);
        
        auto result = this_object->absPath();
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}