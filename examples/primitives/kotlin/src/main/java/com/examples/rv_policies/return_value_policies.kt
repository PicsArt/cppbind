/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/06/2022-11:44.
 * Please do not change it manually.
 */

package com.examples.rv_policies

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

/**
 * A test example for return value policies. This is not used in documentation.
 */
open class Value
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(name: String): Long {
            val id = jConstructor(name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Value"
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
    open val cppbindObjId: Long
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
    
    constructor(name: String): this(CppBindObject(constructHelper(name), true)) {
    }
    
    var name: String
        get() {
            val result = jName(cppbindObjId)
            
            return result
        }
        set(value) {
            
            jSetname(cppbindObjId, value, value)
        }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as Value
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jName(id: Long): String
    private external fun jSetname(id: Long, value: String, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class MovableValue
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(name: String): Long {
            val id = jConstructor(name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::MovableValue"
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
    open val cppbindObjId: Long
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
    
    constructor(name: String): this(CppBindObject(constructHelper(name), true)) {
    }
    
    var name: String
        get() {
            val result = jName(cppbindObjId)
            
            return result
        }
        set(value) {
            
            jSetname(cppbindObjId, value, value)
        }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as MovableValue
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jName(id: Long): String
    private external fun jSetname(id: Long, value: String, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class ValueSharedRef
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(name: String): Long {
            val id = jConstructor(name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::ValueSharedRef"
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
    open val cppbindObjId: Long
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
    
    constructor(name: String): this(CppBindObject(constructHelper(name), true)) {
    }
    
    var name: String
        get() {
            val result = jName(cppbindObjId)
            
            return result
        }
        set(value) {
            
            jSetname(cppbindObjId, value, value)
        }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as ValueSharedRef
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jName(id: Long): String
    private external fun jSetname(id: Long, value: String, valueObj: Any?): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class ValuesHolder
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long

        protected fun constructHelper(valuePtr: Value, valueRef: ValueSharedRef): Long {
            val kotlintojdkvaluePtr = valuePtr.cppbindObjId
            val kotlintojdkvalueRef = valueRef.cppbindObjId
            val id = jConstructor1(kotlintojdkvaluePtr, kotlintojdkvalueRef, valuePtr, valueRef)
            return id
        }

        @JvmStatic
        private external fun jConstructor1(valuePtr: Long, valueRef: Long, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::ValuesHolder"
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
    open val cppbindObjId: Long
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
    
    constructor(): this(CppBindObject(constructHelper(), true)) {
    }

    constructor(valuePtr: Value, valueRef: ValueSharedRef): this(CppBindObject(constructHelper(valuePtr, valueRef), true)) {
    }
    
    fun getPtrDefault(): Value {
        val result = jGetptrdefault(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getPtrCopy(): Value {
        val result = jGetptrcopy(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getPtrMove(): Value {
        val result = jGetptrmove(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getPtrReference(): Value {
        val result = jGetptrreference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getPtrAutomatic(): Value {
        val result = jGetptrautomatic(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getPtrAutomaticReference(): Value {
        val result = jGetptrautomaticreference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getPtrTakeOwnership(): Value {
        val result = jGetptrtakeownership(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueDefault(): Value {
        val result = jGetvaluedefault(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueCopy(): Value {
        val result = jGetvaluecopy(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueMove(): Value {
        val result = jGetvaluemove(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getMovableValue(): MovableValue {
        val result = jGetmovablevalue(cppbindObjId)
        val jdktokotlinresult = MovableValue(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueReference(): Value {
        val result = jGetvaluereference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueAutomatic(): Value {
        val result = jGetvalueautomatic(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueAutomaticReference(): Value {
        val result = jGetvalueautomaticreference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getValueTakeOwnership(): Value {
        val result = jGetvaluetakeownership(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefCopy(): Value {
        val result = jGetrefcopy(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefDefault(): Value {
        val result = jGetrefdefault(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefMove(): Value {
        val result = jGetrefmove(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefReference(): Value {
        val result = jGetrefreference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getRefAutomatic(): Value {
        val result = jGetrefautomatic(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefAutomaticReference(): Value {
        val result = jGetrefautomaticreference(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getRefTakeOwnership(): Value {
        val result = jGetreftakeownership(cppbindObjId)
        val jdktokotlinresult = Value(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefDefault(): ValueSharedRef {
        val result = jGetsharedrefdefault(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefCopy(): ValueSharedRef {
        val result = jGetsharedrefcopy(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefMove(): ValueSharedRef {
        val result = jGetsharedrefmove(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefReference(): ValueSharedRef {
        val result = jGetsharedrefreference(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefAutomatic(): ValueSharedRef {
        val result = jGetsharedrefautomatic(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefAutomaticReference(): ValueSharedRef {
        val result = jGetsharedrefautomaticreference(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun getSharedRefTakeOwnership(): ValueSharedRef {
        val result = jGetsharedreftakeownership(cppbindObjId)
        val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
        return jdktokotlinresult
    }

    fun clean(): Unit {
        val result = jClean(cppbindObjId)
        
        return result
    }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as ValuesHolder
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jGetptrdefault(id: Long): Long
    private external fun jGetptrcopy(id: Long): Long
    private external fun jGetptrmove(id: Long): Long
    private external fun jGetptrreference(id: Long): Long
    private external fun jGetptrautomatic(id: Long): Long
    private external fun jGetptrautomaticreference(id: Long): Long
    private external fun jGetptrtakeownership(id: Long): Long
    private external fun jGetvaluedefault(id: Long): Long
    private external fun jGetvaluecopy(id: Long): Long
    private external fun jGetvaluemove(id: Long): Long
    private external fun jGetmovablevalue(id: Long): Long
    private external fun jGetvaluereference(id: Long): Long
    private external fun jGetvalueautomatic(id: Long): Long
    private external fun jGetvalueautomaticreference(id: Long): Long
    private external fun jGetvaluetakeownership(id: Long): Long
    private external fun jGetrefcopy(id: Long): Long
    private external fun jGetrefdefault(id: Long): Long
    private external fun jGetrefmove(id: Long): Long
    private external fun jGetrefreference(id: Long): Long
    private external fun jGetrefautomatic(id: Long): Long
    private external fun jGetrefautomaticreference(id: Long): Long
    private external fun jGetreftakeownership(id: Long): Long
    private external fun jGetsharedrefdefault(id: Long): Long
    private external fun jGetsharedrefcopy(id: Long): Long
    private external fun jGetsharedrefmove(id: Long): Long
    private external fun jGetsharedrefreference(id: Long): Long
    private external fun jGetsharedrefautomatic(id: Long): Long
    private external fun jGetsharedrefautomaticreference(id: Long): Long
    private external fun jGetsharedreftakeownership(id: Long): Long
    private external fun jClean(id: Long): Unit
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * A test example for reference_internal policy.
 */
open class AnotherValueHolder
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(): Long {
            val id = jConstructor()
            return id
        }

        @JvmStatic
        private external fun jConstructor(): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::AnotherValueHolder"
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
    open val cppbindObjId: Long
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
    
    constructor(): this(CppBindObject(constructHelper(), true)) {
    }
    
    val value: Value
        get() {
            val result = jValue(cppbindObjId)
            val jdktokotlinresult = Value(CppBindObject(result))
            jdktokotlinresult.keepCppBindReference(this)
            return jdktokotlinresult
        }

    val valueReference: Value
        get() {
            val result = jValuereference(cppbindObjId)
            val jdktokotlinresult = Value(CppBindObject(result))
            return jdktokotlinresult
        }

    val sharedValue: ValueSharedRef
        get() {
            val result = jSharedvalue(cppbindObjId)
            val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
            return jdktokotlinresult
        }

    val sharedValueReference: ValueSharedRef
        get() {
            val result = jSharedvaluereference(cppbindObjId)
            val jdktokotlinresult = ValueSharedRef(CppBindObject(result, true))
            return jdktokotlinresult
        }

    /**
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as AnotherValueHolder
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
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
    private external fun jValue(id: Long): Long
    private external fun jValuereference(id: Long): Long
    private external fun jSharedvalue(id: Long): Long
    private external fun jSharedvaluereference(id: Long): Long
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
