/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 05/05/2022-13:33.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/inheritance/rhombus.hpp"
#include "cxx/inheritance/parallelogram.hpp"
#include "cxx/inheritance/square.hpp"

extern const char* IEGEN_IEGEN_EXAMPLE_SQUARE;
extern const char* IEGEN_STD_STDEXCEPTION;

const char* IEGEN_IEGEN_EXAMPLE_IRHOMBUSFIGURE = "iegen::example::Rhombus";

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_inheritance_RhombusFigureImpl_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    static_assert(std::has_virtual_destructor<iegen::example::Rhombus>::value, "iegen::example::Rhombus type must have virtual destructor");
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    if (strcmp(iegen_obj_id->type, IEGEN_IEGEN_EXAMPLE_IRHOMBUSFIGURE) == 0)
        delete static_cast<iegen::example::Rhombus*>(iegen_obj_id_ptr);
    else if (strcmp(iegen_obj_id->type, IEGEN_IEGEN_EXAMPLE_SQUARE) == 0)
        delete static_cast<iegen::example::Square*>(iegen_obj_id_ptr);
    else {
        std::cerr << "Unexpected object type: " << iegen_obj_id->type << std::endl;
        exit(1);
    }
    free(iegen_obj_id->type);
    delete iegen_obj_id;
}

iegen::example::Rhombus* recover_obj_from_IegenExample_IRhombusFigure(jobjectid id) {
    auto iegen_obj_id = reinterpret_cast<IEGenCObject*>(id);
    auto iegen_obj_id_ptr = iegen_obj_id ? iegen_obj_id->ptr : nullptr;
    if (iegen_obj_id_ptr) {
        if (strcmp(iegen_obj_id->type, IEGEN_IEGEN_EXAMPLE_IRHOMBUSFIGURE) == 0)
            return static_cast<iegen::example::Rhombus*>(iegen_obj_id_ptr);
        else if (strcmp(iegen_obj_id->type, IEGEN_IEGEN_EXAMPLE_SQUARE) == 0)
            return static_cast<iegen::example::Square*>(iegen_obj_id_ptr);
        else {
            std::cerr << "Unexpected object type: " << iegen_obj_id->type << std::endl;
            exit(1);
        }
    }
    return nullptr;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_inheritance_RhombusFigureImpl_jConstructor(JNIEnv* env, jobject obj, jdouble diagonal1, jdouble diagonal2){
    
    
    try {
        iegen::example::Rhombus* ptr = new iegen::example::Rhombus(diagonal1, diagonal2);
        return reinterpret_cast<jlong>(new IEGenCObject {strdup(IEGEN_IEGEN_EXAMPLE_IRHOMBUSFIGURE), ptr});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/iegen/exceptionUtils/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_inheritance_RhombusKt_jGettypebyid(JNIEnv* env, jclass cls, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<IEGenCObject*>(id)->type);
}
