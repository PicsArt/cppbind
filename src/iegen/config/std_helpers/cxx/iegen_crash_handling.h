//
// Created by Alik Aslanyan on 2019-01-31.
//

#ifndef PICORE_JNI_CRASH_HANDLING_H
#define PICORE_JNI_CRASH_HANDLING_H


namespace jni {

    template <class Callable>
    auto handleNativeCrash(JNIEnv* env, Callable f) -> decltype(f()) {
            return f();
    }

} // namespace pi

#endif // PICORE_JNI_CRASH_HANDLING_H
