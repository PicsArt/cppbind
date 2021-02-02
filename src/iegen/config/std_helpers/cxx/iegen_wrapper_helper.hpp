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

template <typename T>
struct remove_cvref {
    typedef std::remove_cv_t<std::remove_reference_t<T>> type;
};

template <typename T>
using remove_cvref_t = typename remove_cvref<T>::type;

template <typename T>
using strip_t = std::remove_pointer_t<remove_cvref_t<T>>;

template <typename T>
constexpr void IsTypeValidForJNI() {
    //static_assert(std::is_convertible_v<strip_t<T>*, pi::Object*>);
}


template<typename T, typename... Args>
inline std::shared_ptr<T> allocateRef(Args&&... args) {
    auto obj = new T(std::forward<Args>(args)...);
    return std::shared_ptr<T>(obj);
}


template<typename T, typename BaseT>
inline void deleteRef(jlong id) {
    validateID(id);
    auto obj = reinterpret_cast<std::shared_ptr<BaseT>*>(id);

    delete obj;
}

template <typename T, typename BaseT>
inline jlong AllocRefPtrAsLong(const std::shared_ptr<T>& ref) {
    if (!std::is_same<T, BaseT>::value) {
        std::shared_ptr<BaseT> baseptr = std::static_pointer_cast<BaseT>(ref);
        return reinterpret_cast<jlong>(new std::shared_ptr<BaseT>(baseptr));
    }

    return reinterpret_cast<jlong>(new std::shared_ptr<T>(ref));
}

template <typename T, typename BaseT>
inline jlong AllocRefPtrAsLong(T* ref) {
    BaseT* baseptr = ref;
    return reinterpret_cast<jlong>(new std::shared_ptr<BaseT>(baseptr));
}

template <typename T, typename BaseT>
inline std::shared_ptr<T> RefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    if (!std::is_same<T, BaseT>::value) {
        auto baseptr = *reinterpret_cast<std::shared_ptr<BaseT>*>(id);
        return std::static_pointer_cast<T>(baseptr);
    }
    return *reinterpret_cast<std::shared_ptr<T>*>(id);
}

template <typename T, typename BaseT>
inline std::shared_ptr<T> RefFromLongDynamic(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    if (!std::is_same<T, BaseT>::value) {
        auto baseptr = *reinterpret_cast<std::shared_ptr<BaseT>*>(id);
        return std::dynamic_pointer_cast<T>(baseptr);
    }
    return *reinterpret_cast<std::shared_ptr<T>*>(id);;
}

template <typename T>
inline std::shared_ptr<T> CopyAsSharedPtr(T obj) {
    IsTypeValidForJNI<T>();
    std::shared_ptr<T> obj_ptr = std::make_shared<T>(obj);
    return obj_ptr;
}

template <typename T>
inline T* CopyAsPtr(T obj) {
    IsTypeValidForJNI<T>();
    return new T(obj);
}

template <typename T>
inline std::shared_ptr<T> NullableRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    if (id == 0) {
        return std::shared_ptr<T>{};
    }
    return RefFromLong<T>(id);
}

template<typename T, typename BaseT>
inline jlong UnsafeRefAsLong(T* unsafe) {
    IsTypeValidForJNI<T>();
    BaseT* baseptr = unsafe;
    //DCHECK_NE(unsafe, nullptr);
    return reinterpret_cast<jlong>(baseptr);
}

template<typename T, typename BaseT>
inline T* NullableUnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    if (!std::is_same<T, BaseT>::value) {
        BaseT* baseobj = reinterpret_cast<BaseT*>(id);
        return static_cast<T*>(baseobj);
    }
    return reinterpret_cast<T*>(id);
}

template<typename T, typename BaseT>
inline T* NullableUnsafeRefFromLongDynamic(jlong id) {
    IsTypeValidForJNI<T>();
    if (!std::is_same<T, BaseT>::value) {
        BaseT* baseobj = reinterpret_cast<BaseT*>(id);
        return dynamic_cast<T*>(baseobj);
    }
    return reinterpret_cast<T*>(id);
}

template<typename T, typename BaseT>
inline T* UnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    return NullableUnsafeRefFromLong<T, BaseT>(id);
}

template<typename T, typename BaseT>
inline T* UnsafeRefFromLongDynamic(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    return NullableUnsafeRefFromLongDynamic<T, BaseT>(id);
}


template <class Callable>
auto handleNativeCrash(JNIEnv* env, Callable f) -> decltype(f()) {
        return f();
}

std::pair<jobject, jobject> extract_jni_pair(JNIEnv *env, jobject p);

jobject make_jni_pair(JNIEnv *env, jobject first, jobject second);

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
} // end of iegenn
#endif //__WRAPPER_HELPER_HPP__
