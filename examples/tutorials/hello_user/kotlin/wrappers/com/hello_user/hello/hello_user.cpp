#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/hello_user.hpp"


extern "C" JNIEXPORT void Java_com_hello_1user_hello_UserInfo_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_hello_1user_hello_UserInfo_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<UserInfo, UserInfo>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_hello_1user_hello_UserInfo_jConstructor(JNIEnv* env, jobject obj, jstring user_name, jlong user_age){
  return iegen::handleNativeCrash(env, [&] {
      const std::string & jni_to_cxx_user_name = iegen::jni_to_string(env, user_name);
      
      auto this_object = new UserInfo(jni_to_cxx_user_name, user_age);
      return iegen::UnsafeRefAsLong<UserInfo, UserInfo>(this_object);
      }
  );
}

extern "C" JNIEXPORT jlong Java_com_hello_1user_hello_UserInfo_jAge(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<UserInfo, UserInfo>(id);
        auto result = this_object->age;
        
        return result;
        }
    );
}

extern "C" JNIEXPORT jstring Java_com_hello_1user_hello_UserInfo_jName(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<UserInfo, UserInfo>(id);
        auto result = this_object->name;
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
        }
    );
}

extern "C" JNIEXPORT jboolean Java_com_hello_1user_hello_UserInfo_jWant_1a_1drink(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<UserInfo, UserInfo>(id);
        auto result = this_object->want_a_drink;
        
        return result;
        }
    );
}

extern "C" JNIEXPORT void Java_com_hello_1user_hello_UserInfo_jSetwant_1a_1drink(JNIEnv* env, jobject obj, jobjectid id, jboolean value){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<UserInfo, UserInfo>(id);
        
        
        this_object->want_a_drink = value;
        }
    );
}


extern "C" JNIEXPORT void Java_com_hello_1user_hello_Host_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
    return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_hello_1user_hello_Host_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
    iegen::handleNativeCrash(env, [&] {
        auto this_object = iegen::UnsafeRefFromLong<Host, Host>(id);
        delete this_object;
    });
}
extern "C" JNIEXPORT jobjectid Java_com_hello_1user_hello_Host_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
      auto this_object = new Host();
      return iegen::UnsafeRefAsLong<Host, Host>(this_object);
      }
  );
}


extern "C" JNIEXPORT jstring Java_com_hello_1user_hello_Host_jHello(JNIEnv* env, jobject obj, jobjectid id, jobjectid user){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_user = * reinterpret_cast<UserInfo*>(user);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<Host, Host>(id);
        
        auto result = this_object->hello(jni_to_cxx_user);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jstring Java_com_hello_1user_hello_Host_jWelcome(JNIEnv* env, jobject obj, jobjectid id, jobjectid user){
    return iegen::handleNativeCrash(env, [&] {
        

        auto& jni_to_cxx_user = * reinterpret_cast<UserInfo*>(user);

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<Host, Host>(id);
        
        auto result = this_object->welcome(jni_to_cxx_user);
        jstring cxx_to_jni_result = iegen::string_to_jni(env, result);
        return cxx_to_jni_result;
      }
    );
}