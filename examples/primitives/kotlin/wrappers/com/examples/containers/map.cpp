/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-09:24.
 * Please do not change it manually.
 */

#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/containers/map.hpp"

using namespace iegen::example;


extern "C" JNIEXPORT void Java_com_examples_containers_MapItem_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::MapItem*>(id);
    delete jnitocxxid;
}
extern "C" JNIEXPORT jint Java_com_examples_containers_MapItem_jValue(JNIEnv* env, jobject obj, jobjectid id){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::MapItem*>(id);
    const auto& result = jnitocxxid->value;
    
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_containers_MapItem_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jint value){
    validateID(id);
    
    auto jnitocxxid = reinterpret_cast<iegen::example::MapItem*>(id);
    
    
    jnitocxxid->value = value;
}


extern "C" JNIEXPORT jobjectid Java_com_examples_containers_MapItem_jConstructor(JNIEnv* env, jobject obj, jint _value){
    
    try {
        iegen::example::MapItem* baseptr = new iegen::example::MapItem(_value);
        return reinterpret_cast<jlong>(baseptr);
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
    jobjectid result;
    return result;
}

extern "C" JNIEXPORT void Java_com_examples_containers_MapExamples_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    delete jnitocxxid;
}

extern "C" JNIEXPORT jobjectid Java_com_examples_containers_MapExamples_jConstructor(JNIEnv* env, jobject obj){
    try {
        iegen::example::MapExamples* baseptr = new iegen::example::MapExamples();
        return reinterpret_cast<jlong>(baseptr);
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
    jobjectid result;
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_containers_MapExamples_jAddstringpair(JNIEnv* env, jobject obj, jobjectid id, jobject info){
    
    jclass pairClass_info = env->FindClass("kotlin/Pair");

    jfieldID firstID_info = env->GetFieldID(pairClass_info, "first", "Ljava/lang/Object;");
    jfieldID secondID_info = env->GetFieldID(pairClass_info, "second", "Ljava/lang/Object;");

    auto firstObject_info = env->GetObjectField(info, firstID_info);
    auto secondObject_info = env->GetObjectField(info, secondID_info);
    auto first_info = iegen::extractObject(env, firstObject_info);
    auto second_info = iegen::extractObject(env, secondObject_info);
    jstring jjnitocxxfirst_infoStr = (jstring)first_info;
    auto jnitocxxfirst_info_cstr = env->GetStringUTFChars(jjnitocxxfirst_infoStr, 0);
    std::string jnitocxxfirst_info = jnitocxxfirst_info_cstr;
    env->ReleaseStringUTFChars(jjnitocxxfirst_infoStr, jnitocxxfirst_info_cstr);
    jstring jjnitocxxsecond_infoStr = (jstring)second_info;
    auto jnitocxxsecond_info_cstr = env->GetStringUTFChars(jjnitocxxsecond_infoStr, 0);
    std::string jnitocxxsecond_info = jnitocxxsecond_info_cstr;
    env->ReleaseStringUTFChars(jjnitocxxsecond_infoStr, jnitocxxsecond_info_cstr);
    std::pair<std::basic_string<char>, std::basic_string<char>> jnitocxxinfo = std::make_pair(jnitocxxfirst_info, jnitocxxsecond_info);

    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        jnitocxxid->addStringPair(jnitocxxinfo);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_containers_MapExamples_jAddintmap(JNIEnv* env, jobject obj, jobjectid id, jmapobject info){
    

    std::map<int, int> jnitocxxinfo;
    auto _jnitocxxinfo = iegen::extract_jni_pair(env, info);
    auto tmp_key_jnitocxxinfo = iegen::getIntArray(env, _jnitocxxinfo.first);
    auto tmp_val_jnitocxxinfo = iegen::getIntArray(env, _jnitocxxinfo.second);
    for (size_t i = 0; i < tmp_key_jnitocxxinfo.size(); ++i) {
        auto ktmp_info = tmp_key_jnitocxxinfo[i];
        auto vtmp_info = tmp_val_jnitocxxinfo[i];
        
        
        jnitocxxinfo.insert({ ktmp_info, vtmp_info });
    }

    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        jnitocxxid->addIntMap(jnitocxxinfo);
        return;
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


}


extern "C" JNIEXPORT void Java_com_examples_containers_MapExamples_jAddstringmap(JNIEnv* env, jobject obj, jobjectid id, jmapobject info){
    

    std::map<std::basic_string<char>, std::basic_string<char>> jnitocxxinfo;
    auto _jnitocxxinfo = iegen::extract_jni_pair(env, info);
    auto tmp_key_jnitocxxinfo = iegen::getObjectArray(env, _jnitocxxinfo.first);
    auto tmp_val_jnitocxxinfo = iegen::getObjectArray(env, _jnitocxxinfo.second);
    for (size_t i = 0; i < tmp_key_jnitocxxinfo.size(); ++i) {
        auto ktmp_info = tmp_key_jnitocxxinfo[i];
        auto vtmp_info = tmp_val_jnitocxxinfo[i];
        jstring jjnitocxxktmp_infoStr = (jstring)ktmp_info;
        auto jnitocxxktmp_info_cstr = env->GetStringUTFChars(jjnitocxxktmp_infoStr, 0);
        std::string jnitocxxktmp_info = jnitocxxktmp_info_cstr;
        env->ReleaseStringUTFChars(jjnitocxxktmp_infoStr, jnitocxxktmp_info_cstr);
        jstring jjnitocxxvtmp_infoStr = (jstring)vtmp_info;
        auto jnitocxxvtmp_info_cstr = env->GetStringUTFChars(jjnitocxxvtmp_infoStr, 0);
        std::string jnitocxxvtmp_info = jnitocxxvtmp_info_cstr;
        env->ReleaseStringUTFChars(jjnitocxxvtmp_infoStr, jnitocxxvtmp_info_cstr);
        jnitocxxinfo.insert({ jnitocxxktmp_info, jnitocxxvtmp_info });
    }

    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        jnitocxxid->addStringMap(jnitocxxinfo);
        return;
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


}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_MapExamples_jGetstringmap(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        const auto& result = jnitocxxid->getStringMap();
        
        jobjectArray tmp_key_cxxtojniresult = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        jobjectArray tmp_val_cxxtojniresult = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        size_t index_result  = 0;
        for (auto& value_result : result) {
            auto key_result = value_result.first;
            auto val_result = value_result.second;
            jstring cxxtojnikey_result = env->NewStringUTF(key_result.data());
            env->SetObjectArrayElement(tmp_key_cxxtojniresult, index_result, cxxtojnikey_result);
            jstring cxxtojnival_result = env->NewStringUTF(val_result.data());
            env->SetObjectArrayElement(tmp_val_cxxtojniresult, index_result, cxxtojnival_result);
            ++index_result;
        }
        jmapobject cxxtojniresult = iegen::make_jni_object_pair(env, tmp_key_cxxtojniresult, tmp_val_cxxtojniresult);
        return cxxtojniresult;
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

    jmapobject result;
    return result;
}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_MapExamples_jGetintmap(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        const auto& result = jnitocxxid->getIntMap();
        
        auto tmp_key_cxxtojniresult = env->NewIntArray(result.size());
        auto tmp_val_cxxtojniresult = env->NewIntArray(result.size());
        size_t index_result  = 0;
        for (auto& value_result : result) {
            auto key_result = value_result.first;
            auto val_result = value_result.second;
            
            env->SetIntArrayRegion(tmp_key_cxxtojniresult, index_result, 1, &key_result);
            
            env->SetIntArrayRegion(tmp_val_cxxtojniresult, index_result, 1, &val_result);
            ++index_result;
        }
        jmapobject cxxtojniresult = iegen::make_jni_object_pair(env, tmp_key_cxxtojniresult, tmp_val_cxxtojniresult);
        return cxxtojniresult;
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

    jmapobject result;
    return result;
}


extern "C" JNIEXPORT void Java_com_examples_containers_MapExamples_jAddmixedmap(JNIEnv* env, jobject obj, jobjectid id, jmapobject info){
    

    std::map<std::basic_string<char>, iegen::example::MapItem> jnitocxxinfo;
    auto _jnitocxxinfo = iegen::extract_jni_pair(env, info);
    auto tmp_key_jnitocxxinfo = iegen::getObjectArray(env, _jnitocxxinfo.first);
    auto tmp_val_jnitocxxinfo = iegen::getLongArray(env, _jnitocxxinfo.second);
    for (size_t i = 0; i < tmp_key_jnitocxxinfo.size(); ++i) {
        auto ktmp_info = tmp_key_jnitocxxinfo[i];
        auto vtmp_info = tmp_val_jnitocxxinfo[i];
        jstring jjnitocxxktmp_infoStr = (jstring)ktmp_info;
        auto jnitocxxktmp_info_cstr = env->GetStringUTFChars(jjnitocxxktmp_infoStr, 0);
        std::string jnitocxxktmp_info = jnitocxxktmp_info_cstr;
        env->ReleaseStringUTFChars(jjnitocxxktmp_infoStr, jnitocxxktmp_info_cstr);
        
        auto& jnitocxxvtmp_info = *reinterpret_cast<iegen::example::MapItem*>(vtmp_info);
        jnitocxxinfo.insert({ jnitocxxktmp_info, jnitocxxvtmp_info });
    }

    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        jnitocxxid->addMixedMap(jnitocxxinfo);
        return;
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


}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_MapExamples_jGetmixedmap(JNIEnv* env, jobject obj, jobjectid id){
    
    validateID(id);
    auto jnitocxxid = reinterpret_cast<iegen::example::MapExamples*>(id);
    
    try {
        const auto& result = jnitocxxid->getMixedMap();
        
        jobjectArray tmp_key_cxxtojniresult = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        auto tmp_val_cxxtojniresult = env->NewLongArray(result.size());
        size_t index_result  = 0;
        for (auto& value_result : result) {
            auto key_result = value_result.first;
            auto val_result = value_result.second;
            jstring cxxtojnikey_result = env->NewStringUTF(key_result.data());
            env->SetObjectArrayElement(tmp_key_cxxtojniresult, index_result, cxxtojnikey_result);
            
            iegen::example::MapItem* _val_result = new iegen::example::MapItem(val_result);
            iegen::example::MapItem* cxxtojnival_result_baseptr = const_cast<iegen::example::MapItem*>(_val_result);
            jobjectid cxxtojnival_result = reinterpret_cast<jlong>(cxxtojnival_result_baseptr);
            env->SetLongArrayRegion(tmp_val_cxxtojniresult, index_result, 1, &cxxtojnival_result);
            ++index_result;
        }
        jmapobject cxxtojniresult = iegen::make_jni_object_pair(env, tmp_key_cxxtojniresult, tmp_val_cxxtojniresult);
        return cxxtojniresult;
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

    jmapobject result;
    return result;
}
