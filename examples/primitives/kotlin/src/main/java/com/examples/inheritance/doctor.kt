/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/01/2022-07:54.
 * Please do not change it manually.
 */

package com.examples.inheritance

import com.examples.cppbind.alias.*
import com.examples.cppbind.exceptionUtils.*
import com.examples.cppbind.exception_helpers.*

/**
 * A base class for checking single branch non-polymorphic inheritance cases
 */
open class Doctor
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Doctor"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(doctor_name: String): this(CppBindObject(construct_helper(doctor_name), true)) {
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
    private external fun jFinalize(id: Long): Unit
}

open class Surgeon
internal constructor(obj: CppBindObject) : Doctor(obj) {
    companion object {
        
        protected fun construct_helper(surgeon_name: String): Long {
            val id = jConstructor(surgeon_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(surgeon_name: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::Surgeon"
    }
    
    
    constructor(surgeon_name: String): this(CppBindObject(construct_helper(surgeon_name), true)) {
    }
}


/**
 * A base class for checking multibranch mixed polymorphic inheritance cases
 */
interface IGoodVirtualDoctor : AutoCloseable {
    val id: Long
    fun keepCppBindReference(ref: Any)
    
    

    companion object {
        public fun cppbindConstructObject(id: Long, owner: Boolean = false): IGoodVirtualDoctor {
            val idType = jGettypebyid(id)
            when (idType) {
                GoodYoungDoctor.cppbindCxxTypeName -> return GoodYoungDoctor(CppBindObject(id, owner))
                else -> return GoodVirtualDoctorImpl(CppBindObject(id, owner))
            }
        }
    }
}



open class GoodVirtualDoctorImpl
internal constructor(obj : CppBindObject) : IGoodVirtualDoctor {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        const val cppbindCxxTypeName: String = "cppbind::example::GoodVirtualDoctor"
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
}

open class GoodDoctor
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::GoodDoctor"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(doctor_name: String): this(CppBindObject(construct_helper(doctor_name), true)) {
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
    private external fun jFinalize(id: Long): Unit
}

/**
 * Polymorphic subclass
 */
open class GoodYoungDoctor
internal constructor(obj: CppBindObject) : IGoodVirtualDoctor, GoodDoctor(obj) {
    companion object {
        
        protected fun construct_helper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::GoodYoungDoctor"
    }
    
    override val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(doctor_name: String): this(CppBindObject(construct_helper(doctor_name), true)) {
    }
}

/**
 * Non-polymorphic subclass
 */
open class GoodOldDoctor
internal constructor(obj: CppBindObject) : GoodDoctor(obj) {
    companion object {
        
        protected fun construct_helper(doctor_name: String): Long {
            val id = jConstructor(doctor_name)
            return id
        }

        @JvmStatic
        private external fun jConstructor(doctor_name: String, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::GoodOldDoctor"
    }
    
    
    constructor(doctor_name: String): this(CppBindObject(construct_helper(doctor_name), true)) {
    }
}

open class DoctorInfo
internal constructor(obj: CppBindObject) : AutoCloseable {
    companion object {
        init {
            System.loadLibrary("wrapper_jni")
        }
        
        protected fun construct_helper(s: Surgeon): Long {
            val kotlintojdks = s.id
            val id = jConstructor(kotlintojdks, s)
            return id
        }

        @JvmStatic
        private external fun jConstructor(s: Long, vararg extraObjs: Any?): Long

        protected fun construct_helper(d: GoodYoungDoctor): Long {
            val kotlintojdkd = d.id
            val id = jConstructor_1(kotlintojdkd, d)
            return id
        }

        @JvmStatic
        private external fun jConstructor_1(d: Long, vararg extraObjs: Any?): Long
        const val cppbindCxxTypeName: String = "cppbind::example::DoctorInfo"
    }
    
    protected var cppbindObj = obj
    private var refs: MutableList<Any> = mutableListOf()

    fun keepCppBindReference(ref: Any) {
        refs.add(ref)
    }
    
    open val id: Long
        get() {
            if (cppbindObj.id == 0L) {
                throw RuntimeException("Object is not allocated")
            }
            return cppbindObj.id
        }
    
    constructor(s: Surgeon): this(CppBindObject(construct_helper(s), true)) {
    }

    constructor(d: GoodYoungDoctor): this(CppBindObject(construct_helper(d), true)) {
    }
    
    fun getDoctorName(d: Doctor): String {
        val kotlintojdkd = d.id
        val result = jGetdoctorname(id, kotlintojdkd, d)
        
        return result
    }

    fun getSurgeonName(s: Surgeon): String {
        val kotlintojdks = s.id
        val result = jGetsurgeonname(id, kotlintojdks, s)
        
        return result
    }

    fun getDoctor(): Doctor {
        val result = jGetdoctor(id)
        val jdktokotlinresult = Doctor(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getGoodDoctor(): GoodDoctor {
        val result = jGetgooddoctor(id)
        val jdktokotlinresult = GoodDoctor(CppBindObject(result))
        return jdktokotlinresult
    }

    fun getGoodVirtualDoctor(): IGoodVirtualDoctor {
        val result = jGetgoodvirtualdoctor(id)
        
        val jdktokotlinresult : IGoodVirtualDoctor
        jdktokotlinresult = IGoodVirtualDoctor.cppbindConstructObject(result)
        return jdktokotlinresult
    }

    fun getGoodDoctorName(d: GoodDoctor): String {
        val kotlintojdkd = d.id
        val result = jGetgooddoctorname(id, kotlintojdkd, d)
        
        return result
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
}

private external fun jGettypebyid(id: Long): String
