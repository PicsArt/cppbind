#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/getters/number.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::Number<int>, iegen::example::Number<int>>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberInt_jConstructor(JNIEnv* env, jobject obj, jint n){
  return iegen::handleNativeCrash(env, [&] {
      
      auto this_object = iegen::allocateRef<iegen::example::Number<int>>(n);
      return iegen::AllocRefPtrAsLong<iegen::example::Number<int>, iegen::example::Number<int>>(this_object);
      }
  );
}

extern "C" JNIEXPORT jint Java_com_examples_getters_NumberInt_jNum(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::RefFromLong<iegen::example::Number<int>, iegen::example::Number<int>>(id);
        auto result = this_object->num;
        
        return result;
        }
    );
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberInt_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jint value){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::RefFromLong<iegen::example::Number<int>, iegen::example::Number<int>>(id);
        
        
        this_object->num = value;
        }
    );
}

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::RefFromLong<iegen::example::Number<double>, iegen::example::Number<double>>(id);
        delete &this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_getters_NumberDouble_jConstructor(JNIEnv* env, jobject obj, jdouble n){
  return iegen::handleNativeCrash(env, [&] {
      
      auto this_object = iegen::allocateRef<iegen::example::Number<double>>(n);
      return iegen::AllocRefPtrAsLong<iegen::example::Number<double>, iegen::example::Number<double>>(this_object);
      }
  );
}

extern "C" JNIEXPORT jdouble Java_com_examples_getters_NumberDouble_jNum(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::RefFromLong<iegen::example::Number<double>, iegen::example::Number<double>>(id);
        auto result = this_object->num;
        
        return result;
        }
    );
}

extern "C" JNIEXPORT void Java_com_examples_getters_NumberDouble_jSetnum(JNIEnv* env, jobject obj, jobjectid id, jdouble value){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::RefFromLong<iegen::example::Number<double>, iegen::example::Number<double>>(id);
        
        
        this_object->num = value;
        }
    );
}
