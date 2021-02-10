#include <algorithm>
#include <memory>
#include <iostream>
#include "cxxabi.h"
#include "object.hpp"
#include <functional>

#ifdef __ANDROID__

#include "jni.h"

#endif
namespace iegen {

std::string demangleCPPName(const char* symbol) {
    int status;
    std::unique_ptr<char[], std::function<void(char*)>> demangledSymbol(
        __cxxabiv1::__cxa_demangle(symbol, nullptr, nullptr, &status), free);

    if (status == 0) {
        return demangledSymbol.get();
    } else {
        return symbol;
    }
}

std::string Object::toString() const {
    char res[96];
    auto cn = className();
    snprintf(res, sizeof(res), "<0x%08zx: %s>", reinterpret_cast<std::size_t>(this), cn.c_str());
    return res;
}

std::string Object::className() const {
    return demangleCPPName(typeid(*this).name());
}

bool Object::equals(std::shared_ptr<Object> other) const {
    return this->equals(other.get());
}

bool Object::equals(const Object* p) const {
    return this == p;
}

std::size_t Object::hash() const {
    union {
        std::size_t temp;
        char bytes[sizeof(std::size_t)];
    } _u;

    _u.temp = reinterpret_cast<std::size_t>(this);
    std::reverse(std::begin(_u.bytes), std::end(_u.bytes));
    return _u.temp;
}

std::string Object::debugInfo() const {
    return toString();
}

size_t Object::bytesCount() const {
    return sizeof(*this);
}

#ifdef __ANDROID__
jobject Object::javaObject(JNIEnv* env, jlong ref, jclass clazz) {
    auto localRef = env->NewLocalRef(_jobject.second);
    if (_jobject.first == 0) { // jobject hasn't been created yet
        DCHECK(localRef == nullptr);
        auto ctor = env->GetMethodID(clazz, "<init>", "(J)V");
        localRef = env->NewObject(clazz, ctor, ref);
        _jobject = {ref, env->NewWeakGlobalRef(localRef)};
        return localRef;
    }
    DCHECK(localRef != nullptr);
    if (_jobject.first != ref) {
        // jobject has been created, and the received sp can be deleted
        deleteRef(ref);
    }
    return localRef;
}

void Object::deleteJavaObject() {
    _jobject = {0, nullptr};
}

#endif

} // namespace iegen
