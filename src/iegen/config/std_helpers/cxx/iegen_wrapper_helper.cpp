#include "iegen_wrapper_helper.hpp"

namespace iegen {


std::pair<jobject, jobject> extract_jni_pair(JNIEnv *env, jobject p) {
    jclass pairClass = env->FindClass("kotlin/Pair");
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


std::string jni_to_string(JNIEnv* env, jobject jobj) {
    jstring jStr = (jstring)jobj;
    auto cstr = env->GetStringUTFChars(jStr, 0);
    std::string str = cstr;
    env->ReleaseStringUTFChars(jStr, cstr);
    return str;
}


jstring string_to_jni(JNIEnv* env, const std::string& str) {
    return env->NewStringUTF(str.c_str());
}

std::vector<std::string> getStringVector(JNIEnv* env, jobjectArray stringArray) {
    int len = env->GetArrayLength(stringArray);
    std::vector<std::string> ret(len);
    for (int i = 0; i < len; ++i) {
        jstring ref = static_cast<jstring>(env->GetObjectArrayElement(stringArray, i));
        ret[i] = jni_to_string(env, ref);
    }
    return ret;
}

std::vector<jobject> getObjectArray(JNIEnv* env, jobject obj) {
    jobjectArray objArray = (jobjectArray)obj;
    int len = env->GetArrayLength(objArray);
    std::vector<jobject> ret(len);
    for (int i = 0; i < len; ++i) {
        jobject ref = env->GetObjectArrayElement(objArray, i);
        ret[i] = ref;
    }
    return ret;
}

std::vector<jlong> getLongArray(JNIEnv* env, jobject obj) {
    jlongArray jlongArray1 = (jlongArray)obj;
    int len = env->GetArrayLength(jlongArray1);
    std::vector<jlong> ret;
    ret.reserve(len);
    jlong* arr = env->GetLongArrayElements(jlongArray1, nullptr);
    std::copy(arr, arr + len, std::back_inserter(ret));
    env->ReleaseLongArrayElements(jlongArray1, arr, 0);
    return ret;
}

std::vector<jint> getIntArray(JNIEnv* env, jobject obj) {
    jintArray jintArray1 = (jintArray)obj;
    int len = env->GetArrayLength(jintArray1);
    std::vector<jint> ret;
    ret.reserve(len);
    jint* arr = env->GetIntArrayElements(jintArray1, nullptr);
    std::copy(arr, arr + len, std::back_inserter(ret));
    env->ReleaseIntArrayElements(jintArray1, arr, 0);
    return ret;
}

std::vector<jfloat> getFloatArray(JNIEnv* env, jobject obj) {
    jfloatArray jfloatArray1 = (jfloatArray)obj;
    int len = env->GetArrayLength(jfloatArray1);
    std::vector<jfloat> ret;
    ret.reserve(len);
    jfloat* arr = env->GetFloatArrayElements(jfloatArray1, nullptr);
    std::copy(arr, arr + len, std::back_inserter(ret));
    env->ReleaseFloatArrayElements(jfloatArray1, arr, 0);
    return ret;
}

}
