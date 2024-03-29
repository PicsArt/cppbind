/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/18/2022-09:00.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.*
import com.examples.cppbind.exceptions.*

/**
 * A base class for checking single branch non-polymorphic inheritance cases
 */
open class Doctor
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Doctor"
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
    
    constructor(doctor_name: String): this(CppBindObject(constructHelper(doctor_name), true)) {
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
        other as Doctor
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
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class Surgeon
internal constructor(obj: CppBindObject) : Doctor(obj) {
    companion object {
        
        protected fun constructHelper(surgeon_name: String): Long {
            val id = jConstructor(surgeon_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(surgeon_name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::Surgeon"
    }
    
    
    constructor(surgeon_name: String): this(CppBindObject(constructHelper(surgeon_name), true)) {
    }
}


/**
 * A base class for checking multibranch mixed polymorphic inheritance cases
 */
interface IGoodVirtualDoctor : AutoCloseable {
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    val cppbindObjId: Long
    /**
     * An internal method to bind the lifetimes of the current and another object.
     * It is intended to be used by the generated code.
     */
    fun keepCppBindReference(ref: Any)
    
    

    companion object {
        /**
         * An internal method to create a Kotlin object from a C++ object.
         * It is intended to be used by the generated code.
         */
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IGoodVirtualDoctor {
            val idType = jGettypebyid(id)
            val obj : IGoodVirtualDoctor
            when (idType) {
                GoodYoungDoctor.cppbindCxxTypeName -> obj = GoodYoungDoctor(CppBindObject(id, owner))
                else -> obj = GoodVirtualDoctorImpl(CppBindObject(id, owner))
            }
            return obj
        }
    }
}



open class GoodVirtualDoctorImpl
internal constructor(obj : CppBindObject) : IGoodVirtualDoctor {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::GoodVirtualDoctor"
    }

    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    override fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }

    override val cppbindObjId: Long
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
     * CppBind generated hashCode method returning the hash of underlying C++ object id.
     */
    override fun hashCode(): Int {
        return cxxId.hashCode()
    }

    /**
     * CppBind generated equals method comparing the underlying C++ object ids.
     */
    override fun equals(other: Any?): Boolean {
        other as GoodVirtualDoctorImpl
        return cxxId == other.cxxId
    }

    /**
     * CppBind generated toString method returning underlying C++ object type and id.
     */
    override fun toString(): String {
        return "<0x$cxxId: $cxxTypeName>"
    }

    ///// External wrapper functions ////////////
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

open class GoodDoctor
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::GoodDoctor"
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
    
    constructor(doctor_name: String): this(CppBindObject(constructHelper(doctor_name), true)) {
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
        other as GoodDoctor
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
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

/**
 * Polymorphic subclass
 */
open class GoodYoungDoctor
internal constructor(obj: CppBindObject) : IGoodVirtualDoctor, GoodDoctor(obj) {
    companion object {
        
        protected fun constructHelper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::GoodYoungDoctor"
    }
    
    /**
     * An internal getter to get the id of an object.
     * It is intended to be used by the generated code.
     */
    override val cppbindObjId: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(doctor_name: String): this(CppBindObject(constructHelper(doctor_name), true)) {
    }
}

/**
 * Non-polymorphic subclass
 */
open class GoodOldDoctor
internal constructor(obj: CppBindObject) : GoodDoctor(obj) {
    companion object {
        
        protected fun constructHelper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::GoodOldDoctor"
    }
    
    
    constructor(doctor_name: String): this(CppBindObject(constructHelper(doctor_name), true)) {
    }
}

open class DoctorInfo
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun constructHelper(s: Surgeon): Long {
            val kotlintojdks = s.cppbindObjId
            val id = jConstructor(kotlintojdks, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(s: Long, vararg extraObjs: Any?): Long

        protected fun constructHelper(d: GoodYoungDoctor): Long {
            val kotlintojdkd = d.cppbindObjId
            val id = jConstructor1(kotlintojdkd, d)
            return id
        }

        @JvmStatic
        private external fun jConstructor1(d: Long, vararg extraObjs: Any?): Long
        /**
         * An internal property to keep an information about the underlying C++ object type.
         * It is intended to be used by the generated code.
         */
        const val cppbindCxxTypeName: String = "cppbind::example::DoctorInfo"
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
    
    constructor(s: Surgeon): this(CppBindObject(constructHelper(s), true)) {
    }

    constructor(d: GoodYoungDoctor): this(CppBindObject(constructHelper(d), true)) {
    }
    
    fun getDoctorName(d: Doctor): String {
        val kotlintojdkd = d.cppbindObjId
        val result = jGetdoctorname(cppbindObjId, kotlintojdkd, d)
        
        return result
    }

    fun getSurgeonName(s: Surgeon): String {
        val kotlintojdks = s.cppbindObjId
        val result = jGetsurgeonname(cppbindObjId, kotlintojdks, s)
        
        return result
    }

    fun getDoctor(): Doctor {
        val result = jGetdoctor(cppbindObjId)
        val jdktokotlinresult = Doctor(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getGoodDoctor(): GoodDoctor {
        val result = jGetgooddoctor(cppbindObjId)
        val jdktokotlinresult = GoodDoctor(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getGoodVirtualDoctor(): IGoodVirtualDoctor {
        val result = jGetgoodvirtualdoctor(cppbindObjId)
        
        val jdktokotlinresult : IGoodVirtualDoctor
        jdktokotlinresult = IGoodVirtualDoctor.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    fun getGoodDoctorName(d: GoodDoctor): String {
        val kotlintojdkd = d.cppbindObjId
        val result = jGetgooddoctorname(cppbindObjId, kotlintojdkd, d)
        
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
        other as DoctorInfo
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
    private external fun jGetdoctorname(id: Long, d: Long, vararg extraObjs: Any?): String
    private external fun jGetsurgeonname(id: Long, s: Long, vararg extraObjs: Any?): String
    private external fun jGetdoctor(id: Long): Long
    private external fun jGetgooddoctor(id: Long): Long
    private external fun jGetgoodvirtualdoctor(id: Long): Long
    private external fun jGetgooddoctorname(id: Long, d: Long, vararg extraObjs: Any?): String
    private external fun jFinalize(id: Long): Unit
    private external fun jGetcxxid(id: Long): Long
}

private external fun jGettypebyid(id: Long): String
