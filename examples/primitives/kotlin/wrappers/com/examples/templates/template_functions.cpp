#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/template_functions.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"
using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_TemplateFunctions_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_TemplateFunctions_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_TemplateFunctions_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = new iegen::example::TemplateFunctions();
      return iegen::UnsafeRefAsLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(this_object);
      }
  );
}


extern "C" JNIEXPORT jint Java_com_examples_templates_TemplateFunctions_jMaxInt(JNIEnv* env, jobject obj, jobjectid id, jint arg0, jint arg1){
    return iegen::handleNativeCrash(env, [&] {
        




        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(id);
        
        auto result = this_object->max<int>(arg0, arg1);

        return result;
      }
    );
}


extern "C" JNIEXPORT jstring Java_com_examples_templates_TemplateFunctions_jMaxString(JNIEnv* env, jobject obj, jobjectid id, jstring arg0, jstring arg1){
    return iegen::handleNativeCrash(env, [&] {
        
        const std::string & jni_to_cxx_arg0 = iegen::jni_to_string(env, arg0);

        const std::string & jni_to_cxx_arg1 = iegen::jni_to_string(env, arg1);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(id);
        
        auto result = this_object->max<std::string>(jni_to_cxx_arg0, jni_to_cxx_arg1);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jobject Java_com_examples_templates_TemplateFunctions_jMakepairProjectProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0, jobjectid arg1){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_arg0 =  reinterpret_cast<iegen::example::Project*>(arg0);


        auto jni_to_cxx_arg1 =  reinterpret_cast<iegen::example::Project*>(arg1);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(id);
        
        auto result = this_object->makePair<iegen::example::Project, iegen::example::Project>(jni_to_cxx_arg0, jni_to_cxx_arg1);
        auto first = result.first;
        auto second = result.second;

        jobjectid cxx_to_jni_first =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(first);

        jobjectid cxx_to_jni_second =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(second);
        jobject result_first = iegen::longToObject(env, cxx_to_jni_first);
        jobject result_second = iegen::longToObject(env, cxx_to_jni_second);
        jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, result_first, result_second);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jobject Java_com_examples_templates_TemplateFunctions_jMakepairTaskProject(JNIEnv* env, jobject obj, jobjectid id, jobjectid arg0, jobjectid arg1){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_arg0 =  reinterpret_cast<iegen::example::Task*>(arg0);


        auto jni_to_cxx_arg1 =  reinterpret_cast<iegen::example::Project*>(arg1);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::TemplateFunctions, iegen::example::TemplateFunctions>(id);
        
        auto result = this_object->makePair<iegen::example::Task, iegen::example::Project>(jni_to_cxx_arg0, jni_to_cxx_arg1);
        auto first = result.first;
        auto second = result.second;

        jobjectid cxx_to_jni_first =  iegen::UnsafeRefAsLong<iegen::example::Task, iegen::example::Task>(first);

        jobjectid cxx_to_jni_second =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(second);
        jobject result_first = iegen::longToObject(env, cxx_to_jni_first);
        jobject result_second = iegen::longToObject(env, cxx_to_jni_second);
        jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, result_first, result_second);
        return cxx_to_jni_result;
      }
    );
}