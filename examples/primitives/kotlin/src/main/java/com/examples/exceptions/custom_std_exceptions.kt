/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 08/11/2022-09:04.
 * Please do not change it manually.
 */

package com.examples.exceptions

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*
import com.examples.cppbind.exceptions.StdException

open class SystemError
internal constructor(obj: CppBindObject) : StdException(obj) {
    companion object {
        
        /**
         * comments
         * 
         */
        protected fun constructHelper(message: String): Long {
            val id = jConstructor(message)
            return id
        }

        @JvmStatic
        private external fun jConstructor(message: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::SystemError"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): SystemError {
            val idType = jGettypebyid(id)
            when (idType) {
                FileError.cppbindCxxTypeName -> return FileError(CppBindObject(id, owner))
                else -> return SystemError(CppBindObject(id, owner))
            }
        }
    }
    
    
    /**
     * comments
     * 
     */
    constructor(message: String): this(CppBindObject(constructHelper(message), true)) {
    }
    
    /**
     * comments
     * 
     */
    open override fun what(): String {
        val result = jWhat(cppbindObjId)
        val jdktokotlinresult = result!!
        return jdktokotlinresult
    }

    ///// External wrapper functions ////////////
    private external fun jWhat(id: Long): String?
}

open class FileError
internal constructor(obj: CppBindObject) : SystemError(obj) {
    companion object {
        
        protected fun constructHelper(message: String): Long {
            val id = jConstructor(message)
            return id
        }

        @JvmStatic
        private external fun jConstructor(message: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::FileError"
    }
    
    
    constructor(message: String): this(CppBindObject(constructHelper(message), true)) {
    }
    
    /**
     * comments
     * 
     */
    open override fun what(): String {
        val result = jWhat(cppbindObjId)
        val jdktokotlinresult = result!!
        return jdktokotlinresult
    }

    ///// External wrapper functions ////////////
    private external fun jWhat(id: Long): String?
}

private external fun jGettypebyid(id: Long): String
