#ifndef __WRAPPER_HELPER_HPP__
#define __WRAPPER_HELPER_HPP__

#include "jni.h"
#include<utility>
#include<string>
#include <vector>
#include <type_traits>
#include <memory>


typedef jlong jobjectid;
typedef jobject jmapobject;
typedef jlongArray jobjectidArray;


#define validateID(id) //DCHECK(id != 0, "ID can not be 0")

namespace iegen{

std::pair<jobject, jobject> extract_jni_pair(JNIEnv *env, jobject p);

jobject make_jni_object_pair(JNIEnv *env, jobject first, jobject second);

std::string jni_to_string(JNIEnv* env, jobject jobj);

jstring string_to_jni(JNIEnv* env, const std::string& str);

std::vector<std::string> getStringVector(JNIEnv* env, jobjectArray stringArray);

std::vector<jobject> getObjectArray(JNIEnv* env, jobject obj);

std::vector<jlong> getLongArray(JNIEnv* env, jobject obj);

std::vector<jint> getIntArray(JNIEnv* env, jobject obj);

std::vector<jfloat> getFloatArray(JNIEnv* env, jobject obj);

std::string extractString(JNIEnv* env, jobject obj);

jfloat extractFloat(JNIEnv* env, jobject obj);

jint extractInt(JNIEnv* env, jobject obj);

jlong extractLong(JNIEnv* env, jobject obj);

jobject extractObject(JNIEnv* env, jobject obj);

jobject longToObject(JNIEnv* env, jlong obj);

jobject intToObject(JNIEnv* env, jint obj);

jobject floatToObject(JNIEnv* env, jfloat val);

jobject doubleToObject(JNIEnv* env, jdouble val) ;

jobject shortToObject(JNIEnv* env, jshort val);

jobject boolToObject(JNIEnv* env, jboolean val);

} // end of iegen
#endif //__WRAPPER_HELPER_HPP__
