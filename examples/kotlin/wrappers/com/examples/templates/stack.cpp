#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/stack.hpp"
#include "cxx/classes/task.hpp"
#include "cxx/classes/project.hpp"


extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
        auto this_object = new iegen::example::Stack<iegen::example::Project>();
        return iegen::UnsafeRefAsLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(this_object);
        }
  );
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jConstructor_11(JNIEnv* env, jobject obj, jobjectid st){
  return iegen::handleNativeCrash(env, [&] {
        
        auto& jni_to_cxx_st = * reinterpret_cast<iegen::example::Project*>(st);
        auto this_object = new iegen::example::Stack<iegen::example::Project>(jni_to_cxx_st);
        return iegen::UnsafeRefAsLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(this_object);
        }
  );
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jPush(JNIEnv* env, jobject obj, jobjectid id, jobjectid item){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_item =  reinterpret_cast<iegen::example::Project*>(item);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(id);
        
        this_object->push(jni_to_cxx_item);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jPop(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(id);
        
        this_object->pop();
      }
    );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jTop(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(id);
        
        auto result = this_object->top();

        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Project, iegen::example::Project>(result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jboolean Java_com_examples_templates_StackProject_jEmpty(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Project>, iegen::example::Stack<iegen::example::Project>>(id);
        
        auto result = this_object->empty();

        return result;
      }
    );
}

extern "C" JNIEXPORT void Java_com_examples_templates_StackTask_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_templates_StackTask_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackTask_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
        auto this_object = new iegen::example::Stack<iegen::example::Task>();
        return iegen::UnsafeRefAsLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(this_object);
        }
  );
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackTask_jConstructor_11(JNIEnv* env, jobject obj, jobjectid st){
  return iegen::handleNativeCrash(env, [&] {
        
        auto& jni_to_cxx_st = * reinterpret_cast<iegen::example::Task*>(st);
        auto this_object = new iegen::example::Stack<iegen::example::Task>(jni_to_cxx_st);
        return iegen::UnsafeRefAsLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(this_object);
        }
  );
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackTask_jPush(JNIEnv* env, jobject obj, jobjectid id, jobjectid item){
    return iegen::handleNativeCrash(env, [&] {
        

        auto jni_to_cxx_item =  reinterpret_cast<iegen::example::Task*>(item);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(id);
        
        this_object->push(jni_to_cxx_item);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackTask_jPop(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(id);
        
        this_object->pop();
      }
    );
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackTask_jTop(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(id);
        
        auto result = this_object->top();

        jobjectid cxx_to_jni_result =  iegen::UnsafeRefAsLong<iegen::example::Task, iegen::example::Task>(result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jboolean Java_com_examples_templates_StackTask_jEmpty(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Stack<iegen::example::Task>, iegen::example::Stack<iegen::example::Task>>(id);
        
        auto result = this_object->empty();

        return result;
      }
    );
}