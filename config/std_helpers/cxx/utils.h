//
// Created by Alik Aslanyan on 03/07/2018.
//

#ifndef PICORE_UTILS_H
#define PICORE_UTILS_H


#include <jni.h>
#include <vector>


#define validateID(id) DCHECK(id != 0, "ID can not be 0")

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
    static_assert(std::is_convertible_v<strip_t<T>*, pi::Object*>);
}

template <typename T>
struct objectify {
    using type = pi::Object;
};

template <typename T>
struct objectify<const T> {
    using type = const pi::Object;
};

template <typename T>
using objectify_t = typename objectify<T>::type;

template <typename T>
inline jlong AllocWeakRefPtrAsLong(const std::weak_ptr<T> &ref) {
    IsTypeValidForJNI<T>();
    // We are giving back weak_ptr of pi::Object, to make it possible
    // to access the whole inheritance hierarchy via returned value.
    return reinterpret_cast<jlong>(new std::weak_ptr<objectify_t<T>>(ref));
}

inline void deleteWeakRef(jlong id) {
    validateID(id);
    auto objWeak = reinterpret_cast<std::weak_ptr<pi::Object>*>(id);
    delete objWeak;
}

template <typename T>
inline const std::shared_ptr<T> RefFromWeakRefLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    // The weak_ptr of pi::Object is stored in the id.
    // Revive it and dynamic_cast it to the requested type with check.
    auto objWeak = reinterpret_cast<std::weak_ptr<pi::Object>*>(id);
    auto objStrong = objWeak->lock();
    auto t = std::dynamic_pointer_cast<T>(objStrong);
    DCHECK(t.get() == objStrong.get(), "Can't convert to type.");
    return t;
}

template <typename T>
inline std::weak_ptr<T> WeakRefFromLong(jlong id) {
    // There is no dynamic_cast for weak_ptr, so we get it from shared_ptr of required type.
    return RefFromWeakRefLong<T>(id);
}

template <typename T>
inline jlong AllocRefPtrAsLong(const std::shared_ptr<T>& ref) {
    IsTypeValidForJNI<T>();
    // We are giving back shared_ptr of pi::Object, to make it possible
    // to access the whole inheritance hierarchy via returned value.
    return reinterpret_cast<jlong>(new std::shared_ptr<objectify_t<T>>(ref));
}

inline void deleteRef(jlong id) {
    validateID(id);
    auto obj = reinterpret_cast<std::shared_ptr<pi::Object>*>(id);
    delete obj;
}

template <>
inline jlong AllocRefPtrAsLong<pi::RXNode>(const std::shared_ptr<pi::RXNode> &ref) {
    auto obj = ref.get()->javaObject();
    if (obj.first != 0) {
        return obj.first;
    }
    return reinterpret_cast<jlong>(new std::shared_ptr<pi::Object>(ref));
}

template <>
inline jlong AllocRefPtrAsLong<pi::RXVirtualValue>(const std::shared_ptr<pi::RXVirtualValue> &ref) {
    auto obj = ref.get()->javaObject();
    if (obj.first != 0) {
        return obj.first;
    }
    return reinterpret_cast<jlong>(new std::shared_ptr<pi::Object>(ref));
}

template <typename T>
inline std::shared_ptr<T> RefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    auto obj = reinterpret_cast<std::shared_ptr<pi::Object>*>(id);
    auto t = std::dynamic_pointer_cast<T>(*obj);
    DCHECK(t.get() == obj->get(), "Invalid type");
    return t;
}

template <typename T>
inline std::shared_ptr<T> NullableRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    if (id == 0) {
        return std::shared_ptr<T>{};
    }
    return RefFromLong<T>(id);
}

template<typename T>
inline jlong UnsafeRefAsLong(T* unsafe) {
    IsTypeValidForJNI<T>();
    DCHECK_NE(unsafe, nullptr);
    return reinterpret_cast<jlong>(static_cast<objectify_t<T>*>(unsafe));
}

template<typename T>
inline T* NullableUnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    pi::Object* obj = reinterpret_cast<pi::Object*>(id);
    T* t = dynamic_cast<T*>(obj);
    DCHECK(t == obj, "Invalid type.");
    return t;
}

template<typename T>
inline T* UnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    return NullableUnsafeRefFromLong<T>(id);
}

template<typename T>
T* UnsafeKernelRefFromLong(jlong pointer) {
    return pi::polymorphic_downcast<T*>(UnsafeRefFromLong<pi::RKernel>(pointer));
}

template<typename T>
inline auto ValueRefFromLong(jlong id) {
    return RefFromLong<pi::RXVirtualValue>(id)->as<T>();
}

pi::StringVector getStringArray(JNIEnv *env, jobjectArray stringArray);
std::set<std::string> getStringSet(JNIEnv *env, jobjectArray stringArray);
std::vector<jlong> getLongArray(JNIEnv *env, jlongArray jlongArray1);
std::vector<jint> getIntArray(JNIEnv *env, jintArray jintArray1);
std::vector<jfloat> getFloatArray(JNIEnv *env, jfloatArray jfloatArray1);
std::vector<std::string> getStringVector(JNIEnv *env, jobjectArray stringArray);

#endif //PICORE_UTILS_H
