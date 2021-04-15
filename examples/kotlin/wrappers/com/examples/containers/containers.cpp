#include "jni.h"
#include <iostream>
#include "kotlin/wrappers/iegen_wrapper_helper.hpp"
#include "cxx/containers/containers.hpp"


extern "C" JNIEXPORT void Java_com_examples_containers_Item_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_containers_Item_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Item, iegen::example::Item>(id);
    delete this_object;
  });
}

extern "C" JNIEXPORT jint Java_com_examples_containers_Item_jValue(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Item, iegen::example::Item>(id);
        auto result = this_object->value;
        
        return result;
        }
    );
}

extern "C" JNIEXPORT void Java_com_examples_containers_Item_jSetvalue(JNIEnv* env, jobject obj, jobjectid id, jint value){
    return iegen::handleNativeCrash(env, [&] {
        validateID(id);
        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Item, iegen::example::Item>(id);
        
        
        this_object->value = value;
        }
    );
}

extern "C" JNIEXPORT jobjectid Java_com_examples_containers_Item_jConstructor(JNIEnv* env, jobject obj, jint _value){
  return iegen::handleNativeCrash(env, [&] {
        
        auto this_object = new iegen::example::Item(_value);
        return iegen::UnsafeRefAsLong<iegen::example::Item, iegen::example::Item>(this_object);
        }
  );
}

extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jSet_1this(JNIEnv* env, jobject obj, jobjectid id, jobject self){
  return iegen::handleNativeCrash(env, [&] {});
}
extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jFinalize(JNIEnv* env, jobject obj, jobjectid id){
  iegen::handleNativeCrash(env, [&] {
    auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
    delete this_object;
  });
}
extern "C" JNIEXPORT jobjectid Java_com_examples_containers_Containers_jConstructor(JNIEnv* env, jobject obj){
  return iegen::handleNativeCrash(env, [&] {
        auto this_object = new iegen::example::Containers();
        return iegen::UnsafeRefAsLong<iegen::example::Containers, iegen::example::Containers>(this_object);
        }
  );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddstringpair(JNIEnv* env, jobject obj, jobjectid id, jobject info){
    return iegen::handleNativeCrash(env, [&] {
        
        jclass pairClass = env->FindClass("kotlin/Pair");

        jfieldID firstID = env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
        jfieldID secondID = env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");

        auto firstObject = env->GetObjectField(info, firstID);
        auto secondObject = env->GetObjectField(info, secondID);
        auto first = iegen::extractObject(env, firstObject);
        auto second = iegen::extractObject(env, secondObject);
        std::string jni_to_cxx_first = iegen::jni_to_string(env, first);
        std::string jni_to_cxx_second = iegen::jni_to_string(env, second);
        std::pair<std::string, std::string> jni_to_cxx_info = std::make_pair(jni_to_cxx_first, jni_to_cxx_second)

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addStringPair(jni_to_cxx_info);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddintmap(JNIEnv* env, jobject obj, jobjectid id, jmapobject info){
    return iegen::handleNativeCrash(env, [&] {
        

        std::map<int, int> jni_to_cxx_info;
        auto _jni_to_cxx_info = iegen::extract_jni_pair(env, info);
        auto tmp_key_jni_to_cxx_info = iegen::getIntArray(env, _jni_to_cxx_info.first);
        auto tmp_val_jni_to_cxx_info = iegen::getIntArray(env, _jni_to_cxx_info.second);
        for (size_t i = 0; i < tmp_key_jni_to_cxx_info.size(); ++i) {
            auto ktmp = tmp_key_jni_to_cxx_info[i];
            auto vtmp = tmp_val_jni_to_cxx_info[i];
            
            
            jni_to_cxx_info.insert({ ktmp, vtmp });
        }

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addIntMap(jni_to_cxx_info);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddstringmap(JNIEnv* env, jobject obj, jobjectid id, jmapobject info){
    return iegen::handleNativeCrash(env, [&] {
        

        std::map<std::string, std::string> jni_to_cxx_info;
        auto _jni_to_cxx_info = iegen::extract_jni_pair(env, info);
        auto tmp_key_jni_to_cxx_info = iegen::getObjectArray(env, _jni_to_cxx_info.first);
        auto tmp_val_jni_to_cxx_info = iegen::getObjectArray(env, _jni_to_cxx_info.second);
        for (size_t i = 0; i < tmp_key_jni_to_cxx_info.size(); ++i) {
            auto ktmp = tmp_key_jni_to_cxx_info[i];
            auto vtmp = tmp_val_jni_to_cxx_info[i];
            std::string jni_to_cxx_ktmp = iegen::jni_to_string(env, ktmp);
            std::string jni_to_cxx_vtmp = iegen::jni_to_string(env, vtmp);
            jni_to_cxx_info.insert({ jni_to_cxx_ktmp, jni_to_cxx_vtmp });
        }

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addStringMap(jni_to_cxx_info);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddintpair(JNIEnv* env, jobject obj, jobjectid id, jobject info){
    return iegen::handleNativeCrash(env, [&] {
        
        jclass pairClass = env->FindClass("kotlin/Pair");

        jfieldID firstID = env->GetFieldID(pairClass, "first", "Ljava/lang/Object;");
        jfieldID secondID = env->GetFieldID(pairClass, "second", "Ljava/lang/Object;");

        auto firstObject = env->GetObjectField(info, firstID);
        auto secondObject = env->GetObjectField(info, secondID);
        auto first = iegen::extractInt(env, firstObject);
        auto second = iegen::extractInt(env, secondObject);


        std::pair<int, int> jni_to_cxx_info = std::make_pair(first, second)

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addIntPair(jni_to_cxx_info);
      }
    );
}


extern "C" JNIEXPORT jobject Java_com_examples_containers_Containers_jGetstringpair(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getStringPair();
        auto first = result.first;
        auto second = result.second;
        jstring cxx_to_jni_first = iegen::string_to_jni(env, first);;
        jstring cxx_to_jni_second = iegen::string_to_jni(env, second);;
        jobject cxx_to_jni_result = iegen::make_jni_object_pair(env, cxx_to_jni_first, cxx_to_jni_second);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_Containers_jGetstringmap(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getStringMap();

        jobjectArray tmp_key_cxx_to_jni_result = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        jobjectArray tmp_val_cxx_to_jni_result = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        size_t index = 0;
        for (auto& value : result) {
            auto key = value.first;
            auto val = value.second;
            jstring cxx_to_jni_key = iegen::string_to_jni(env, key);
            env->SetObjectArrayElement(tmp_key_cxx_to_jni_result, index, cxx_to_jni_key);
            jstring cxx_to_jni_val = iegen::string_to_jni(env, val);
            env->SetObjectArrayElement(tmp_val_cxx_to_jni_result, index, cxx_to_jni_val);
            ++index;
        }
        jmapobject cxx_to_jni_result = iegen::make_jni_object_pair(env, tmp_key_cxx_to_jni_result, tmp_val_cxx_to_jni_result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_Containers_jGetintmap(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getIntMap();

        auto tmp_key_cxx_to_jni_result = env->NewIntArray(result.size());
        auto tmp_val_cxx_to_jni_result = env->NewIntArray(result.size());
        size_t index = 0;
        for (auto& value : result) {
            auto key = value.first;
            auto val = value.second;
            
            env->SetIntArrayRegion(tmp_key_cxx_to_jni_result, index, 1, &key);
            
            env->SetIntArrayRegion(tmp_val_cxx_to_jni_result, index, 1, &val);
            ++index;
        }
        jmapobject cxx_to_jni_result = iegen::make_jni_object_pair(env, tmp_key_cxx_to_jni_result, tmp_val_cxx_to_jni_result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jmapobject Java_com_examples_containers_Containers_jGetmap(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getMap();

        jobjectArray tmp_key_cxx_to_jni_result = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        auto tmp_val_cxx_to_jni_result = env->NewLongArray(result.size());
        size_t index = 0;
        for (auto& value : result) {
            auto key = value.first;
            auto val = value.second;
            jstring cxx_to_jni_key = iegen::string_to_jni(env, key);
            env->SetObjectArrayElement(tmp_key_cxx_to_jni_result, index, cxx_to_jni_key);
            
            iegen::example::Item* _val = iegen::CopyAsPtr<iegen::example::Item>(val);
            jobjectid cxx_to_jni_val =  iegen::UnsafeRefAsLong<iegen::example::Item, iegen::example::Item>(_val);
            env->SetLongArrayRegion(tmp_val_cxx_to_jni_result, index, 1, &cxx_to_jni_val);
            ++index;
        }
        jmapobject cxx_to_jni_result = iegen::make_jni_object_pair(env, tmp_key_cxx_to_jni_result, tmp_val_cxx_to_jni_result);
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddintvector(JNIEnv* env, jobject obj, jobjectid id, jintArray v){
    return iegen::handleNativeCrash(env, [&] {
        

        std::vector<int> jni_to_cxx_v;
        auto _jni_to_cxx_v = iegen::getIntArray(env, v);
        for (auto& value : _jni_to_cxx_v) {
            
            jni_to_cxx_v.emplace_back(value);
        }

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addIntVector(jni_to_cxx_v);
      }
    );
}


extern "C" JNIEXPORT void Java_com_examples_containers_Containers_jAddstringvector(JNIEnv* env, jobject obj, jobjectid id, jobjectArray v){
    return iegen::handleNativeCrash(env, [&] {
        

        std::vector<std::string> jni_to_cxx_v;
        auto _jni_to_cxx_v = iegen::getObjectArray(env, v);
        for (auto& value : _jni_to_cxx_v) {
            std::string jni_to_cxx_value = iegen::jni_to_string(env, value);
            jni_to_cxx_v.emplace_back(jni_to_cxx_value);
        }

        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        this_object->addStringVector(jni_to_cxx_v);
      }
    );
}


extern "C" JNIEXPORT jobjectArray Java_com_examples_containers_Containers_jGetstringvector(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getStringVector();

        jobjectArray cxx_to_jni_result = env->NewObjectArray(result.size(), env->FindClass("java/lang/Object"), NULL);
        size_t index = 0;
        for (auto& value : result) {
            jstring cxx_to_jni_value = iegen::string_to_jni(env, value);
            env->SetObjectArrayElement(cxx_to_jni_result, index, cxx_to_jni_value);
            ++index;
        }
        return cxx_to_jni_result;
      }
    );
}


extern "C" JNIEXPORT jintArray Java_com_examples_containers_Containers_jGetintvector(JNIEnv* env, jobject obj, jobjectid id){
    return iegen::handleNativeCrash(env, [&] {
        
        validateID(id);

        auto this_object = iegen::UnsafeRefFromLong<iegen::example::Containers, iegen::example::Containers>(id);
        
        auto result = this_object->getIntVector();

        jintArray cxx_to_jni_result = env->NewIntArray(result.size());
        size_t index = 0;
        for (auto& value : result) {
            
            env->SetIntArrayRegion(cxx_to_jni_result, index, 1, &value);
            ++index;
        }
        return cxx_to_jni_result;
      }
    );
}