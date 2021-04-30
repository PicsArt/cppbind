#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/stack_usage.hpp"
#include "cxx/simple/project.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_StackUsage_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_StackUsage_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::StackUsage, iegen::example::StackUsage>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = new iegen::example::StackUsage();
      return iegen::UnsafeRefAsLong<iegen::example::StackUsage, iegen::example::StackUsage>(this_object);
      }
  );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jFirstitemofspecialized(JNIEnv* env, jobject obj, jobjectid id, jobjectid p){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_p =  reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(p);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::StackUsage, iegen::example::StackUsage>(id);
        
        auto result = this_object->firstItemOfSpecialized(jni_to_cxx_p);

        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackUsage_jFirstitemoftemplateProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_arg0 =  reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(arg0);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::StackUsage, iegen::example::StackUsage>(id);
        
        auto result = this_object->firstItemOfTemplate<iegen::example::Project>(jni_to_cxx_arg0);

        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(result);
        return cxx_to_jni_result;
      }
    );
}