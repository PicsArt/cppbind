#include "jni.h"
#include<utility>
#include<string>

typedef jlong jobjectid;
typedef jobject jmapobject;
typedef jlongArray jobjectidArray;

std::pair<jobject, jobject> extract_jni_pair(JNIEnv *env, jobject p) {
    jclass pairClass = env->FindClass("android/util/Pair");
    jfieldID first = env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
    jfieldID second = env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");

    return std::make_pair(env->GetObjectField(p, first), env->GetObjectField(p, second));
}


jobject make_jni_pair(JNIEnv *env, jobject first, jobject second) {
    // Get the pair class that we wish to return an instance of
    jclass pairClass = env->FindClass("android/util/Pair");

    // Get the method id of an empty constructor in class
    jmethodID constructor = env->GetMethodID(pairClass, "<init>", "()V");

    // Create an instance of class
    jobject obj = env->NewObject(pairClass, constructor);

    // Get Field references
    jfieldID first_field = env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
    jfieldID second_field = env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");

    // Set fields for object
    env->SetObjectField(obj, first_field, first);
    env->SetObjectField(obj, second_field, second);
    return obj;
}


std::string jni_to_string(JNIEnv* env, jstring jStr) {
    auto cstr = env->GetStringUTFChars(jStr, 0);
    std::string str = cstr;
    env->ReleaseStringUTFChars(jStr, cstr);
    return str;
}


jstring string_to_jni(JNIEnv* env, const std::string& str) {
    return env->NewStringUTF(str.c_str());
}
