#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/overloads/overload.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_overloads_OverloadedFunctions_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_overloads_OverloadedFunctions_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::OverloadedFunctions, iegen::example::OverloadedFunctions>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_overloads_OverloadedFunctions_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = iegen::allocateRef<iegen::example::OverloadedFunctions>();
      return iegen::AllocRefPtrAsLong<iegen::example::OverloadedFunctions, iegen::example::OverloadedFunctions>(this_object);
      }
  );
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_OverloadedFunctions_jConcatenate(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second){
    return iegen::handleNativeCrash(env, [&] {
        
        std::string jni_to_cxx_first = iegen::jni_to_string(env, first);

        std::string jni_to_cxx_second = iegen::jni_to_string(env, second);

        validateID(id);

        auto this_object = iegen::RefFromLong<iegen::example::OverloadedFunctions, iegen::example::OverloadedFunctions>(id);
        
        auto result = this_object->concatenate(jni_to_cxx_first, jni_to_cxx_second);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_OverloadedFunctions_jConcatenate_11(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second, jstring third){
    return iegen::handleNativeCrash(env, [&] {
        
        std::string jni_to_cxx_first = iegen::jni_to_string(env, first);

        std::string jni_to_cxx_second = iegen::jni_to_string(env, second);

        std::string jni_to_cxx_third = iegen::jni_to_string(env, third);

        validateID(id);

        auto this_object = iegen::RefFromLong<iegen::example::OverloadedFunctions, iegen::example::OverloadedFunctions>(id);
        
        auto result = this_object->concatenate(jni_to_cxx_first, jni_to_cxx_second, jni_to_cxx_third);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}