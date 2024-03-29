/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/22/2022-09:33.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include <cxxabi.h>
#include <string.h>
#include <type_traits>
#include "kotlin/wrappers/c_helpers.h"
#include "kotlin/wrappers/cppbind_wrapper_helper.hpp"
#include "cxx/factories/school.h"
#include "cxx/forward_decl/teacher.hpp"

extern const char* CPPBIND_STD_STDEXCEPTION;
extern const char* CPPBIND_CPPBIND_EXAMPLE_TEACHER;

const char* CPPBIND_CPPBIND_EXAMPLE_SCHOOL = "cppbind::example::School";


extern "C" JNIEXPORT void Java_com_examples_factories_School_jFinalize(JNIEnv*, jobject, jobjectid id){
    using namespace cppbind::example;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    delete static_cast<std::shared_ptr<cppbind::example::School>*>(cppbind_obj_id_ptr);
    free(cppbind_obj_id->type);
    delete cppbind_obj_id;
}

extern "C" JNIEXPORT jlong Java_com_examples_factories_School_jGetcxxid(JNIEnv*, jobject, jobjectid id) {
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id->ptr;
    return reinterpret_cast<jlong>(static_cast<std::shared_ptr<cppbind::example::School>*>(cppbind_obj_id_ptr)->get());
}

extern "C" JNIEXPORT jobjectid Java_com_examples_factories_School_jCreate([[maybe_unused]] JNIEnv* env, jobject, jobjectidArray teachers, ...){
    using namespace cppbind::example;
    
    std::vector<Teacher *> jnitocxxteachers;
    auto _jnitocxxteachers = cppbind::getLongArray(env, teachers);
    for (auto& value__jnitocxxteachers : _jnitocxxteachers) {
        
        auto cppbind_obj_value__jnitocxxteachers = reinterpret_cast<CppBindCObject*>(value__jnitocxxteachers);
        auto cppbind_obj_value__jnitocxxteachers_ptr = cppbind_obj_value__jnitocxxteachers ? cppbind_obj_value__jnitocxxteachers->ptr : nullptr;
        auto jnitocxxvalue__jnitocxxteachers = static_cast<cppbind::example::Teacher*>(cppbind_obj_value__jnitocxxteachers_ptr);
        jnitocxxteachers.emplace_back(jnitocxxvalue__jnitocxxteachers);
    }
    try {
        auto this_object = cppbind::example::School::create(jnitocxxteachers);
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SCHOOL), new std::shared_ptr<cppbind::example::School>(this_object)});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_factories_School_jCreate1([[maybe_unused]] JNIEnv* env, jobject){
    using namespace cppbind::example;
    try {
        auto this_object = cppbind::example::School::create();
        return reinterpret_cast<jlong>(new CppBindCObject {strdup(CPPBIND_CPPBIND_EXAMPLE_SCHOOL), new std::shared_ptr<cppbind::example::School>(this_object)});
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }
    jobjectid result {};
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_factories_School_jAddteacher([[maybe_unused]] JNIEnv* env, jobject, jobjectid id, jobjectid teacher, ...){
    using namespace cppbind::example;
    

    auto cppbind_obj_teacher = reinterpret_cast<CppBindCObject*>(teacher);
    auto cppbind_obj_teacher_ptr = cppbind_obj_teacher ? cppbind_obj_teacher->ptr : nullptr;
    auto jnitocxxteacher = static_cast<cppbind::example::Teacher*>(cppbind_obj_teacher_ptr);

    validateID(id);
    std::shared_ptr<cppbind::example::School> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::School>*>(cppbind_obj_id_ptr);
    
    try {
        jnitocxxid->addTeacher(jnitocxxteacher);
        return;
    }
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }


}

extern "C" JNIEXPORT jobjectidArray Java_com_examples_factories_School_jTeachers([[maybe_unused]] JNIEnv* env, jobject, jobjectid id){
    using namespace cppbind::example;
    validateID(id);
    
    std::shared_ptr<cppbind::example::School> jnitocxxid;
    auto cppbind_obj_id = reinterpret_cast<CppBindCObject*>(id);
    auto cppbind_obj_id_ptr = cppbind_obj_id ? cppbind_obj_id->ptr : nullptr;
    jnitocxxid = *static_cast<std::shared_ptr<cppbind::example::School>*>(cppbind_obj_id_ptr);
    try {
        decltype(auto) result = jnitocxxid->teachers();
        
        jobjectidArray cxxtojniresult = env->NewLongArray(result.size());
        size_t index_result = 0;
        for (auto& value_result : result) {
            cppbind::example::Teacher* cxxtojnivalue_result_ptr = value_result;
            char* type_value_result = strdup(CPPBIND_CPPBIND_EXAMPLE_TEACHER);
            CppBindCObject* cppbind_obj_cxxtojnivalue_result = new CppBindCObject {type_value_result, cxxtojnivalue_result_ptr};
            jobjectid cxxtojnivalue_result = reinterpret_cast<jlong>(cppbind_obj_cxxtojnivalue_result);
            env->SetLongArrayRegion(cxxtojniresult, index_result, 1, &cxxtojnivalue_result);
            ++index_result ;
        }
        return cxxtojniresult;
    }
    
    catch (const std::exception& e) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF(e.what()));
    }
    catch (...) {
        jclass handlerCls = env->FindClass("com/examples/cppbind/ExceptionHandler");
        jmethodID handlerMethod = env->GetStaticMethodID(handlerCls, "handleUncaughtException", "(Ljava/lang/String;)V");
        env->CallStaticVoidMethod(handlerCls, handlerMethod, env->NewStringUTF("Uncaught Exception"));
    }

    jobjectidArray result {};
    return result;
}

extern "C" JNIEXPORT jstring Java_com_examples_factories_SchoolKt_jGettypebyid(JNIEnv* env, jclass, jobjectid id) {
    validateID(id);
    return env->NewStringUTF(reinterpret_cast<CppBindCObject*>(id)->type);
}
