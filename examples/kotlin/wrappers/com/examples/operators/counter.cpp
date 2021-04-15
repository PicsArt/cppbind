#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/operators/counter.hpp"


extern "C" JNIEXPORT void Java_com_examples_operators_Counter_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_operators_Counter_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_operators_Counter_jConstructor(JNIEnv* env, jobject obj, jint count){
  return iegen::handleNativeCrash(env, [&] {
        
        auto this_object = new iegen::example::Counter(count);
        return iegen::UnsafeRefAsLong<iegen::example::Counter, iegen::example::Counter>(this_object);
        }
  );
}

extern "C" JNIEXPORT jint Java_com_examples_operators_Counter_jCount(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
        auto result = this_object->count();
        
        return result;
        }
    );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_operators_Counter_jPlus(JNIEnv* env, jobject obj, jobjectid id, jobjectid counter){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_counter = * reinterpret_cast<iegen::example::Counter*>(counter);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
        
        auto result = this_object->operator+(jni_to_cxx_counter);

        iegen::example::Counter* _result = iegen::CopyAsPtr<iegen::example::Counter>(result);
        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Counter, iegen::example::Counter>(_result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jint Java_com_examples_operators_Counter_jCompareto(JNIEnv* env, jobject obj, jobjectid id, jobjectid counter){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_counter = * reinterpret_cast<iegen::example::Counter*>(counter);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
        
        auto result = this_object->compareTo(jni_to_cxx_counter);

        return result;
      }
    );
}


extern "C" JNIEXPORT jboolean Java_com_examples_operators_Counter_jGt(JNIEnv* env, jobject obj, jobjectid id, jobjectid counter){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_counter = * reinterpret_cast<iegen::example::Counter*>(counter);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
        
        auto result = this_object->operator>(jni_to_cxx_counter);

        return result;
      }
    );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_operators_Counter_jAdd(JNIEnv* env, jobject obj, jobjectid id, jobjectid counter){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_counter = * reinterpret_cast<iegen::example::Counter*>(counter);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Counter, iegen::example::Counter>(id);
        
        auto result = this_object->operator+=(jni_to_cxx_counter);

        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Counter, iegen::example::Counter>(&result);
        return cxx_to_jni_result;
      }
    );
}