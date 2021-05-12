#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/overloads/utils.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_overloads_Utils_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_overloads_Utils_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::Utils, iegen::example::Utils>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_overloads_Utils_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = iegen::allocateRef<iegen::example::Utils>();
      return iegen::AllocRefPtrAsLong<iegen::example::Utils, iegen::example::Utils>(this_object);
      }
  );
}


extern "C" JNIEXPORT jint Java_com_examples_overloads_Utils_jSum(JNIEnv* env, jobject obj, jint first, jint second){
    return iegen::handleNativeCrash(env, [&] {
        




        
        auto result = iegen::example::Utils::sum(first, second);

        return result;
      }
    );
}


extern "C" JNIEXPORT jfloat Java_com_examples_overloads_Utils_jSum_11(JNIEnv* env, jobject obj, jfloat first, jfloat second){
    return iegen::handleNativeCrash(env, [&] {
        




        
        auto result = iegen::example::Utils::sum(first, second);

        return result;
      }
    );
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second){
    return iegen::handleNativeCrash(env, [&] {
        
        std::string jni_to_cxx_first = iegen::jni_to_string(env, first);

        std::string jni_to_cxx_second = iegen::jni_to_string(env, second);

        validateID(id);

        auto this_object = iegen::RefFromLong<iegen::example::Utils, iegen::example::Utils>(id);
        
        auto result = this_object->concatenate(jni_to_cxx_first, jni_to_cxx_second);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jstring Java_com_examples_overloads_Utils_jConcatenate_11(JNIEnv* env, jobject obj, jobjectid id, jstring first, jstring second, jstring third){
    return iegen::handleNativeCrash(env, [&] {
        
        std::string jni_to_cxx_first = iegen::jni_to_string(env, first);

        std::string jni_to_cxx_second = iegen::jni_to_string(env, second);

        std::string jni_to_cxx_third = iegen::jni_to_string(env, third);

        validateID(id);

        auto this_object = iegen::RefFromLong<iegen::example::Utils, iegen::example::Utils>(id);
        
        auto result = this_object->concatenate(jni_to_cxx_first, jni_to_cxx_second, jni_to_cxx_third);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}