#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"


using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Stack<iegen::example::Project>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::Stack<iegen::example::Project>* baseptr = new iegen::example::Stack<iegen::example::Project>();
    return reinterpret_cast<jlong>(baseptr);
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jConstructor_11(JNIEnv* env, jobject obj, jobjectid st){
    
    auto& jni_to_cxx_st = * reinterpret_cast<iegen::example::Project*>(st);
    iegen::example::Stack<iegen::example::Project>* baseptr = new iegen::example::Stack<iegen::example::Project>(jni_to_cxx_st);
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jPush(JNIEnv* env, jobject obj, jobjectid id, jobjectid item){
    

    auto jni_to_cxx_item =  reinterpret_cast<iegen::example::Project*>(item);

    validateID(id);
    iegen::example::Stack<iegen::example::Project>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(id);
    
    this_object->push(jni_to_cxx_item);
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackProject_jPop(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Project>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(id);
    
    this_object->pop();
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackProject_jTop(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Project>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(id);
    
    auto result = this_object->top();


    iegen::example::Project* cxx_to_jni_result_baseptr = result;
    jobjectid cxx_to_jni_result = reinterpret_cast<jlong>(cxx_to_jni_result_baseptr);
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_templates_StackProject_jEmpty(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Project>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Project>*>(id);
    
    auto result = this_object->empty();

    return result;
}

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_templates_StackRoot_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_templates_StackRoot_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Stack<iegen::example::Root>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Root>*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackRoot_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::Stack<iegen::example::Root>* baseptr = new iegen::example::Stack<iegen::example::Root>();
    return reinterpret_cast<jlong>(baseptr);
}
extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackRoot_jConstructor_11(JNIEnv* env, jobject obj, jobjectid st){
    
    auto& jni_to_cxx_st = * reinterpret_cast<iegen::example::Root*>(st);
    iegen::example::Stack<iegen::example::Root>* baseptr = new iegen::example::Stack<iegen::example::Root>(jni_to_cxx_st);
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackRoot_jPush(JNIEnv* env, jobject obj, jobjectid id, jobjectid item){
    

    auto jni_to_cxx_item =  reinterpret_cast<iegen::example::Root*>(item);

    validateID(id);
    iegen::example::Stack<iegen::example::Root>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Root>*>(id);
    
    this_object->push(jni_to_cxx_item);
}


extern "C" JNIEXPORT void Java_com_examples_templates_StackRoot_jPop(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Root>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Root>*>(id);
    
    this_object->pop();
}


extern "C" JNIEXPORT jobjectid Java_com_examples_templates_StackRoot_jTop(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Root>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Root>*>(id);
    
    auto result = this_object->top();


    iegen::example::Root* cxx_to_jni_result_baseptr = result;
    jobjectid cxx_to_jni_result = reinterpret_cast<jlong>(cxx_to_jni_result_baseptr);
    return cxx_to_jni_result;
}


extern "C" JNIEXPORT jboolean Java_com_examples_templates_StackRoot_jEmpty(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Stack<iegen::example::Root>* this_object = reinterpret_cast<iegen::example::Stack<iegen::example::Root>*>(id);
    
    auto result = this_object->empty();

    return result;
}