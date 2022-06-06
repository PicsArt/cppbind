/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/06/2022-08:28.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*


interface ISign : AutoCloseable {
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    val id: Long
    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any)
    
    
    open fun typeName(): String {
        val result = ISignHelper.jTypename(id)
        
        return result
    }

    companion object {
        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): ISign {
            val idType = jGettypebyid(id)
            when (idType) {
                Digit.cppbindCxxTypeName -> return Digit(CppBindObject(id, owner))
                else -> return SignImpl(CppBindObject(id, owner))
            }
        }
    }
}


class ISignHelper {
    companion object {
        @JvmStatic
        external fun jTypename(id: Long): String
    }
}


open class SignImpl
internal constructor(obj : CppBindObject) : ISign {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Sign"
    }

    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }

    override val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
        }
    }

    /**
    * Finalize and deletes the object
    */
    protected fun finalize() {
        close()
    }
    
    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as SignImpl
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class Text
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Text"

        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): Text {
            val idType = jGettypebyid(id)
            when (idType) {
                Digit.cppbindCxxTypeName -> return Digit(CppBindObject(id, owner))
                else -> return Text(CppBindObject(id, owner))
            }
        }
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open fun typeName(): String {
        val result = jTypename(id)
        
        return result
    }

    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as Text
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jTypename(id: Long): String
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class Digit
internal constructor(obj: CppBindObject) : ISign, Text(obj) {
    companion object {
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Digit"
    }
    
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    override val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }
    
    open override fun typeName(): String {
        val result = jTypename(id)
        
        return result
    }

    ///// External wrapper functions ////////////
    private external fun jTypename(id: Long): String
}

open class SymbolUsage
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long

        protected fun construct_helper(d: Digit): Long {
            val kotlintojdkd = d.id
            val id = jConstructor_1(kotlintojdkd, d)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(d: Long, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::SymbolUsage"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }

    /**
     * An internal property returning underlying C++ object id.
     * It is intended to be used by the generated code.
     */
    internal val cxxId: Long by lazy {
        jGetcxxid(cppbindObj.id)
    }

    /**
     * An internal property returning underlying C++ type name.
     * It is intended to be used by the generated code.
     */
    internal val cxxTypeName: String by lazy {
        jGettypebyid(cppbindObj.id)
    }
    
    constructor(): this(CppBindObject(construct_helper(), true)) {
    }

    constructor(d: Digit): this(CppBindObject(construct_helper(d), true)) {
    }
    
    fun getTextType(t: Text): String {
        val kotlintojdkt = t.id
        val result = jGettexttype(id, kotlintojdkt, t)
        
        return result
    }

    fun getSignType(s: ISign): String {
        val kotlintojdks = s.id
        val result = jGetsigntype(id, kotlintojdks, s)
        
        return result
    }

    fun getTextId(t: Text): Int {
        val kotlintojdkt = t.id
        val result = jGettextid(id, kotlintojdkt, t)
        
        return result
    }

    fun getSignId(s: ISign): Int {
        val kotlintojdks = s.id
        val result = jGetsignid(id, kotlintojdks, s)
        
        return result
    }

    fun getTextPtr(): Text {
        val result = jGettextptr(id)
        
        val jdktokotlinresult : Text
        jdktokotlinresult = Text.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    fun getSignPtr(): ISign {
        val result = jGetsignptr(id)
        
        val jdktokotlinresult : ISign
        jdktokotlinresult = ISign.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    /**
     * CPPBind generated hashCode method returning the hash of underlying C++ object id. .
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CPPBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as SymbolUsage
        return cxxId == other.cxxId
    }

    /**
     * CPPBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x%x: %s>".format(cxxId, cxxTypeName)
    }

    override fun close() {
        if (cppbindObj.owner && cppbindObj.id != 0L) {
            jFinalize(cppbindObj.id)
            cppbindObj.id = 0L
        }
    }

    /**
     * Finalize and deletes the object
     */
    protected fun finalize() {
        close()
    }

    ///// External wrapper functions ////////////
    private external fun jGettexttype(id: Long, t: Long, vararg extraObjs: Any?): String
    private external fun jGetsigntype(id: Long, s: Long, vararg extraObjs: Any?): String
    private external fun jGettextid(id: Long, t: Long, vararg extraObjs: Any?): Int
    private external fun jGetsignid(id: Long, s: Long, vararg extraObjs: Any?): Int
    private external fun jGettextptr(id: Long): Long
    private external fun jGetsignptr(id: Long): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
