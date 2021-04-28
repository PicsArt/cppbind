#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/forward_decl/teacher.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Teacher_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Teacher_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Teacher, iegen::example::Teacher>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_forward_1decl_Teacher_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = new iegen::example::Teacher();
      return iegen::UnsafeRefAsLong<iegen::example::Teacher, iegen::example::Teacher>(this_object);
      }
  );
}


extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Teacher_jAddstudent(JNIEnv* env, jobject obj, jobjectid id, jobjectid s){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_s =  reinterpret_cast<iegen::example::Student*>(s);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Teacher, iegen::example::Teacher>(id);
        
        this_object->addStudent(jni_to_cxx_s);
      }
    );
}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_forward_1decl_Teacher_jStudents(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Teacher, iegen::example::Teacher>(id);
        
        auto result = this_object->students();

        jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
        size_t index = 0;
        for (auto& value : result) {
            
            jobjectid cxx_to_jni_value =  iegen::UnsafeRefAsLong<iegen::example::Student, iegen::example::Student>(value);
            env->SetLongArrayRegion(cxx_to_jni_result, index, 1, &cxx_to_jni_value);
            ++index;
        }
        return cxx_to_jni_result;
      }
    );
}