#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/forward_decl/student.hpp"

using namespace iegen::example;
extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Student_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
}
extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Student_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::example::Student* this_object = reinterpret_cast<iegen::example::Student*>(id);
    delete this_object;
}
extern "C" JNIEXPORT jobjectid Java_com_examples_forward_1decl_Student_jConstructor(JNIEnv* env, jobject obj){
    iegen::example::Student* baseptr = new iegen::example::Student();
    return reinterpret_cast<jlong>(baseptr);
}


extern "C" JNIEXPORT void Java_com_examples_forward_1decl_Student_jAddteacher(JNIEnv* env, jobject obj, jobjectid id, jobjectid t){
    

    auto jni_to_cxx_t =  reinterpret_cast<iegen::example::Teacher*>(t);

    validateID(id);
    iegen::example::Student* this_object = reinterpret_cast<iegen::example::Student*>(id);
    
    this_object->addTeacher(jni_to_cxx_t);
}


extern "C" JNIEXPORT jobjectidArray Java_com_examples_forward_1decl_Student_jTeachers(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    iegen::example::Student* this_object = reinterpret_cast<iegen::example::Student*>(id);
    
    auto result = this_object->teachers();

    jobjectidArray cxx_to_jni_result = env->NewLongArray(result.size());
    size_t index = 0;
    for (auto& value : result) {
        

        iegen::example::Teacher* cxx_to_jni_value_baseptr = value;
        jobjectid cxx_to_jni_value = reinterpret_cast<jlong>(cxx_to_jni_value_baseptr);
        env->SetLongArrayRegion(cxx_to_jni_result, index, 1, &cxx_to_jni_value);
        ++index;
    }
    return cxx_to_jni_result;
}