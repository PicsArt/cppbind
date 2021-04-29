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