/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/04/2021-12:27.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/extra/object_usage.hpp"
#include "cxx/extra/object.hpp"

using namespace iegen;


extern "C" JNIEXPORT jobjectid Java_com_examples_extra_ObjectUsage_jConstructor(JNIEnv* env, jobject obj){
    iegen::ObjectUsage* obj_ptr = new iegen::ObjectUsage();
    auto this_object = std::shared_ptr<iegen::ObjectUsage>(obj_ptr);
    std::shared_ptr<iegen::Object> baseptr = std::dynamic_pointer_cast<iegen::Object>(this_object);
    return reinterpret_cast<jlong>(new std::shared_ptr<iegen::Object>(baseptr));
}