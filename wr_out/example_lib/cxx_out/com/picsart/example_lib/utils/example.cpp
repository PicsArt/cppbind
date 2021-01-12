#include "jni.h"
#include <iostream>
#include "example_lib/cxx_out/iegen_wrapper_helper.hpp"
#include "../examples/example_cxx/example.h"



extern "C" JNIEXPORT void Java_com_picsart_example_1lib_utils_Example_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_picsart_example_1lib_utils_Example_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<pi::utils::Example, pi::utils::Example>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_picsart_example_1lib_utils_Example_jConstructor(JNIEnv* env, jobject obj, jint x, jstring name){
  return iegen::handleNativeCrash(env, [&] {
        
        std::string jni_to_cxx_name = iegen::jni_to_string(env, name);
        auto this_object = new pi::utils::Example(x, jni_to_cxx_name);
        return iegen::UnsafeRefAsLong<pi::utils::Example, pi::utils::Example>(this_object);
        }
  );
}


extern "C" JNIEXPORT jint Java_com_picsart_example_1lib_utils_Example_jF(JNIEnv* env, jobject obj, jobjectid id, jint t, jint i, jstring test){
    return iegen::handleNativeCrash(env, [&] {
        
        auto jni_to_cxx_t = (pi::utils::Example::Type)t;



        const char * jni_to_cxx_test = iegen::jni_to_string(env, test);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<pi::utils::Example, pi::utils::Example>(id);
        
        auto result = this_object->f(jni_to_cxx_t, i, jni_to_cxx_test);
        jint cxx_to_jni_result = (jint)result;
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jint Java_com_picsart_example_1lib_utils_Example_jGet_1attribute(JNIEnv* env, jobject obj, jobjectid id, jstring test){
    return iegen::handleNativeCrash(env, [&] {
        
        const char * jni_to_cxx_test = iegen::jni_to_string(env, test);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<pi::utils::Example, pi::utils::Example>(id);
        
        auto result = this_object->get_attribute(jni_to_cxx_test);

        return result;
      }
    );
}