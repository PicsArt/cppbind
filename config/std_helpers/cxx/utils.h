//
// Created by Alik Aslanyan on 03/07/2018.
//

#ifndef PICORE_UTILS_H
#define PICORE_UTILS_H


#include <jni.h>
#include <vector>
#include <type_traits>
#include <memory>


#define validateID(id) //DCHECK(id != 0, "ID can not be 0")

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


template<typename T>
inline void deleteRef(jlong id) {
    validateID(id);
    auto obj = reinterpret_cast<std::shared_ptr<T>*>(id);
    delete obj;
}


template <typename T>
inline std::shared_ptr<T> RefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    auto obj = reinterpret_cast<std::shared_ptr<T>*>(id);
    auto t = std::dynamic_pointer_cast<T>(*obj);
    //DCHECK(t.get() == obj->get(), "Invalid type");
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
    //DCHECK_NE(unsafe, nullptr);
    return reinterpret_cast<jlong>(static_cast<T*>(unsafe));
}

template<typename T>
inline T* NullableUnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    T* obj = reinterpret_cast<T*>(id);
    T* t = dynamic_cast<T*>(obj);
    //DCHECK(t == obj, "Invalid type.");
    return t;
}

template<typename T>
inline T* UnsafeRefFromLong(jlong id) {
    IsTypeValidForJNI<T>();
    validateID(id);
    return NullableUnsafeRefFromLong<T>(id);
}

#endif //PICORE_UTILS_H
