#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/simple/project.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_simple_Project_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_simple_Project_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Project, iegen::example::Project>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_simple_Project_jConstructor(JNIEnv* env, jobject obj, jstring title){
  return iegen::handleNativeCrash(env, [&] {
      const std::string & jni_to_cxx_title = iegen::jni_to_string(env, title);
      auto this_object = new iegen::example::Project(jni_to_cxx_title);
      return iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(this_object);
      }
  );
}

extern "C" JNIEXPORT jstring Java_com_examples_simple_Project_jTitle(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Project, iegen::example::Project>(id);
        auto result = this_object->title();
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
        }
    );
}


extern "C" JNIEXPORT void Java_com_examples_simple_Project_jAddtask(JNIEnv* env, jobject obj, jobjectid id, jobjectid task){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_task =  reinterpret_cast<iegen::example::Task*>(task);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Project, iegen::example::Project>(id);
        
        this_object->addTask(jni_to_cxx_task);
      }
    );
}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_simple_Project_jTasks(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Project, iegen::example::Project>(id);
        
        auto result = this_object->tasks();

        jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
        size_t index = 0;
        for (auto& value : result) {
            
            jobjectid cxx_to_jni_value =  iegen::UnsafeRefAsLong<iegen::example::Task, iegen::example::Task>(value);
            env->SetLongArrayRegion(cxx_to_jni_result, index, 1, &cxx_to_jni_value);
            ++index;
        }
        return cxx_to_jni_result;
      }
    );
}